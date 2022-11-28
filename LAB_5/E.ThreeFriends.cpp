#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tree{
  Tree* mama = nullptr;
  Tree* lkid;
  Tree* rkid;
  string data;
};

struct commands {
  Tree *root = nullptr;

  void add(string x) {
    if(check(x)) return;
    Tree *tree = new Tree;
    tree->data = x;
    tree -> lkid = tree -> rkid = nullptr;
    Tree *element = root;
    while (element != nullptr) {
      tree -> mama = element;
      if (tree->data < element->data) {
        element = element->lkid;
      } else {
        element = element->rkid;
      }
    }
    if(tree -> mama == nullptr){
      root = tree;
    }
    else{
      if(tree->data < tree -> mama -> data){
        tree -> mama -> lkid = tree;
      }
      else{
        tree -> mama ->rkid = tree;
      }
    }
  }
  Tree *exists(string x){
    Tree* element = root;
    while(element != nullptr && x != element -> data)
    {
      if(x < element -> data){
        element = element ->lkid;
      }
      else{
        element = element -> rkid;
      }
    }
    return element;
  }
  bool check(string x){
    return exists(x) != nullptr;
  }
};

int main() {
  commands a;
  commands b;
  commands c;
  vector<string> a1;
  vector<string> b1;
  vector<string> c1;
  int n;
  cin >> n;
  string k;
  int score[3] = {0,0,0};
  for(int i = 0;i < n;i++){
    cin >> k;
    a.add(k);
    a1.push_back(k);
  }
  for(int i = 0;i < n;i++){
    cin >> k;
    b.add(k);
    b1.push_back(k);
  }
  for(int i = 0;i < n;i++){
    cin >> k;
    c.add(k);
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
