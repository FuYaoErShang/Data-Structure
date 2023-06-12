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
    node->next = list;
    list = node;
    list->data++;
}
void tailInsert(Node* list,int newData)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = newData;
    if (list->next == NULL)
    {
        list->next = node;
        node->next = NULL;
    }
    list->data++;
    
}
void delate(Node* list,int num)
{
    Node* head = list;
    Node* current;
    list = list->next;           //此处的list是链表的首地址，并不代表整一个链表
    while (list->next != NULL)
    {
        if(list->data == num)
        {
            current = list->next;
            list->next = current->next;
            free(current);
            break;
        }
    }
    head->data--;
}
void printList(Node* list)
{
    list = list->next;
    while (list->next != NULL)
    {
        std::cout << list->data << "->";
        list = list->next;
    }
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
    delate(list,4);
    std::cout<<"After Delate is :"<<list->data<<" Element(s) :\n";;
    printList(list);
    std::cout<<"\n";
    return 0;
}