#include<iostream>
#include<string>
using namespace std;

int main() {
    long long a;
    string bStr;
    cin >> a >> bStr;

    long long b = (bStr[0] - '0') * 100 + (bStr[2] - '0') * 10 + bStr[3] - '0';
    long long result = a * b / 100;

    cout << result;
}
