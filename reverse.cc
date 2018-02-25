/*
* problem:
* input => a string of words
* o/p => reveresed words
* ex: hello world ==> world hello
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void
reverseWords(const string& s) {
    string rev(s.rbegin(), s.rend());

    istringstream iss(rev);
    vector<string> words{istream_iterator<string>(iss), istream_iterator<string>()};
    int c = words.size() - 1;

    for (auto &word : words) {
    	cout << string(word.rbegin(), word.rend());
    	if (c-- > 0) cout << " ";

    }

    //return s;
}



int main() {
    string s = "sky is blue today";
    reverseWords(s);
    //cout << endl << reverseWords(s);
    cout << endl;
}
