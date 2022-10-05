#include <iostream>

using namespace std;

int main(){
    int N,min1 = 2000000000,min2 = 2000000000,tmp;
    cin >> N;
    int a[N];
    for(int i = 0;i < N;i++){
        cin >> a[i];
        if(a[i] < min1) {
            min1 = a[i];
            tmp = i;
        }
    }
    for(int i = 0;i < N;i++){
        if(a[i] < min2 && a[i] >= min1 && i != tmp) {
            min2 = a[i];
        }
    }
    cout << min1 << " "<< min2;

    return 0;
}
