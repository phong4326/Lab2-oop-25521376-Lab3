#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include"cDay.h"
#include<iostream>
#include<string>

class cNhanVienSX
{
private:
    std::string maNV, hoTen;
    cDay        ngaySinh;
    int         soSanPham;
    double      donGia;
public:
    cNhanVienSX(): maNV(""), hoTen(""), soSanPham(0), donGia(0) {}
    cNhanVienSX(const std::string& maNV, const std::string& hoTen, 
                const cDay& ngaySinh, int soSanPham, double donGia)
    : maNV(maNV), hoTen(hoTen), ngaySinh(ngaySinh), soSanPham(soSanPham), donGia(donGia) {}

    //Getter
    std::string getMaNV()     const { return maNV; }
    std::string getHoTen()    const { return hoTen; }
    cDay        getNgaySinh() const { return ngaySinh; }
    int         getSoSanPham()const { return soSanPham; }
    double      getDonGia()   const { return donGia; }
    double      getLuong()    const { return soSanPham * donGia; }
 
    // Setter
    void setMaNV(const std::string& s)  { maNV = s; }
    void setHoTen(const std::string& s) { hoTen = s; }
    void setNgaySinh(const cDay& d)     { ngaySinh = d; }
    void setSoSanPham(int sp)           { soSanPham = sp; }
    void setDonGia(double dg)           { donGia = dg; }

    friend std::istream& operator>>(std::istream& in, cNhanVienSX& nv);
    friend std::ostream& operator<<(std::ostream& out, const cNhanVienSX& nv);

    bool operator<(const cNhanVienSX& o) const { return getLuong() < o.getLuong(); }
    bool operator>(const cNhanVienSX& o) const { return o < *this; }

    ~cNhanVienSX(){}
};

#endif
