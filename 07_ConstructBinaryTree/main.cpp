#include <cstdlib>
#include <iostream>

#include "BinaryTree.h"
#include <exception>

using namespace std;

// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。


BinaryTreeNode* Construct(int* preorder,int* inorder,int length)
{
    if(preorder == NULL || inorder == NULL || length<=0)
        return NULL;
    
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder, int* endInorder)
{
    //前序遍历序列第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
    }
    
    //在中序遍历中找到根节点的值 
           
}




int main(int argc, char *argv[])
{
    system("PAUSE");
    return EXIT_SUCCESS;
}
