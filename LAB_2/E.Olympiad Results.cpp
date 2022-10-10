#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int id[n],
        scores[n];
    for (int i = 0; i < n; i++) {
        cin >> id[i] >> scores[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (scores[j - 1] < scores[j]) {
                swap(scores[j], scores[j - 1]);
                swap(id[j], id[j - 1]);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (scores[j] == scores[j - 1] && id[j] < id[j - 1]) {
                swap(scores[j], scores[j - 1]);
                swap(id[j], id[j - 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << id[i] << " " << scores[i] << "\n";
    }
    return 0;
}
