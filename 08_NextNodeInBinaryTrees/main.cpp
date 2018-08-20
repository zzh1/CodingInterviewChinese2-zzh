#include <cstdlib>
#include <iostream>
#include "BinaryTreeNode.h"

using namespace std;

// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent,BinaryTreeNode* pLeft,BinaryTreeNode* pRight);
void DestroyTree(BinaryTreeNode* pRoot);
void PrintTreeNode(BinaryTreeNode* pNode);
void PrintTree(BinaryTreeNode* pRoot);

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode==NULL)
        return NULL;
        
    BinaryTreeNode* pNext = NULL;
    
    if(pNode->m_pRight != NULL)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != NULL)
            pRight = pRight->m_pLeft;
        
        pNext = pRight;
    }
    else if(pNode->m_pParent != NULL)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        
        while(pParent!=NULL && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        
        pNext = pParent;
    }
    
    return pNext;
}


// ====================测试代码====================
void Test(char* testName,BinaryTreeNode* pNode,BinaryTreeNode* expected)
{
    if(testName!=NULL)
        printf("%s begins: ",testName);
    
    BinaryTreeNode* pNext = GetNext(pNode);
    //PrintTreeNode(pNext);
    //std::cout<<pNext->m_nValue<<endl;
    if(pNext == expected)
        printf("Passed. \n");
    else
        printf("FAILED. \n");
    
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
    
    ConnectTreeNodes(pNode8,pNode6,pNode10);
    ConnectTreeNodes(pNode6,pNode5,pNode7);
    ConnectTreeNodes(pNode10,pNode9,pNode11);
    
    Test("Test1",pNode8,pNode9);
    Test("Test2",pNode6,pNode7);
    Test("Test3",pNode10,pNode11);
    Test("Test4",pNode5,pNode6);
    Test("Test5",pNode7,pNode8);
    Test("Test6",pNode9,pNode10);
    Test("Test7",pNode11,NULL);
    
    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test8_11()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);
    
    //PrintTree(pNode5);
    
    Test("Test8", pNode5, NULL);
    Test("Test9", pNode4, pNode5);
    Test("Test10", pNode3, pNode4);  
    Test("Test11", pNode2, pNode3);

    DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode5);

    Test("Test12", pNode5, NULL);
    Test("Test13", pNode4, pNode5);
    Test("Test14", pNode3, pNode4);
    Test("Test15", pNode2, pNode3);

    DestroyTree(pNode2);
}

void Test16()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
 
    Test("Test16", pNode5, NULL);

    DestroyTree(pNode5);
}


int main(int argc, char *argv[])
{
    //Test1_7();
    //Test8_11();
    //Test12_15();
    Test16();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
