#include <iostream>
#include <vector>

using namespace std;

void radixSort(vector<string>& a,int n,int index)
{
    vector<string> str;
    char abc = 'a';
    int k = 0;
    for(int i = 0;i < 26;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(a[j][index] == abc)
            {
                str.push_back(a[j]);
                k++;
            }
        }
        abc++;
    }
    for(int i = 0;i < n;i++)
    a[i] = str[i];
}

int main()
{
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    vector<string> result;

    for(int i = 0;i < n;i++) {
        string el;
        cin >> el;
        result.push_back(el);
    }
    for(int index = m - 1;index >= m - k;index--)
        radixSort(result,n,index);

    for(int i = 0;i < n;i++)
        cout << result[i] << '\n';

    return 0;
}
