#include <iostream>
#include <set>
#include <cstdlib>
#include <time.h>
#include<cmath>

using namespace std;

#define N 10
#define PI 3.14159

class Point {
public:
    Point() : x_(0), y_(0) {} // origin by-default
    explicit Point(double x, double y) : x_(x), y_(y) {
        tt_ = atan(y_/x_) * 180/PI;
    }
    Point(const Point& rhs)
    : x_(rhs.x_)
    , y_(rhs.y_)
    , tt_(rhs.tt_) {}

    Point(double angle) : x_(0), y_(0), tt_(angle) {}

    double x() { return x_;}
    double y() { return y_;}

    void set_x(double x) { x_ = x;}
    void set_y(double y) { y_ = y;}

    double angle() const { return tt_;}

    friend ostream & operator << (ostream &strm, const Point &obj);

private:
    double x_, y_;
    double tt_;
};

ostream & operator << (ostream &strm, Point& obj)
{
    strm << obj.x() << " " << obj.y() << " " << obj.angle();
    return strm;
}

struct custom_compare {
    bool operator() (const Point& lhs, const Point& rhs) const { return lhs.angle() < rhs.angle();}
};

double myrand() {
    return static_cast<double>(rand()) / static_cast<double>(RAND_MAX/N);
}

int main() {
    srand(time(NULL));

    set<Point, custom_compare> Points;
    for (auto i = 0; i < N; i++) {
        Points.insert(Point(myrand(), myrand()));
    }

    int angle = 1 + rand() % 31;

    int max_count = 0, ret_angle = 0;
    for (auto slide_window = 0; slide_window <= 360; slide_window += angle) {

        Point lb(slide_window);
        Point ub(slide_window + angle);

        set<Point, custom_compare> sw_set;
        sw_set.insert(Points.lower_bound(lb), Points.upper_bound(ub));
        auto count = sw_set.size();

        if (count > max_count) {
            max_count = count;
            ret_angle = slide_window;
        }

    }

    for (auto e : Points) cout << endl << e;

    cout << "\nmax viewing angle: " << ret_angle << endl << "Count: " << max_count << endl << "original angle: " << angle;
    return 0;
}
