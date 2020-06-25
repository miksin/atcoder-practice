#include<iostream>
#include<set>
using namespace std;

int main() {
    int x, n;
    set<int> pSet;
    cin >> x >> n;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        pSet.insert(p);
    }

    int diff = 0;
    while (true) {
        if (pSet.find(x - diff) == pSet.end()) {
            cout << (x - diff);
            break;
        }
        if (pSet.find(x + diff) == pSet.end()) {
            cout << (x + diff);
            break;
        }
        diff++;
    }
}
