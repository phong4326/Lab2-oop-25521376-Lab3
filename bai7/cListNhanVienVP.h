#ifndef CLISTNHANVIENVP_H
#define CLISTNHANVIENVP_H

#include"cNhanVienVP.h"
#include<vector>

class cListNhanVienVP
{
private:
    std::vector<cNhanVienVP> list;
public:
    cListNhanVienVP() : list() {}
    friend std::istream& operator>>(std::istream& in, cListNhanVienVP& l);
    friend std::ostream& operator<<(std::ostream& out, cListNhanVienVP& l);

    cNhanVienVP luongCaoNhat() const;
    cNhanVienVP tuoiCaoNhat() const;
    double      tongLuong() const;
    void        sapXepTangDan();
    ~cListNhanVienVP() {}
};

#endif //CLISTNHANVIENVP_H