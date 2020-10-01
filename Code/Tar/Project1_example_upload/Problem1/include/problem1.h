#include<stdbool.h>
#include<stdlib.h>
//Parameter
#define MAX_SIZE 100

//Function prototype

bool insert(int **L, int X, int* length);
bool _delete(int **L, int X, int *length);// Because delete is unqualfied ID
bool   find(int *L, int X, int length);
int  findkth(int *L, int X, int length);
void printlist(int *L, int length);
bool isEmpty(int *L);
bool makeEmpty(int **L);

