#include <iostream>
#include "DataStruct.h"
Node* queueInit()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data =0;
    head->next =NULL;
    return head;
}
void inQueue(Node* queue,int newData)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = newData;
    node->next = queue->next;
    queue->next = node;
    queue->data++;
}

bool isEmpty(Node* queue)
{
    if (queue->next == NULL || queue->data == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int deQueue(Node* queue)
{
    if (isEmpty(queue) == true)
    {
        std::cout<<"Queue is Empty\n";
        return -1;
    }
    else
    {
        Node* previous;
        Node* head = queue;
        while (queue->next != NULL)
        {
            previous = queue;
            queue = queue->next;
            if (queue->next == NULL)
            {
                previous->next = NULL;
                free(queue);
                head->data--;
            }
        }
    }  
}

int getHead(Node* queue)
{
    while (queue->next != NULL)
    {
        queue = queue->next;
        if (queue->next == NULL)
        {
            return queue->data;
        }
        
    }
    
}

void printQueue(Node* queue)
{
    if (isEmpty(queue) == true)
    {
        std::cout<<"Queue is Empty\n";
    }
    else
    {
        std::cout<<"Queue have "<<queue->data<<" Element(s)\n";
        std::cout<<"Head is "<<getHead(queue)<<"\n";
        while (queue->next != NULL)
        {
            queue = queue->next;
            std::cout<<queue->data;
            if (queue->next != NULL)
            {
                std::cout<<"->";
            }
            
        }
        std::cout<<"\n";
    }
}

int main()
{
    Node* queue = queueInit();
    inQueue(queue,1);
    inQueue(queue,2);
    inQueue(queue,3);
    printQueue(queue);
    deQueue(queue);
    deQueue(queue);
    printQueue(queue);
}
