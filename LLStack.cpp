#include "LLStack.h"

// Node constructor
Node::Node(string s)
{
    data = s;
    next = nullptr;
}

// Stack constructor
LLStack::LLStack()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// Return the top element (newest item)
string LLStack::top()
{
    if (head == nullptr)
        return "";

    return head->data;
}

// Return number of elements
int LLStack::size()
{
    return count;
}

// Push a new element to the stack
void LLStack::push(string s)
{
    Node* newNode = new Node(s);

    // Case 1: stack empty
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    count++;
}

// Remove the top element
void LLStack::pop()
{
    if (head == nullptr)
        return;

    // Case: only one element
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    count--;
}

// Remove all nodes that match target
int LLStack::removeAll(const string& target)
{
    Node* curr = head;
    Node* prev = nullptr;
    int removed = 0;

    while (curr != nullptr)
    {
        if (curr->data == target)
        {
            Node* temp = curr;

            // Removing head
            if (prev == nullptr)
            {
                head = curr->next;
                curr = head;
            }
            else
            {
                prev->next = curr->next;
                curr = curr->next;
            }

            delete temp;
            removed++;
            count--;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    // Fix tail if list becomes empty
    if (head == nullptr)
        tail = nullptr;
    else
    {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        tail = temp;
    }

    return removed;
}