//
// Created by tachibana on 01/12/2018.
//

#ifndef CHECK_PARENTHESES_READINPUT_H
#define CHECK_PARENTHESES_READINPUT_H

#include <iostream>
#include <fstream>
#include <string>
#include "Postfix_to_Infix.h"

void ReadInput(){
    //Read input from file:
    std::ifstream file;
    file.open("text.txt");
    std::string str;
    while (!file.eof()){
        getline(file, str);
        Postfix_to_Infix<double> postfix_to_infix(str);
        std::cout << str;
        std::cout << " = " << postfix_to_infix.EvaluatePostfix() << std::endl;
    }

}

#endif //CHECK_PARENTHESES_READINPUT_H
