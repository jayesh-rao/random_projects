#include <iostream>
#include <vector>

class Tree {

public:
    Tree(int v) : v(v), l(nullptr), r(nullptr), ht(1) {}
    Tree() {}
    
    int v;
    Tree *l;
    Tree *r;
    int ht;
    int height() {
        auto lh = l ? l->ht : 0;
        auto rh = r ? r->ht : 0;
        return std::max(lh, rh);
    }
};
