#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//ջ�ṹ

typedef struct Node{
    int data;
    struct Node * Pnext;
}Node,* Pnode;
typedef struct Stack{
     Pnode pbottom;
     Pnode ptop;


}Stack,*Pstack;
//ջ��������
void inint(Pstack);//��ʼ��ջ
void push(Pstack,int);//��ջ
void show(Pstack);//���ջԪ��
bool out(Pstack);//��ջ
//������
int main(void)
{
    Stack stack;

    //printf("%d \n",stack.ptop);
    //printf("%d \n",stack.pbottom);
    inint(&stack);

    //printf("%d \n",stack.ptop);
    //printf("%d \n",stack.pbottom);



    /*if(stack.ptop==stack.pbottom)
    {
        printf("���������\n");
    }
    else
    {
        printf("�����ⲻ��\n");
    }*/
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    push(&stack,4);
    push(&stack,5);
    push(&stack,6);
    show(&stack);

    out(&stack);
    show(&stack);
    return 0;
}
//ջ������������ʵ��
void inint(Pstack s)
{
    s->ptop=(Pnode)malloc(sizeof(Node));

    if(s->ptop==NULL)
    {
        printf("����ջʧ�ܣ�");
        exit(-1);
    }
    else
    {
        s->pbottom=s->ptop;
        s->ptop->Pnext=NULL;


    }


}
void push(Pstack stack,int e)
{   Pnode pnew;
    pnew=(Pnode)malloc(sizeof(Node));
    pnew->data=e;
    pnew->Pnext=stack->ptop;
    stack->ptop=pnew;

}
void show(Pstack stack)
{   Pnode p;
    //p=(Pnode)malloc(sizeof(Node));
    p=stack->ptop;

    if(p==stack->pbottom)
    {
        printf("��ջΪ�գ�");

    }
    else
    {
        while(p!=stack->pbottom)
        {
            printf("%d  ",p->data);
            p=p->Pnext;
        }
    }
    printf("\n");
}
bool out(Pstack stack)
{
    Pnode r;//ΪʲôҪ��malloc����ֱ��ʹ�ã�
    r=stack->ptop;

    if(r==stack->pbottom)
    {
        printf("��ջΪ���޷�ɾ����\n");
        return false;
    }
    else
    {
        //r->Pnext=stack->ptop;�����������仰���Ļ�ptop��δ�ƶ���Ȼ������ͷ���r��˻���ִ���
        stack->ptop=r->Pnext;
        free(r);
        r=NULL;
        return true;

    }

}
