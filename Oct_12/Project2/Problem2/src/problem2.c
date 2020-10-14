#include <stdio.h>
#include <stdlib.h>

#include "problem2.h"

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
void inorderWalk(BinarySearchTreeNode *Tree)
{
  if (Tree->left != NULL)
    inorderWalk(Tree->left);
  printf("%d ", Tree->value);
  if (Tree->right != NULL)
    inorderWalk(Tree->right);

}
void preorderWalk(BinarySearchTreeNode *Tree)
{
  printf("%d ", Tree->value);
  if (Tree->left != NULL)
    preorderWalk(Tree->left);
  if (Tree->right != NULL)
    preorderWalk(Tree->right);

}
void postorderWalk(BinarySearchTreeNode *Tree)
{
  if (Tree->left != NULL)
    postorderWalk(Tree->left);
  if (Tree->right != NULL)
    postorderWalk(Tree->right);
  printf("%d ", Tree->value);

}

BinarySearchTreeNode *insert(BinarySearchTreeNode **Tree, int X ) {
  int flag = 1; // flag == 1, exit left flag == 2 exit right 
  if (*Tree == NULL)
  {
    *Tree = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
    if (*Tree == NULL)
    {
      pererror_function(InsertError);
      return NULL;

    }
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

