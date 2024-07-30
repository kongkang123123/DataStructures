#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[]);        // Organize expression tree
int EvaluateExpTree(BTreeNode * bt);        // Evaluate expression tree

void ShowPrefixTypeExp(BTreeNode * bt);     // Printing based prefix expression
void ShowInixTypeExp(BTreeNode * bt);       // Printing based prefix expression
void ShowPostfixTypeExp(BTreeNode * bt);    // Printing based prefix expression

#endif