#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>//包含了exit（）

//定义一个数据类型，该数据类型名字叫struct Arr，该数据类型含有三个成员
struct Arr{
    int len;  //数组定义长度
    int *pbase; //数组首元素地址
    int cnt;   //数组实际数字个数
};
//各种功能
void init_arr(struct Arr * pArr,int length);
bool append_arr(struct Arr * pArr,int elem);//追加
bool insert_arr(struct Arr * pArr,int pos,int elem);//插入      pos的值从1开始
bool deletet_arr(struct Arr * pArr,int pos);//插入      pos的值从1开始
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
        printf("动态内存分配失败！\n");
        exit(-1);//表示终止整个程序
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
       printf("数组为空\n");
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
    {   printf("添加%d失败！\n",elem);
        return false;
    }
    else
    {

        pArr->pbase[pArr->cnt]=elem;
        (pArr->cnt)++;
        printf("添加%d成功！\n",elem);

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
        printf("数组已满无法插入！");
        return false;

    }
    if(pos<1 || pos>pArr->cnt+1)
    {   printf("输入格式不正确或大于数组有效个数！");
        return false;
    }

    for(int i = pArr->cnt-1;i>=pos-1;--i)
    {
        pArr->pbase[i+1]=pArr->pbase[i];
    }
    pArr->pbase[pos-1]=elem;
    pArr->cnt=pArr->cnt+1;
    printf("将%d插入到第%d个位置成功！\n",elem,pos);
    return true;

}
bool deletet_arr(struct Arr * pArr,int pos)
{
    if(is_empty(pArr))
    {
        printf("列表为空无元素删除了！\n");
        return false;
    }
    if(pos<1 || pos>pArr->cnt)
    {
        printf("输入格式不正确或大于数组有效个数！\n");
        return false;
    }

    int x=pArr->pbase[pos-1];
    for(int i=pos;i<pArr->cnt;i++)
    {
        pArr->pbase[i-1]=pArr->pbase[i];

    }
    (pArr->cnt)--;
    printf("删除第%d个位置数值为%d成功！\n",pos,x);
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
    printf("倒置数组完成！\n");
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



    } printf("排序完成！\n");
}
