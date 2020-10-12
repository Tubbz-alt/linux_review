#include <stdio.h>
#include <stdlib.h>

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

BinarySearchTreeNode *insert(BinarySearchTreeNode *Tree, int X){
 //Write your own code below
}

BinarySearchTreeNode *searchNode(BinarySearchTreeNode *Tree, int X){
 //Write your own code below
}

BinarySearchTreeNode *findMaxNode(BinarySearchTreeNode *Tree){
 //Write your own code below  
}


BinarySearchTreeNode *findMinNode(BinarySearchTreeNode *Tree){
 //Write your own code below
}

BinarySearchTreeNode *deleteNode(BinarySearchTreeNode *Tree, int X){
 //Write your own code below
}

BinarySearchTreeNode *findSuccessorNode(BinarySearchTreeNode *Tree, int X){
 //Write your own code below
}


BinarySearchTreeNode *findPredecessorNode(BinarySearchTreeNode *Tree, int X){
 //Write your own code below
}

void makeEmptyNode(BinarySearchTreeNode *Tree){
//Write your own code below
}


