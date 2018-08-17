#include "list.h"
#include <stdio.h>
#include <stdlib.h>

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = NULL;
    
    return pNode;
}

void ConnectListNodes(ListNode* pCurrent,ListNode* pNext)
{
    if(pCurrent == NULL)
    {
        printf("Error to connect two nodes. \n");
        exit(1);
    }
    
    pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{
    if(pNode == NULL)
    {
        printf("The node is NULL \n");
    }
    else
    {
        printf("The key in node is %d.\n",pNode->m_nValue;
    }
}

void PrintList(ListNode* pHead)
{
    printf("PrintList starts. \n");
    
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        printf("%d\t",pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
    
    printf("\n PrintList ends. \n");
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead,int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = NULL;
    
    if(*pHead == NULL)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != NULL)
            
    }
    
    
} 

