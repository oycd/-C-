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
        printf("������ʽ����ʧ�ܣ�\n");
        exit(-1);
    }
    else
    {
        pTail = pHead;
        pTail->pnext=NULL;
        int data;
        int i;
        int len;

        printf("������Ҫ��������ĳ���:\n");
        scanf("%d",&len);
        for(i=1;i<=len;i++)
        {
            PNODE pNew=(PNODE)malloc(sizeof(NODE));
            if(pNew == NULL)
            {
                printf("��������ʧ�ܣ�������ֹ��\n");
                exit(-1);
            }
            printf("�������%d��λ�õ���\n",i);
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
        printf("�ö���Ϊ�գ�\n");

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
        printf("�����½ڵ�ʧ�ܣ�\n");
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
        printf("����Ϊ�գ��޷�ɾ����\n");

    }
    else
    {
      int data=pHead->pnext->data;
      pHead->pnext=pHead->pnext->pnext;
      printf("����%d�Ѿ����У�\n",data);
    }



}
