#include<iostream>
#include <string>

using namespace std;

string
reverseWords(const string& s) {
    string rev(s.rbegin(), s.rend());
    return rev;
}



int main() {
    string s = "sky is blue today";
    cout << endl << reverseWords(s);
    cout << endl;
}
