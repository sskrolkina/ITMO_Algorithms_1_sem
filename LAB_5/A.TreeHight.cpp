#include <iostream>

using namespace std;

struct Tree{
    int data = 0;
    Tree* lkid = nullptr;
    Tree* rkid = nullptr;
    int hight = 1;
};

int main(){
    int n;
    int l,r;
    int max = 0;
    cin >> n;
    Tree tree[n];
    for(int i = 0;i < n;i++){
        cin >> tree[i].data >> l >> r;
        tree[l-1].lkid = &tree[i];
        tree[r-1].rkid = &tree[i];

        if(tree[i].lkid != nullptr){
            tree[i].hight = tree[i].lkid -> hight + 1;
        }
        if(tree[i].rkid != nullptr){
            tree[i].hight = tree[i].rkid -> hight + 1;
        }
        if(tree[i].hight > max)
            max = tree[i].hight;
    }
    cout << max;
}
