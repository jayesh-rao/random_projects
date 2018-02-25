
/*
 * Problem:
 * input => a1a2a3a4...anb1b2b3b4...bn
 * output => a1b1a2b2a3b3..anbn
 *
 * Constarint: Inplace update
 */

#include <string>
#include <iostream>

using namespace std;


// a1a2a3a4b1b2b3b4
// 
// a1a2b1a3b2b3
//   !   ^
// a1b1a2 

void rearrange(string &s) {

	size_t sz = s.size(); // 20
	size_t mid = sz/2; // 10

	int pair_swaps = mid/2 - 1; // 4

	if (pair_swaps < 1) return;

	cout << "\nBefore processing: " << s << "  pair_swaps: " << pair_swaps;

	for (int i = 1; i <= pair_swaps; i++) {
		int s_pos = mid - 2*i;
		int e_pos = mid + 2*(i-1);
		cout << "\n Start pos: " << s_pos << "  End pos: " << e_pos;
		for (int j = s_pos; j <= e_pos; j++) {
			char tmp = s[j+2];
			s[j+2] = s[j];
			s[j] = tmp;
			if (j%2) j+=2;



		}
		cout << "\n intermediate processing: " << s;

	}

	cout << "\nAfter processing: " << s;
}

int main(int argc, char *argv[]) {

	string s = "a1a2a3a4a5a6b1b2b3b4b5b6";
	rearrange(s);
	cout << "\n HelloWorld";
}
