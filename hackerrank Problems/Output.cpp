#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef int iType;

typedef struct node
{
    iType info;
    struct node *link, *rlink;
} node;

typedef struct List
{
    node *head, *tail;
} List;
void initialize(List *lp)
{
    lp->head = NULL;
    lp->tail = NULL;
}

node *createNode(iType x)
{
    node *p;

    p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("memory not allocated\n");
        exit(1);
    }
    p->info = x;
    p->link = NULL;
    p->rlink = NULL;
    return p;
}
List *clist(void);
void insert(List *ls, int x);
List *addition(List *ls1, List *ls2, int n3)
{

    List *add;
    add = clist();
    int x, y;
    node *p, *q;
    p = ls1->head;
    q = ls2->head;

    int i = 0;
    while (i <= n3)
    {
        x = 0;
        y = 0;
        if (p != NULL)
            x = p->info;

        if (q != NULL)
            y = q->info;
        // printf("x=%d,          y=%d",x,y);
        int z = x + y;

        insert(add, z);

        if (p != NULL)
            p = p->link;
        if (q != NULL)
            q = q->link;

        i++;
    }
    return add;
}
List *subtraction(List *ls1, List *ls2, int n3)
{

    List *sub;
    sub = clist();
    int x, y;
    node *p, *q;
    p = ls1->head;
    q = ls2->head;

    int i = 0;
    while (i <= n3)
    {
        if (p != NULL)
            x = p->info;
        else
            x = 0;
        if (q != NULL)
            y = q->info;
        else
            y = 0;
        int z = x - y;

        insert(sub, z);

        if (p != NULL)
            p = p->link;
        if (q != NULL)
            q = q->link;

        i++;
    }
    return sub;
}

void show(List *lp, int n)
{
    node *p;
    if (lp->head == NULL)
    {
        printf("NULL POINTER");
        return;
    }

    printf("polynomial::");
    p = lp->tail;

    for (int i = n; i >= 0; i--)
    {
        if (p->info < 0)
            printf(" ");
        else
            printf(" + ");
        printf("%dx^%d", p->info, i);
        p = p->rlink;
    }
    printf("\n\n");
}

List *clist(void)

{
    List *p;
    p = (List *)malloc(sizeof(List));
    if (p == NULL)
    {
        printf("memory not allocated");
        exit(1);
    }
    initialize(p);
    return p;
}

void insert(List *ls, int x)
{
    node *p;
    p = createNode(x);

    if (ls->head == NULL)

        ls->head = p;

    else
    {
        ls->tail->link = p;
        p->rlink = ls->tail;
    }

    ls->tail = p;
}

int main()
{
    List *ls1, *ls2;

    ls1 = clist();
    ls2 = clist();

    printf("Enter degree of polynomial::");

    int n1, n2;
    scanf("%d", &n1);
    int i = 0;
    while (i <= n1)
    {
        printf("enter cofficient of x^%d ", i);
        int x;
        scanf("%d", &x);
        insert(ls1, x);
        i++;
    }

    printf("\n\nenter degree of polynomial::");

    scanf("%d", &n2);
    i = 0;
    while (i <= n2)
    {
        printf("enter cofficient of x^%d ", i);
        int x;
        scanf("%d", &x);
        insert(ls2, x);
        i++;
    }

    show(ls1, n1);

    show(ls2, n2);
    List *add, *sub;

    int n3;
    n3 = n1;
    if (n1 < n2)
        n3 = n2;

    add = addition(ls1, ls2, n3);
    show(add, n3);
    sub = subtraction(ls1, ls2, n3);
    show(sub, n3);
}