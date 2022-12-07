#include<iostream>
#include<vector>
#include "Functions.h"
using namespace std;

vector <string>arr;
string find_key_word(string& str){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i][str.length() - 1] == ']' || arr[i][0] == '['){
            return "fuu";
        }
        else{
            return "const";
        }
    }
    return "const";
}

void foo(int argc, char* argv[]){
    string expr;
    string function;
    while(getline(cin,expr)) {
        for (int i = 0; i < expr.length(); i++) {
            if (check_if_letter(expr[i]) == true && expr[i] != 'x')
            {
                if ((function = find_function(expr, i, expr.length() - 1)) == "!") {
                    function = construct_word(expr, i);
                    ::arr.push_back(function);
                    i = i + construct_word(expr, i).length();
                } else {
                    i = i + find_function(expr, i, expr.length() - 1).length();
                }
            }
        }
        string result = create_expr(expr);
        if(result.length() > 3) {
            for (int i = 1; i <= result.length() - 2; i++) {
                if (result[i - 1] == '(' && result[i + 1] == ')' && 'x' != result[i]) {
                    result.erase(i + 1, 1);
                    result.erase(i - 1, 1);
                }
            }
        }
        cout << result << "\n";
    }
}

int main(int argc, char*argv[]) {
    foo(argc, argv);
    return 0;
}
