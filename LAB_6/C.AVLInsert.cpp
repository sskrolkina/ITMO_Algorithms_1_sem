#include <iostream>
#include <vector>

using namespace std;

struct Tree {
  int data{};
  int lkid;
  int rkid;

  Tree() = default;
};

struct Node
{
  int value = -1;
  Node* left = nullptr;
  Node* right = nullptr;
  int height = -1;
};

struct AVL {

  Node* root = nullptr;
  vector<Tree> tree;


  int hei(Node* x) {
    if (x == nullptr) {
      return -1;
    }
    if (x -> height == -1)
    {
      x->height = max(hei(x->left), hei(x->right)) + 1;
    }
    return x -> height;
  }

  int balance(Node* x) {
    return hei(x -> right) - hei(x->left);
  }


  Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(hei(x->left), hei(x->right)) + 1;
    y->height = max(hei(y->left), hei(y->right)) + 1;

    return y;
  }

  Node* rotateRight(Node* x) {
    Node* y = x->left;
    x->left = y -> right;
    y -> right = x;
    x->height = max(hei(x->left), hei(x->right)) + 1;
    y->height = max(hei(y->left), hei(y->right)) + 1;
    return y;
  }

  Node* rebalance(Node* x) {
    x->height = max(hei(x->left), hei(x->right)) + 1;

    if (balance(x) == 2) {
      if (balance(x->right) < 0) {
        x->right = rotateRight(x->right);
      }
      return rotateLeft(x);
    }
    if(balance(x)== -2){
      if (balance(x->left) > 0) {
        x->left = rotateLeft(x->left);
      }
      return rotateRight(x);
    }
    x->height = max(hei(x->left), hei(x->right)) + 1;
    return x;
  }

  void  insert(int x) {
    root = add(root, x);
  }

  Node *add(Node *current, int x){
    if (current == nullptr) {
      current = new Node;
      current->value = x;
      current->height = 0;
      current->left = nullptr;
      current->right = nullptr;
      return current;
    }
    if (x < current->value)
      current->left = add(current->left, x);
    else
      current->right = add(current->right, x);
    return rebalance(current);
  }

  void build(int &current, Node *x){
    if (x == nullptr) {
      return;
    }
    int tmp = current;
    tree[current-1].data = x->value;
    if (x->left == nullptr) tree[current-1].lkid = 0;
    else {
      tree[current - 1].lkid = current + 1;
      current++;
      build(current, x->left);
    }

    if (x->right == nullptr) tree[tmp - 1].rkid = 0;
    else {
      tree[tmp - 1].rkid = current + 1;
      current++;
      build(current, x->right);
    }
  }

  void print(int n) {
    tree.resize(n);
    int i = 1;
    build(i, root);

    for (auto x: tree) {
      cout << x.data << ' ' << x.lkid << ' ' << x.rkid << '\n';
    }
  }
};


int main() {
  int n;
  cin >> n;
  AVL trree;
  vector<Node> a(n + 1);
  int val, l, r;
  for (int i = 0; i<n; i++) {
    cin >> val >> l >> r;
    a[i].value = val;

    if (l - 1 != -1) a[i].left = &a[l - 1];
    else a[i].left = nullptr;

    if (r - 1 != -1) a[i].right = &a[r - 1];
    else a[i].right = nullptr;
  }

  int number;
  cin >> number;
  if (n != 0) trree.root = &a[0];
  trree.insert(number);
  n++;

  cout << n << '\n';

  trree.print(n);
  return 0;
}
