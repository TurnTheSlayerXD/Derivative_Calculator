//
// Created by Professional on 27.11.2022.
//

#ifndef MAIN_CPP_FUNCTIONS_H
#define MAIN_CPP_FUNCTIONS_H
#include<iostream>
#include "Stack.h"

#include<cmath>
using namespace std;
int find_plusORminus(string& str, int l, int r);

int find_multiplyORdivide(string& str, int l, int r) ;

int find_involution(string& str, int l, int r);

bool check_brackets(string& str, int l, int r);

int find_X(string& str, int l, int r);

bool check_if_letter(char x);

string find_key_word(string& str);

string find_function(string& str, int l, int r);

bool check_if_num(char x);

bool check_if_letter(char x);

string construct_num(string& str, int l, int r);

string construct_word(string& str, int l);

string create_expr(string expr);

#endif //MAIN_CPP_FUNCTIONS_H


