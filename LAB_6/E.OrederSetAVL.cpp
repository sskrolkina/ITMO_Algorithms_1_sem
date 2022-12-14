#include <iostream>
#include <vector>

using namespace std;


struct Node {
  int value;
  Node *left;
  Node *right;
  int height;
  Node(int k) { value = k; left = right = nullptr; height = 1; }
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

Node *insert(Node *current, int x){
  if(!current) return new Node(x);
  if(x < current -> value){
    current -> left = insert(current -> left,x);
  }
  else{
    current -> right = insert(current -> right,x);
  }
  return Balance(current);
}

  Node* maximum(Node* x)
  {
    if (x->right==nullptr) return x;
    return maximum(x->right);
  }

Node* removemax(Node* x){
  if (x->right == nullptr)
    return x->left;
  x->right = removemax(x->right);
  return Balance(x);
}

  Node *Delete(Node *x, int k) {
    if (x == nullptr) return nullptr;
      if (k < x->value) x->left = Delete(x->left, k);
      else if (k > x->value) x->right = Delete(x->right, k);
      else {
        Node *y = x->left;
        Node *z = x->right;
        delete (x);
        if(y == nullptr){
          return z;
        }
        Node *maxNode = maximum(y);
        maxNode->left = removemax(y);
        maxNode->right = z;
        return Balance(maxNode);
      }
      return Balance(x);
    }

Node* exists(Node* root, int k){
  if (root == nullptr) return nullptr;
  if (root -> value == k) return root;
  if (k < root -> value) return exists(root -> left, k);
  else return exists(root -> right, k);
}

  int main()
  {
    srand(time(0));
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    cin >> n;
    char command;
    int x;
    Node* tree = nullptr;
    for(int i = 0;i < n;i++){
      cin >> command;
      cin >> x;
      if(command == 'A')
      {
        if (!exists(tree, x))tree = insert(tree,x);
        cout << balance(tree) << endl;
      }
      if(command == 'D')
      {
        if (exists(tree, x))tree = Delete(tree,x);
        cout << balance(tree) << endl;
      }
      if(command == 'C')
      {
        if(exists(tree,x)) cout << "Y" << endl;
        else cout << "N" << endl;
      }
    }
  }
