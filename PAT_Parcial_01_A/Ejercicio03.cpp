#include "Ejercicio03.h"
#include <algorithm>

MinStack::MinStack(): head(nullptr) 
{
}

void MinStack::push(int value)
{
    if (head == nullptr) {
        head = new Node(value, value, nullptr);
    }
    else {
        head = new Node(value, std::min(value, head->min), head);
    }
}

void MinStack::pop()
{
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int MinStack::top()
{
    if (head != nullptr) {
        return head->value;
    }
	return 0;
}

int MinStack::getMin()
{
    if (head != nullptr) {
        return head->min;
    }
	return 0;
}
