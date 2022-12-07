//
// Created by Professional on 27.11.2022.
//

#ifndef MAIN_CPP_STACK_H
#define MAIN_CPP_STACK_H
#include<iostream>
using namespace std;
struct Node {
    string value;
    char symbol;
    Node* next;
    Node* prev;
};
class Stack {
public:
    Node* end;
    int size = 0;
    void push_back(char value);
    void pop_back();
    bool is_empty();

};
#endif //MAIN_CPP_STACK_H
