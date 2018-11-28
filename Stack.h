//
// Created by tachibana on 20/11/2018.
//

#ifndef CHECK_PARENTHESES_STACK_H
#define CHECK_PARENTHESES_STACK_H

#include <iostream>
#include <string>
#include <iomanip>
#include "List.h"

template <typename T>
struct Stack{
    List<T> list;

    T Push(T data){
        return list.addFirst(data);
    }

    T Pop(){
        return list.removeFirst();
    }

    T Top(){
        return list.getpTail()->data;
    }

    T Bot(){
        return list.getpHead()->data;
    }

    bool isEmpty(){
        return (list.isSize() == 0);
    }

    int isSize(){
        return list.isSize();
    }

};


#endif //CHECK_PARENTHESES_STACK_H
