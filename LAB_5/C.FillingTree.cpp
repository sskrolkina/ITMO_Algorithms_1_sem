#include <iostream>
#include <vector>

using namespace std;

int lkid[200000];
int rkid[200000];
int tree[200000];
int cur;

void Tree(int i)
{
  if(cur == 0) return;
  else{
    if(rkid[i] != 0) Tree(rkid[i]-1);
    if(tree[i] == 0){
      tree[i] = cur;
      cur--;
    }
    if(lkid[i] != 0){
      Tree(lkid[i]-1);
      if(tree[i] == 0){
        tree[i] = cur;
        cur--;
      }
    }
  }
}

void print(int n){
  for(int i = 0;i < n;i++){
    cout << tree[i] << " ";
  }
}
int main(){
  int n;
  cin >> n;
  cur = n;
  int l,r;
  for(int i = 0;i < n;i++){
    cin >> lkid[i] >> rkid[i];
    tree[i] = 0;
  }
   Tree(0);
   print(n);
  }
