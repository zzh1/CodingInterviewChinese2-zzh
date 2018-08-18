#include <cstdlib>
#include <iostream>

#include "List.h"
#include <stack>

using namespace std;

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

/*栈的方式实现*/
void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;
    
    ListNode* pNode=pHead;
    while(pNode!=NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    
    while(!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t",pNode->m_nValue);
        nodes.pop();
    }
}

/*递归方式实现*/
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if(pHead->m_pNext != NULL)
        {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        
        printf("%d\t",pHead->m_nValue);
    }
}


// ====================测试代码====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    PrintListReversingly_Recursively(pHead);
} 


// 1->2->3->4->5
void Test1()
{
    printf("\nTest1 begins.\n");
    
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    
    ConnectListNodes(pNode1,pNode2);
    ConnectListNodes(pNode2,pNode3);
    ConnectListNodes(pNode3,pNode4);
    ConnectListNodes(pNode4,pNode5);
    
    Test(pNode1);
     
    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    printf("\nTest2 begins. \n");
    
    ListNode* pNode1 = CreateListNode(1);
    
    Test(pNode1);
    DestroyList(pNode1);    
}

// 空链表
void Test3()
{
    printf("\nTest3 begins. \n");
    Test(NULL);
} 

int main(int argc, char *argv[])
{
   // Test1();
    //Test2();
    Test3();
    system("PAUSE");
    return EXIT_SUCCESS;
}
