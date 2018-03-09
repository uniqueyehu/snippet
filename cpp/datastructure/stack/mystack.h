#ifndef MYSTACK_H
#define MYSTACK_H

#include<iostream>

using namespace std;

// 在c++的标准库中，头文件stack中有栈

/*
抽象数据类型
ADT List
{
    Data:
    Operation:
        InitStack(&S,maxsize,incresize)
        ClearStack(&S)
        StackLength(S)
        Push(&S,e)
        Pop(&S,&e)
        GetTop(S,&e)
        StackTraverse(S)
        StackEmpty(S)
        DestroyStack(&S)
}//ADT List
*/

// 顺序栈
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int ElemType;

typedef struct {
    ElemType *stack;
    int top;
    int stacksize;
    int incrementsize;
}SqStack;

void InitStack(SqStack &S, int maxsize=STACK_INIT_SIZE, int incresize=STACKINCREMENT)
{
    S.stack = (ElemType *) malloc(maxsize * sizeof(ElemType));
    if (!S.stack)
        exit(1);
    S.top = -1;
    S.stacksize = maxsize;
    S.incrementsize = incresize;
}

#endif // MYSTACK_H
