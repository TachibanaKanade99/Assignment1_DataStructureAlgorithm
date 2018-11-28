//
// Created by tachibana on 22/11/2018.
//

#ifndef CHECK_PARENTHESES_POSTFIX_TO_INFIX_H
#define CHECK_PARENTHESES_POSTFIX_TO_INFIX_H

#include <iostream>
#include <string>
#include <sstream>
#include "Infix_to_Postfix.h"

//Binary Operation:
#define Add "+"
#define Subtract "-"
#define Multiply "*"
#define Divide "/"

//Unary Operation:

template <typename T>
struct Postfix_to_Infix{
    //Read data from here:
    T data;
    Infix_to_Postfix<T> infix_to_postfix;
    Postfix_to_Infix(T data){
        this->data = data;
        infix_to_postfix.EvaluateInfix(this->data);
    }

         bool isOperator(std::string C){
            if (C == Add ||
                C == Subtract ||
                C == Multiply ||
                C == Divide)
            {
                return 1;
            }
            return 0;
        }

    //Function to perform operation:
    int PerformOperation(std::string operation, int operand1, int operand2){
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
        else{
            std::cout << "Inexpected Error" << std::endl;
            return -1;
        }
    }

    int EvaluatePostfix(){

        Stack<int> stack;
        Node<T>* ptr = infix_to_postfix.Postfix_list.getpHead();

        while (ptr != NULL){
            //Check operator:
            if (isOperator(ptr->data)){
                //Pop two operands:
                int operand2 = stack.Pop();
                int operand1 = stack.Pop();

                //Perform operation:
                int result = PerformOperation(ptr->data, operand1, operand2);

                //Push back to stack:
                stack.Push(result);
            }

            //Check Numberdigit:
            else {
                int operand;
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
