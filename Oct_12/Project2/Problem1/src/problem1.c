#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> 
#include "problem1.h"


void pererror_function(int error_code){
  switch(error_code){
    case InsertError             : printf("Fail to insert node\n"); break;
    case DeleteError             : printf("Fail to delete node\n"); break;
    case SearchError             : printf("Fail to searching node\n"); break;
    case SearchMaxError          : printf("Fail to search max node\n"); break;
    case SearchMinError          : printf("Fail to search min node\n"); break;
    case SearchSuccessorError    : printf("Fail to search sucessor\n"); break;
    case searchPredecessorError  : printf("Fail to search predecessor\n"); break;
    case FailDeleteAllError      : printf("Fail to delete all node\n"); break;

    default:printf("Error\n"); break;
  }
}
BinarySearchTreeNode *insert(BinarySearchTreeNode **Tree, int X )  // Use non Recursive
{
  int flag = 1; // flag == 1,Left Tree exit; flag == 2 ，Right Tree exit 
  if (*Tree == NULL)
  {
    *Tree = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    if (*Tree == NULL)
    {
      pererror_function(InsertError);
      return NULL;
    }
    // Construct BST pointer field 
    (*Tree)->left = NULL;
    (*Tree)->right = NULL;
    (*Tree)->parent = NULL;
    (*Tree)->value = X;
  }
  else
  {
    BinarySearchTreeNode* p = *Tree;
    BinarySearchTreeNode* pre = NULL;
    while (p)  
    {
      if (p->value >= X)
      {
        pre = p;
        p = p->left;
        flag = 1;
      }
      else {
        pre = p;
        p = p->right;
        flag = 2;
      }
    }
    p = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    if (*Tree == NULL)
    {
      pererror_function(InsertError);
      return NULL;

    }
    p->left = NULL;
    p->right = NULL;
    p->value = X;
    p->parent = pre;
    if (flag == 1)
    {
      pre->left = p;

    }
    else
    {
      pre->right = p;

    }

  }

  return *Tree;

}
BinarySearchTreeNode *searchNode(BinarySearchTreeNode *Tree, int X) {
  if (Tree == NULL)
  {
    pererror_function(SearchError);
    return NULL;

  }
  else
  {
    if (X == Tree->value)
      return Tree;
    else if (X < Tree->value)
      return searchNode(Tree->left, X);
    else
      return searchNode(Tree->right, X);

  }

}

BinarySearchTreeNode *findMaxNode(BinarySearchTreeNode *Tree)  // The maximum value is the value of the rightmost node of the BinarySearchTreeNode 
{
  if (Tree == NULL)
  {
    pererror_function(SearchMaxError);
    return NULL;

  }
  else
  {
    BinarySearchTreeNode *p = Tree;
    while (p->right != NULL)
    {
      p = p->right;

    }
    return p;
  }

}


BinarySearchTreeNode *findMinNode(BinarySearchTreeNode *Tree) // The minimum value is the left most node value of the BinarySearchTreeNode 
{
  if (Tree == NULL)
  {
    pererror_function(SearchMinError);
    return NULL;

  }
  else
  {
    BinarySearchTreeNode *p = Tree;
    while (p->left != NULL)
    {
      p = p->left;

    }
    return p;

  }

}

void deleteNode(BinarySearchTreeNode* bt) 
{
  BinarySearchTreeNode *p;
  if (bt->left == NULL && bt->right == NULL) //Leaf node
  {
    p = bt;
    if (p->parent->left == p)
    {
      p->parent->left = NULL;

    }
    else
    {
      p->parent->right = NULL;

    }
    free(p);

  }
  else if (bt->right == NULL)  // Only left 
  {
    p = bt;
    bt = bt->left;
    p->parent->left = bt;
    free(p);
    p = NULL;

  }
  else if (bt->left == NULL)  // Only right 
  {
    p = bt;
    bt = bt->right;
    p->parent->right = bt;
    free(p);
    p = NULL;

  }
  else   //If the left and right subtrees are not empty, find the largest one in the left tree or the smallest one in the right BinarySearchTreeNode 
  {
    p = bt;
    bt = bt->right;
    while (bt->left != NULL) // Now we have found the minimum value BT in the right tree 
    {
      bt = bt->left;
    }
    p->value = bt->value;
    bt->parent->left = bt->right;
    free(bt);
    bt = NULL;

  }

}
bool deleteBST(BinarySearchTreeNode *Tree, int X)  // Recursive comparison node 
{
  BinarySearchTreeNode *p = Tree;
  if (Tree == NULL)
  {
    pererror_function(DeleteError);
    return false;
  }
  else
  {
    if (Tree->value == X)
    {
      deleteNode(Tree);

    }
    else if (X < Tree->value)
    {
      return deleteBST(Tree->left,X);

    }
    else
    {
      return deleteBST(Tree->right,X);

    }
    return true;

  }

}



BinarySearchTreeNode *findSuccessorNode(BinarySearchTreeNode *Tree, int X)
{
  BinarySearchTreeNode *res = searchNode(Tree, X);
  if (res == NULL)
  {
    pererror_function(SearchSuccessorError);
    return NULL;

  }
  else
  {
    if (res->left != NULL)   //  Left subtree not empty return left subtree node 
    {
      return res->left;

    }
    if (res->right != NULL) // Right subtree not empty return right subtree 
    {
      return res->right;

    }
    pererror_function(SearchSuccessorError);
    return NULL;
  }

}

BinarySearchTreeNode *findPredecessorNode(BinarySearchTreeNode *Tree, int X) {
  BinarySearchTreeNode *res = searchNode(Tree, X);
  if (res == NULL)
  {
    pererror_function(searchPredecessorError);
    return NULL;

  }
  else
  {
    return res->parent;

  }
}
void makeEmptyNode(BinarySearchTreeNode **Tree)  // Node deletion recursively 
{
  if (*Tree == NULL)
  {
    return;
  }
  makeEmptyNode(&(*Tree)->left);
  makeEmptyNode(&(*Tree)->right);
  free(*Tree);
  *Tree = NULL;
}

