#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;


template<typename T>
class MyRange {
public:
    MyRange(T begin, T end) : b_(begin), e_(end) {}
    MyRange(const MyRange &r) : b_(r.b_), e_(r.e_) {}
    //MyRange() : b_(static_cast<T>(0)), e_(static_cast<T>(0)) {}

    class Iter {
        public:
            friend class MyRange;
            T operator *() {return it_;}
            Iter operator ++() { ++it_ ; return *this; }
            Iter operator --() { --it_ ; return *this; }
            Iter operator ++(int) {Iter temp(*this); ++it_; return temp;}
            Iter operator --(int) {Iter temp(*this); --it_; return temp;}
            bool operator ==(const Iter &rhs) { return it_ == rhs.it_;}
            bool operator !=(const Iter &rhs) { return it_ != rhs.it_;}
            bool operator >(const Iter &rhs) { return it_ > rhs.it_;}
            bool operator <(const Iter &rhs) { return it_ < rhs.it_;}
            bool operator <=(const Iter &rhs) { return it_ <= rhs.it_;}
            bool operator >=(const Iter &rhs) { return it_ >= rhs.it_;}
        protected:
            Iter(T val) : it_(val) {}
        private:
            T it_;
    };

    Iter begin() const { return b_;}
    Iter end() const { return e_;}

    // Making stuffs physical, basically unpack the range
    // and "realize" each element.
    vector<T> realize() {
        res_.clear();
        //for ( auto e: *this) res_.push_back(e);
        for (auto i = b_; i < e_; i++) res_.push_back(*i);
        return res_;
    }

    vector<T> res() {
        return res_;
    }

    void set_res(vector<T> e) { res_ = e;}
    T data(int idx) { return res_[idx];}

    template<typename F>
    MyRange<T> *transform(F func);

private:
    Iter b_;
    Iter e_;
    vector<T> res_;
};

template<typename T>
template<typename F>
MyRange<T> *MyRange<T>::transform(F func) {
    MyRange<T> *new_range = new MyRange<T>(*this);
    //func();
    auto new_vec = new_range->realize();
    auto cur_vec = this->res();
    std::transform(cur_vec.begin(), cur_vec.end(), new_vec.begin(), func);
    //std::transform(this->res().begin(), this->res().end(), new_range->res().begin(), func);
    new_range->set_res(new_vec);
    return new_range;
}

int main() {
#if 0
    vector<int> v1 = {1,2,3,4,5,6,7,8};
    vector<int> v2(v1.size());

    transform(v1.begin(), v1.end(), v1.begin(), [](int const &e) { return 2*e;});
    copy_if(v1.begin(), v1.end(), v2.begin(), [](int const &e) { return !(e & (e-1));});
    for (auto &e: v2) cout << "\n" << e;

    MyRange<double> r1(1.1, 20.2);
    for (auto i = r1.begin(); i <= r1.end(); i++) cout << "\n" << *i;
    
    MyRange<char> r2('a', 'z');
    for (auto i = r2.begin(); i <= r2.end(); i++) cout << "\n" << *i;
    vector<int> res = r.realize();
    for (auto &e : res) cout << endl << e;
#endif

    cout << "\n";
    MyRange<int> r(5, 10);
    for (auto e : r) cout << "\n" << e;
    r.realize();
    
    MyRange<int> *r2;
    r2 = (&r)->transform([](int const &e) -> int { return e+1;})
             ->transform([](int const &e) -> int { return e*e;});

    auto new_vec = r2->res();
    for (auto &i : new_vec) cout << "\n" << i;
    //for (auto e : r2) cout << "\n" << e;
    
    MyRange<char> cr('a', 'z');
    cr.realize();

    MyRange<char> *cr2 = cr.transform([](char const &c) -> char { return toupper(c);});
    auto new_vec2 = cr2->res();
    for (auto &i : new_vec2) cout << "\n" << i;
}
