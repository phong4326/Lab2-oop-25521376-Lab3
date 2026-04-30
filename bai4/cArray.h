#ifndef CARRAY_H
#define CARRAY_H

#include<iostream>
#include<vector>

class cArray
{
private:
    std::vector<int> data;
public:
    cArray() {}
    void TaoNgauNhien();
    void Xuat() const;
    int DemX(int x) const;
    bool KiemTraTangDan() const;
    int TimMinLe() const;
    int TimMaxSNT() const;
    void cArrayQuicksort(bool TangDan); //muon tang dan: True, muon giam dan False
    int getter();
    ~cArray() {
    }
};

#endif