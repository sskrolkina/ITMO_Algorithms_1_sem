#include <iostream>

using namespace std;

struct Tree{
  int height = 1;
  int data = 0;
  int lkid_height = height;
  int rkid_height = height;
  Tree* mama = nullptr;
};

int main(){
  int n;
  int l,r;
  cin >> n;
  Tree tree[n];
  for(int i = 0;i < n;i++){
    cin >> tree[i].data >> l >> r;
    tree[l-1].mama = &tree[i];
    tree[r-1].mama = &tree[i];

    if(tree[i].mama != nullptr){
      tree[i].height = tree[i].mama -> height + 1;
    }
    tree[i].rkid_height = tree[i].height;
    tree[i].lkid_height = tree[i].height;
  }
  for (int i = n-1; i > 0; i--){
    if (tree[i].data > tree[i].mama->data)
      tree[i].mama->rkid_height = tree[i].height;
    else tree[i].mama->lkid_height = tree[i].height;
    if (tree[i].height > tree[i].mama->height)
      tree[i].mama->height = tree[i].height;
  }
  for (int i = 0; i < n; i++){
    cout << tree[i].rkid_height-tree[i].lkid_height << '\n';
  }
  return 0;
}
