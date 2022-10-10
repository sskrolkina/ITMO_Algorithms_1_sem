#include<iostream>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int size = n * m;
    int ship[size];
    for(int i = 0;i < size;i++){
        cin >> ship[i];
    }
    for(int i = 1;i < size;i++){
        for(int j = i; j > 0 && ship[j-1] > ship[j];j--){
            swap(ship[j-1],ship[j]);
        }
    }
    int k;
    cin >> k;
    int mesklinites[k];
    for(int i = 0;i < k;i++){
        cin >> mesklinites[i];
    }
    for(int i = 1;i < k;i++){
        for(int j = i; j > 0 && mesklinites[j-1] > mesklinites[j];j--){
            swap(mesklinites[j-1],mesklinites[j]);
        }
    }
    int c = 0;
    while(size * k > 0){
        if(ship[size-1] >= mesklinites[k-1]){
            c++;
            size--;
            k--;
        }
        else if(k > 0){
            k--;
        }
        else{
            size--;
        }

    }
    cout << c;
    return 0;
}
