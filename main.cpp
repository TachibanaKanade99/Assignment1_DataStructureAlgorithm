#include <iostream>
#include <string>

#include "Infix_to_Postfix.h"
#include "Postfix_to_Infix.h"

int main() {
    std::string str = "";
    getline(std::cin, str);

    /*Infix_to_Postfix<std::string> infix_to_postfix;
    infix_to_postfix.EvaluateInfix(str);*/

    Postfix_to_Infix<std::string> postfix_to_infix(str);
    //std::cout << postfix_to_infix.EvaluatePostfix() << std::endl;

    std::cout << "Postfix of String: " << std::endl;
    std::cout << postfix_to_infix.infix_to_postfix.Postfix_list << std::endl;

    /*std::cout << infix_to_postfix.Postfix_list << std::endl;*/

    return 0;
}