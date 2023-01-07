#include <bits/stdc++.h>
using namespace std;

typedef struct Node *treePointer;
typedef struct Node
{
    int key;
    int level;
    treePointer leftChild, rightChild;
} tree;

void preOrder(treePointer ptr) /*前序走訪*/
{
    if (ptr)
    {
        cout << ptr->key << " ";

        preOrder(ptr->leftChild);
        preOrder(ptr->rightChild);
    }
}

void insert(treePointer *ptr, int item)
{
    if (*ptr == NULL)
    {
        *ptr = (treePointer)malloc(sizeof(Node));
        (*ptr)->key = item;
        (*ptr)->rightChild = NULL;
        (*ptr)->leftChild = NULL;
    }
    else if (*ptr != NULL)
    {
        if (item > (*ptr)->key)
        {
            insert(&(*ptr)->rightChild, item);
        }
        else if (item < (*ptr)->key)
        {
            insert(&(*ptr)->leftChild, item);
        }
    }
}

int main()
{
    int item;
    int AAA = 200;
    treePointer root = NULL;
    int BBB = 200;
    for (int i = 0; i < AAA; i++)
        for (int j = 0; j < BBB; j++)
            if (i > j)
                continue;
    while (scanf("%d", &item) != EOF)
    {
        insert(&root, item);
        preOrder(root);
        cout << endl;
    }

    return 0;
}
