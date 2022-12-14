#include <iostream>
#include <vector>

using namespace std;


struct Node
{
  string value;
  Node* left = nullptr;
  Node* right = nullptr;
  int height = -1;
};

struct AVL {

  Node* root = nullptr;

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

  void  insert(string x) {
    root = add(root, x);
  }

  Node *add(Node *current, string x){
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

  Node *exists(string x){
    Node* element = root;
    while(element != nullptr && x != element -> value)
    {
      if(x < element -> value){
        element = element ->left;
      }
      else{
        element = element -> right;
      }
    }
    return element;
  }
  bool check(string x){
    return exists(x) != nullptr;
  }
};


int main() {
  AVL a;
  AVL b;
  AVL c;
  vector<string> a1;
  vector<string> b1;
  vector<string> c1;
  int n;
  cin >> n;
  string k;
  int score[3] = {0,0,0};
  for(int i = 0;i < n;i++){
    cin >> k;
    a.insert(k);
    a1.push_back(k);
  }
  for(int i = 0;i < n;i++){
    cin >> k;
    b.insert(k);
    b1.push_back(k);
  }
  for(int i = 0;i < n;i++){
    cin >> k;
    c.insert(k);
    c1.push_back(k);
  }
  for(int i = 0;i < n;i++){
    string t = a1[i];
    if(!b.check(t) && !c.check(t)){
      score[0] += 3;
    }
    else if(b.check(t) && c.check(t)){
      score[0] += 0;
    }
    else score[0] += 1;
  }
  for(int i = 0;i < n;i++){
    string t = b1[i];
    if(!a.check(t) && !c.check(t)){
      score[1] += 3;
    }
    else if(a.check(t) && c.check(t)) {
      score[1] += 0;
    }
    else score[1] += 1;
  }
  for(int i = 0;i < n;i++){
    string t = c1[i];
    if(!a.check(t) && !b.check(t)){
      score[2] += 3;
    }
    else if(a.check(t) && b.check(t)){
      score[2] += 0;
    }
    else score[2] += 1;
  }
  for(int i = 0;i < 3;i++){
    cout << score[i] << " ";
  }
}
