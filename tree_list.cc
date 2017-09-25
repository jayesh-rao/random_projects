#include <iostream>
using namespace std;

class Tnode {
private:
    Tnode *l, *r;
    int d;
public:
    Tnode(int d) : d(d), l(NULL), r(NULL) {}
    void add(int v);
    void display();
};

void
Tnode::add(int v) {
    //auto tmp = new Tnode(v);

    if (this->d >= v) {
        if (this->l)
            this->l->add(v);
        else
            this->l = new Tnode(v);
    } else {
        if (this->r)
            this->r->add(v);
        else
            this->r = new Tnode(v);
    }
}

void
Tnode::display() {
    if (this == NULL) { return; }
    if (this->l == NULL && this->r == NULL) { cout << this->d << endl; return;}
    this->l->display();
    cout << this->d << endl;
    this->r->display();
    return;
}

int main() {
    Tnode *tree = new Tnode(6);
    tree->add(4);
    tree->add(8);
    tree->add(12);
    tree->display();
    return 0;
}
