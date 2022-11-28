#include <iostream>
#include <vector>


using namespace std;

struct Tree{
  Tree* lkid;
  Tree* rkid;
  int data;
};
Tree *newNode(int n)
{
  Tree *root=new Tree;
  root->data=n;
  root->lkid=root->rkid=nullptr;
  return root;
}


Tree* add(Tree *&root,int x){
  if (root == nullptr) {
    root = new Tree;
    root->data = x;
    root->lkid = root->rkid = NULL;
  }
  else if (root->data > x) add(root->lkid, x);
  else if (root->data < x) add(root->rkid, x);
  return root;
}


Tree* tree(vector<int>& a, int* index, int key,int min,int max, int size) {
  Tree* root = nullptr;
  if (*index >= size) {
    return nullptr;
  }

  if (key > min && key < max) {
    root = add(root,key);
    *index = *index + 1;

    if (*index < size) {
      root->lkid = tree(a, index, a[*index], min, key, size);
    }
    if (*index < size) {
      root->rkid = tree(a, index, a[*index], key, max, size);
    }
  }
  return root;
}
void print(Tree*&tree) {
  if (tree != nullptr) {
    print(tree->lkid);
    print(tree->rkid);
    cout << tree->data << " ";
  }
}

int main() {
  int n;
  cin >> n;
  int k;
  int index = 0;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    cin >> k;
    a.push_back(k);
  }
  Tree* meow;
  meow = tree(a,&index,a[0],INT_MIN,INT_MAX,n);
  print(meow);
}
