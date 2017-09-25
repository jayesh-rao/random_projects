#include <iostream>
#include<vector>

using namespace std;

template<typename T>
class Heap {
private:
    vector<T> h_;
protected:
    void heapify();
    // util functions
    int right(int parent) {
        int ret = 2*parent+2;
        return (ret >= size() ? -1 : ret);
    }
    int left(int parent) { 
        int ret = 2*parent+1;
        return (ret >= size() ? -1 : ret);
    }
    int size() { return h_.size();}
    int max(int i, int j) {
        if (i == -1 && j == -1) return -1;
        if (i == -1) return j;
        if (j == -1) return i;
        return h_[i]>=h_[j] ? i : j;
    }

    void display() { for (auto &e : h_) cout << endl << e; }
    void bubble_down(int index);
public:
    // heap operations
    // insert, remove
    template<typename F>
    void insert(T job, F completion_handler);
    
    template<typename F>
    const T& remove(F completion_handler);
    Heap() {}
    Heap(vector<T> input) {
        h_ = input;
        heapify();
    }
};

template<typename T>
void
Heap<T>::heapify() {
    cout << endl << "Heapfiying...";
    // start from last node and make up the way
    // keep doing till all the parents are visited
    for (int i = size()-1; i >= 0; --i) {
        bubble_down(i);
    }
    // start from the lowest parent
    display();
}

// compare and swap with the max(left, right)
template<typename T>
void
Heap<T>::bubble_down(int i) {
    int max_child = max(left(i), right(i));
    if (max_child == -1) return;
    if (h_[i] < h_[max_child]) { 
        std::swap(h_[i], h_[max_child]);
        bubble_down(max_child);
    }
}

// Driver function
int main() {
    Heap<int> *h = new Heap<int>({1, 11, 22, 33, 44});
    return 0;
}
