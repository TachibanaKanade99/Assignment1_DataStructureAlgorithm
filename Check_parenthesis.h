//
// Created by tachibana on 20/11/2018.
//

#ifndef CHECK_PARENTHESES_CHECK_PARENTHESIS_H
#define CHECK_PARENTHESES_CHECK_PARENTHESIS_H

#include <iostream>
#include <sstream>
#include <string>

#include "Stack.h"
#include "List.h"

#define left_parentheses '('
#define right_parentheses ')'
#define left_bracket '['
#define right_bracket ']'
#define left_curlybrace '{'
#define right_curlybrace '}'

struct Check{
	List<std::string> list;
	~Check(){
		//std::cout << "\nDestructor calls here " << std::endl;
	}

    std::string RemoveSpace(std::string data){
        std::stringstream ss;
        std::string temp;

        ss << data;
        data = "";

        while (!ss.eof()){
            ss >> temp;
            data = data + temp;
        }
        return data;
    }

	bool isPair(char open, char close){
	    if (open == left_parentheses && close == right_parentheses){
	        return 1;
	    }
	    else if(open == left_bracket && close == right_bracket){
	        return 1;
	    }
	    else if (open == left_curlybrace && close == right_curlybrace) {
            return 1;
        }
        return 0;
	}

	//Check balanced parentheses:
	bool isBalanced(std::string data){
		data = RemoveSpace(data);
	    Stack<char> stack;

	    for (int i = 0; i < data.length(); i++){
	    	char t;
	    	std::istringstream(data.substr(i, 1)) >> t;
	        if (t == '(' || t == '[' || t == '{'){
	            stack.Push(t);
	        }
	        else if (t == ')' || t == ']' || t == '}'){
	            if (stack.isEmpty() || !isPair(stack.Pop(), t)){
	                return 0;
	            }
	        }
	    }
	    if (stack.isEmpty()){
	    	return 1;
	    }
	    else{
	    	return 0;
	    }
	}

	//Check is numeber:
	bool IsNumberDigit(std::string str){
		if (str == "0" ||
			str == "1" ||
			str == "2" ||
			str == "3" ||
			str == "4" ||
			str == "5" ||
			str == "6" ||
			str == "7" ||
			str == "8" ||
			str == "9" ||
			str == ".")
		{
			return 1;
		}
		else{
			return 0;
		}
	}

	//CHeck is letter digit:
	bool isLetter(char c){
		if (c >= 'a' && c <= 'z'){
			return 1;
		}
		else {
			return 0;
		}
	}

	bool isWord(std::string str){
		for (int i = 0; i < str.length(); i++){
			if (isLetter(str[i])){
				return 1;
			}
			else{
				return 0;
			}
		}
	}

	//Read each token to list:
    bool ReadToken(std::string data){
		data = RemoveSpace(data);

        if (isBalanced(data)) { // If isBalanced == 1 call ReadToken:
			for (int i = 0; i < data.length(); i++) {
				std::string t;
				if (IsNumberDigit(data.substr(i, 1))) {
					int count = 0;
					int temp = i;
					while (i < data.length() && IsNumberDigit(data.substr(i, 1))){
						count++;
						i++;
					}
					t = data.substr(temp, count);
					list.addLast(t);
				}
				if (isWord(data.substr(i, 1))){
				    int count = 0;
				    int temp = i;
				    while (i < data.length() && isWord(data.substr(i, 1))){
				        count++;
				        i++;
				    }
				    t = data.substr(temp, count);
				    list.addLast(t);
				}
				t = data.substr(i, 1);
				if (t == ""){
                    continue;
				}
				list.addLast(t);
			}
		}
		else{
			std::cout << "Error Operation" << std::endl;
			return 0;
		}
    }


    void Print(){
        std::cout << list << std::endl;
    }
};


#endif //CHECK_PARENTHESES_CHECK_PARENTHESIS_H
