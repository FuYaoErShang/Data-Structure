#include <iostream>
#include "DataStruct.h"

Node* stackInit()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

bool isEmpty(Node* stack)
{
    if(stack->data == 0 || stack->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(Node* stack,int newData)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = newData;
    node->next = stack->next;
    stack->next = node;
    stack->data ++;
}
int getTop(Node* stack)
{
    if (isEmpty(stack) == true)
    {
        std::cout << "Stack is Empty";
        return -1;
    }
    else
    {
        return stack->next->data;
    }
}
int pop(Node* stack)
{
    if (isEmpty(stack) == true)
    {
        std::cout << "Stack is Empty";
        return -1;
    }
    else
    {
        Node* head = stack;
        Node* top = stack->next;
        head->next = top->next;
        free(top);
        head->data--;
    }
    
}

void printStack(Node* stack)
{
    std::cout<<"Stack have "<<stack->data<<" element(s)\n";
    while (stack->next != NULL)
    {
        stack = stack->next;
        std::cout<<stack->data;
        if (stack->next != NULL)
        {
            std::cout<<"->";
        }
        
    }
    std::cout<<"\n";
    
}

int main()
{
    Node* stack = stackInit();
    push(stack,1);
    push(stack,2);
    push(stack,3);
    printStack(stack);
    std::cout<<"Top is "<<getTop(stack)<<"\n";
    pop(stack);
    pop(stack);
    pop(stack);
    printStack(stack);
    return 0;
}