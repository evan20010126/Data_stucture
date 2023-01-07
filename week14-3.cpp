#include <iostream>
#include <stdio.h>
using namespace std;

void Union(int arr[], int ele_num, int a,int b){
    int leader_a = a;
    int leader_b = b;
    while(arr[leader_a] != -1){
        leader_a = arr[leader_a];
    }
    while(arr[leader_b] != -1){
        leader_b = arr[leader_b];
    }
    if(leader_a > leader_b)
        arr[leader_a] = leader_b;
    else if(leader_a < leader_b)
        arr[leader_b] = leader_a;
    cout << "Union(" << a << "," << b << "):";
    for(int leader = 0; leader < ele_num; leader++){
        if (arr[leader] == -1){
            cout << " {" << leader;
        }
        for (int i = (leader + 1); i < ele_num; i++){
            //cout << i;
            int temp = i;
            while(arr[temp] != -1){
                temp = arr[temp];
            }
            if(leader == temp){
                cout << "," << i; 
            }
        }
        if (arr[leader] == -1){
            cout << "}";
        }
    }
    cout << endl;
}

void Find(int arr[], int ele_num, int a, int b){
    int leader_a = a;
    while(arr[leader_a] != -1){
        leader_a = arr[leader_a];
    }
    int leader_b = b;
    while(arr[leader_b] != -1){
        leader_b = arr[leader_b];
    }
    if (leader_a == leader_b){
        cout << "Find(" << a << "), Find(" << b << "): Yes" << endl;
    }else
    {
        cout << "Find(" << a << "), Find(" << b << "): No" << endl;
    }
}

int main(){
    int element_num;
    scanf("%d", &element_num);
    int parent[element_num];
    for (int i = 0; i<element_num; i++)
    {
        parent[i] = -1;
    }
    
    while(true){
        char input_format;
        scanf("%c", &input_format);
        if (input_format == '-') 
            break;
        if (input_format == 'U'){
            int input_A;
            int input_B;
            scanf("nion(%d,%d)", &input_A, &input_B);
            Union(parent, element_num, input_A, input_B);
        }else if(input_format == 'F'){
            int input_A;
            int input_B;
            scanf("ind(%d), Find(%d)", &input_A, &input_B);
            Find(parent, element_num, input_A, input_B);
        }
    }
    return 0;
}
