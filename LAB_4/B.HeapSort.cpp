#include <iostream>

using namespace std;

void heap(int a[],int n,int i)
{
    int mama = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[mama]){
        mama = left;
    }
    if(right < n && a[right] > a[mama]){
        mama = right;
    }
    if(mama != i){
        swap(a[i],a[mama]);
        heap(a,n,mama);
    }
}

void heapSort(int a[],int n){
    for(int i = n / 2 - 1;i >= 0;i--){
        heap(a,n,i);
    }
    for(int i = n - 1;i >= 0;i--){
        swap(a[0],a[i]);
        heap(a,i,0);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    heapSort(a,n);

    for(int i = 0; i < n;i++){
        cout << a[i] << " ";
    }

    return 0;
}
