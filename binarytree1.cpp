#include <iostream>  
using namespace std; 


struct Node {  
    int data;  
    Node *left;  
    Node *right;  
};  

Node* insert(Node* T, int x) 
{  
    if (T == NULL){
        Node* node = new Node;  
        node->data = x;  
        node->left = NULL;
        node->right = NULL;  
        return node;
    }
    else if (x < T->data)  
        T->left = insert(T->left, x);  
    else  
        T->right = insert(T->right, x);  
    return T;  
}  

Node* findMinimum(Node* T)   
{  
    if(T->left == NULL) {  
        return T;  
    }  
    else{
        return findMinimum(T->left);
    } 
} 

Node* findMaximum(Node* T ){
    if(T->right ==NULL){
        return T;
    }
    else{
        return findMaximum(T->right);
    }
}

void inorder(Node *T)  
{  
    if (T != NULL) {
        inorder(T->left); 
        cout<< T->data << "\t"; 
        inorder(T->right);
    }
         
        
}  
void preOrder(Node *T){
    if(T!=NULL){
        cout<<T->data<<"\t";
        preOrder(T->left);
        preOrder(T->right);
    }
}


Node* find(Node* T, int x)  
{  

    while(T!=NULL){

        if(T->data ==x){
            return T;
        }
        else if (x > T->data){
          T=T->right;
        }
        else{
            T=T->left;
        }
    }
    
    return 0;
}  

Node * delete(Node* T , int x ){

    // if tree is empty just return 
    if(T==NULL)
        return T; 
    
    //if x<T of data then traverse left 
    else if (x<T->data)
        T->left = delete(T->left,x);

    // if x>T of data , then traverse right 
    else if(x>T->data)
        T->right =  delete (T->right , x );

    // if we reach to the leftomost part and element is not found 
    // then traverse right again 
    else if(T->left==NULL)
        T=T->right; 

    // likewise if we reach to the right most part and element is not found 
    // then traverse left part of the tree 
    else if(T->right ==NULL){
        T=T->left;
    }
    else{

        T = findMinimum(T->right);
        T->right = delete(T->right, T->data);

    }

    return T;
}


int main()  
{  
  Node* root = NULL;  
  root = insert(root, 45);  
  root = insert(root, 30);  
  root = insert(root, 50);  
  root = insert(root, 25);  
  root = insert(root, 35);  
  root = insert(root, 45);  
  root = insert(root, 60);  
  root = insert(root, 4);  
  printf("\n\nThe inorder traversal of the given binary tree is - \n"); inorder(root);  
  delete(root, 25);  
  printf("\nAfter deleting node 25, the inorder traversal of the given binary tree is - \n");  
  inorder(root);   
  insert(root, 2);  
  printf("\nAfter inserting node 2, the inorder traversal of the given binary tree is - \n");  
  inorder(root);  
  return 0;  
}  