//
// Created by tachibana on 01/12/2018.
//

#ifndef CHECK_PARENTHESES_EXERCISE2_H
#define CHECK_PARENTHESES_EXERCISE2_H

#include <iostream>
#include <sstream>
#include <string>
#include "Postfix_to_Infix.h"
#include "Operand_List.h"

template <typename T>
struct Exercise2{
    Operand_List<T> operand_list;

    /*T GetVal(std::string str){
        Postfix_to_Infix<T> postfix_to_infix(str);
        T result = postfix_to_infix.EvaluatePostfix();

        //Add new operand to operand_list:
        operand_list.addLast(new Operand<T>(postfix_to_infix.infix_to_postfix.Postfix_list.getpHead()->data, result));
        return result;
    }*/

    //Check is operand:
    bool isOperand(char c){
        if (c >= 'a' && c <= 'z'){
            return 1;
        }
        return 0;
    }

    bool CheckOperand(std::string str){
        for (int i = 0; i < str.length(); i++){
            if (isOperand(str[i])){
                return 1;
            }
            else{
                return 0;
            }
        }
    }

    //Look for operand and replace it by value:
    T SwapVal(std::string str){
        Postfix_to_Infix<T> postfix_to_infix(str);
        Node<std::string>* ptr = postfix_to_infix.infix_to_postfix.Postfix_list.getpHead();

        while(ptr != NULL){
            if (CheckOperand(ptr->data) && operand_list.Find_Operand(ptr->data)){
                ptr->data = std::to_string(operand_list.Find_Val(ptr->data));
            }
            ptr = ptr->pNext;
        }
        T result = postfix_to_infix.EvaluatePostfix();

        operand_list.addLast(new Operand<T>(postfix_to_infix.infix_to_postfix.Postfix_list.getpHead()->data, result));
        return result;
    }
};


#endif //CHECK_PARENTHESES_EXERCISE2_H
