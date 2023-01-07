#include <bits/stdc++.h>
using namespace std;

typedef struct Node *treePointer;
typedef struct Node
{
    int key;
    int level;
    treePointer left, right; //leftChild, rightChild
} tree;

void insert(treePointer *ptr, int item);
void preOrder(treePointer ptr); /*前序走訪*/

int main()
{
    int item;

    treePointer root = NULL;

    while (scanf("%d", &item) != EOF)
    {
        insert(&root, item);
        cout << endl;
    }
    preOrder(root);
    return 0;
}

void insert(treePointer *ptr, int item)
{
    if (*ptr == NULL)
    {
        *ptr = (treePointer)malloc(sizeof(Node));

        (*ptr)->key = item;
        (*ptr)->left = NULL;
        (*ptr)->right = NULL;
    }

    else if (*ptr != NULL)
    {
        if (item > (*ptr)->key)
        {
            insert(&(*ptr)->right, item);
        }
        else if (item < (*ptr)->key)
        {
            insert(&(*ptr)->left, item);
        }
    }
}

void preOrder(treePointer ptr) /*前序走訪*/
{
    if (ptr)
    {
        cout << ptr->key << " ";
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}