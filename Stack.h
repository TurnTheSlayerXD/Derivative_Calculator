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
    void push_back(char value) {
        size++;
        Node* el = new Node;
        el->symbol = value;
        el->next = nullptr;
        if (size == 1)
        {
            end = el;
        }
        else
        {
            end->next = el;
            end->next->prev = end;
            end = el;
        }
    }
    void pop_back()
    {
        size--;
        if (size == 0)
        {
            delete end;
        }
        else
        {
            Node* buf = end;
            end = end->prev;
            delete buf;
        }
    }
    bool is_empty() {
        if (size <= 0) {
            return true;
        }
        return false;
    }
};
#endif //MAIN_CPP_STACK_H
