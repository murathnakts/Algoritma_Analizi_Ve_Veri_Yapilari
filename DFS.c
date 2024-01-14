#include <stdio.h>
#include <stdlib.h>

#define NODE_NUMBER 10

typedef struct stack
{
    int capacity;
    int top;
    int* items;
}stack;

stack* NewStack(int size);
int StackEmpty(stack* pt);
int StackFull(stack* pt);
void Push(int element, stack* pt);
int Pop(stack* pt);

int graf[NODE_NUMBER][NODE_NUMBER] = {};
void AddEdge(int v1,int v2);
void ShowMatris();
void DFS(int start);

int main()
{
    AddEdge(0,1);
    AddEdge(0,2);
    AddEdge(0,3);
    AddEdge(1,4);
    AddEdge(2,5);
    AddEdge(2,6);
    AddEdge(3,7);
    AddEdge(4,8);
    AddEdge(5,9);
    DFS(0);
    return 0;
}

void AddEdge(int v1,int v2)
{
    graf[v1][v2] = 1;
    graf[v2][v1] = 1;
}

void ShowMatris()
{
    int i,j;
    for(i = 0; i < NODE_NUMBER; i++)
    {
        for(j = 0; j < NODE_NUMBER; j++)
        {
            printf("%d ",graf[i][j]);
        }
        printf("\n");
    }
}

void DFS(int start)
{
    int n,i;
    int visit[NODE_NUMBER] = {};
    stack* stck = NewStack(NODE_NUMBER);
    Push(start,stck);
    visit[start] = 1;

    while(!StackEmpty(stck)) {
        n = Pop(stck);
        printf("%d ",n);
        for(i = NODE_NUMBER;i >= 0;i--){
            if(graf[n][i] == 1 && !visit[i]) {
                visit[i] = 1;
                Push(i,stck);
            }
        }
    }
}

stack* NewStack(int size)
{
	struct stack *pt = (stack*)malloc(sizeof(stack));

	pt->capacity = size;
	pt->top = -1;
	pt->items = (int*)malloc(sizeof(int) * size);

	return pt;
}

int StackEmpty(stack *pt)
{
	return (pt->top == -1);
}

int StackFull(stack *pt)
{
    return (pt->top == pt->capacity-1);
}

void Push(int element, stack* pt)
{
    if(StackFull(pt))
    {
        printf("Stack doldu! Yeni eleman eklenemez!\n");
    }
    else
    {
        pt->top++;
        pt->items[pt->top] = element;
        printf("%d elemani eklendi\n",element);
    }
}

int Pop(stack* pt)
{
    if(StackEmpty(pt))
    {
        printf("Stack bos!\n");
        exit(-1);
    }
    else
    {
        pt->top--;
        printf("%d elemani siliniyor.\n",pt->items[pt->top+1]);
        return pt->items[pt->top+1];
    }
}
