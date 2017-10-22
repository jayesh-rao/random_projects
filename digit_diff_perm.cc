#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int prev(int piv) { return piv - 1;}
int next(int piv) { return piv + 1;}

void f(int piv, int len, int cur, vector<int> ans)
{
    if (cur == len) {
        print_vec(ans);
        return;
    }

    if (piv <= -1 || piv >= 10) return;

    ans.push_back(piv);
    f(prev(piv), len, cur + 1,ans);
    f(next(piv), len, cur + 1, ans);
}

int main() {
    for (int dig = 3; dig < 4; dig++) {
        for (int piv = 1; piv < 10; piv++) {
            f(piv, dig, 0, {});
        }
    }
}
