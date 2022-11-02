#include <iostream>
#include <vector>
using namespace std;

struct Splitting{
    bool okidoki(long int mid, long int* numbers, long int k, long int n) {
        long int total = 0;
        long int check = 0;
        for (long int i = 0; i < n; i++) {
            if(numbers[i] > mid) return false;
            if(total + numbers[i] <= mid) total = total + numbers[i];
            else {
                check++;
                total = numbers[i];
            }
        }
        check++;
        return (check <= k);
    }
    long int middle(long int a, long int b) {
        return (a + b) / 2;
    }

    long int split(long int* numbers, long int k, long int n, long int sum) {
        long int left = 0;
        long int right = sum;

        while (left < right) {
            long int mid = middle(left, right);
            if (okidoki(mid, numbers, k, n)){
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
};

int main(){
    long int n;
    cin >> n;
    long int result[n];
    long int numbers[n];
    long int k;
    long int sum = 0;
    cin >> k;
    for(long int i = 0;i < n;i++){
        cin >> numbers[i];
        result[i] = 0;
        sum += numbers[i];
    }
    Splitting res;
    long int split_sum = res.split(numbers,k, n, sum);

    long int current_sum = 0;
    long int counter = 0;
    for(long int i = 0; i < n; i++) {
        if(current_sum + numbers[i] > split_sum){
            current_sum = numbers[i];
            result[i] = 1;
            counter++;
        }
        else{
            current_sum += numbers[i];
        }
    }

    for(long int i = 1; counter < k - 1; i++){
        if(result[i] == 0) {
            result[i] = 1;
            counter++;
        }
    }

    for(long int i = 0; i < n; i++){
        if(result[i] == 1){
            cout << i << ' ';
        }
    }

    return 0;
}
