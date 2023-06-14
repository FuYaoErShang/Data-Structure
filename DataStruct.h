#ifndef _DATASTRUCT_H
#define _DATASTRUCT_H

#include <stdlib.h>

typedef struct listNode
{
    struct listNode* next;
    int data;
}Node;

Node* listInit();
void headInsert(Node* list,int data);
void tailInsert(Node* list,int data);
void delate(Node* list,int num);
void printList(Node* list);

Node* stackInit();
void push(Node* stack,int newDtata);
int pop(Node* stack);
bool isEmpty(Node* stack);
int getTop(Node* stack);
void printStack(Node* stack);

Node* queueInit();
void inQueue(Node* queue,int newData);
bool isEmpty(Node* queue);
int deQueue(Node* queue);
void printQueue(Node* queue);

#endif