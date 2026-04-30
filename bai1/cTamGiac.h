#ifndef TAMGIAC_H
#define TAMGIAC_H

#include"cDiem.h"
#include<string>

class cTamGiac {
private:
    cDiem A, B, C;
public:
    cTamGiac() {}
    cTamGiac(cDiem a, cDiem b, cDiem c) : A(a), B(b), C(c) {}
    void Nhap();
    void Xuat() const;
    std::string PhanLoai() const;
    double TinhChuVi() const;
    double TinhDienTich() const;
    cDiem TrongTam() const; //day la ham tien ich nen em ko de vao diagram nha<3
    cTamGiac TinhTien(double dx, double dy) const;
    cTamGiac PhongTo(double k) const;
    cTamGiac ThuNho(double k) const;
    cTamGiac Quay(double rad) const;
    ~cTamGiac() {}
};

#endif