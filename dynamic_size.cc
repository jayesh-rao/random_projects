#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> v;

	//v.reserve(5);
	for (int i = 0; i < 5; i++) {
		v.push_back(vector<int>());
	}

	v[0].push_back(1);
	cout << "\n" << v[0].size();
}