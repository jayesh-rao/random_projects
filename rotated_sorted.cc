#include <iostream>
#include <vector>

using namespace std;
#if 1
int transition_point(vector<int> a) {
    int l = 0;
    int h = a.size() - 1;
    //int mid = (l+h)/2; // l+h can lead to overflow
    int mid;
    while (l <= h) {
        mid = l + (h-l)/2;
        if (a[mid] < a[mid+1] && a[mid-1] < a[mid]) {
            if (a[l] < a[mid])
                l = mid+1;
            else h = mid-1;
        } else if (a[mid] > a[mid+1]) {
            return mid;
        } else if (a[mid] < a[mid+1]){
            return mid-1;
        }
    }
    return -1;
}
#endif

int bsearch(vector<int> a, int l, int h, int k) {
    if (l > h) return -1;
    int mid = l + (h-l)/2;
    if (k == a[mid]) return mid;
    if (k > a[mid]) return bsearch(a, mid+1, h, k);
    if (k < a[mid]) return bsearch(a, l, mid-1, k);
    return -1;
}

int main() {
    //std::vector<int> vec = {8,1,2,3, 4, 5, 6, 7};
    std::vector<int> vec = {8, 9, 10, 11, 1,2,3, 4, 5, 6, 7};
    //std::vector<int> vec = {4,8,1};
    auto tp = transition_point(vec);
    cout << tp << endl;
    if (tp == -1) {
        // sorted array perhaps!!
        return 1;
    }
    cout << "\n Transition point: " << tp << endl;
    int key = 18;
    int ret;
    if (key == vec[tp]) { cout << "Found at " << tp << endl; return 1; }
    if (key < vec[0])
        ret = bsearch(vec, tp+1, vec.size()-1, key);
    if (key > vec[0])
        ret = bsearch(vec, 0, tp, key);
    if (ret == -1)
        cout << "Not found the element..";
    else
        cout << "\n found at .." << ret;

    cout << endl;
    std::vector<int> a = {1, 2, 3, 4, 5,6 ,7, 8, 9};
    cout << bsearch(a, 0, a.size()-1, 8);
    return 1;

}
