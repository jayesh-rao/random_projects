#include <iostream>
#include <math.h>

using namespace std;

int num_digits(int n) {
    int d = 0;
    while (n) {
        d++;
        n /= 10;
    }
    cout << endl << "num of digits :" << d;
    return d;
}

bool is_pali(int n) {
    auto t = n;
    int dig = num_digits(n);
    int sum = 0;
    int deci = 10;

    while (t) {
        int r = t % deci;
        sum += (r * pow(deci, --dig));
        t /= deci;
    }
    cout << endl << "sum : " << sum;
    return sum == n;
}

int main() {
    int n = 13531;
    cout << endl << "Entered Num: " << n << endl;
    string str;
    is_pali(n) ? str = " is a " : str = " is not a ";
    cout << endl << n << str << "palindrome" << endl;
}
