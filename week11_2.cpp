#include <iostream>
using namespace std;

int main(){
    int arr_1D[1000];
    for (int i = 0; i< 1000; i++){
        arr_1D[i] = 0;
    }
    int f1;
    cin >> f1;
    arr_1D[1] = f1;

    int input;
    int counts[100];
    for (int i = 0; i< 100; i++){
        counts[i] = 1;
    }
    int k = 0;
    while(cin >> input){
        int i = 1;
        while(arr_1D[i*2] != 0 || arr_1D[i*2+1] != 0){
            if (arr_1D[i*2+1] != 0 && arr_1D[i] < input){
                i = i*2+1;
                counts[k]++;
            }else if(arr_1D[i*2] != 0 && arr_1D[i] > input){
                i = i*2;
                counts[k]++;
            }else{
                break;
            }
        }
        if(arr_1D[i] < input){
            arr_1D[i*2+1] = input;
            counts[k]++;
        }else{
            arr_1D[i*2] = input;
            counts[k]++;
        }
        k++;
    }

    int max = 0;
    for (int i = 0; i<100; i++){
        if(counts[i]> max){
            max = counts[i];
        }
    }
    cout << max << endl;
    return 0;
}
