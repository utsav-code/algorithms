#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;


void enqueue(int value) {
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = value;
	ptr->next = NULL;
	if ((front == NULL) && (rear == NULL)) {
		front = rear = ptr;
	} else {
		rear->next = ptr;
		rear = ptr;
	}
	printf("UTSAV POUDEL 21BDS0384 || Node is Inserted\n\n");
}


int dequeue() {
	if (front == NULL) {
		printf("\nUTSAV POUDEL 21BDS0384 || Underflow\n");
		return -1;
	} else {
		struct node *temp = front;
		int temp_data = front->data;
		front = front->next;
		free(temp);
		return temp_data;
	}
}


void display() {
	struct node *temp;
	if ((front == NULL) && (rear == NULL)) {
		printf("\nUTSAV POUDEL 21BDS0384 || Queue is Empty\n");
	} else {
		printf("UTSAV POUDEL 21BDS0384 || The queue is \n");
		temp = front;
		while (temp) {
			printf("%d--->", temp->data);
			temp = temp->next;
		}
		printf("NULL\n\n");
	}
}

int main() {
	int choice, value;
	printf("\nUTSAV POUDEL 21BDS0384 ||Implementaion of Queue using Linked List\n");
    printf("\n UTSAV POUDEL 21BDS0384 || \t 1. Insert \n");  
    printf ( "\n UTSAV POUDEL 21BDS0384 || \t 2. Delete \n");   
    printf ( "\n UTSAV POUDEL 21BDS0384 || \t 3. Display \n");  
    printf ( "\n UTSAV POUDEL 21BDS0384 || \t 4. Exit \n"); 
    
	
	while (1) {
	    
		printf("\nUTSAV POUDEL 21BDS0384 || Enter your choice (1,2,3,4) =");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\nUTSAV POUDEL 21BDS0384 || Enter the value to insert: ");
			scanf("%d", &value);
			enqueue(value);
			break;
		case 2:
			printf("\nUTSAV POUDEL 21BDS0384 || Popped element is :%d\n", dequeue());
			break;
		case 3:
			display();
			break;
		case 4:
		    printf("\nUTSAV POUDEL 21BDS0384 || Program exitedt\n");
			exit(0);
			break;
		default:
			printf("\n UTSAV POUDEL 21BDS0384 || Invalid input\n");
		}
	}
	return 0;
}


// void deletion(Node*& root, int x)   
// {  
//     Node* parent = NULL;  
//     Node* cur = root;  
//     search(cur, x, parent); 
//         return;  
//     if (cur->left == NULL && cur->right == NULL) /*When node has no children*/  
//     {  
//         if (cur != root)  
//         {  
//             if (parent->left == cur)  
//                 parent->left = NULL;  
//             else  
//                 parent->right = NULL;  
//         }  
//         else  
//             root = NULL;  
//         free(cur);       
//     }  
//     else if (cur->left && cur->right)  
//     {  
//         Node* succ  = findMinimum(cur->right);  
//         int val = succ->data;  
//         deletion(root, succ->data);  
//         cur->data = val;  
//     }  
//     else  
//     {  
//         Node* child = (cur->left)? cur->left: cur->right;  
//         if (cur != root)  
//         {  
//             if (cur == parent->left)  
//                 parent->left = child;  
//             else  
//                 parent->right = child;  
//         }  
//         else  
//             root = child;  
//         free(cur);  
//     }  
// }