#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode * pnode;

    int expLen = strlen(exp);
    int i;

    StackInit(&stack);

    for(i=0; i<expLen; i++)
    {
        pnode = MakeBTreeNode();

        if(isdigit(exp[i]))
        {
            SetData(pnode, exp[i]- '0');
        }
        else
        {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }

        SPush(&stack, pnode);
    }
}

int EvaluateExpTree(BTreeNode * bt)
{
    int op1, op2;

    if(GetLeftSubTree(bt)==NULL && GetRightSubTree(bt)==NULL)   // If bt is terminal node..
    {
        return GetData(bt);
    }

    op1 = EvaluateExpTree((GetLeftSubTree(bt)));  // 1st Operand. Left sub tree
    op2 = EvaluateExpTree((GetLeftSubTree(bt)));  // 2nd Operand. Right sub tree

    switch(GetData(bt))
    {
        case '+':
            return (op1 + op2);
        case '-':
            return (op1 - op2);
        case '*':
            return (op1 * op2);
        case '/':
            return (op1 / op2);
    }

    return 0;
}

void ShowNodeData(int data)
{
    if(0<=data && data<=9)
    {
        printf("%d ", data);
    }
    else
    {
        printf("%c ", data);
    }
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
    if(bt == NULL)
    {
        return ;
    }

    if(bt->left != NULL || bt->right != NULL)
    {
        printf(" ( ");
    }

    ShowInfixTypeExp(bt->left);      // Print 1st operand
    ShowNodeData(bt->data);         // Print operator
    ShowInfixTypeExp(bt->right);     // Print 2nd operand

    if(bt->left != NULL || bt->right != NULL)
    {
        printf(" ) ");
    }
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
    PostorderTraverse(bt, ShowNodeData);
}