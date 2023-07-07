
#include <stdio.h>
#include <stdlib.h>
int g[5][5], n, stack[5], top = -1, vis[5];
void readmatrix()
{
    int i, j;
    printf("\nEnter the number of vertices:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            printf("\nEdge from %d to %d:", i, j);
            scanf("%d", &g[i][j]);
        }
}
void initialize()
{
    int i;
    for (i = 0; i < n; i++)
        vis[i] = 0;
}
void printmatrix()
{
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
}
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
void dfs(int s)
{
    int x, i;
    push(s);
    vis[s] = 1;
    x = pop();
    if (x != -1)
        printf(" %d", x);
    while (x != -1)
    {
        for (i = 0; i <= n - 1; i++)
        {
            if ((g[x][i] == 1) && (vis[i] == 0))
            {
                push(i);
                vis[i] = 1;
            }
        }
        x = pop();
        if (x != -1)
            printf(" %d", x);
    }
}
int main()
{
    int s;
    printf("\nDFS\n UTSHV POUDEL  (21BDS0384)");
    readmatrix();
    printmatrix();
    while (1)
    {
        initialize();
        printf("\nEnter Source:");
        scanf("%d", &s);
        printf("\nDFS:");
        dfs(s);
    }
    return 0;
}
