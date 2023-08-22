#include <stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *void insert(node *T, int x)
{

    if (T == NULL)
    {
        T = (struct node *)malloc(sizeof(struct node * T));
        // node *T = new node();
        t->data = x;
        t->left = NULL;
        t->right = NULL:
    }

    else if (x < T.data)
    {
        T->left = insert(T->left, x);
    }
    else
        T->right = insert(T->right, x); // resurcive call for the function insert
}

struct node *findmin(struct node *T)
{
    if (T->left == NULL)
    {
        return T;
    }
    else
        return findmin(T->left);
}

struct node *findmax(struct node *T)
{
    if (T->right == NULL)
    {
        return T;
    }
    else
        return findmax(T->right);
}
void swap(int *a, int *b)
{

    int temp = *a;

    *a = *b;

    *b = temp;

    // a ra b swap
}


// display
void inorder(struct node *T)
{

    if (T != NULL)
    {
        inorder(T->left);
        printf("%d", T->data);
        inorder(T->right);
    }
}

void preOrder(struct node *T)
{
    if (T != NULL)
    {
        printf("%d", T->data);
        preOrder(T->left);
        preOrder(T->right);
    }
}

void postOrder(struct node *T)
{
    if (T != NULL)
    {
        postOrder(T->left);
        postOrder(T->right);
        printf("%d", T->data);
    }
}

struct node *find(struct node *T, int x)
{

    struct node *temp;

    // temp T;
    //  bool status = false;

    while (temp != NULL)
    {
        if (temp->data == x)
        {

            return temp;
        }
        else if (x > temp->data)
        {
            temp = temp->right;
        }
        else
            temp = temp->left;
    }
}

struct node *delete (struct node *T, int x)
{
    struct node *temp;

    if (T == NULL)
        return T;

    else if (x < T->data)
        T->left = delete (T->left, x);

    else if (x > T->data)
        T->right = delete (T->right, x);

    else if (T->left == NULL)
        T = T->right;

    else if (T->right == NULL)
        T = T->left;

    else
    {
        temp = findmin(T->right);
        T->data = temp->data;
        T->right = delete (T->right, T->data);
    }

    return T;
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 45);

    return 0;
}



