#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct bstNode {
  char name[30];
  int count;
  struct bstNode *left, *right;
};


typedef struct bstNode bsTreeNode;
typedef bsTreeNode *bstNodePointer;
bstNodePointer FindMin(bstNodePointer node);
bstNodePointer FindMax(bstNodePointer node);


void insertNode(bstNodePointer *treePointer, char word[30]){
  bsTreeNode *temp = NULL;
  if(*treePointer == NULL){
    temp = (bsTreeNode *)malloc(sizeof(bsTreeNode));
    temp->left = NULL;
    temp->right = NULL;
    strcpy(temp->name, word);
    *treePointer = temp;
  }
  else if(strcmp(word, (*treePointer)->name) < 0)
    insertNode(&((*treePointer)->left), word);
  else if(strcmp(word, (*treePointer)->name) > 0)
    insertNode(&((*treePointer)->right), word);
}


void alphabetic(bstNodePointer treePointer){
  if(treePointer != NULL){
    alphabetic(treePointer->left);
    printf("%s\n", treePointer->name);
    alphabetic(treePointer->right);
  }
}



void deleteNode(bstNodePointer treePointer, char word[30])
{
  bstNodePointer temp;
  if(treePointer==NULL){
    printf("Element Not Found");
  }
  else if(strcmp(word, (treePointer)->name) > 0){
    deleteNode(treePointer->left, word);
  }
  else if(strcmp(word, (treePointer)->name) < 0){
    deleteNode(treePointer->right, word);
  } else {
    if(treePointer->right && treePointer->left){
      temp = FindMin(treePointer->right);
      strcpy(temp->name, word);
      treePointer = temp; 
      deleteNode(treePointer->right, temp->name);
    } else {
      temp = treePointer;
      if(treePointer->left == NULL)
	treePointer = treePointer->right;
      else if(treePointer->right == NULL)
	treePointer = treePointer->left;
      }
  }
}





bstNodePointer FindMin(bstNodePointer node){
  if(node==NULL){
    return NULL;
  }

  if(node->left)
    return FindMin(node->left);
  else
    return node;
}


bstNodePointer FindMax(bstNodePointer node){
  if(node==NULL){
    return NULL;
  }

  if(node->right)
    FindMax(node->right);
  else
    return node;
}








int main(){

  char list[30];
  FILE *fpl;
  bstNodePointer rootPointer = NULL;
  int c;
  fpl = fopen("names.txt", "r");
  do{
    c = fscanf(fpl, "%s\n", list);
    insertNode(&rootPointer, list);

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
      insertNode(&rootPointer, temp);
    }
    else if(f1 == 2){
      printf("Please enter name you wish to remove\n\n");
      char temp[30];
      scanf("%s", temp);
      deleteNode(rootPointer, temp);
    }
    else if(f1 == 3){
      alphabetic(rootPointer);
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
