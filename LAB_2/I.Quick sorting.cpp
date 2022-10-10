#include <iostream>

using namespace std;

int partition(int a[],int start,int end){
    int pivot = a[start];
    int k = 0;
    for(int i = start + 1;i <= end;i++){
        if(a[i] <= pivot)k++;
    }

    int pivotIndex = start + k;
    swap(a[pivotIndex],a[start]);

    int i = start,
    j = end;
    while(i < pivotIndex && j > pivotIndex){
        while(a[i] <= pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(a[i++],a[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int a[],int start,int end){
    if(start >= end)return;

    int part = partition(a,start,end);

    quickSort(a,start,part - 1);
    quickSort(a,part + 1,end);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    quickSort(a,0,n-1);

    for(int i = 0;i < n;i++){
        cout << a[i] << " ";
    }
    return 0;
}
