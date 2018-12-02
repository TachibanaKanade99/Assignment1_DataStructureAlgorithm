#include <iostream>
#include <string>
#include "Postfix_to_Infix.h"
#include "ReadInput.h"
#include "Exercise2.h"

int main() {
    //Exercise 1:
    /*std::string str1 = "";
    getline(std::cin, str1);

    Postfix_to_Infix<double> postfix_to_infix1(str1);
    std::cout << "= " << postfix_to_infix1.EvaluatePostfix() << std::endl;

    postfix_to_infix1.infix_to_postfix.check.Print();
    std::cout << "Postfix of String: " << std::endl;
    std::cout << postfix_to_infix1.infix_to_postfix.Postfix_list << std::endl;
*/
    //ReadInput Exercise1:
    ReadInput1();

    //Exercise 2:
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


    //ReadInput Exercise2:
    std::cout << "\n";
    ReadInput2();

    return 0;
}























