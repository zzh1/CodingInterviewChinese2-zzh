#include <cstdlib>
#include <iostream>
#include "List.h"

using namespace std;

// ������18��������ɾ���������ظ��Ľ��
// ��Ŀ����һ������������У����ɾ���ظ��Ľ�㣿���磬��ͼ3.4��a�����ظ�
// ��㱻ɾ��֮��������ͼ3.4��b����ʾ��

void DeleteDuplication(ListNode** pHead)
{
    if(pHead==NULL || *pHead == NULL)
        return ;
    
    ListNode* pPreNode = NULL;
    ListNode* pNode = *pHead;
    
    while(pNode!=NULL)
    {
        ListNode* pNext = pNode->m_pNext;
        bool needDelete = false;
        if(pNext != NULL && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;
            
        if(!needDelete)
        {
            pPreNode = pNode;
            pNode = pNode->m_pNext;
        }
        else
        {
            int value = pNode->m_nValue;
            ListNode* pToBeDel = pNode;
            while(pToBeDel != NULL && pToBeDel->m_nValue == value)
            {
                pNext = pToBeDel->m_pNext;
                
                delete pToBeDel;
                pToBeDel = NULL;
                
                pToBeDel = pNext;
            }
            
            if(pPreNode == NULL)
                *pHead = pNext;
            else
                pPreNode->m_pNext = pNext;
            
            pNode = pNext;
        }
    }
}

// ====================���Դ���====================
void Test(char* testName,ListNode** pHead,int* expectedValues,int expectedLength)
{
    if(testName != NULL)
        printf("%s begins: ",testName);
    
    DeleteDuplication(pHead);
    
    int index = 0;
    ListNode* pNode = *pHead;
    while(pNode != NULL && index<expectedLength)
    {
        if(pNode->m_nValue != expectedValues[index] )
            break;
        
        pNode = pNode->m_pNext;
        index++;
    }
    
    if(pNode == NULL && index == expectedLength)
        printf("Passed. \n");
    else
        printf("FAILED. \n");
    
}

// ĳЩ������ظ���
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 5 };
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

int main(int argc, char *argv[])
{
    Test1();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
