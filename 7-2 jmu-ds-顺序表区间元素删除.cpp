#include <bits/stdc++.h>

using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}
SqList;
Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
    {
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
int main()
{
    SqList L,t;
    int x,y;
    int n;
    cin>>n;
    L.length=n;
    L.elem=(ElemType *)malloc(L.length*sizeof(ElemType));
    for(int i=0; i<L.length; i++)
    {
        cin>>L.elem[i];
    }
    cin>>x>>y;
    t.elem=(ElemType *)malloc(L.length*sizeof(ElemType));
    t.length=0;
    int r=0;
    for(int i=0; i<L.length; i++)
    {
        if(L.elem[i]<x||L.elem[i]>y)
        {
            t.elem[r++]=L.elem[i];
        }
    }
    t.length+=r;
    for(int i=0;i<t.length-1;i++)
        cout<<t.elem[i]<<" ";
    cout<<t.elem[t.length-1];
}
/*若一个线性表L采用顺序存储结构存储，其中所有的元素为整数。设计一个算法，删除元素值在[x,y]之间的所有元素，要求算法的时间复杂度为O(n)，空间复杂度为O(1)。

输入格式:
三行数据，第一行是顺序表的元素个数，第二行是顺序表的元素，第三行是x和y。

输出格式:
删除元素值在[x,y]之间的所有元素后的顺序表。

输入样例:
10
5 1 9 10 67 12 8 33 6 2
3 10

输出样例:
1 67 12 33 2*/ 
