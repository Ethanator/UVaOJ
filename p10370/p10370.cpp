#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
	int	c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		vector<int> a;
		double sum = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			a.push_back(x);
			sum += x;
		}
		double mean = sum / n;
		double count = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] > mean) ++count;
		}
		printf("%.3lf%%\n", count / n * 100);
	}
}
