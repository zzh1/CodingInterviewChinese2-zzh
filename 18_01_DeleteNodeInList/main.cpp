#include <cstdlib>
#include <iostream>
#include "List.h"
using namespace std;

// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。

void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;
    
    //要删除的节点不是尾节点
    if(pToBeDeleted->m_pNext != NULL)
    {
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;
        
        delete pNext;
        pNext = NULL;
    }
    //链表只有一个节点，删除头结点 
    else if(*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
        *pListHead = NULL; 
    } 
    //链表有多个节点，删除尾节点 
    else
    {
        ListNode* pNode = *pListHead;
        while(pNode->m_pNext != pToBeDeleted)
        {
            pNode = pNode->m_pNext;
        } 
        pNode->m_pNext = NULL;
        
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);
    
    printf("The node to be deleted is: \n");
    PrintListNode(pNode);
    
    DeleteNode(&pListHead,pNode);
    
    printf("The result list is: \n");
    PrintList(pListHead);
}


// 链表中有多个结点，删除中间的结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

//链表中多个节点，删除头结点
void Test3()
{
    ListNode* pNode1=CreateListNode(1);
    ListNode* pNode2=CreateListNode(2);
    ListNode* pNode3=CreateListNode(3);
    ListNode* pNode4=CreateListNode(4);
    ListNode* pNode5=CreateListNode(5);
    
    ConnectListNodes(pNode1,pNode2);
    ConnectListNodes(pNode2,pNode3);
    ConnectListNodes(pNode3,pNode4);
    ConnectListNodes(pNode4,pNode5);
    
    Test(pNode1,pNode1);
    
    DestroyList(pNode1);
} 

//链表中只有一个节点，删除头结点 
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    Test(pNode1,pNode1);
}

//链表为空
void Test5()
{
    Test(NULL, NULL);
} 

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4(); 
    Test5(); 
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
