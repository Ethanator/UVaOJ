#include <iostream>
using namespace std;

long sumDigits(long x) {
	long sum = x % 10;
	while (x / 10 >= 1) {
		x /= 10;
		sum += x % 10;
	}
	return sum;
}

long single(long x) {
	if (x < 0) return -x;
	while (x / 10 >= 1) {
		x = sumDigits(x);
	}
	return x;
}

int main() {
	long x;
	while (cin >> x) {
		if (!x) return 0;
		cout << single(x) << endl;
	}
}
