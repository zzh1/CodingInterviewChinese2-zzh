#include <cstdlib>
#include <iostream>

#include "BinaryTree.h"
#include <exception>

using namespace std;

// ������7���ؽ�������
// ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
// ���ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,
// 2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ���
// ͼ2.6��ʾ�Ķ��������������ͷ��㡣


BinaryTreeNode* Construct(int* preorder,int* inorder,int length)
{
    if(preorder == NULL || inorder == NULL || length<=0)
        return NULL;
    
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder, int* endInorder)
{
    //ǰ��������е�һ�������Ǹ��ڵ��ֵ
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
    
    //������������ҵ����ڵ��ֵ 
           
}




int main(int argc, char *argv[])
{
    system("PAUSE");
    return EXIT_SUCCESS;
}
