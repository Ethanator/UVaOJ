#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

int compare(pair<char, int> a, pair<char, int> b) {
	if (a.second > b.second) return true;
	if (a.second < b.second) return false;
	return a.first < b.first;
}

int main() {
	unsigned long long n;
	cin >> n;
	string s;
	getline(cin, s);
	pair<char, int> count[26];
	while (n--) {
		getline(cin, s);
		for (int i = 0; i < s.size(); ++i) {
			if (isalpha(s[i])) {
				int c = toupper(s[i]) - 'A';
				count[c].first = toupper(s[i]);
				count[c].second++;
			}
		}
	}
	sort(count, count + 26, compare);
	for (int i = 0; i < 26; i++) {
		if (!count[i].second) break;
		cout << count[i].first << " " << count[i].second << endl;
	}
}
