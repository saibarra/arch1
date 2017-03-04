#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct treeNode {
  char name[30];
  int count;
  struct treeNode *left, *right;
};


typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;


void insertNode(TreeNodePtr *treePtr, char word[30]){
  TreeNode *temp = NULL;
  if(*treePtr == NULL){
    temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->left = NULL;
    temp->right = NULL;
    strcpy(temp->name, word);
    *treePtr = temp;
  }
  else if(strcmp(word, (*treePtr)->name) < 0)
    insertNode(&((*treePtr)->left), word);
  else if(strcmp(word, (*treePtr)->name) > 0)
    insertNode(&((*treePtr)->right), word);
}


void alphabetic(TreeNodePtr treePtr){
  if(treePtr != NULL){
    alphabetic(treePtr->left);
    printf("%s\n", treePtr->name);
    alphabetic(treePtr->right);
  }
}

/*
void deleteNode(treeNodePtr *node, char name[30])
{
  treeNode *temp;
  if(node==NULL){
    printf("Element Not Found");
  }
  else if(strcmp(word, (*treePtr)->name) > 0)
    node->left = deleteNode(node->left, name);
  }
  else if(strcmp(word, (*treePtr)->name) < 0)
    node->right = deleteNode(node->right, name);
  } else {
    if(node->right && node->left){
      temp = FindMin(node->right);
      node->name = temp->name;
      node->right = deleteNode(node->right, temp->name);
    } else {
      temp = node;
      if(node->left == NULL)
	node = node->right;
      else if(node->right == NULL)
	node = node->left;
      free(temp);
    }

  }
  return node;
}



TreeNodePtr FindMin(TreeNodePtr *node)
{
  if(node==NULL){
    return NULL;
  }

  if(node->left)
    return FindMin(node->left);
  else
    return node;
}


TreeNodePtr FindMax(TreeNodePtr *node)
{
  if(node==NULL){
    return NULL;
  }

  if(node->right)
    FindMax(node->right);
  else
    return node;
}

*/






int main(){

  char list[30];
  FILE *fpl;
  TreeNodePtr rootPtr = NULL;
  int c;
  fpl = fopen("names.txt", "r");
  do{
    c = fscanf(fpl, "%s\n", list);
    insertNode(&rootPtr, list);

  }while(c != EOF);
  fclose(fpl);

  printf("WELCOME TO ACME SOLUTIONS!\n\n");
  float f1;   //for initial input
  float f2;   //for selection input
  
  while(1){
    printf("What would you like to do?\n");
    printf("PLEASE ENTER COMMAND NUMBER\n");
    printf("1. Add employee name\n");
    printf("2. Remove employee name\n");
    printf("3. List employee names\n");
    printf("4. Quit\n\n");
    scanf("%f", &f1);

    if(f1 ==1){
      printf("Please enter name you wish to add\n\n");
      char temp[30];
      scanf("%s", temp);
      insertNode(&rootPtr, temp);
    }
    else if(f1 == 2){
      printf("Please enter name you wish to remove\n\n");
      
    }
    else if(f1 == 3){
      alphabetic(rootPtr);
      printf("\n");
    }
    else if(f1 == 4){
      break;
    } else {

      printf("Incorrect Command...\n");
      
    }

    printf("\n");
  }
  

}
