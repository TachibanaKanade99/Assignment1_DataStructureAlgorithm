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
        std::cout << " = " /*<< std::setprecision(5)*/ << postfix_to_infix.EvaluatePostfix() << std::endl;
        /*std::cout << "Postfix of String: " << std::endl;
        std::cout << postfix_to_infix.infix_to_postfix.Postfix_list << std::endl;*/
    }
}

/*std::string str1 = "";
    getline(std::cin, str1);

    Postfix_to_Infix<double> postfix_to_infix1(str1);
    std::cout << "= " << postfix_to_infix1.EvaluatePostfix() << std::endl;

    postfix_to_infix1.infix_to_postfix.check.Print();
    std::cout << "Postfix of String: " << std::endl;
    std::cout << postfix_to_infix1.infix_to_postfix.Postfix_list << std::endl;
*/

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
        std::cout << " = " /*<< std::setprecision(5)*/ << exercise2.SwapVal(str) << std::endl;
    }
}

/*std::string str2 = "";
    int n = 0;
    int N;
    std::cout << "Enter number of operation: " << std::endl;
    std::cin >> N;
    std::cin.ignore();

    Exercise2<double> exercise2;
    do{
        getline(std::cin, str2);
        if (n == 0){
            std :: cout << " = " << exercise2.GetVal(str2) << std::endl;
        }
        else {
            std::cout << " = " << exercise2.SwapVal(str2) << std::endl;
        }
        n++;
    }
    while (n < N);*/


#endif //CHECK_PARENTHESES_READINPUT_H
