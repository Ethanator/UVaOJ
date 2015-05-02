#include <iostream>
#include <vector>
using namespace std;

int dir[8][2] = {{-1, 0}, { 1,0}, {0,-1}, {0,1}, 
		         {-1,-1}, {-1,1}, {1,-1}, {1,1}};

int isInBounds(int i, int j, int r, int c) {
	return i >= 0 && i < r && j >= 0 && j < c;
}

int main() {
	int r, c;
	bool isFirstCase = true;
	int count = 1;
	while (cin >> r >> c) {
		if (!r && !c) return 0;
		if (!isFirstCase) cout << endl;
		else isFirstCase = false;
		cout << "Field #" << count++ << ":" << endl;
		vector<vector<char> > a;
		vector<vector<int> > b;
		for (int i = 0; i < r; ++i) {
			vector<char> tmpa;
			for (int j = 0; j < c; ++j) {
				char tmpi;
				cin >> tmpi;
				tmpa.push_back(tmpi);
			}
			a.push_back(tmpa);
		}
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (a[i][j] == '*') {
					cout << '*';
					continue;
				}
				int count = 0;
				for (int k = 0; k < 8; ++k) {
					int ii = i + dir[k][0];
					int jj = j + dir[k][1];
					if (isInBounds(ii, jj, r, c) && a[ii][jj] == '*')
						++count;
				}
				cout << count;
			}
			cout << endl;
		}
	}
}
