#ifndef CDIEM_H
#define CDIEM_H

#include <iostream>

class cDiem {
private:
    double x, y;

    // cho phep lop cTamGiac truy cap truc tiep vao x, y
    friend class cDaGiac; 

public:
    cDiem(double x = 0, double y = 0) : x(x), y(y) {}

    void Nhap() {
        std::cin >> x >> y;
    }

    void Xuat() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

#endif