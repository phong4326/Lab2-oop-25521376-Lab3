#ifndef CDAY_H
#define CDAY_H

#include<iostream>

class cDay
{
private:
    int d, m, y;
public:
    cDay(int d = 1, int m = 1, int y = 1) : d(d), m(m), y(y) {}
    friend std::istream& operator>>(std::istream& in, cDay& date) {
        in >> date.d >> date.m >> date.y;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out, const cDay& date) {
        out << date.d << "/" << date.m << "/" << date.y;
        return out;
    }
    // const cDay& getDay() const { return d; }
    // const cDay& getMounth() const { return m; }
    // const cDay& getYear() const { return y; }
    ~cDay() {};
};

#endif