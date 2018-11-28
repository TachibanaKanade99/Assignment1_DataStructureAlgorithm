//
// Created by tachibana on 27/11/2018.
//

#ifndef CHECK_PARENTHESES_INFIX_TO_POSTFIX_H
#define CHECK_PARENTHESES_INFIX_TO_POSTFIX_H

#include <iostream>
#include "Check_parenthesis.h"
#include <string>


template <typename T>
struct Infix_to_Postfix{
    Check<T> check;
    List<T> Postfix_list;

    ~Infix_to_Postfix(){}

    bool isOperator(std::string c){
        if (c == "+" || c == "-" || c == "*" || c == "/"){
            return 1;
        }
        else{
            return 0;
        }
    }

    int Precedence(std::string c){
        if (c == "+" || c == "-"){
            return 1;
        }
        else if (c == "*" || c == "/"){
            return 2;
        }
    }

    bool HigherPrecedence(std::string C1, std::string C2){
        int temp = 0;
        int GetPrecedenceC1 = Precedence(C1);
        int GetPrecedenceC2 = Precedence(C2);

        if (GetPrecedenceC1 == GetPrecedenceC2){
            temp = 1;
            return temp;
        }
        else if (GetPrecedenceC1 > GetPrecedenceC2){
            temp =  1;
            return temp;
        }
        return temp;
    }

    void EvaluateInfix(T data){
        Stack<std::string> stack;
        check.ReadToken(data);
        Node<T>* ptr = check.list.getpHead();

        while (ptr != NULL){
            if (isOperator(ptr->data)){
                while (!stack.isEmpty() && HigherPrecedence(stack.Bot(), ptr->data)){
                    if (stack.Bot() == "(" || stack.Bot() == "[" || stack.Bot() == "{") {
                        break;
                    }
                    if (ptr->data == "-"){
                        std::string temp = ptr->data;
                        if (ptr != NULL) {
                            ptr = ptr->pNext;
                        }
                        temp += ptr->data;
                        Postfix_list.addLast(temp);
                    }
                    Postfix_list.addLast(stack.Pop());
                    ptr = ptr->pNext;
                }
                    stack.Push(ptr->data);
                }

            else if (ptr->data == "(" ||
                     ptr->data == "[" ||
                     ptr->data == "{"){
                stack.Push(ptr->data);
            }

            else if (ptr->data == ")" ||
                     ptr->data == "]" ||
                     ptr->data == "}"){
                while (!stack.isEmpty()){
                    if (stack.Bot() == "(" || stack.Bot() == "[" || stack.Bot() == "{"){
                        break;
                    }
                    Postfix_list.addLast(stack.Pop());
                }
                stack.Pop();

            }
            else if (ptr->data == ""){
                if (ptr != NULL){
                    ptr = ptr->pNext;
                }

                continue;
            }
            else{
                Postfix_list.addLast(ptr->data);
            }
            ptr = ptr->pNext;
        }
        while (!stack.isEmpty()){
            Postfix_list.addLast(stack.Pop());
        }
    }


};

#endif //CHECK_PARENTHESES_INFIX_TO_POSTFIX_H
