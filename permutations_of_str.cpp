/*
* print all permutations of a given string
* (doesnt handle repetiton)
*/


#include <iostream>
#include <string>

using namespace std;


/*
* p("", "abc") --> 
p("a", "bc")

*/

void
permutations(string processed, string to_process) {
	if (to_process.size() == 0) cout << "\n" << processed;

	else {
		for(int i = 0; i < to_process.size(); i++) {
			permutations(processed + to_process[i], to_process.substr(0, i) + to_process.substr(i+1, to_process.size()));
		}
	}

}

int main() {
	string s = "abc";
	permutations("", s);
	cout << "\n";
}