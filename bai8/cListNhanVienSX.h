#ifndef CLISTNHANVIENSX_H
#define CLISTNHANVIENSX_H

#include"cNhanVienSX.h"
#include<vector>

class cListNhanVienSX
{
private:
    std::vector<cNhanVienSX> list;
public:
    cListNhanVienSX() : list(0) {}

    friend std::istream& operator>>(std::istream& in, cListNhanVienSX& l);
    friend std::ostream& operator<<(std::ostream& out, const cListNhanVienSX& l);

    cNhanVienSX luongThapNhat() const;
    cNhanVienSX tuoiCaoNhat()   const;
    double      tongLuong()     const;
    void        sapXepTangDan();
    
    ~cListNhanVienSX() {}
};

#endif