#include <bits/stdc++.h>
using namespace std;

typedef struct Node* treePointer;
typedef struct Node {
         int key;
         int level;
         treePointer leftChild, rightChild;
         }tree;

void preOrder (treePointer ptr)   /*前序走訪*/
{
    if (ptr) 
 {
  cout << ptr->key << " " ; 
  
        preOrder (ptr->leftChild);
        preOrder (ptr->rightChild);
    }
}


void insert(treePointer* ptr, int item )
{  
 if(*ptr == NULL)
 {
  *ptr = (treePointer)malloc(sizeof(Node));
  (*ptr)->key = item;
  (*ptr)->rightChild = NULL; 
  (*ptr)->leftChild = NULL; 
 }
 else if(*ptr != NULL )                
 {   
  if(item > (*ptr)->key)
  {
   insert(&(*ptr)->rightChild,item);  
  }
  else if(item < (*ptr)->key)
  { 
   insert(&(*ptr)->leftChild,item);
  }   
 }
}

void del(treePointer* ptr, int item){
    treePointer ptr_copy = *ptr;
    int up_num;
    if (*ptr != NULL){
        while((*ptr)->key != item && (*ptr)->key != NULL){
            for(; item > (*ptr)->key; *ptr = (*ptr)->rightChild);
            for(; item < (*ptr)->key; *ptr = (*ptr)->leftChild);
        } //找到要刪的數
        if ((*ptr)->key == NULL){
            cout << "no" << item << endl;
            return;
        }
        //
        *ptr = (*ptr)->leftChild;
        while((*ptr)->rightChild != NULL){
            *ptr = (*ptr)->rightChild;
        }
        if((*ptr)->leftChild == NULL && (*ptr)->rightChild == NULL){
            (*ptr)->key == NULL;
        }else{    
            up_num = (*ptr)->key; //找到要填上去的num
            (*ptr)->key = (*ptr)->leftChild->key; //把放上去的數的左邊的放過去 上面一層
            (*ptr)->leftChild->key = NULL; //左邊變成null 
        }
        ////////////以下要找回原本要刪除的位子 並把剛剛up_num放到剛剛位子
        *ptr = ptr_copy; //一開始有copy一份位子放回去ptr
        while((*ptr)->key != item && (*ptr)->key != NULL){
            for(; item > (*ptr)->key; *ptr = (*ptr)->rightChild);
            for(; item < (*ptr)->key; *ptr = (*ptr)->leftChild);
        } //找到要刪的數
        (*ptr)->key = up_num; //up_num放回要刪除的位子
    }
}

int main()
{
 int item;
 cout<< "Binary search tree (before):" << endl;
 treePointer root = NULL;
 while(scanf("%d",&item) != EOF)
 { 
  insert(&root,item);
 }
 preOrder(root);
 cout << endl << "Binary search tree (after):";
 while(scanf("%d",&item) != EOF)
 { 
  del(&root,item);
 }
 preOrder(root);
 cout << endl;
 return 0;
}


