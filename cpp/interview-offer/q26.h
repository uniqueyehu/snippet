#ifndef Q26_H
#define Q26_H

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;

        if (pRoot1 != nullptr && pRoot2 != nullptr)
        {
            if (pRoot1->val == pRoot2->val)
                result = DoesTree1HaveTree2(pRoot1, pRoot2);
            // Root2为子树，此处用Root2和Root1的左右子结点比较
            if (!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }

    bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        // 空指针判断很重要
        if (pRoot2 == nullptr)
            return false;
        if (pRoot1 == nullptr)
            return false;
        if (!(pRoot1->val == pRoot2->val))
            return false;
        // 根结点相同时，同时比较左右子节点
        return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) &&
                DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
    }

    // 防止待比较的数值为double或者float类型的情况
//    bool Equal(double num1, double num2)
//    {
//        if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
//            return true;
//        else
//            return false;
//    }
};

#endif // Q26_H
