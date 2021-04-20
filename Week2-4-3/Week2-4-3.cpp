#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

void Add(set<pair<string,string>>& res, string word1, string word2) {
	res.insert({{word1},{word2}});
}

void Count(set<pair<string, string>>& res, string word) {
	int c = 0;
	for (auto i : res) {
		if ((i.first == word) || (i.second == word))
			c++;
	}
	cout << c << endl;
}

void Check(set<pair<string, string>>& res, string word1, string word2) {
	if ((res.count({word1,word2}) != 0)|| (res.count({ word2,word1 }) != 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	int N=100;
	string line, command, str1, str2;
	set<pair<string, string>> res;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		getline(cin, line);
		stringstream ss(line);
		ss >> command;
		ss >> str1;
		if (ss.good())
			ss >> str2;
		if (command == "ADD") {
			Add(res, str1, str2);
		}
		if (command == "COUNT") {
			Count(res, str1);
		}
		if (command == "CHECK") { 
			Check(res, str1, str2);
		}

	}
}
