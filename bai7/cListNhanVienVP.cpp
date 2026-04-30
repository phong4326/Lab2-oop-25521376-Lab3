#include"cListNhanVienVP.h"
#include<algorithm>

using namespace std;

std::istream& operator>>(std::istream& in, cListNhanVienVP& l) {
    int n; in >> n;
    in.ignore();
    l.list.resize(n);
    for (int i = 0; i < n; i++) {
        in >> l.list[i];
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, cListNhanVienVP& l) {
    int n = l.list.size();
    for (int i = 0; i < n; i++) {
        out << "\n" << i + 1 << "\t" << l.list[i];
    }
    return out;
}

cNhanVienVP cListNhanVienVP::luongCaoNhat() const {
    if (list.empty()) return cNhanVienVP();
    return *max_element(list.begin(), list.end());
}

cNhanVienVP cListNhanVienVP::tuoiCaoNhat() const {
    // tuoi lon nhat = ngaySinh nho nhat
    return *min_element(list.begin(), list.end(), //viet them mot lambda
        [] (const cNhanVienVP& a, const cNhanVienVP& b){
            return a.getNgaySinh() < b.getNgaySinh();
        });
}

double cListNhanVienVP::tongLuong() const {
    double tong = 0;
    for (const auto& nv : list) {
        tong += nv.getLuong();
    }// cong don co ban
    return tong;
}

void cListNhanVienVP::sapXepTangDan() {
    sort(list.begin(), list.end());
}