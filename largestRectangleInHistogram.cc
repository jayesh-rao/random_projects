#include <iostream>
#include <vector>

using namespace std;

#define max(a, b, c) (a > b ? ((a > c) ? a : c) : (b > c) ? b : c)

int findMin(vector<int>& h, int s, int e) {
    int hmin = s;
    for (int i = s; i < e; i++) {
        if (h[i] < h[hmin])
            hmin = i;
    }
    return hmin;
}

int maxRect(vector<int>& h, int s, int e) {
    if (s > e) return 0;
    if (s == e) return h[s];
    int hmin = findMin(h, s, e);
    return max(h[hmin]*(e-s+1), maxRect(h, s, hmin-1), maxRect(h, hmin+1, e));

}

int main() {
    vector<int> h = {10, 40, 30, 70, 10, 30, 60};

    cout << "\nMax rectangle: " << maxRect(h, 0, h.size() - 1);
    cout << "\n";


}
