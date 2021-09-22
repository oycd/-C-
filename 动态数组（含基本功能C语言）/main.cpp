#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>//������exit����

//����һ���������ͣ��������������ֽ�struct Arr�����������ͺ���������Ա
struct Arr{
    int len;  //���鶨�峤��
    int *pbase; //������Ԫ�ص�ַ
    int cnt;   //����ʵ�����ָ���
};
//���ֹ���
void init_arr(struct Arr * pArr,int length);
bool append_arr(struct Arr * pArr,int elem);//׷��
bool insert_arr(struct Arr * pArr,int pos,int elem);//����      pos��ֵ��1��ʼ
bool deletet_arr(struct Arr * pArr,int pos);//����      pos��ֵ��1��ʼ
//int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr *pArr);
void sort_arr(struct Arr *pArr);
void show_arr(struct Arr *pArr);
void inversion_arr(struct Arr *pArr);
int main(void)
{
   struct Arr arr;


    init_arr(&arr,6);
   append_arr(&arr,1);
   append_arr(&arr,2);
   append_arr(&arr,3);
   append_arr(&arr,4);
   append_arr(&arr,5);
   //append_arr(&arr,6);
   insert_arr(&arr,1,6);

  // printf("%d",arr.len);

    show_arr(&arr);
    deletet_arr(&arr,1);
    show_arr(&arr);
    inversion_arr(&arr);
     show_arr(&arr);
     sort_arr(&arr);
     show_arr(&arr);

    return 0;
}
void init_arr(struct Arr * pArr,int length)
{
    pArr->pbase= (int*)malloc(sizeof(int)*length);
    if (NULL == pArr->pbase)
    {
        printf("��̬�ڴ����ʧ�ܣ�\n");
        exit(-1);//��ʾ��ֹ��������
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }
    return ;
}

void show_arr(struct Arr *pArr)
{
    if(is_empty(pArr))
    {
       printf("����Ϊ��\n");
    }
    else
    {
       for(int i=0;i<(pArr->cnt);i++)
       {
           printf("%d",pArr->pbase[i]);
       }
       printf("\n");
    }
}
bool is_empty(struct Arr * pArr)
{
    if(0==pArr->cnt)
        return true;
    else
        return false;
}

bool append_arr(struct Arr * pArr,int elem)
{
    if(is_full(pArr))
    {   printf("���%dʧ�ܣ�\n",elem);
        return false;
    }
    else
    {

        pArr->pbase[pArr->cnt]=elem;
        (pArr->cnt)++;
        printf("���%d�ɹ���\n",elem);

        return true;}
}

bool is_full(struct Arr *pArr)
{
    if(pArr->cnt==pArr->len)
    {
        return true;

    }
    else
    {
      return false;
    }
}
bool insert_arr(struct Arr * pArr,int pos,int elem)
{   if(is_full(pArr))
    {
        printf("���������޷����룡");
        return false;

    }
    if(pos<1 || pos>pArr->cnt+1)
    {   printf("�����ʽ����ȷ�����������Ч������");
        return false;
    }

    for(int i = pArr->cnt-1;i>=pos-1;--i)
    {
        pArr->pbase[i+1]=pArr->pbase[i];
    }
    pArr->pbase[pos-1]=elem;
    pArr->cnt=pArr->cnt+1;
    printf("��%d���뵽��%d��λ�óɹ���\n",elem,pos);
    return true;

}
bool deletet_arr(struct Arr * pArr,int pos)
{
    if(is_empty(pArr))
    {
        printf("�б�Ϊ����Ԫ��ɾ���ˣ�\n");
        return false;
    }
    if(pos<1 || pos>pArr->cnt)
    {
        printf("�����ʽ����ȷ�����������Ч������\n");
        return false;
    }

    int x=pArr->pbase[pos-1];
    for(int i=pos;i<pArr->cnt;i++)
    {
        pArr->pbase[i-1]=pArr->pbase[i];

    }
    (pArr->cnt)--;
    printf("ɾ����%d��λ����ֵΪ%d�ɹ���\n",pos,x);
    return true;
}
void inversion_arr(struct Arr *pArr)
{
    int i=0;
    int j=pArr->cnt-1;
    int t;
    while(i<j)
    {
        t=pArr->pbase[i];
        pArr->pbase[i]=pArr->pbase[j];
        pArr->pbase[j]=t;
        ++i;
        --j;
    }
    printf("����������ɣ�\n");
    return;

}
void sort_arr(struct Arr *pArr)
{   int i,j;
    for(i=0;i<pArr->cnt;i++)
        for(j=i+1;j<pArr->cnt;j++)
    {
        if(pArr->pbase[i]>pArr->pbase[j]){
            int t;

        t=pArr->pbase[i];
        pArr->pbase[i]=pArr->pbase[j];
        pArr->pbase[j]=t;}



    } printf("������ɣ�\n");
}
