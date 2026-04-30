#include"PhanSo.h"

using namespace std;

void PhanSo::Nhap() {
    do {
        std::cin >> x >> y;
    } while (y == 0);

    *this = RutGon();
}

void PhanSo::Xuat() const{
    if (x % y == 0) std::cout << x/y;
    else std::cout << x << "/" << y;
}
    
PhanSo PhanSo::RutGon() {
    if (y < 0) return PhanSo(-x/gcd(x, y), -y/gcd(x, y));
    return PhanSo(x/gcd(x, y), y/gcd(x, y));
}

PhanSo PhanSo::Cong(const PhanSo& p) const {
    PhanSo ans;
    ans.x = x * p.y + p.x * y;
    ans.y = y * p.y;
    return ans.RutGon();
}

bool PhanSo::operator<(const PhanSo& p) const{
    return x * p.y < y * p.x;
}

bool PhanSo::operator>(const PhanSo& p) const {
return x * p.y > p.x * y;
}