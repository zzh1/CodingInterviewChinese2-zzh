#include <cstdlib>
#include <iostream>

#include <exception>
#include <stdexcept>

#include "BinaryTreeNode.h"

using namespace std;

// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder, int* endInorder);
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
            //throw std::exception("Invalid input."); 
		    
            //std::logic_error ex("Invalid input.");
		    //throw std::exception(ex);
		    
		    //throw "exception_test STRING";
		    throw std::runtime_error("Invalid input.");
    }
    
    
    //在中序遍历中找到根节点的值 
    int* rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;
    
    //if(rootInorder == endInorder && *rootInorder != rootValue)
      //  throw std::exception("Invalid input.");
    
    while(rootInorder == NULL || rootInorder == '\0')
        //throw std::exception("Invalid input.");
         throw std::runtime_error("Invalid input.");    
    
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    
    if(leftLength>0)
    {
        //构建左子树
        root->m_pLeft = ConstructCore(startPreorder+1,leftPreorderEnd,
            startInorder,rootInorder-1); 
    }
    if(leftLength < endPreorder - startPreorder)
    {
        //构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd+1,endPreorder,
            rootInorder+1,endInorder);    
    }
    
    return root;
}


// ====================测试代码====================
void Test(char* testName,int* preorder,int* inorder,int length)
{
    if(testName != NULL)
        printf("%s begins: \n",testName);
    
    printf("The preorder sequence is: ");
    for(int i=0;i<length;i++)
        printf("%d ",preorder[i]);
    printf("\n");
    
    printf("The inorder sequence is: ");
    for(int i=0;i<length;++i)
        printf("%d ",inorder[i]);
    printf("\n");
    
    try
    {
        BinaryTreeNode* root = Construct(preorder,inorder,length);
        PrintTree(root);
        
        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input. \n");
    }
    
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}


// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
    Test("Test6", NULL, NULL, 0);
}

// 输入的两个序列不匹配
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
}


int main(int argc, char *argv[])
{
    //Test1();
    //Test2();
    //Test3();
    //Test4();
    //Test5();
    //Test6();
    Test7();
    system("PAUSE");
    return EXIT_SUCCESS;
}
