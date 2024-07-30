// 열혈 자료구조 p.302
#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
    BTreeNode * bt1 = MakeBTreeNode();  // Create Node bt1
    BTreeNode * bt2 = MakeBTreeNode();  // Create Node bt2
    BTreeNode * bt3 = MakeBTreeNode();  // Create Node bt3
    BTreeNode * bt4 = MakeBTreeNode();  // Create Node bt4

    SetData(bt1, 1);    // Save 1 to bt1
    SetData(bt2, 2);    // Save 2 to bt2
    SetData(bt3, 3);    // Save 3 to bt3
    SetData(bt4, 4);    // Save 4 to bt4

    MakeLeftSubTree(bt1, bt2);      // Link bt2 to bt1 as left child node
    MakeRightSubTree(bt1, bt3);     // Link bt3 to bt1 as left child node
    MakeLeftSubTree(bt2, bt4);      // Link bt4 to bt2 as left child node

    // Print data of bt1's left child node
    printf("%d \n", GetData(GetLeftSubTree(bt1)));

    // Print data of left child node of bt1's left child node 
    printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

    return 0;
}