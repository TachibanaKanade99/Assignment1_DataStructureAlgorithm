#include <iostream>
#include <string>
#include "Postfix_to_Infix.h"

int main() {
    std::string str = "";
    getline(std::cin, str);

    Postfix_to_Infix<std::string> postfix_to_infix(str);
    std::cout << postfix_to_infix.EvaluatePostfix() << std::endl;

    std::cout << "Postfix of String: " << std::endl;
    std::cout << postfix_to_infix.infix_to_postfix.Postfix_list << std::endl;

    return 0;
}