#include <iostream>
#include <cstdlib>
using namespace std;

struct listNode
{
    int data;
    struct listNode *link;
};

void append(struct listNode **first, struct listNode *x, int input_num)
{
    /* insert a new node with data = 80 into the chain first after node x */
    struct listNode *temp;
    temp = (struct listNode *)malloc(sizeof(*temp));
    temp->data = input_num; // (*temp).data=80
    
    if(*first) {            //Case 1: nonempty list
        temp->link = x->link; // (*temp).link= (*x).link
        x->link = temp;      // (*x).link=temp
    }
    else {                   //Case 2: empty list
        temp->link = NULL;    // (*temp).link= 0
        *first = temp;
    }
}

void printList(struct listNode* first)
{
    for ( ; first ; first = first->link )
       cout << first->data << ",";
    cout << endl;
}
void insert(struct listNode **first, struct listNode *x, int input_num)
{
    /* insert a new node with data = 80 into the chain first after node x */
    struct listNode *temp;
    temp = (struct listNode *)malloc(sizeof(*temp));
    temp->data = input_num; // (*temp).data=80
    
    if(*first) {            //Case 1: nonempty list
        if(*first ==  x){
            temp->link = x;
            *first = temp;
        }else{
            temp->link = x->link; // (*temp).link= (*x).link
            x->link = temp;      // (*x).link=temp
        }
    }
    else {                   //Case 2: empty list
        temp->link = NULL;    // (*temp).link= 0
        *first = temp;
    }
}


int main(){
    int input_num;
    cin >> input_num;
    /*此兩個陣列互相對應*/
    string items[1000];
    struct listNode* head[1000];
    for (int i =0; i<1000; i++){
        items[i] = "";
        head[i] = NULL;
    }
    /**/
    string item;
    int price;
    int k = 0; 
    for(int i = 0; i<input_num; i++){
        cin >> item >> price;
        for (int i = 0; i<1000; i++){
            if(items[i] == item){
                if (head[i] != NULL){
                    struct listNode* temp2;
                    // for (temp2 = head[i]; (*temp2).link != NULL; temp2 = (*temp2).link){
                    //     if ((*temp2).data > price){
                    //         break;
                    //     }
                    // }
                    for (temp2 = head[i]; (*temp2).link != NULL; temp2 = (*temp2).link) {
                        if (temp2->link->data > price)
                            break;
                    }
                    // if (temp2 == head[i]){
                    //     if (temp2->link == NULL){
                    //         insert(&(head[i]), temp2, price);
                    //     }else{
                    //         append(&(head[i]), temp2, price);
                    //     }
                    // }else{
                    //     insert(&(head[i]), temp2, price);
                    // }
                    if (temp2 == head[i] && temp2->data < price)
                        append(&head[i], temp2, price);
                    else
                        insert(&(head[i]), temp2, price);
                      
                }else{
                    insert(&(head[i]), head[i], price);
                }
                break;
            }else if(items[i] != item && i == 1000-1){ //沒有找到一樣的
                items[k] = item;
                struct listNode* temp2;
                if (head[k] != NULL){
                    // for (temp2 = head[i]; (*temp2).link != NULL; temp2 = (*temp2).link){
                    //     if ((*temp2).data > price){
                    //         break;
                    //     }
                    // }
                    for (temp2 = head[i]; (*temp2).link != NULL; temp2 = (*temp2).link) {
                        if (temp2->link->data > price)
                            break;
                    }
                    // if (temp2 == head[i]){
                    //     if (temp2->link == NULL){
                    //         insert(&(head[i]), temp2, price);
                    //     }else{
                    //         append(&(head[i]), temp2, price);
                    //     }
                    // }else{
                    //     insert(&(head[i]), temp2, price);
                    // }
                    if (temp2 == head[i] && temp2->data < price)
                        append(&head[i], temp2, price);
                    else
                        insert(&(head[i]), temp2, price);
                }else{
                    insert(&head[k], head[k], price);
                }
                k++;
            }
        }
    }
    
    for(int i = 0; i<k; i++){
        cout << items[i] << ",";
        printList(head[i]);
    }
    return 0;
}
