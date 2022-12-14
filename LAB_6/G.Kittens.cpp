#include <iostream>
#include <vector>

using namespace std;

vector<int> meat;

void fix(int i) {
  i = i / 2;
  while (i != 0) {
    meat[i] = meat[i * 2] + meat[i * 2 + 1];
    i = i / 2;
  }
}
int sum(int left, int right) {
  int result = 0;
  while (left <= right) {
    if (left % 2 != 0) {
      result += meat[left];
    }
    if (right % 2 == 0) {
      result += meat[right];
    }

    left = (left + 1) / 2;
    right = (right - 1) / 2;
  }

  return result;
}


int main()
{
  int kittens;
  int n;
  char ask;
  int x;
  int kitty;
  int l,r;
  int New;
  cin >> kittens >> n;

  for(int i = 0;i <= kittens * 2 + 1;i++){
    meat.push_back(0);
  }

  for(int i = kittens;i > 0;i--){
    meat[i] = meat[2*i] + meat[2 * i + 1];
  }

  for(int i = 0;i < n;i++){
    cin >> ask;
    if(ask == '+'){
      cin >> kitty >> x;
      meat[kittens + kitty] += x;
      fix(kittens + kitty);
    }
    else if(ask == '-')
    {
      cin >> kitty >> x;
      if(x >= meat[kittens + kitty]){
        New = 0;
      }
      else New = meat[kitty + kittens] - x;
      meat[kittens + kitty] = New;
      fix(kittens + kitty);
    }
    else if(ask == '?'){
      cin >> l >> r;
      int res = sum(l+kittens,r+kittens);
      cout << res << '\n';
    }
  }
  return 0;
}
