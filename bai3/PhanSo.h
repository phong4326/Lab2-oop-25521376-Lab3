#ifndef PHANSO_H
#define PHANSO_H

#include<iostream>
#include<cmath>

class PhanSo 
{
private:
    int x, y;
    friend class cDSPhanSo;
    int gcd(int a, int b) {
        a = std::abs(a); b = std::abs(b);
        return (b) ? gcd(b, a%b) : a;
    }
public:
    PhanSo(int x = 0, int y = 1) : x(x), y(y) {}
    void Nhap();
    void Xuat() const;
    PhanSo RutGon();
    PhanSo Cong(const PhanSo& p) const;
    bool operator<(const PhanSo& p) const;
    bool operator>(const PhanSo& p) const;
    ~PhanSo() {}
};

#endif