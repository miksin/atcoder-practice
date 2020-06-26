#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<pair<long, int>> primeFactorize(long n) {
    vector<pair<long, int>> primes;
    for (long p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;

        int e = 0;
        while (n % p == 0) {
            n /= p;
            e++;
        }
        primes.push_back(make_pair(p, e));
    }

    if (n != 1) primes.push_back(make_pair(n, 1));
    return primes;
}

int main() {
    long n;
    cin >> n;

    int count = 0;
    vector<pair<long, int>> primes(primeFactorize(n));
    for (const pair<long, int>& prime: primes) {
        long p = prime.first;
        int e = prime.second;
        for (int i = 1; i <= e; i++) {
            e -= i;
            count += 1;
        }
    }
    cout << count;
}
