#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n;
	int k = 0;
	while (cin >> n) {
		if (!n) return 0;
		++k;
		vector<int> v;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			sum += x;
			v.push_back(x);
		}
		int mean = sum / n;
		int count = 0;
		for (int i = 0; i < n; ++i) {
			count += abs(v[i] - mean);
		}
		cout << "Set #" << k << endl << "The minimum number of moves is "
				<< (count / 2) << "." << endl << endl;
	}
}
