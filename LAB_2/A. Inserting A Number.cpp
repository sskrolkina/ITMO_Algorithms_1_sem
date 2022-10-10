#include <iostream>

using namespace std;

int main(){
    int n;
    int number;
    int place;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    cin >> number >> place;
    for(int i = 0; i < n;i++){
        if(i == place - 1){ 
            cout << number << " " << a[i] << " ";
        }
        else{
            cout << a[i] << " ";
        }
    }
    return 0;
}
