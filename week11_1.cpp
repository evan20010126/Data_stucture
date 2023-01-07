#include <iostream>
using namespace std;

int index(int arr[], int n){
    int i = 1;
    while(true){
        if (n == arr[i]){
            return i;
        }
        i++;
    }
}

int main(){
    int arr_1D[1000];
    for (int i = 0; i <1000; i++){
        arr_1D[i] = 0;
    }
	int number;
    cin >> number;
    int f1,f2,f3;
    cin >> f1 >> f2 >> f3;
    arr_1D[1] = f1;
    arr_1D[2] = f2;
    arr_1D[3] = f3;

    int input_1;
    while(cin >> input_1){
        if (input_1 == -1){
            break;
        }
        int position = index(arr_1D, input_1);
        int input_2,input_3;
        cin >> input_2 >> input_3;
        arr_1D[position*2] = input_2;
        arr_1D[position*2+1] = input_3;
    }

    int j = 1;
    int k = 0;
    cout << arr_1D[j];
    ++k;
    ++j;
    while(k != number){
        cout << " " << arr_1D[j];
        if (arr_1D[j] != 0){
            k++;
        }
        j++;
    }
    cout << endl;
    return 0;
}
