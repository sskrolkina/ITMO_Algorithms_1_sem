#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int,int>> elements;

void siftUp(int i) {
    while (i != 0 && elements[i].first < elements[(i - 1) / 2].first) {
        swap(elements[i], elements[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void siftDown(int i) {
    int left;
    int right;
    int j;
    while (2 * i + 1 < elements.size()) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;
        if (right < elements.size() && elements[right].first < elements[left].first) {
            j = right;
        }
        if (elements[i].first <= elements[j].first) {
            break;
        }
        swap(elements[i], elements[j]);
        i = j;
    }
}


int main(){
    int n = 0;
    int count = 0;
    string command;
    while(cin >> command)
    {
        if(command == "push")
        {
            count++;
            int num;
            cin >> num;
            elements.emplace_back(num,count);
            n++;
            siftUp(n - 1);
        }
        else if(command == "extract-min")
        {
            count++;
            if(n < 1)
                cout << "*" << '\n';
            else
            {
                cout << elements[0].first << '\n';
                elements[0] = elements[n-1];
                elements.pop_back();
                siftDown(0);
                n--;
            }
        }
        else if(command == "decrease-key")
        {
            count++;
            int id;
            int num;
            cin >> id >> num;
            for(int i = 0;i < elements.size();i++){
                if(id == elements[i].second)
                {
                    elements[i].first = num;
                    siftUp(i);
                    break;
                }
            }
        }
    }
}
