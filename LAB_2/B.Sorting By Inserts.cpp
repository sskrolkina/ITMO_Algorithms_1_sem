#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    for(int i = 1;i < n;i++){
        for(int j = i; j > 0 && a[j-1] > a[j];j--){
            swap(a[j-1],a[j]);
        }
    }
    for(int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
    return 0;
}
