#include <iostream>

using namespace std;

int main(){
    int N,k=0;
    cin >> N;
    int a[N];
    for(int i = 0;i < N;i++){
        cin >> a[i];
    }
    for(int i = 1;i < N-1;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            k++;
        }
    }
    cout << k;

    return 0;
}
