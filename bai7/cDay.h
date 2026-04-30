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
        if (y != o.y) return y < o.y; // bat dau so sanh tu nam
        if (m != o.m) return m < o.m; // neu nam bang nhau thi ss thang roi toi ngay
        return d < o.d;
    } // sau se cos getter lay ra va dung cho method so sanh
 
    friend std::istream& operator>>(std::istream& in, cDay& date) {
        in >> date.d >> date.m >> date.y;
        return in;
    }
 
    friend std::ostream& operator<<(std::ostream& out, const cDay& date) {
        out << date.d << "/" << date.m << "/" << date.y;
        return out; //in ra theo fomart d/m/y
    }
 
    ~cDay() {}
};

#endif