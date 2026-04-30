#include"cNhanVienVP.h"
#include<iomanip>

std::istream& operator>>(std::istream& in, cNhanVienVP& nv) {
    std::getline(in, nv.maNV);
    std::getline(in, nv.hoTen);
    in >> nv.ngaySinh >> nv.luong;
    in.ignore();
    return in;
}

std::ostream& operator<<(std::ostream& out, const cNhanVienVP& nv) {
    out << nv.maNV << "| " << nv.hoTen << " | " << nv.ngaySinh << " | "
        << std::fixed << std::setprecision(2) << nv.luong;
    return out;
} 