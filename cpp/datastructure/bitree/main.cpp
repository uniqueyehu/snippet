#include <iostream>
#include <stack>

using namespace std;

// 结点结构
typedef struct BiTNode {
    char data;   // 数据类型
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void visit(char data)
{
    cout << data;
}

// 先序遍历
void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void nPreOrderTraverse(BiTree T)
{
    if (T)
    {
        BiTree p = T;
        stack<BiTNode *> stk;   // 把指针放到栈中
        while (p != NULL || !stk.empty())
        {
            while (p != NULL)
            {
                visit(p->data);
                stk.push(p);
                p = p->lchild;
            }
            if (!stk.empty())
            {
                p = stk.top();
                stk.pop();
                p = p->rchild;
            }
        }
    }
}

// 中序遍历
void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        visit(T->data);
        InOrderTraverse(T->rchild);
    }
}
void nInOrderTraverse(BiTree T)
{
    if (T)
    {
        BiTree p = T;
        stack<BiTNode *> stk;
        while (p != nullptr || !stk.empty())
        {
            while (p != nullptr)
            {
                stk.push(p);
                p = p->lchild;
            }
            if (!stk.empty())
            {
                p = stk.top();
                stk.pop();
                visit(p->data);
                p = p->rchild;
            }
        }
    }
}

// 后序遍历
void PostOrderTraverse(BiTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        visit(T->data);
    }
}
void nPostOrderTraverse(BiTree T)
{
    if (T)
    {
        BiTNode *cur;
        BiTNode *pre = nullptr;
        stack<BiTNode *> stk;
        stk.push(T);
        while (!stk.empty())
        {
            cur = stk.top();
            if ((cur->lchild == nullptr && cur->rchild == nullptr)||
                    (pre != nullptr && (cur->lchild == pre || cur->rchild == pre)))
            {
                visit(cur->data);
                stk.pop();
                pre = cur;
            }
            else
            {
                if (cur->rchild != nullptr)
                    stk.push(cur->rchild);
                if (cur->lchild != nullptr)
                    stk.push(cur->lchild);
            }
        }
    }
}

void CreateTree(BiTree &T)
{// 按先序遍历的序列输入结点构建二叉树
    char ch;
    cin >> ch;
    if (ch == '#')  // #表示空结点
        T = nullptr;
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateTree(T->lchild);
        CreateTree(T->rchild);

        // 中序序列构建
//        CreateTree(T->lchild);
//        T->data = ch;
//        CreateTree(T->rchild);
        // 后序序列构建
//        CreateTree(T->lchild);
//        CreateTree(T->rchild);
//        T->data = ch;
    }
}

int main(int argc, char *argv[])
{
    BiTree T = nullptr;
    cout << "Input Tree Nodes :" << endl;
    CreateTree(T);
    cout << "Create BiTree !" << endl;

    cout << "\nPreOrderTraverse :" << endl;
    PreOrderTraverse(T);
    cout << endl;
    nPreOrderTraverse(T);

    cout << "\nInOrderTraverse :" << endl;
    InOrderTraverse(T);
    cout << endl;
    nInOrderTraverse(T);

    cout << "\nPostOrderTraverse :" << endl;
    PostOrderTraverse(T);
    cout << endl;
    nPostOrderTraverse(T);
    return 0;
}
