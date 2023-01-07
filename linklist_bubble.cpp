#include <iostream>
using namespace std;

struct item {
    int exp, coef;
};

struct listNode {
    struct item data;
    struct listNode *link;
};

typedef struct listNode *listPointer;

void printer(listPointer first) {
    for (listPointer temp0 = first; temp0 != nullptr; temp0 = temp0->link)
        cout << (temp0->data).coef << "x^" << (temp0->data).exp << " ";
    cout << endl;
}

void bubble_sort(listPointer &first) {
    /* large -> small*/
    listPointer temp0, temp1, temp2;
    int count = 0;
    for (temp0 = first; temp0 != nullptr; temp0 = temp0->link, ++count)
        ;

    for (int i = count - 1; i >= 1; --i) {
        temp1 = first;
        temp2 = first->link;
        for (int j = 0; j + 1 <= i; ++j) {
            if ((temp1->data).exp < (temp2->data).exp) {
                // swap
                temp1->link = temp2->link;
                temp2->link = temp1;

                if (temp1 == first) {
                    first = temp2;
                } else {
                    temp0->link = temp2;
                }
                temp0 = temp2;
                temp1 = temp1;
                temp2 = temp1->link;
            } else {
                temp0 = temp1;
                temp1 = temp2;
                temp2 = temp1->link;
            }
            // cout << "round"; // printer(first);
        }
    }
}

int main() {
    listNode d;
    (d.data).exp = 0;
    (d.data).coef = 0;
    listNode d1;
    (d1.data).exp = 9;
    (d1.data).coef = 1;
    listNode d2;
    (d2.data).exp = 7;
    (d2.data).coef = 2;
    listNode d3;
    (d3.data).exp = 8;
    (d3.data).coef = 3;
    listNode d4;
    (d4.data).exp = 2;
    (d4.data).coef = 4;
    listPointer first = &d;
    first->link = &d1;
    first->link->link = &d2;
    first->link->link->link = &d3;
    first->link->link->link->link = &d4;
    first->link->link->link->link->link = nullptr;

    printer(first);
    bubble_sort(first);
    printer(first);

    return 0;
}