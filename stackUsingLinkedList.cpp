#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};
Node* top = NULL;


void push(int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value; 
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; 
    }
    top = newNode; 
    printf("UTSAV POUDEL 21BDS0384 || Node is Inserted\n\n");
}

int pop() {
    if (top == NULL) {
        printf("\nUTSAV POUDEL 21BDS0384 || Stack Underflow\n");
    } else {
        struct Node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;

    }
    return 0;
}

void display() {
    
    if (top == NULL) {
        printf("\nUTSAV POUDEL 21BDS0384 || Stack Underflow\n");
    } else {
        printf("UTSAV POUDEL 21BDS0384 ||The stack is \n");
        struct Node *temp = top;
        while (temp->next != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n\n", temp->data);
    }
}

int main() {
    int choice, value;
    printf("\nUTSAV POUDEL 21BDS0384 ||Implementaion of Stack using Linked List\n");
    printf("\n UTSAV POUDEL 21BDS0384 || \t 1. Insert \n");  
    printf ( "\n UTSAV POUDEL 21BDS0384 || \t 2. Delete \n");   
    printf ( "\n UTSAV POUDEL 21BDS0384 || \t 3. Display \n");  
    printf ( "\n UTSAV POUDEL 21BDS0384 || \t 4. Exit \n"); 
    
    while (1) {  
    
        printf("\nUTSAV POUDEL 21BDS0384 || enter your choice (1,2,3,4) =");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nUTSAV POUDEL 21BDS0384 || Enter the value to insert: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            printf("UTSAV POUDEL 21BDS0384 || Popped element is :%d\n", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            printf("UTSAV POUDEL 21BDS0384 || Program exitedt");
            exit(0);
            break;
        default:
            printf("\n UTSAV POUDEL 21BDS0384 || Invalid input\n");
        }
    }
    return 0;
}
