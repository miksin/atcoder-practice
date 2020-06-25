#include<iostream>
#include<map>
using namespace std;

int main() {
	long len;
    cin >> len;
	
    long sum = 0;
    map<long, long> numCount;
    for (int i = 0; i < len; i++) {
    	long a;
        cin >> a;
      	sum += a;
        numCount[a] += 1;
    }
  
    long q;
    cin >> q;
    for (long i = 0; i < q; i++) {
    	long b, c;
        cin >> b >> c;
      	
      	long amount = numCount[b];
        sum += amount * (c - b);
        cout << sum << endl;
      	
      	numCount[c] += amount;
      	numCount[b] = 0;
    }
}
