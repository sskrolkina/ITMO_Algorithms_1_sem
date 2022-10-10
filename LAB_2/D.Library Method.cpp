#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    bool flag = false;
    {
        for (int i = 1; i < n; i++) {
            bool f = false;
            for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
                swap(a[j - 1], a[j]);
                f = true;
            }
            if (f) {
                if (flag) {
                    cout << '\n';
                }
                for (int s = 0; s < n; s++) {
                    if (s != 0) cout << " ";
                    cout << a[s];
                    flag = true;
                }
            }
        }
    }
    return 0;

}
