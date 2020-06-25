#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned int allXor = 0;
    vector<unsigned int> arr(n);
    for (int i = 0; i < n; i++) {
        unsigned int a;
        cin >> a;
        allXor = allXor ^ a;
        arr[i] = a;
    }

    for (int i = 0; i < n - 1; i++) {
        cout << (arr[i] ^ allXor) << " ";
    }

    cout << (arr[n - 1] ^ allXor);
}
