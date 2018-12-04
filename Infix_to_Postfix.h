//
// Created by tachibana on 27/11/2018.
//

#ifndef CHECK_PARENTHESES_INFIX_TO_POSTFIX_H
#define CHECK_PARENTHESES_INFIX_TO_POSTFIX_H

#include <iostream>
#include "Check_parenthesis.h"
#include <string>


struct Infix_to_Postfix{
    Check check;
    List<std::string> Postfix_list;

    ~Infix_to_Postfix(){}

    bool isOperator(std::string c){
        if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^"){
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
        else if (c == "^"){
            return 3;
        }
    }

    bool HigherPrecedence(std::string C1, std::string C2){
        int GetPrecedenceC1 = Precedence(C1);
        int GetPrecedenceC2 = Precedence(C2);

        if (GetPrecedenceC1 == GetPrecedenceC2){
            return 1;
        }
        else if (GetPrecedenceC1 > GetPrecedenceC2){
            return 1;
        }
        return 0;
    }

    void EvaluateInfix(std::string data){
        Stack<std::string> stack;
        check.ReadToken(data);
        Node<std::string>* ptr = check.list.getpHead();

        while (ptr != NULL){
            if (isOperator(ptr->data)) {
                while (!stack.isEmpty() && HigherPrecedence(stack.Bot(), ptr->data)) {
                    if (stack.Bot() == "(" || stack.Bot() == "[" || stack.Bot() == "{") {
                        break;
                    }

                    //Check unary operation:
                    if (ptr->data == "-" && (isOperator(ptr->pPrev->data) || ptr->pPrev->data == "-")) {
                        std::string temp = ptr->data;
                        if (ptr != NULL) {
                            ptr = ptr->pNext;
                        }
                        temp += ptr->data;
                        Postfix_list.addLast(temp);
                    }
                    Postfix_list.addLast(stack.Pop());
                }
                if (isOperator(ptr->data)){
                    stack.Push(ptr->data);
                }
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
