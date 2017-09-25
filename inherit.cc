#include <iostream>

using namespace std;

class Par {
    protected:
        int x_;
    public:
        Par() : x_(6) { cout << "\nIn par construct.."; }
        void show_x() {
            cout << "\nhere is: " << x_;
        }
        virtual int x() { return x_; }
};

class Chi : public Par {
public:
    //int x() override { tampering_x(); return x_;}
    void tampering_x() { cout << "\nModifying..."; x_ = 10; }
};

int main() {
    Chi c1;
    c1.x();
    c1.show_x();
}
