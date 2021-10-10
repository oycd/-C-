#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//栈结构

typedef struct Node{
    int data;
    struct Node * Pnext;
}Node,* Pnode;
typedef struct Stack{
     Pnode pbottom;
     Pnode ptop;


}Stack,*Pstack;
//栈操作函数
void inint(Pstack);//初始化栈
void push(Pstack,int);//入栈
void show(Pstack);//输出栈元素
bool out(Pstack);//出栈
//主函数
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
        printf("函数外相等\n");
    }
    else
    {
        printf("函数外不等\n");
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
//栈操作函数具体实现
void inint(Pstack s)
{
    s->ptop=(Pnode)malloc(sizeof(Node));

    if(s->ptop==NULL)
    {
        printf("创建栈失败！");
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
        printf("该栈为空！");

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
    Pnode r;//为什么要用malloc不能直接使用？
    r=stack->ptop;

    if(r==stack->pbottom)
    {
        printf("该栈为空无法删除！\n");
        return false;
    }
    else
    {
        //r->Pnext=stack->ptop;有误，如果按这句话来的话ptop并未移动，然后后面释放了r因此会出现错误！
        stack->ptop=r->Pnext;
        free(r);
        r=NULL;
        return true;

    }

}
