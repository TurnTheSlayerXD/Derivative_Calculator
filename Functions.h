//
// Created by Professional on 27.11.2022.
//

#ifndef MAIN_CPP_FUNCTIONS_H
#define MAIN_CPP_FUNCTIONS_H
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Derivative {
private :
    string expr;
    vector <string> arr;
    string result;

public:
    Derivative(string expr);

    string get_result();

    int find_plusORminus(const string &str, int l, int r);

    int find_multiplyORdivide(const string &str, int l, int r);

    int find_involution(const string &str, int l, int r);

    bool check_brackets(const string &str, int l, int r);

    int find_X(const string &str, int l, int r);

    bool check_if_letter(char x);

    string find_key_word(const string &str);

    string find_function(const string &str, int l, int r);

    bool check_if_num(char x);

    string construct_num(const string &str, int l, int r);

    string construct_word(const string &str, int l);

    string create_expr(string expr);
};
#endif //MAIN_CPP_FUNCTIONS_H


