#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Node {
  string value;
  Node *left;
  Node *right;
  int height;
  Node(const string& x) { value = x; left = right = nullptr; height = 1; }
};

int hei(Node* x) {
  if (x == nullptr) return 0;
  return x -> height;
}

int balance(Node* x) {
  if (x==nullptr) return 0;
  return hei(x->right) - hei(x->left);
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

Node* Balance(Node* x){
  if (x==nullptr) return nullptr;
  x->height = max(hei(x->left), hei(x->right)) + 1;
  if(balance(x)==2)
  {
    if (balance(x->right) < 0)
      x->right = rotateRight(x->right);
    return rotateLeft(x);
  }
  if(balance(x)== -2){
    if (balance(x->left) > 0)
      x->left = rotateLeft(x->left);
    return rotateRight(x);
  }
  return x;
}

Node* exists(Node* root, const string& k){
  if (root == nullptr) return nullptr;
  if (root -> value == k) return root;
  if (k < root -> value) return exists(root -> left, k);
  else return exists(root -> right, k);
}


Node *insert(Node *current, const string& x) {
      if (!current) return new Node(x);
      if (x < current -> value){
        current->left = insert(current->left, x);
      }
      else{
        current->right = insert(current->right, x);
      }
      return Balance(current);
  }
bool check(Node* tree,const string& x){
  return exists(tree,x) != nullptr;
}

  int main() {
    int n;
    int result = 0;
    cin >> n;
    string x;
    Node *tree = nullptr;

    for (int i = 0; i < n; i++) {
      cin >> x;
      if (check(tree, x)) {
        Node *cash = nullptr;
        for (char j : x) {
          if (!check(cash, to_string(j))) {
            cash = insert(cash, to_string(j));
            result++;
          }
        }
      }
      else{
        tree = insert(tree,x);
      }
    }
    cout << result;
  }
