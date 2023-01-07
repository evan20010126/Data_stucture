#include<stdio.h>  
#include <string.h>
int varr = 0;  
typedef struct my_node {  
    char op;  
    char value;  
    struct my_node* leftChild;  
    struct my_node* rightChild;  
}node;  
node* Create_tree(char *str, int &index) {  
    node* new_node = new node;  
    if (str[index] == '(') {  
        index += 2;  
        new_node->op = str[index];  
        index += 2;  
        new_node->leftChild = Create_tree(str, index);  
        index += 2;  
        new_node->rightChild = Create_tree(str, index);  
        index += 2;  
        if (str[index] == ')') {  
            return new_node;  
        }  
    }  
    else{  
        new_node->op = ' ';  
        new_node->value = str[index];  
        return new_node;  
    }  
}  
  
int create(node* head) {  
    switch (head->op)  
    {  
    case '+':  
        return create(head->leftChild) + create(head->rightChild);  
        break;  
    case '-':  
        return create(head->leftChild) - create(head->rightChild);  
        break;  
    case '*':  
        return create(head->leftChild) * create(head->rightChild);  
        break;  
    case '/':  
        return create(head->leftChild) / create(head->rightChild);  
        break;  
    default:  
        if (head->value >= 48 && head->value <= 57) {  
            return int(head->value - 48);  
        }  
        else {  
            return varr;  
        }  
        break;  
    }  
}  
int main() {  
    char str[100];  
    char varrStr[100];  
    int index = 0;  
    gets(str);  
    gets(varrStr);  
    varr = int(varrStr[4]-48);  
    node* root;  
    root = Create_tree(str, index);  
    printf("%d\n", create(root));  
    return 0;
}