#include <iostream>

using namespace std;

struct Fridge{
    int milk;
    int meat;
    int cheese;
    int human_bodies;
};


int main(){
    struct Fridge pink_fridge;
    pink_fridge.human_bodies = 3;
    pink_fridge.cheese = 1;
    pink_fridge.meat = 13;

    struct Fridge black_fridge;
    black_fridge.milk = 1;
    black_fridge.cheese = 43;
    black_fridge.meat = 0;

    cout << "How much meat do you want? = ";
    cin >> pink_fridge.human_bodies;
    cout << "YAY. We have dinner on " << pink_fridge.human_bodies << "days =)";

    return 0;
}
