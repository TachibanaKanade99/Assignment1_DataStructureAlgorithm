//
// Created by tachibana on 01/12/2018.
//

#ifndef CHECK_PARENTHESES_OPERAND_LIST_H
#define CHECK_PARENTHESES_OPERAND_LIST_H

#include <iostream>
#include <string>
#include "List.h"

template <typename T>
struct Operand{
    std::string name;
    T val;
    Operand(std::string name, int val){
        this->name = name;
        this->val = val;
    }
    ~Operand(){}
};

template <typename T>
struct Operand_Node{
    Operand<T>* data;
    Operand_Node<T>* pNext;
    Operand_Node<T>* pPrev;

    Operand_Node(Operand<T>* operand){
        this->data = operand;
        pNext = NULL;
        pPrev = NULL;
    }
};

template <typename T>
struct Operand_List{
    int size;
    Operand_Node<T>* pHead;
    Operand_Node<T>* pTail;

    Operand_List(){
        this->size = 0;
        pHead = NULL;
        pTail = NULL;
    }
    ~Operand_List(){
        Operand_Node<T>* pRun = NULL;
        while(pHead != NULL){
            pRun = pHead;
            pHead = pHead->pNext;
            delete pRun;
        }
    }

    void addLast(Operand<T>* operand){
        Operand_Node<T>* pNew = new Operand_Node<T>(new Operand<T>(operand->name, operand->val));
        if (size == 0){
            pHead = pNew;
            pTail = pNew;
        }
        else {
            pTail->pNext = pNew;
            pTail = pNew;
        }
        size++;
    }

    T Find_Val(std::string name){
        Operand_Node<T>* ptr = pHead;
        while (ptr != NULL){
            if (ptr->data->name == name){
                break;
            }

            ptr = ptr->pNext;
        }
        return ptr->data->val;
    }

    bool Find_Operand(std::string name){
        Operand_Node<T>* ptr = pHead;
        while (ptr != NULL){
            if (ptr->data->name == name){
                return 1;
            }
            ptr = ptr->pNext;
        }
        return 0;
    }
};

#endif //CHECK_PARENTHESES_OPERAND_LIST_H
