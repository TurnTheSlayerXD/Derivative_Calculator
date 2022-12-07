//
// Created by Professional on 07.12.2022.
//
#include "Stack.h"

void Stack::push_back(char value) {
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
void Stack::pop_back() {
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
bool Stack:: is_empty() {
    if (size <= 0) {
        return true;
    }
    return false;
}