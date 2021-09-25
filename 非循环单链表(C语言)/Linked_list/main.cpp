#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
    int data;//������������
    struct Node * pNext;//�������ָ����

}NODE,*PNODE;//NODE �ȼ���struct Node PNODE�ȼ���struct Node *
PNODE create_list(void);//β�巨����
void traverse_list(PNODE pHead);//��������
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE,int ,int);
bool delete_list(PNODE,int,int*);
void sort_list(PNODE);

int main(void ){
    int val;
    PNODE pHead = NULL ;//�ȼ��� struct Node * pHead = NULL;
    pHead=create_list();//����һ����ѭ��������,�����������ͷ���ĵ�ַ������pHead
    traverse_list(pHead);
    printf("������Ϊ��%d\n",length_list(pHead));
    sort_list(pHead);
    printf("����������\n");
    traverse_list(pHead);
    insert_list(pHead,3,10);
    printf("����������\n");
    traverse_list(pHead);
    delete_list(pHead,3,&val);
    printf("ɾ���������\n");
    traverse_list(pHead);

    return 0;

}
PNODE create_list(void)
{
    PNODE pHead=(PNODE)malloc(sizeof(NODE));//������һ����������Ч���ݵ�ͷ���

    PNODE pTail= (PNODE)malloc(sizeof(NODE));//ָ�����һ��Ԫ�ص�βָ��

    pTail = pHead;
    pTail->pNext=NULL;
    int i;
    int len;//���������Ч�ڵ�ĸ���
    int data;//������Ž���ֵ

    if(pHead == NULL)
    {
        printf("��������ʧ�ܣ�������ֹ��\n");
        exit(-1);
    }
    printf("������Ҫ���������������:");
    scanf("%d",&len);


    for(i=0;i<len;i++)
    {
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(pNew == NULL)
        {
            printf("��������ʧ�ܣ�������ֹ��\n");
            exit(-1);
        }
        printf("�������%d��������ֵ:",i+1);
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
        printf("����Ϊ�գ�");

    }
    while(p->pNext!=NULL)
    {
        printf("��%d������������%d\n",i,p->pNext->data);
        i++;
        p=p->pNext;
    }
    printf("\n");
}
bool is_empty(PNODE pHead)
{
    if (NULL == pHead->pNext)
    {
        printf("����Ϊ��");
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
            if(p->data>q->data)//�����������е�a[i]>a[j]
            {
                t=p->data; //�����������е�t=a[i]
                p->data=q->data;//�����������е�a[i]=a[j]
                q->data=t;//�����������е�a[j]=t
            }
        }
    }

}
//��pHead��ָ������ĵ�pos������ǰ�����һ���µĽ�㣬�ý���ֵΪval
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
       printf("��̬�����ڴ�ʧ�ܣ�\n");
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

    printf("������Ҫ�����λ�ã�");
    scanf("%d",&pos);
        if((list->pNext==NULL&&pos>1)||pos<=0)
    {
        printf("�������λ������");
        printf("���������루���ܴ���1��С�ڵ���0����");
        scanf("%d",&pos);

    }
    printf("���������%dλ�õ���ֵ��",pos);
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
