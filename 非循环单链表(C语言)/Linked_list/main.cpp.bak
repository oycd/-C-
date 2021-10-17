#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
    int data;//单链表数据域
    struct Node * pNext;//单链表的指针域

}NODE,*PNODE;//NODE 等价于struct Node PNODE等价于struct Node *
PNODE create_list(void);//尾插法创建
void traverse_list(PNODE pHead);//遍历链表
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE,int ,int);
bool delete_list(PNODE,int,int*);
void sort_list(PNODE);

int main(void ){
    int val;
    PNODE pHead = NULL ;//等价于 struct Node * pHead = NULL;
    pHead=create_list();//创建一个非循环单链表,并将该链表的头结点的地址赋给了pHead
    traverse_list(pHead);
    printf("链表长度为：%d\n",length_list(pHead));
    sort_list(pHead);
    printf("排序后的链表：\n");
    traverse_list(pHead);
    insert_list(pHead,3,10);
    printf("插入后的链表：\n");
    traverse_list(pHead);
    delete_list(pHead,3,&val);
    printf("删除后的链表：\n");
    traverse_list(pHead);

    return 0;

}
PNODE create_list(void)
{
    PNODE pHead=(PNODE)malloc(sizeof(NODE));//分配了一个不存在有效数据的头结点

    PNODE pTail= (PNODE)malloc(sizeof(NODE));//指向最后一个元素的尾指针

    pTail = pHead;
    pTail->pNext=NULL;
    int i;
    int len;//用来存放有效节点的个数
    int data;//用来存放结点的值

    if(pHead == NULL)
    {
        printf("生成链表失败！程序终止！\n");
        exit(-1);
    }
    printf("请输入要创建的链表结点个数:");
    scanf("%d",&len);


    for(i=0;i<len;i++)
    {
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("生成链表失败！程序终止！\n");
            exit(-1);
        }
        printf("请输入第%d个结点的数值:",i+1);
        scanf("%d",&data);
        pTail->pNext=pNew;
        pNew->data=data;
        pNew->pNext=NULL;
        pTail=pNew;



        }


    return pHead;

}
void traverse_list(PNODE pHead)
{   int i=1;
    PNODE p;

    p=pHead;
    if(is_empty(pHead))
    {
        printf("链表为空！");

    }
    while(p->pNext!=NULL)
    {
        printf("第%d个结点的数据是%d\n",i,p->pNext->data);
        i++;
        p=p->pNext;
    }
    printf("\n");
}
bool is_empty(PNODE pHead)
{
    if (NULL == pHead->pNext)
    {
        printf("链表为空");
        return true;
    }
    else{
        return false;
    }

}
int length_list(PNODE pHead)
{   PNODE p = (PNODE)malloc(sizeof(NODE));
    p=pHead;
    int len=0;
    while(p->pNext!=NULL)
    {
        len++;
        p=p->pNext;

    }
    return len;

}

void sort_list(PNODE pHead)
{   int len=length_list(pHead);
    int i,j;
    PNODE p;
    PNODE q;
    int t;
    for(i=0,p=pHead->pNext;i<len-1;i++,p=p->pNext)
    {
        for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext)
        {
            if(p->data>q->data)//类似于数组中的a[i]>a[j]
            {
                t=p->data; //类似于数组中的t=a[i]
                p->data=q->data;//类似于数组中的a[i]=a[j]
                q->data=t;//类似于数组中的a[j]=t
            }
        }
    }

}
//在pHead所指向链表的第pos个结点的前面插入一个新的结点，该结点的值为val
bool insert_list(PNODE pHead ,int pos,int val)
{
   int i = 0;
   PNODE p = pHead;
   while (NULL!=p && i<pos-1)
   {
       p = p->pNext;
       ++i;
   }
   if(i>pos-1 || NULL==p)
    return false;
   PNODE pNew = (PNODE)malloc(sizeof(NODE));
   if(NULL == pNew)
   {
       printf("动态分配内存失败！\n");
       exit(-1);
   }
   pNew->data = val;
   PNODE q = p->pNext;
   p->pNext=pNew;
   pNew->pNext=q;
   return true;


}
bool delete_list(PNODE pHead,int pos,int *pval)
{
   int i = 0;
   PNODE p = pHead;
   while (NULL!=p->pNext && i<pos-1)
   {
       p = p->pNext;
       ++i;
   }
   if(i>pos-1 || NULL==p->pNext)
    {
    return false;
    }
    PNODE q;
    q=p->pNext;
    *pval=q->data;
    p->pNext=p->pNext->pNext;
    free(q);
    return true;

}
/*bool insert_list(PNODE list )
{
    int i;
    int elem;
    int pos;

    printf("请输入要插入的位置：");
    scanf("%d",&pos);
        if((list->pNext==NULL&&pos>1)||pos<=0)
    {
        printf("输入插入位置有误");
        printf("请重新输入（不能大于1或小于等于0）：");
        scanf("%d",&pos);

    }
    printf("请输入插入%d位置的数值：",pos);
    scanf("%d",&elem);
    PNODE pInsert=(PNODE)malloc(sizeof(NODE));
    PNODE p=(PNODE)malloc(sizeof(NODE));
    p=list;
    for(i=0;i<pos-1;i++)
    {   p=p->pNext;

    }
    if(p==NULL)
    {
        p=list->pNext;
        p->data=elem;
    }




*/
