#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Queue
{   int * pbase;
    int front;
    int rear;
    int len;
    int nlen;


}QUE,* PQUE;

void init_que(PQUE,int);
void insert(PQUE,int);
bool full_que(PQUE);
void traverse_que(PQUE);
void delete_que(PQUE);

int main(void)
{
    QUE q1;
    init_que(&q1,6);
    insert(&q1,1);
    insert(&q1,2);
    insert(&q1,3);
    insert(&q1,4);
    insert(&q1,5);
    insert(&q1,6);
    insert(&q1,7);
    delete_que(&q1);
    traverse_que(&q1);
    return 0;
}
void init_que(PQUE Q,int len)
{
    Q->pbase=(int*)malloc(len*sizeof(int));
    if(Q->pbase==NULL)
    {
        printf("����ѭ������ʧ��!\n");
        exit(-1);

    }
    else
    {
    Q->front=0;
    Q->rear=0;
    Q->len=len;
    Q->nlen=0;
    }

}
void insert(PQUE Q,int val)
{
    if(full_que(Q))
    {
        printf("ѭ�������������޷�������ӣ�\n");

    }
    else
    {
        Q->pbase[Q->rear]=val;
        Q->rear=(Q->rear+1)%Q->len;
        Q->nlen=Q->nlen+1;
       // printf("nlen:%d\n rear:%d\n len:%d\n front:%d\n",Q->nlen,Q->rear,Q->len,Q->front);

        printf("��Ӳ�����ɣ�\n");
    }



}
bool full_que(PQUE Q)
{
    if (((Q->rear+1)%(Q->len))==Q->front)
    {
        //printf("nlen:%d\n rear:%d\n len:%d\n front:%d\n",Q->nlen,Q->rear,Q->len,Q->front);
        return true;
    }
    else
    {
        return false;
    }
}
void traverse_que(PQUE Q)
{
    if(Q->nlen==0)
    {
        printf("����Ϊ�գ�\n");

    }
    else
    {   int i=Q->front;
        while(i!=Q->rear)
        {
            printf("%d ",Q->pbase[i]);
            i=(i+1)%Q->len;
        }
    }
}
void delete_que(PQUE Q)
{
    if(Q->nlen==0)
    {
        printf("����Ϊ�գ��޷��ٽ��г��Ӳ�����\n");

    }
    else
    {
        printf("����ӵĵ���Ϊ%d\n",Q->pbase[Q->front]);
        Q->front=(Q->front+1)%Q->len;

    }


}
