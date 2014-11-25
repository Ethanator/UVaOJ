#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        int mm = m;
        vector<int> a;
        while (m--) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int count = 0;
        for (int i = mm - 1; i >= 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (a[j] > a[j + 1]) {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
		    ++count;
                }
            }
        }
        cout << "Optimal train swapping takes " << count << " swaps." << endl;
    }
}
