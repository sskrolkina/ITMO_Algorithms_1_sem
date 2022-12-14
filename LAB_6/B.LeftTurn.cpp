#include <iostream>
#include <vector>

using namespace std;

struct Tree {
  int data{};
  int lkid;
  int rkid;
  int height;
  Tree() : lkid{-1}, rkid{-1}, height{-1} {}
  Tree(int data, int lkid, int rkid) : data{data}, lkid{lkid}, rkid{rkid}, height{-1} {}
};

struct AVL {
  vector<Tree> tree;
  int root;
  explicit AVL(int n) : tree{vector<Tree>(n)}, root{0} {}


  int hei(int x) {
    if (x == -1) {
      return 0;
    }
    if (tree[x].height != -1)
    {
      return tree[x].height;
    }
    return tree[x].height = 1 + max(hei(tree[x].lkid), hei(tree[x].rkid));
  }

  int balance(int x) {
    return hei(tree[x].rkid) - hei(tree[x].lkid);
  }


  int rotateLeft(int x) {
    int y = tree[x].rkid;
    tree[x].rkid = tree[y].lkid;
    tree[y].lkid = x;
    tree[x].height = max(hei(tree[x].lkid), hei(tree[x].rkid)) + 1;
    tree[y].height = max(hei(tree[y].lkid), hei(tree[y].rkid)) + 1;

    root = y;

    return y;
  }

  int bigLeftRotate(int x) {
    tree[x].rkid = rotateRight(tree[x].rkid);
    return rotateLeft(x);
  }

  int rotateRight(int x) {
    int y = tree[x].lkid;
    tree[x].lkid = tree[y].rkid;
    tree[y].rkid = x;
    tree[x].height = max(hei(tree[x].lkid), hei(tree[x].rkid)) + 1;
    tree[y].height = max(hei(tree[y].lkid), hei(tree[y].rkid)) + 1;
    return y;
  }

  void treeTurn() {
    if (balance(tree[0].rkid) == -1) {
      bigLeftRotate(0);
    } else {
      rotateLeft(0);
    }
  }
  void print() {
    Tree* rooty = &tree[root];
    cout << rooty->data << ' ' << mhmmmhhmmhmh(rooty->lkid, root) << ' ' << mhmmmhhmmhmh(rooty->rkid, root) << '\n';

    for (int i = 0; i < tree.size(); i++) {
      if (i == root) continue;
      Tree* el = &tree[i];
      if (i < root) {
        cout << el->data << ' ' << mhmmmhhmmhmh(el->lkid, root)
             << ' ' << mhmmmhhmmhmh(el->rkid, root) << '\n';
      } else {
        cout << el->data << ' ' << mhmmmhhmmhmh(el->lkid, root) << ' ' << el->rkid + 1 << '\n';
      }
    }
  }

  int mhmmmhhmmhmh(int child, int root) {
    if (child == -1) return 0;
    if (child <= root) return child + 2;
    else return child + 1;
  }
};


int main() {
  int n;
  cin >> n;
  AVL *tree = new AVL(n);
  int val, l, r;
  for (int i = 0; i<n; i++) {
    cin >> val >> l >> r;
    tree->tree[i] = Tree(val, l - 1, r - 1);
  }

  tree->treeTurn();

  cout << n << '\n';

  tree ->print();

  return 0;
}
