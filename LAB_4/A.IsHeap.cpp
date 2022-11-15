#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 1;i < n+1;i++){
        cin >> a[i];
    }
    for(int i = 1;i < n/2;i++) {
        if ((2 * i > n || a[i] > a[2 * i]) || (2 * i + 1 > n || a[i] > a[2 * i + 1])) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
