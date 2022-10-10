#include <iostream>

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


int main(){
    int n;
    cin >> n;
    int begin[n];
    int end[n];
    int result;

    for(int i = 0;i < n;i++){
        cin >> begin[i] >> end[i];
    }
    MergeSort(begin,0,n-1);
    MergeSort(end,0,n-1);

    result = end[0] - begin[0] + 1;

    for(int i = 1; i < n;i++){
        if(begin[i] <= end[i-1]){
            result += end[i] - end[i-1];
        }else{
            result += end[i] - begin[i] + 1;
        }
    }
    cout << result;
}
