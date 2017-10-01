#include <iostream>

#include "tree.h"

using namespace std;

Tree* generate(std::vector<int> &n, int lo, int hi) {
    if (lo > hi) return nullptr;
    int m = lo + (hi-lo)/2;
    Tree *root = new Tree(n[m]);
    root->l = generate(n, lo, m-1);
    root->r = generate(n, m+1, hi);
    root->ht = 1 + root->height();
    return root;
}

void preorder(Tree *t) {
    if (!t) return;
    cout << endl << t->v << "    " << t->ht;
    preorder(t->l);
    preorder(t->r);
}

Tree *lca(Tree *t, int n1, int n2) {
    if (!t) return nullptr;
    if (t->v == n1) return t;
    if (t->v == n2) return t;
    auto l = lca(t->l, n1, n2);
    auto r = lca(t->r, n1, n2);
    if (l && r) return t;
    return l ? l : r;
}

int distance(Tree *t, int n) {
    if (!t) return 0;
    if (t->v == n) return 1;
    int l = distance(t->l, n);
    if (l > 0) return 1 + l;
    int r = distance(t->r, n);
    if (r > 0) return 1 + r;
    return 0;
}

int main() {

    vector<int> v = {1, 2, 3, 4, 5, 6, 10, 12, 55, 101};
    //vector<int> v = {1};
    Tree *root = generate(v, 0, v.size()-1);
    preorder(root);
    int n1 = 12, n2 = 101;
    Tree *lcap = lca(root, n1, n2);
    cout << "\nLCA : " << lcap->v << endl;
    cout << "Distance : " << distance(lcap, n1) + distance(lcap, n2) - 2<< endl;
}
