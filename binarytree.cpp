#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int x)
{
    if (node == NULL)
        return createNode(x);

    if (x < node->data)
        node->left = insert(node->left, x);
    else
        node->right = insert(node->right, x);

    return node;
}

struct node *find_min(struct node *T)
{
    if (T->left == NULL)
    {
        return T;
        cout << T->data << "\n";
    }
    else
        return find_min(T->left);
}

struct node *find_max(struct node *T)
{

    if (T->right == NULL)
    {
        return T;
        cout << T->data << "\n";
    }
    else
        return find_max(T->right);
}

void inorder(struct node *T)
{
    if (T != NULL)
    {
        inorder(T->left);
        cout << T->data << "\t";
        inorder(T->right);
    }
}

void preorder(struct node *T)
{
    if (T != NULL)
    {

        cout << T->data << "\t";
        preorder(T->left);
        preorder(T->right);
    }
}

void postorder(struct node *T)
{
    if (T != NULL)
    {
        postorder(T->left);
        postorder(T->right);
        cout << T->data << "\t";
    }
}

struct node *find(struct node *T, int x)
{
    if (T->data == x)
    {
        cout << "The element " << x << " is found in the tree \n";
    }
    else if (T->data > x)
    {
        if (T->right == NULL)
        {
            cout << "not found " << endl;
        }
        else
            find(T->right, x);
    }
    else
    {
        if (T->left == NULL)
        {
            cout << "not found " << endl;
        }
        else
        {
            find(T->right, x);
        }
    }
}

struct node *deleteNode(struct node *T, int x)
{
    // base case
    if (T == NULL)
        return T;

    // If the x is smaller than the T , go left
    if (x < T->data)
        T->left = deleteNode(T->left, x);

    // If the x is greater than the T , go right
    else if (x > T->data)
        T->right = deleteNode(T->right, x);

    // if same then : 3 cases
    else
    {
        // node has no child
        if (T->left == NULL and T->right == NULL)
            return NULL;

        // node with only one child or no child
        else if (T->left == NULL)
        {
            struct node *temp = T->right;
            free(T);
            return temp;
        }
        else if (T->right == NULL)
        {
            struct node *temp = T->left;
            free(T);
            return temp;
        }

        // node with two children
        // getting  inorder successor
        // (smallest in the right subtree)
        struct node *temp = find_min(T->right);

        // Copy the inorder successor's content to this node
        T->data = temp->data;

        // Delete the inorder successor
        T->right = deleteNode(T->right, temp->data);
    }
    return T;
}

/*

    This is my  BST

           7
        /     \
       5       9
      / \     / \
     2   6   8   10

*/

int main()
{
    struct node *T = NULL;
    T = insert(T, 7);
    T = insert(T, 5);
    T = insert(T, 9);
    T = insert(T, 2);
    T = insert(T, 6);
    T = insert(T, 8);
    T = insert(T, 10);

    cout << "\nInorder traversal of the given tree: \n";
    inorder(T);

    cout << "\n\nPreorder traversal of the given tree: \n ";
    preorder(T);

    cout << "\n\nPostorder traversal of the given tree:\n ";
    postorder(T);

    cout << "\n\nDeleting  2\n";
    T = deleteNode(T, 2);
    cout << "Inorder traversal after deleting 2: \n";
    inorder(T);

    cout << "\n\nDeleting  9\n";
    T = deleteNode(T, 9);
    cout << "Inorder traversal after deleting 9: \n";
    inorder(T);

    cout << "\n\nInserting 15 ";
    T = insert(T, 15);
    cout << "\nInorder traversal after inserting 15 : \n";
    inorder(T);

    cout << "\n\nSerchhing 15 : \n";
    find(T, 15);

    cout << "\nThe minimum element in the tree is : " << find_min(T)->data;
    cout << "\nThe maximum element in the tree is : " << find_max(T)->data << endl;
    cout<<endl;

    return 0;
} 
