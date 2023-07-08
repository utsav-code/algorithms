#include <iostream>

using namespace std;
/******** Fucntions Prototype *********/

void printList();


typedef struct Node
{
    string data;
    struct Node *next;
}node;

struct Node* newNode(string userData)
{
    node *temp = new Node;
    temp->data = userData;
    temp->next = NULL;
    return temp;
}

void printList(node* head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
void reverseList(node *head)
{
    node *curr = head;
    node *prev = NULL, *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

}
int main()
{
    node *head = newNode("World");
    head->next = newNode("is");
    head->next->next = newNode("full");
    head->next->next->next = newNode("of");
    head->next->next->next->next = newNode("good");
    head->next->next->next->next->next = newNode("people");
    cout<<"Linked list before reverse is:\n";
    printList(head);
    cout<<"\n";
    reverseList(head);
    cout<<"Linked list after reverse is:\n";
    printList(head);

    return 0;
}