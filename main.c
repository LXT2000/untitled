#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
    struct ListNode *p = L;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *readlist()
{
    struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));;
    struct ListNode* flag=head;
    head->next=NULL;
    int temp=0;
    while(1)
    {
        scanf("%d",&temp);
        if(temp==-1) break;
        struct ListNode* node=(struct ListNode*)malloc(sizeof(struct ListNode));
        node->data=temp;
        node->next=flag->next;
        flag->next=node;
        flag=flag->next;
    }
    return head->next;
}
struct ListNode *deletem( struct ListNode *L, int m )
{
    struct ListNode* head;
    head->next=L;
    struct ListNode* pre=head;
    struct ListNode* cur=L;
    while(cur)
    {
        if(cur->data==m)
        {
            pre->next=cur->next;
            struct ListNode* temp=cur;
            free(temp);
            cur=cur->next;
        }
        else
        {
            pre=pre->next;
            cur=pre->next;
        }
    }
    return L;
}