

#include <iostream>
#include <deque>
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

void spiral(Tree *t) {
    if (!t) return;
    deque<Tree *> q;
    q.push_back(t);
    int c1 = 1, c2 = 0;
    bool rtol = true;
    while (!q.empty()) {
        Tree *tmp;
        if (rtol) {
            tmp = q.front();
            q.pop_front();
        } else {
            tmp = q.back();
            q.pop_back();
        }
        --c1;
        if (rtol) {
            if (tmp->r) {++c2; q.push_back(tmp->r);}
            if (tmp->l) {++c2; q.push_back(tmp->l);}
        } else {
            if (tmp->l) {++c2; q.push_front(tmp->l);}
            if (tmp->r) {++c2; q.push_front(tmp->r);}
        }

        if (c1 == 0) {
            swap(c1, c2);
            rtol = !rtol;
        }
        
        cout << endl << tmp->v;
    }
}

void spiral_without_q_util(Tree *t, int cur, int req, bool ltor) {
    if (!t) return;
    if (cur == req) { cout << endl << t->v; return; }
    if (ltor) {
        spiral_without_q_util(t->l, cur-1, req, ltor);
        spiral_without_q_util(t->r, cur-1, req, ltor);
    } else {
        spiral_without_q_util(t->r, cur-1, req, ltor);
        spiral_without_q_util(t->l, cur-1, req, ltor);
    }
    
}

void spiral_without_q(Tree *t) {
    int len = t->ht;
    bool ltor = true;
    for(int i = len; i > 0; i--) {
        ltor = !ltor;
        spiral_without_q_util(t, len, i, ltor);
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 10, 12, 55, 101};
    //vector<int> v = {1};
    Tree *root = generate(v, 0, v.size()-1);
    preorder(root);
    cout << endl << endl << "spiral .. " << endl;
    spiral(root);
    cout << endl << endl << "spiral without Q... " << endl;
    spiral_without_q(root);
    cout << endl;
}
