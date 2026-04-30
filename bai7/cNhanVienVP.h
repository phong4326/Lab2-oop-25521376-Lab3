#ifndef CNHANVIENVP_H
#define CNHANVIENVP_H

#include"cDay.h"
#include<iostream>
#include<string>

class cNhanVienVP
{
private:
    std::string maNV, hoTen;
    cDay ngaySinh;
    double luong;
public:
    cNhanVienVP() : maNV(""), hoTen(""), luong(0) {}
    cNhanVienVP(const std::string& maNV, const std::string& hoTen, 
                const cDay& ngaySinh, double luong)
    : maNV(maNV), hoTen(hoTen), ngaySinh(ngaySinh), luong(luong) {}
    //Getter
    std::string getMaNV()   const { return maNV; }
    std::string getHoTen()  const { return hoTen; }
    cDay        getNgaySinh() const { return ngaySinh; } // sau dung de so sanh tuoi lon nha
    double      getLuong()  const { return luong; }
    //Setter
    void setMaNV(const std::string& s)  {maNV = s;}
    void setHoTen(const std::string& s) {hoTen = s;}
    void setNgaySinh(const cDay& d)     {ngaySinh = d;}
    void setLuong(double l)             {luong = l;}
    //phai dung gettet, setter
    //ko dung ke thua de ko pha vo Encapsulation

    friend std::istream& operator>>(std::istream& in, cNhanVienVP& nv);
    friend std::ostream& operator<<(std::ostream& out, const cNhanVienVP& nv);
 
    bool operator<(const cNhanVienVP& o) const { return luong < o.luong; }
    bool operator>(const cNhanVienVP& o) const { return o < *this; }
 
    ~cNhanVienVP() {}
};

#endif // CNHANVIENVP_H
