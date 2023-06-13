#include <iostream>
#include <stdlib.h>
typedef struct listNode
{
    struct listNode* next;
    int data;
}Node;
Node* listInit()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}
void headInsert(Node* list,int newData)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = newData;
    node->next = list->next;
    list->next = node;
    list->data++;
}
void tailInsert(Node* list,int newData)
{
    Node* node = (Node*)malloc(sizeof(Node));
    Node* head = list;
    node->data = newData;
    while (list->next != NULL)
    {
        list = list->next;
        if (list->next == NULL)
        {
            list->next = node;
            node->next = NULL;
        }
    }
    head->data++;
}
void delate(Node* list,int num)
{
    Node* head = list;
    Node* previous;
    while (list->next != NULL)
    {
        previous = list;
        list = list->next;
        if(list->data == num)
        {
            previous->next = list->next;
            free(list);
            head->data--;
            list = head; 
        }
    }
}
void printList(Node* list)
{
    while (list->next != NULL)
    {
        list = list->next;
        std::cout << list->data;
        if (list->next != NULL)
        {
            std::cout<<"->";
        }
    }
    std::cout<<"\n";
}
int main()
{
    Node* list = listInit();
    headInsert(list,1);
    headInsert(list,2);
    headInsert(list,3);
    tailInsert(list,2);
    tailInsert(list,3);
    tailInsert(list,4);
    std::cout<<"Link List has " <<list->data<<" Element(s) :\n";
    printList(list);
    //delate(list,4);
    delate(list,2);
    std::cout<<"After Delate has :"<<list->data<<" Element(s) :\n";
    printList(list);
    return 0;
}