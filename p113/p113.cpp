#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	double a, b;
	while (cin >> a >> b) {
		printf("%.0lf\n", pow(b, 1/a));
	}	
}
