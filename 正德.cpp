#define _CRT_SECURE_NO_WARNINGS  
#include<stdio.h>
using namespace std;

typedef struct listnodeT {  
    int exp;  
    int coef;  
    listnodeT* link;  
}listnode;

void append(listnode** head, listnode* x) {  
    listnode* temp, * belap;  
    temp = NULL;  
    belap = NULL;  
    temp = *head;  
    if (*head == NULL) {  
        (*x).link = NULL;  
        *head = x;  
        return;  
    }  
    while (1) {  
        belap = temp;  
        temp = temp->link;  
        if (temp == NULL)  
            break;  
    }  
    (*x).link = NULL;  
    belap->link = x;  
}  
  
void insert(listnode** head, listnode* x, int index)  
{  
    listnode* temp, * belap;  
    temp = *head;  
    belap = *head;  
    if (*head == NULL) {  
        (*x).link = NULL;  
        *head = x;  
        return;  
    }  
    if (index == 0)  
    {  
        *head = x;  
        (*x).link = temp;  
        return;  
    }  
    while (index > 0)  
    {  
        index--;  
        belap = temp;  
        temp = temp->link;  
        if (temp == NULL)  
            break;  
    }  
    belap->link = x;  
    (*x).link = temp;  
}  
listnode* ADD(listnode* head_A, listnode* head_B) {  
    listnode* temp1, * temp2;  
    temp1 = head_A;  
    temp2 = head_B;  
    listnode* my_head = NULL;  
    while (temp1 || temp2) {  
        listnode* A_node = new listnode;  
        if (temp1 == NULL) {  
            while (temp2) {  
                A_node = temp2;  
                append(&my_head, A_node);  
                temp2 = temp2->link;  
            }  
            break;  
        }  
        if (temp2 == NULL) {  
            while (temp1) {  
                A_node = temp1;  
                append(&my_head, A_node);  
                temp1 = temp1->link;  
            }  
            break;  
        }  
        if (temp1->exp == temp2->exp) {  
            A_node->coef = temp1->coef + temp2->coef;  
            A_node->exp = temp1->exp;  
            append(&my_head, A_node);  
            temp1 = temp1->link;  
            temp2 = temp2->link;  
        }  
        else if (temp1->exp > temp2->exp) {  
            A_node->coef = temp1->coef;  
            A_node->exp = temp1->exp;  
            append(&my_head, A_node);  
            temp1 = temp1->link;  
        }  
        else if (temp1->exp < temp2->exp) {  
            A_node->coef = temp2->coef;  
            A_node->exp = temp2->exp;  
            append(&my_head, A_node);  
            temp2 = temp2->link;  
        }  
    }  
    return my_head;  
}  
listnode* multPoly(listnode*head_A,listnode *head_B) {  
    listnode* temp1, * temp2, * temp;  
    temp1 = head_A;  
    temp2 = head_B;  
    listnode* my_head = new listnode;  
    my_head = NULL;  
    int C_1 = -1;  
    while (temp1) {  
        while (temp2) {  
            C_1++;  
            listnode* M_node = new listnode;  
            M_node->coef = temp1->coef * temp2->coef;  
            M_node->exp = temp1->exp + temp2->exp;  
            temp = my_head;  
            int find = 0;  
            if (C_1 == 0)  
                append(&my_head, M_node);  
            else {  
                for (int i = 0; i < C_1; i++) {  
                    if (temp->exp < M_node->exp) {  
                        insert(&my_head, M_node, i);  
                        find = 1;  
                        break;  
                    }  
                    temp = temp->link;  
                }  
            }  
            if (!find && C_1 != 0)  
                append(&my_head, M_node);  
            temp2 = temp2->link;  
        }  
        temp2 = head_B;  
        temp1 = temp1->link;  
    }  
    //manage the same exp  
    listnode* temp3, * belap;  
    temp3 = my_head;  
    belap = temp3;  
    int same = 0;  
    while (temp3) {  
        if (same)  
            belap = belap;  
        else  
            belap = belap->link;  
        temp3 = belap->link;  
        same = 0;  
        if (temp3 == NULL)  
            break;  
        if (temp3->exp == belap->exp) {  
            belap->coef += temp3->coef;  
            belap->link = temp3->link;  
            same = 1;  
        }  
    }  
    return my_head;  
}  
int main() {  
    int c,e;  
    int C_1 = -1;
    listnode* head_A, * head_B;  
    head_A = NULL;  
    head_B = NULL;    
    while (scanf("%d", &c)) {  
        if (c == -1)  
            break;  
        scanf("%d", &e);  
        listnode* N_node = new listnode; 
        C_1++;  
        int find = 0;
        N_node->coef = c;  
        N_node->exp = e;  
        N_node->link = NULL;  
        listnode* temp;  
        temp = head_A;  
         
        if (C_1 == 0)  
            append(&head_A, N_node);  
        else {  
            for (int i = 0; i < C_1; i++) {  
                if (temp->exp < N_node->exp) {  
                    insert(&head_A, N_node, i);  
                    find = 1;  
                    break;  
                }  
                temp = temp->link;  
            }  
        }  
        if(!find&&C_1!=0)  
            append(&head_A, N_node);  
    }  
    int C_2 = -1;  
    while (scanf("%d", &c)) {  
        if (c == -1)  
            break;  
        scanf("%d", &e);  
        C_2++;  
        listnode* N_node = new listnode;  
        N_node->coef = c;  
        N_node->exp = e;  
        N_node->link = NULL;  
        listnode* temp2;  
        temp2 = head_B;  
        int find = 0;  
        if (C_2 == 0)  
            append(&head_B, N_node);  
        else {  
            for (int i = 0; i < C_2; i++) {  
                if (temp2->exp < N_node->exp) {  
                    insert(&head_B, N_node, i);  
                    find = 1;  
                    break;  
                }  
                temp2 = temp2->link;  
            }  
        }  
        if (!find && C_2 != 0)  
            append(&head_B, N_node);  
    }  
    int kkkk = 111111;
    for(int i = 0; i< kkkk; i++){
        for ( int j = 0; j<kkkk ;j++);
    }
    listnode* my_head;  
    my_head = ADD(head_A, head_B);  
    printf("add = ");  
    if (my_head->coef > 0)  
        printf("%dx^%d", my_head->coef, my_head->exp);  
    my_head = my_head->link;  
    while (my_head) {  
        if (my_head->coef == 0) {  
            my_head = my_head->link;    
        }  
        else if (my_head->exp == 1) {  
            printf(" + %dx", my_head->coef);  
            my_head = my_head->link;   
        }  
        else if (my_head->exp == 0) {  
            printf(" + %d", my_head->coef);  
            break;  
        }  
        else {  
            printf(" + %dx^%d", my_head->coef, my_head->exp);  
            my_head = my_head->link;    
        }  
    }
    for(int i = 0; i< kkkk; i++){
        for ( int j = 0; j<kkkk ;j++);
    }
    printf("\n");
    listnode* poly_head;  
    poly_head = multPoly(head_A, head_B);  
    printf("mult = ");  
    if (poly_head->coef > 0)  
        printf("%dx^%d", poly_head->coef, poly_head->exp);  
    poly_head = poly_head->link;  
    while (poly_head) {  
        if (poly_head->coef == 0) {  
            poly_head = poly_head->link;    
        }  
        else if (poly_head->exp == 1) {  
            printf(" + %dx", poly_head->coef);  
            poly_head = poly_head->link;  
        }  
        else if (poly_head->exp == 0) {  
            printf(" + %d", poly_head->coef);  
            break;  
        }  
        else {  
            printf(" + %dx^%d", poly_head->coef, poly_head->exp);  
            poly_head = poly_head->link;
        }  
    }  
    printf("\n");  
}