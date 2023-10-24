#include "Ejercicio01.h"

Node<char>* Ejercicio01::remove(Node<char>* head, char value)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    while (head != nullptr && head->value == value)
    {
        Node<char>* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == nullptr)
    {
        return nullptr;
    }

    Node<char>* current = head;
    Node<char>* previous = current;

    while (current != nullptr) 
    {
        if (current->value == value) 
        {
            Node<char>* temp = current;
            previous->next = current->next;
            current = current->next;
            delete temp;
        } else
        {
            previous = current;
            current = current->next;
        }
    }

    return head;
}
