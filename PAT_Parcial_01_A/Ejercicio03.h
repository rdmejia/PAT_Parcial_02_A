#pragma once
class MinStack
{
private:
    struct Node {
        int value;
        int min;
        Node* next;
        Node(int val, int m, Node* n) : value(val), min(m), next(n) {}
    };
    Node* head;

public:
	MinStack();

	void push(int value);

	void pop();

	int top();

	int getMin();
};

