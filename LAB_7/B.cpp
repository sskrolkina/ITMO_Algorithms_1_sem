#include <iostream>

using namespace std;

int main()
{
  int s;
  int n;
  cin >> s >> n;

  int weight[n+1];
  int a[n+1][s+1];

  for (int i = 1; i <= n; i++) {
    cin >> weight[i];
  }

  for (int i = 0; i <= s; i++) {
    a[0][i] = 0;
  }
  for (int i = 0; i <= n; i++) {
    a[i][0] = 0;
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= s; j++)
    {
      if (s >= weight[i] && j - weight[i] >= 0)
      {
        a[i][j] = max(a[i - 1][j], a[i - 1][j - weight[i]] + weight[i]);
      }
      else
        a[i][j] = a[i - 1][j];
    }
  }
  cout << a[n][s];
  return 0;
}
