#include"cListNhanVienSX.h"
#include<algorithm>

using namespace std;

std::istream& operator>>(std::istream& in, cListNhanVienSX& l) {
    int n; in >> n;
    in.ignore();
    l.list.resize(n);
    for (int i = 0; i < n; i++) {
        in >> l.list[i];
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const cListNhanVienSX& l) {
    int n = l.list.size();
    for (int i = 0; i < n; i++) {
        out << "\n" << i + 1 << "\t" << l.list[i];
    }
    return out;
}

cNhanVienSX cListNhanVienSX::luongThapNhat() const {
    return *min_element(list.begin(), list.end());
}

cNhanVienSX cListNhanVienSX::tuoiCaoNhat() const {
    return *min_element(list.begin(), list.end(), 
            [] (const cNhanVienSX& a, const cNhanVienSX& b) {
                return a.getNgaySinh() < b.getNgaySinh();
            });
}

double cListNhanVienSX::tongLuong() const {
    double tong = 0;
    for (const auto& nv : list)
        tong += nv.getLuong();
    return tong;
}

void cListNhanVienSX::sapXepTangDan() {
    sort(list.begin(), list.end());
}