#include <iostream>
#include <string>

using namespace std;

struct Tree{
  Tree* mama = nullptr;
  Tree* lkid;
  Tree* rkid;
  int data;
};


struct commands {
  Tree *root = nullptr;

  void add(int x) {
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
  void Delete(int x) {
    Tree* find = exists(x);
    if(find == nullptr){
      return;
    }
    Tree* prev;
    Tree* element;
    Tree* del = exists(x);

    if (del -> lkid == nullptr || del -> rkid == nullptr) {
      prev = del;
    }
    else {
      prev = next(x);
    }
    if (prev -> lkid != nullptr)
      element = prev -> lkid;
    else
      element = prev -> rkid;
    if (element != nullptr)
     element -> mama = prev -> mama;
    if (prev -> mama == nullptr)
      root = element;
    else
    {
      if (prev == prev -> mama -> lkid)
        prev -> mama -> lkid = element;
      else
        prev -> mama -> rkid = element;
    }
    if (prev != del)
      del -> data = prev -> data;
    delete prev;
  }

  Tree * next(int x){
    Tree* element = root;
    Tree* suc = nullptr;
    while(element != nullptr){
      if(element -> data > x) {
        suc = element;
        element = element->lkid;
      }
      else{
        element = element -> rkid;
      }
    }
    return suc;
  }

  Tree *exists(int x){
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
  Tree* prev(int x)
  {
    Tree* element = root;
    Tree* prev = nullptr;
    while (element != nullptr)
    {
      if (element -> data < x)
      {
        prev = element;
        element = element -> rkid;
      }
      else
        element = element -> lkid;
    }

    return prev;
  }
  bool check(int x){
    return exists(x) != nullptr;
  }

};

int main(){
  string command;
  commands tree;
  int x;
  while (cin >> command) {
    if(command == "insert"){
      cin >> x;
      tree.add(x);
    }
    else if(command == "delete"){
      cin >> x;
      Tree* check = tree.exists(x);
      if(check != nullptr) {
        tree.Delete(x);
      }
    }
    else if(command == "exists"){
      cin >> x;
      cout << (tree.check(x) ? "true" : "false") << '\n';
    }
    else if(command == "next"){
      cin >> x;
      Tree* check = tree.next(x);
      if(check != nullptr){
        cout << check -> data << '\n';
      }
      else{
        cout << "none" << '\n';
      }
    }
    else if(command == "prev"){
      cin >> x;
      Tree* check = tree.prev(x);
      if(check != nullptr){
        cout << check -> data << '\n';
      }
      else{
        cout << "none" << '\n';
      }
    }
  }
}
