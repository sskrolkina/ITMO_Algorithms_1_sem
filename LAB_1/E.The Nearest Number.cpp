#include <iostream>

using namespace std;

int main(){
    int N,k=0,x,dif,answer;
    cin >> N;
    int a[N];
    for(int i = 0;i < N;i++){
        cin >> a[i];
    }
    cin >> x;
    dif = abs(x - a[0]);
    answer = a[0];
    for(int i = 1;i <N;i++){
        if(abs(x-a[i])<dif){
            dif = abs(x - a[i]);
            answer = a[i];
        }
    }
    cout << answer;

    return 0;
}
