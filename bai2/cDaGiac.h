#ifndef CDAGIAC_H
#define CDAGIAC_H

#include"cDiem.h"
#include<vector>
#include<string>

class cDaGiac
{
private:
    int n;
    std::vector<cDiem> points;
public:
    cDaGiac() {}
    void Nhap();
    void Xuat() const;
    std::string PhanLoai() const;
    double TinhChuVi() const;
    double TinhDienTich() const;
    cDaGiac TinhTien(double dx, double dy) const;
    cDiem TrongTam() const; //day la ham tien ich nen em ko de vao diagram nha<3
    cDaGiac PhongTo(double k) const;
    cDaGiac ThuNho(double k) const;
    cDaGiac Quay(double rad) const;
    ~cDaGiac() {}
};

#endif