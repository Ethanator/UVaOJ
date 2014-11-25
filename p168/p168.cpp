/* p168.cpp
 * Solution to the problem on: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=104
 * 	     Author: Yuxuan "Ethan" Chen
 *   Start Time: 3:55 PM, Tuesday, November 25, 2014
 *     End Time:
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct labyrinth {
	map<char, vector<char> > graph;
	map<char, bool> lit;
};

vector<string> split(const string &s, char delim) {
	vector<string> res;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		res.push_back(item);	
	}
	return res;
}

labyrinth build_labyrinth(string s) {
	labyrinth res;
	vector<string> v = split(s, ';');
	for (int i = 0; i < v.size(); ++i) {
		string e = v[i];
		vector<char> p;
		for (int j = 2; j < e.size(); ++j) {
			p.push_back(e[j]);
		}		
		res.graph[e[0]] = p;
		res.lit[e[0]] = false;
	}
	return res;
}

void traverse_labyrinth(labyrinth l, char m, char t, int k) {
	int count_step = 0;	
	bool first_output = true;

	while (1) {
		vector<char> next = l.graph[m];
		bool moved = false;
		for (int i = 0; i < next.size(); ++i) {
			if (next[i] == t || l.lit[next[i]]) continue;
			t = m;
			m = next[i];
			++count_step;
			if (count_step == k) {
				count_step = 0;
				l.lit[t] = true;
				if (first_output) { first_output = false; } else { cout << " "; }
				cout << t;
			}
			moved = true;
			break;
		}
		if (!moved) {
			if (first_output) { first_output = false; } else { cout << " "; }
			cout << "/" << m << endl;
			return;
		}
	}
}

int main() {
	string line; 
	char m, t; 
	long k;

	while (getline(cin, line)) {
		if (line == "#") break;
		vector<string> in = split(line, ' ');
		labyrinth l = build_labyrinth(in[0].substr(0, in[0].size() - 1));
		traverse_labyrinth(l, in[1][0], in[2][0], atoi(in[3].c_str()));
    }
}
