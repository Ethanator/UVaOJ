/* p280.cpp
 * Solution to the problem on: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=216
 * 	     Author: Yuxuan "Ethan" Chen
 *   Start Time: 5:44 PM, Tuesday, November 25, 2014
 *     End Time: 6:31 PM, Tuesday, November 25, 2014
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(map<long long, vector<long long> > &g, vector<bool> &a, long long k) {
	if (!g.count(k)) return;
	vector<long long> v = g[k];
	for (int i = 0; i < v.size(); ++i) {
		if (!a[v[i]]) {
			a[v[i]] = true;
			dfs(g, a, v[i]);
		}
	}
}

void inaccessible(map<long long, vector<long long> > &g, const long long &n, long long k) {
	vector<bool> a(n + 1, false);
	dfs(g, a, k);
	vector<long long> unaccessed;
	for (int i = 1; i <= n; ++i) {
		if (!a[i]) unaccessed.push_back(i);
	}
	cout << unaccessed.size();
	for (int i = 0; i < unaccessed.size(); ++i) {
		cout << " " << unaccessed[i];
	}
	cout << endl;
}

int main() {
	long long n;
	while (cin >> n) {
		if (!n) return 0;
		map<long long, vector<long long> > g;
		long long m;
		while (cin >> m) {
			if (!m) break;
			long long k;
			vector<long long> v;
			while (cin >> k) {
				if (!k) break;
				v.push_back(k);
			}
			g[m] = v;
		}
		cin >> m;
		while (m--) {
			long long k;
			cin >> k;
			inaccessible(g, n, k);
		}
	}
}
