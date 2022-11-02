#include <iostream>
#include <iomanip>

using namespace std;

double n;
double A;
bool notGround;

double middle(double a, double b)
{
    return (a+b)/2;
}

double binarySearch(){
    double left = 0;
    double right = A;
    double last;

    while(right - left > 0.0000001)
    {
        double mid = middle(left,right);
        double prev = A;
        double cur = mid;
        notGround = cur > 0;
        for(int i = 2;i < n;i++){
            double next = 2 * cur - prev + 2;
            notGround = notGround && (next > 0);
            prev = cur;
            cur = next;
        }
        if(notGround) {
            right = mid;
            last = cur;
        }
        else left = mid;
    }
    return last;
}

int main(){
    cin >> n;
    cin >> A;
    double result = binarySearch();
    cout  << fixed << setprecision(2) << result;
    return 0;
}
