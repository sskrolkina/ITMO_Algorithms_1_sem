#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a;
  int x;

  for(int i = 0;i < n;i++){
    cin >> x;
    a.push_back(x);
  }

  int prev[n];
  int d[n];

  for(int i = 0;i < n;i++){
    d[i] = 1;
    prev[i] = -1;
    for(int j = 0;j < i;j++){
      if(a[j] < a[i] && d[j] + 1 > d[i]){
        d[i] = d[j] + 1;
        prev[i] = j;
      }
    }
  }

  int pos = 0;
  int length = d[0];

  for(int i = 0;i < n;i++){
    if(d[i] > length){
      pos = i;
      length = d[i];
    }
  }

  vector<int> answer;
  while(pos != -1){
    answer.push_back(a[pos]);
    pos = prev[pos];
  }

  reverse(begin(answer),end(answer));

  cout << answer.size() << '\n';

  for(int i = 0;i < answer.size();i++){
    cout << answer[i] << " ";
  }
  return 0;
}
