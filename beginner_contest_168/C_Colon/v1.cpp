#define _USE_MATH_DEFINES

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
    long double A, B, H, M;
    cin >> A >> B >> H >> M;

    long double ratioH = (60.0 * H + M) / (12.0 * 60.0);
    long double ratioM = M / 60.0;
    long double diff = abs(ratioH - ratioM);
    long double theta = diff * M_PI * 2.0;

    long double C = sqrtl(A * A + B * B - 2.0 * A * B * cosl(theta));
    cout << setprecision(10) << C;
}
