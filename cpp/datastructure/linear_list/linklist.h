#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>
#include<malloc.h>

using namespace std;

/*
抽象数据类型
ADT List
{
    Data:
    Operation:
        InitList(&L)
        CreateList(&L)
        ListEmpty(L)
        ListLength(L)
        LocateElem(L,e)
        PriorElem(L,cur_e,&pre_e)
        NextElem(L,cur_e,&pre_e)
        ListInsert(&L,i,e)
        ListDelete(&L,i,&e)
        GetElem(L,i,&e)
        ListTraverse(L)
        DestroyList(&L)
    }//ADT List
*/

typedef int ElemType;

// 单链表
typedef struct Node {
    ElemType data;      // 数据域
    struct Node *next;  // 指针域
}LNode, *LinkList;

// 链表初始化
void InitList_L(LinkList &L)
{
    L = (LNode *) malloc(sizeof(LNode));    // 申请表头结点
    if (!L)
        exit(1);    // 申请失败
    L->next = nullptr;
}

// 求单链表的长度
int ListLength_L(LinkList L)
{
    LinkList p;
    int k = 0;
    p = L->next;
    while (p)
    {
        ++k;
        p = p->next;
    }
    return k;
}

// 在第i个结点之前插入元素e
bool ListInsert_L(LinkList &L, int i, ElemType e)
{
    LinkList p, s;
    int j;
    p = L;
    j = 0;
    // 寻找第i-1个结点
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    }

    if (!p || j > i - 1)
        return false;

    s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除第i个结点，并让e返回其值
bool ListDelete_L(LinkList &L, int i, ElemType &e)
{
    LinkList p, q;
    int j;
    p = L;
    j = 0;
    // 寻找第i-1个结点
    while (p->next && j < i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
        return false;

    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return true;
}

// 创建单链表-尾插
void CreateList_L_Rear(LinkList &L, ElemType a[], int n)
{
    LinkList p, q;
    int i;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = nullptr;

    q = L;  // q始终指向尾结点
    for (i = 0; i < n; ++i)
    {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = a[i];
        q->next = p;
        q = p;
    }
    q->next = nullptr;
}

// 创建单链表-头插
void CreateList_L_Front(LinkList &L, ElemType a[], int n)
{
    LinkList p;
    int i;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = nullptr;

    for (i = n - 1; i >= 0; --i)
    {
        p = (LinkList) malloc(sizeof(LNode));
        p->data = a[i];
        p->next = L->next;
        L->next = p;
    }
}

// 遍历输出单链表各元素数据
void ListTraverse_L(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

#endif // LINKLIST_H
