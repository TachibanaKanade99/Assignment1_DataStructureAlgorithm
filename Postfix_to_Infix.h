//
// Created by tachibana on 22/11/2018.
//

#ifndef CHECK_PARENTHESES_POSTFIX_TO_INFIX_H
#define CHECK_PARENTHESES_POSTFIX_TO_INFIX_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "Infix_to_Postfix.h"

//Binary Operation:
#define Add "+"
#define Subtract "-"
#define Multiply "*"
#define Divide "/"
#define Power "^"
#define Modulo "%"

//Unary Operation:

template <typename T>
struct Postfix_to_Infix{
    //Read data from here:
    std::string data;
    Infix_to_Postfix<T> infix_to_postfix;
    Postfix_to_Infix(std::string data){
        this->data = data;
        infix_to_postfix.EvaluateInfix(this->data);
    }

    //Check is operator:
    bool isOperator(std::string C){
        if (C == Add      ||
            C == Subtract ||
            C == Multiply ||
            C == Divide   ||
            C == Power  /*||
            C == Modulo*/) // Consider Type Double cannot perform Modulo operation:
        {
            return 1;
        }
        return 0;
    }

    //Function to perform operation:
    T PerformOperation(std::string operation, T operand1, T operand2){
        if (operation == Add){
            return operand1 + operand2;
        }
        else if (operation == Subtract){
            return operand1 - operand2;
        }
        else if (operation == Multiply){
            return operand1 * operand2;
        }
        else if (operation == Divide){
            return operand1 / operand2;
        }
        else if (operation == Power){
            return std::pow(operand1, operand2);
        }
        /*else if (operation == Modulo){
            return operand1 % operand2;
        }*/
        else{
            std::cout << "Operator Error" << std::endl;
            return -1;
        }
    }

    T EvaluatePostfix(){

        Stack<T> stack;
        Node<std::string>* ptr = infix_to_postfix.Postfix_list.getpHead();

        if (ptr == NULL){
            std::cout << "\nError Operation" << std::endl;
            return - 1;
        }

        while (ptr != NULL){
            if (ptr->data == ""){
                ptr = ptr->pNext;
                continue;
            }

            //Check operator:
            else if (isOperator(ptr->data)){
                //Pop two operands:
                T operand2 = stack.Pop();
                T operand1 = stack.Pop();

                //Perform operation:
                T result = PerformOperation(ptr->data, operand1, operand2);

                //Push back to stack:
                stack.Push(result);
            }

            //Check Numberdigit:
            else {
                T operand;
                std::istringstream(ptr->data) >> operand;
                stack.Push(operand);
            }
            ptr = ptr->pNext;
        }
        //Return the result in stack:
        return stack.Pop();
    }

};

#endif //CHECK_PARENTHESES_POSTFIX_TO_INFIX_H
