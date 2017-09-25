#include <iostream>
#include <functional>

using namespace std;

template <typename F>
void invoke(F func) {
    func();
}

int main() {

    invoke([](){
            cout << "in lambda" << endl;
            });
}
