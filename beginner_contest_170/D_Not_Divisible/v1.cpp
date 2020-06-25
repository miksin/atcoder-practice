#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int arrMax = arr.back();
    vector<int> dp(arrMax + 1, true);

    int count = 0;
    for (int i = 0; i < n; i++) {
        int a = arr[i];
        if (dp[a]) {
            for (int j = 0; j * a <= arrMax; j++) {
                dp[j * a] = false;
            }
            if (i == n - 1 || a != arr[i + 1]) {
                count++;
            }
        }
    }
    cout << count;
}
