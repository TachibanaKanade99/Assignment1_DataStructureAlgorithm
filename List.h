//
// Created by tachibana on 20/11/2018.
//

#ifndef CHECK_PARENTHESES_LIST_H
#define CHECK_PARENTHESES_LIST_H


#include <iostream>
#include <string>
#include <iomanip>

template <typename T>
struct Node{
    T data;
    Node<T>* pNext;
    Node<T>* pPrev;

    Node(T data){
        this->data = data;
        pNext = NULL;
        pPrev = NULL;
    }
};
template <typename T>
struct List{ //This is Double-Linked List;
    Node<T>* pHead;
    Node<T>* pTail;
    int size;

    List(){
        pHead = NULL;
        pTail = NULL;
        size = 0;
    }

    ~List(){
        //std::cout << "\nDestructor of List calls here" << std::endl;
        Clear();
    }

    T addFirst(T data){
        Node<T>* pNew = new Node<T>(data);

        if (size == 0){
            pHead = pNew;
            pTail = pNew;
        }
        else{
            pHead->pPrev = pNew;
            pNew->pNext = pHead;
            pHead = pNew;
        }
        size++;
        return data;
    }

    T addLast(T data){
        Node<T>* pNew = new Node<T>(data);

        if (size == 0){
            pHead = pNew;
            pTail = pNew;
        }
        else{
            pNew->pPrev = pTail;
            pTail->pNext = pNew;
            pTail = pNew;
        }
        size++;
        return data;
    }

    T removeFirst(){
        if (size == 0){
            return 0;
        }
        else{
            Node<T>* ptr = pHead;
            T data = ptr->data;
            pHead = pHead->pNext;
            delete ptr;
            size--;
            return data;
        }
    }

    T removeLast(){
        if (size == 0){
            return 0;
        }
        else{
            Node<T>* ptr = pHead;
            while(ptr->pNext->pNext != NULL){
                ptr = ptr->pNext;
            }
            T data = ptr->data;
            pTail = ptr;
            ptr->pNext = NULL;
            size--;
            return data;
        }
    }

    int isSize(){
        return size;
    }

    Node<T>* getpHead(){
        return pHead;
    }

    Node<T>* getpTail(){
        return pTail;
    }

    void Clear(){
        Node<T>* ptr = NULL;
        while (pHead != NULL){
            ptr = pHead;
            delete pHead;
            pHead = ptr->pNext;
        }
    }

    void Print(){
        Node<T>* ptr = pHead;
        while(ptr != NULL){
            std::cout << ptr->data << " ";
            ptr = ptr->pNext;
        }
    }
};

template <typename T>
std::ostream &operator << (std::ostream &os, const List<T> &list){
    Node<T>* ptr = list.pHead;
    while(ptr != NULL){
        os << ptr->data;
        ptr = ptr->pNext;
        if (ptr != NULL){
            std::cout << ", ";
        }
    }
    return os;
}


#endif //CHECK_PARENTHESES_LIST_H
