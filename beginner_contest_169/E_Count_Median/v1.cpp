#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

median 0 ~ N-1

odd: (N - 1)/2
even: N/2-1, N/2
*/

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (N % 2 == 0) { // even
        // the double of median
        int maxMed = B[N / 2 - 1] + B[N / 2];
        int minMed = A[N / 2 - 1] + A[N / 2];
        cout << maxMed - minMed + 1;
    } else { // odd
        int maxMed = B[(N - 1) / 2];
        int minMed = A[(N - 1) / 2];
        cout << maxMed - minMed + 1;
    }
}
