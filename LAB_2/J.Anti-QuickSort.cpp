#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    for (int i = 2; i < n; i++)
    {
        int temp = a[i];
        a[i] = a[i / 2];
        a[i / 2] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}
