//
// Created by tachibana on 01/12/2018.
//

#ifndef CHECK_PARENTHESES_READINPUT_H
#define CHECK_PARENTHESES_READINPUT_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Postfix_to_Infix.h"
#include "Exercise2.h"

void ReadInput1() {
    //Read input from text.txt:
    std::ifstream file;
    file.open("text.txt");
    std::string str;
    while (!file.eof()) {
        getline(file, str);
        Postfix_to_Infix<double> postfix_to_infix(str);
        std::cout << str;
        std::cout << " = " << std::setprecision(5) << postfix_to_infix.EvaluatePostfix() << std::endl;
    }
}

void ReadInput2(){
    //Read input from text2.txt
    std::ifstream file;
    file.open("Text2.txt");
    std::string str;
    Exercise2<double> exercise2;

    while (!file.eof()){
        getline(file, str);
        if (str == ""){
            break;
        }
        std::cout << str;
        std::cout << " = " << std::setprecision(5) << exercise2.SwapVal(str) << std::endl;
    }
}

#endif //CHECK_PARENTHESES_READINPUT_H
