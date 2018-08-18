#pragma once

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

__declspec(dllexport) BinaryTreeNode* CreateBinaryTreeNode(int value);
__declspec(dllexport) void ConnectTreeNodes(BinaryTreeNode* pParent,BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
__declspec(dllexport) void PrintTreeNode(const BinaryTreeNode* pRoot);
__declspec(dllexport) void PrintTree(const BinaryTreeNode* pRoot);
__declspec(dllexport) void DestroyTree(BinaryTreeNode* pRoot);

