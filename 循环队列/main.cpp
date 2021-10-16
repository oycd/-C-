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
        printf("创建循环队列失败!\n");
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
        printf("循环队列已满！无法进行入队！\n");

    }
    else
    {
        Q->pbase[Q->rear]=val;
        Q->rear=(Q->rear+1)%Q->len;
        Q->nlen=Q->nlen+1;
       // printf("nlen:%d\n rear:%d\n len:%d\n front:%d\n",Q->nlen,Q->rear,Q->len,Q->front);

        printf("入队操作完成！\n");
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
        printf("队列为空！\n");

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
        printf("队列为空！无法再进行出队操作！\n");

    }
    else
    {
        printf("你出队的的数为%d\n",Q->pbase[Q->front]);
        Q->front=(Q->front+1)%Q->len;

    }


}
