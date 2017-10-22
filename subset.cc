#include <iostream>
#include <vector>

using namespace std;

void print_ans(std::vector<int> ans) {
    for (auto &e : ans) cout << e << " ";
    cout << endl;
}

void f1(std::vector<int> arr, int ht, std::vector<int> ans) {
    if (arr.size() == ht) print_ans(ans);
    else {
        f1(arr, ht+1, ans);
        ans.push_back(arr[ht]);
        f1(arr, ht+1, ans);
    }
}

int main() {
    f1({1, 2, 3}, 0, {});
}
