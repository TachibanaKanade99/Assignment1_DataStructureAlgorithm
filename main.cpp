#include <iostream>
#include <string>
#include "Postfix_to_Infix.h"
#include <fstream>

int main() {
    //Exercise 1:
    /*std::string str1 = "";
    getline(std::cin, str1);

    Postfix_to_Infix<std::string> postfix_to_infix1(str1);
    std::cout << "= " << postfix_to_infix1.EvaluatePostfix() << std::endl;

    std::cout << "Postfix of String: " << std::endl;
    std::cout << postfix_to_infix1.infix_to_postfix.Postfix_list << std::endl;*/

    //Read input from file:
    /*std::ifstream file;
    file.open("text.txt");
    std::string str;
    while (!file.eof()){
        getline(file, str);
        Postfix_to_Infix<std::string> postfix_to_infix(str);
        std::cout << str;
        std::cout << " = " << postfix_to_infix.EvaluatePostfix() << std::endl;
    }*/

    //Exercise 2:


    return 0;
}