#include <iostream>
#include <vector>

using namespace std;

void Merge(int *a,int left,int right,int mid){
    int i = left,
            j = mid + 1,
            k = 0,
            tmp[right - left + 1];

    while(i <= mid && j <= right){
        if(a[i] < a[j]){
            tmp[k] = a[i];
            k++;
            i++;
        }
        else{
            tmp[k] = a[j];
            k++;
            j++;
        }
    }
    while(i <= mid){
        tmp[k] = a[i];
        k++;
        i++;
    }
    while(j <= right){
        tmp[k] = a[j];
        k++;
        j++;
    }

    for(i = left; i <= right;i++){
        a[i] = tmp[i - left];
    }
}
void MergeSort(int *a,int left,int right){
    int mid;
    if(left < right){
        mid = (left + right)/2;
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);

        Merge(a,left,right,mid);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    MergeSort(a,0,n-1);
    int k;
    vector<int> aFixed;

    aFixed.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            aFixed.push_back(a[i]);
        }
    }


    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    MergeSort(b,0,m-1);
    vector<int> bFixed;
    bFixed.push_back(b[0]);
    for (int i = 1; i < m; i++) {
        if (b[i] != b[i - 1]) {
            bFixed.push_back(b[i]);
        }
    }

    bool f = true;
    if(aFixed.size() != bFixed.size()){
        cout << "NO";
        f = false;
    }
    else {
        for (int i = 0; i < aFixed.size(); i++) {
            if (aFixed[i] != bFixed[i]) {
                cout << "NO";
                f = false;
                break;
            }
        }
    }

    if(f) { cout << "YES"; }

    return 0;
}
