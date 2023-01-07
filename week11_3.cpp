#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;
    char i1,i2,i3;
    cin >> i1 >> i2 >> i3;
    int index = input.find(i1);
    cout << index;
    return 0;
}
