#include <iostream>
#include <cstdint>
#include <limits>
#include <cmath>

#define MAX std::numeric_limits<std::uint32_t>::max()

class Num {
public:
    Num(uint32_t n)
    : n_(n) {
        uint32_t c = 0;
        while(n) {
            c++;
            n /= 10;
        }
        digs_ = c;
    }
    uint32_t digs() { return digs_;}
    uint32_t n() {return n_;}
    uint32_t dig(uint32_t pos) {
        return (n_/(uint32_t)pow(10, pos-1)) % 10;
    }

    uint32_t dig(uint32_t pos, uint32_t num) {
        return (num/(uint32_t)pow(10, pos-1)) % 10;
    }

    uint32_t immi_big(uint32_t pos) {

        uint32_t val = dig(pos);
        uint32_t delta = MAX;
        uint32_t loc = pos-1;
        for (uint32_t i = pos-1; i > 0; i--) {
            if (dig(i) > val) {
                if (delta > (dig(i) - val)) {
                    loc = i;
                    delta = dig(i) - val;
                }
            }
        }
        //std::cout << "\n next big: " << loc << " for pos: " << pos;
        return loc;
    }

    uint32_t pivot() {
        for (uint32_t i = 1; i <= digs_; i++) {
            if (dig(i) > dig(i+1)) {
                if (i == digs_) return -1;
                return i+1;
            }
        }
        //std::cout << "\n there there";
        return -1;
    }


    uint32_t min_dig(uint32_t pos, uint32_t x) {
        uint32_t dmin = MAX;
        for (uint32_t i = pos; i > 0; i--) {
            if (dig(i, x) < dmin) {
                dmin = dig(i, x);
            }
        }
        return (dmin != MAX) ? dmin : 0;
    }

    uint32_t gen(uint32_t pos, uint32_t x) {
        uint32_t sum = 0;
        uint32_t part = x;
        for (uint32_t i = pos; i > 0; i--) {
            sum += min_dig(i, part)*((uint32_t)pow(10, i-1));
     //       std::cout << "\n part: " << part << " sum: " << sum;
            part /= 10;
        }
        return sum;
    }

    uint32_t kinda_swap(uint32_t tp, uint32_t loc) {
        uint32_t sum = dig(loc) * ((uint32_t)pow(10, tp-1));
        uint32_t m = 0;
        for (uint32_t i = tp-1; i>0; i--) {
            if (i == loc) m = dig(tp);
            else m = dig(i);
            sum += (m * ((uint32_t)pow(10, i-1)));
        }
     //   std::cout << "\n partial swapped sum: " << sum;
        return sum;
    }


    uint32_t next_lex() {
        //uint32_t pivot = dig(1); // last digit
        uint32_t tp = pivot();
        std::cout << "\nNum: " << n_;
        if(tp==-1) return n_;
        uint32_t loc = immi_big(tp);
        // swap loc with tp
        uint32_t rem = kinda_swap(tp, loc);
        rem = rem - rem % ((uint32_t)pow(10, tp-1)) + gen(tp-1, rem);
        //std::cout << "\n after swap: " << rem;
        uint32_t x = n_ - n_ % ((uint32_t)pow(10, tp)) + rem;
        return x;

        //gen(loc);
    }
private:
    uint32_t n_;
    uint32_t digs_;
};

int main() {
    Num n1(3621);
    std::cout << "\n Next lex: " << n1.next_lex() << "\n";

}
