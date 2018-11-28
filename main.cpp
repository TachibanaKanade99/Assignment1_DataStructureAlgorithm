#include <iostream>
#include <string>

#include "Infix_to_Postfix.h"
#include "Postfix_to_Infix.h"

int main() {
    std::string str = "";
    getline(std::cin, str);

    Infix_to_Postfix<std::string> infix_to_postfix;
    infix_to_postfix.EvaluateInfix(str);


    std::cout << infix_to_postfix.Postfix_list << std::endl;

    return 0;
}