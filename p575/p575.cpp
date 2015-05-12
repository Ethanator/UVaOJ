#include<iostream>
using namespace std;

long decim(string s){
	long res = 0;
	long unit = 1;
	for (int i = s.size()-1; i >=0; i--) {
		res += (s[i] - '0') * unit;
		unit = unit * 2 + 1;
	}
	return res;
}

int main() {
	string s;
	while (cin >> s) {
		if (s == "0") break;
		cout << decim(s) << endl;
	}
}
