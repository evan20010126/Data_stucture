#include <iostream>
#include <cstdlib>
using namespace std;

struct listNode
{
    int data;
    struct listNode *link;
};

void insert(struct listNode **first, struct listNode *x, int input_num)
{
    /* insert a new node with data = 80 into the chain first after node x */
    struct listNode *temp;
    temp = (struct listNode *)malloc(sizeof(*temp));
    temp->data = input_num; // (*temp).data=80

    if (*first)
    { //Case 1: nonempty list
        if (*first == x)
        { //要插到第一個
            temp->link = x;
            *first = temp;
        }
        else
        {                         //要插到中間 (某Node的後面)
            temp->link = x->link; // (*temp).link= (*x).link
            x->link = temp;       // (*x).link=temp
        }
    }
    else
    {                      //Case 2: empty list
        temp->link = NULL; // (*temp).link= 0
        *first = temp;
    }
}

void printList(struct listNode *first, int n)
{
    int ans[n];
    for (int i = 0; first; first = first->link, i++)
    {
        ans[i] = first->data;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
        if (i != n - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
}

void append(struct listNode **first, struct listNode *x, int input_num)
{
    /* insert a new node with data = 80 into the chain first after node x */
    struct listNode *temp;
    temp = (struct listNode *)malloc(sizeof(*temp));
    temp->data = input_num; // (*temp).data=80

    if (*first)
    {                         //Case 1: nonempty list
        temp->link = x->link; // (*temp).link= (*x).link
        x->link = temp;       // (*x).link=temp
    }
    else
    {                      //Case 2: empty list
        temp->link = NULL; // (*temp).link= 0
        *first = temp;
    }
}

struct listNode *invert(struct listNode *lead)
{
    /* invert the list pointed to by lead */ struct listNode *middle;
    struct listNode *trail;
    middle = NULL;
    while (lead)
    {
        trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    return middle;
}

int main()
{
    int input_number;
    struct listNode *head;
    head = NULL;
    int i = 0;
    while (cin >> input_number)
    {
        i++;
        struct listNode *temp2;
        if (head != NULL)
        {
            for (temp2 = head; (*temp2).link != NULL; temp2 = (*temp2).link)
                ;
            append(&head, temp2, input_number);
        }
        else
        {
            append(&head, head, input_number);
        }
    }
    printList(invert(head), i); //有i筆數字
    return 0;
}
