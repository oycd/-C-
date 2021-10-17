#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct NODE
{
    struct NODE *pnext;
    int data;


}NODE,*PNODE;

PNODE create_que(void);
void traverse_que(PNODE);
void en_que(PNODE,int);
void leave_que(PNODE);

int main(void)
{
    PNODE pHead = NULL;
    pHead=create_que();
    traverse_que(pHead);
    en_que(pHead,7);
    printf("----------------\n");
    traverse_que(pHead);
    leave_que(pHead);
    traverse_que(pHead);

    return 0;
}
PNODE create_que(void)
{
    PNODE pHead=(PNODE)malloc(sizeof(NODE));
    PNODE pTail=(PNODE)malloc(sizeof(NODE));
    if(pHead==NULL)
    {
        printf("创建链式队列失败！\n");
        exit(-1);
    }
    else
    {
        pTail = pHead;
        pTail->pnext=NULL;
        int data;
        int i;
        int len;

        printf("请输入要创建链表的长度:\n");
        scanf("%d",&len);
        for(i=1;i<=len;i++)
        {
            PNODE pNew=(PNODE)malloc(sizeof(NODE));
            if(pNew == NULL)
            {
                printf("生成链表失败！程序终止！\n");
                exit(-1);
            }
            printf("请输入第%d个位置的数\n",i);
            scanf("%d",&data);
            pNew->data=data;

            pTail->pnext=pNew;
            pNew->pnext=NULL;
            pTail=pNew;


        }
        return pHead;

    }



}
void traverse_que(PNODE pHead)
{
    PNODE p;
    p=pHead;
    if(p->pnext==NULL)
    {
        printf("该队列为空！\n");

    }
    else
    {
        while(p->pnext!=NULL)
        {
            printf("%d ",p->pnext->data);
            p=p->pnext;
        }
    }
    printf("\n");
}
void en_que(PNODE pHead,int val)
{
    PNODE pNew=(PNODE)malloc(sizeof(NODE));
    if(pNew==NULL)
    {
        printf("创建新节点失败！\n");
        exit(-1);
    }
    else
    {
        pNew->data=val;
        PNODE p;
        p=pHead;
        while(p->pnext!=NULL)
        {
         p=p->pnext;
        }
        p->pnext=pNew;
        pNew->pnext=NULL;


    }
}
void leave_que(PNODE pHead)
{
    if(pHead->pnext==NULL)
    {
        printf("队列为空，无法删除！\n");

    }
    else
    {
      int data=pHead->pnext->data;
      pHead->pnext=pHead->pnext->pnext;
      printf("数字%d已经出列！\n",data);
    }



}
