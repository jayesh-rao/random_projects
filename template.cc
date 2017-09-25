#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class Generic {
public:
    Generic() = default;
    T get() { return data_;}

    void set(T const &ele);
private:
    T data_;
};

template <class T>
void Generic<T>::set(T const &ele) {
    data_ = ele;
}

int main() {
    cout << "\n Template demo..\n";
    Generic<int> o1;
    o1.set(5);
    cout << "\n data: " << o1.get() << endl;

    Generic<string> s1;
    s1.set("Jayesh");
    cout << "\n data: " << s1.get() << endl;
}
