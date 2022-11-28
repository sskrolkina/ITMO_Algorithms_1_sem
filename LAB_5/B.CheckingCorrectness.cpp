#include <iostream>

using namespace std;

struct Tree{
    int data = 0;
    Tree* lkid = nullptr;
    Tree* rkid = nullptr;
    Tree* mama = nullptr;
    int min;
    int max;
};

Tree tree[200000];
bool check = true;

void Checking(int i,int min,int max){
  if(tree[i].mama -> data >= tree[i].data && tree[i].mama -> rkid == &tree[i]){
    check = false;
  }
  else if (tree[i].mama->data <= tree[i].data && tree[i].mama->lkid == &tree[i]){
    check = false;
    }
  else if (tree[i].mama->data > tree[i].data && tree[i].data <= tree[i].mama -> min){
    check = false;
    }
  else if (tree[i].mama->data < tree[i].data && tree[i].data >= tree[i].mama -> max)
    check = false;
  if (tree[i].mama->data > tree[i].data){
          tree[i].max = tree[i].mama->data;
          tree[i].min = tree[i].mama -> min;
        }
  else if (tree[i].mama->data < tree[i].data){
          tree[i].min = tree[i].mama->data;
          tree[i].max = tree[i].mama -> max;
        }
}

int main(){
    int n;
    int l,r;
    cin >> n;
    if(n == 0){
      cout << "YES";
      return 0;
    }
    for(int i = 0;i < n;i++){
        cin >> tree[i].data >> l >> r;
        if (l != 0) {
            tree[i].lkid = &tree[l-1];
            tree[l-1].mama = &tree[i];
        }
        if (r != 0) {
            tree[i].rkid = &tree[r-1];
            tree[r-1].mama = &tree[i];
        }
        if(i != 0){
          int k = i;
        Checking(k,tree[i].mama -> min,tree[i].mama -> max);
    }
        else{
          tree[i].min = -1000000001;
          tree[i].max =  1000000001;
        }
    }
    if(check) cout << "YES";
    else cout << "NO";
}
