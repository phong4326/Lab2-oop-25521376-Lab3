#ifndef CDSPHANSO_H
#define CDSPHANSO_H

#include"PhanSo.h"
#include<vector>

class cDSPhanSo
{
private:
    std::vector<PhanSo> DS;
public:
    cDSPhanSo() {}
    void Nhap();
    void Xuat() const;
    PhanSo TongPs() const;
    PhanSo PsMax() const;
    PhanSo PsMin() const;
    PhanSo PsNguyenTo() const;
    void SapXepTangDan();
    void SapXepGiamDan(); 
    int getter() const;
    ~cDSPhanSo() {}
};

#endif