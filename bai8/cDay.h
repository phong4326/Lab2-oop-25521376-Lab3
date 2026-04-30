#ifndef CDAY_H
#define CDAY_H

#include<iostream>

class cDay
{
private:
    int d, m, y;
public:
    cDay(int d = 1, int m = 1, int y = 1) : d(d), m(m), y(y) {}
 
    // int getDay()   const { return d; }
    // int getMonth() const { return m; }
    // int getYear()  const { return y; }
    // So sanh ngay sinh: nho hon = sinh truoc = tuoi cao hon
    bool operator<(const cDay& o) const {
        if (y != o.y) return y < o.y;
        if (m != o.m) return m < o.m;
        return d < o.d;
    }
 
    friend std::istream& operator>>(std::istream& in, cDay& date) {
        in >> date.d >> date.m >> date.y;
        return in;
    }
 
    friend std::ostream& operator<<(std::ostream& out, const cDay& date) {
        out << date.d << "/" << date.m << "/" << date.y;
        return out;
    }
 
    ~cDay() {}
};

#endif