#include <iostream>
#include <vector>
using namespace std;

int middle(int a,int b)
{
    return (a+b)/2;
}
int binarySearch_first(vector<int>& a,int key,int n){
    int left = -1;
    int right = n;

    while(left < right - 1)
    {
        int mid = middle(left,right);
        if(a[mid] < key) left = mid;
        else right = mid;
    }
    return right;
}
int binarySearch_last(vector<int>& a,int key,int n){
    int left = -1;
    int right = n;

    while(left < right - 1)
    {
        int mid = middle(left,right);
        if(a[mid] <= key) left = mid;
        else right = mid;
    }
    return right - 1;
}
int main(){
    vector<int> a;
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n;i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    for(int i = 0;i < m;i++){
        int key;
        cin >> key;
        if (binarySearch_first(a, key, n) > binarySearch_last(a, key, n)) cout << "-1 -1\n";
        else cout << binarySearch_first(a,key,n) + 1 << " " << binarySearch_last(a, key, n) + 1 << endl;
    }
    return 0;
}
