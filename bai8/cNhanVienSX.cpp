#include"cNhanVienSX.h"
#include<iomanip>

std::istream& operator>>(std::istream& in, cNhanVienSX& nv) {
    std::getline(in, nv.maNV);
    std::getline(in, nv.hoTen);
    in >> nv.ngaySinh >> nv.soSanPham >> nv.donGia;
    in.ignore();
    return in;
}

std::ostream& operator<<(std::ostream& out, const cNhanVienSX& nv) {
    out << nv.maNV << " | " << nv.hoTen << " | " << nv.ngaySinh
        << " | SP: " << nv.soSanPham
        << " | Don gia: " << nv.donGia
        << std::fixed << std::setprecision(0)
        << " | Luong: " << nv.getLuong();
    return out;
}