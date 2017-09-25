#include <iostream>
#include <string>

using namespace std;
int main() {
    string s("my name is jayesh");
    std::reverse(s.begin(), s.end());
    s.split(" ");
    cout << s;
}
