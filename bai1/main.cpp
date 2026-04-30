#include<iostream>
#include"cTamGiac.h"

using namespace std;

int main() {
    cTamGiac tg;
    double dx, dy, k, _k, rad;

    cout <<"NHAP TAM GIAC\n";
    tg.Nhap();

    cout << "NHAP THONG SO\n";
    cout << "\tNhap he so tinh tien dx, dy: "; cin >> dx >> dy;
    cout << "\tNhap he so quay: "; cin >> rad;
    cout << "\tNhap he phong to: "; cin >> k;
    cout << "\tNhap he thu nho: "; cin >> _k;

    tg.Xuat();
    cout << "\nLoai: " << tg.PhanLoai();
    cout << "\nChu vi: " << tg.TinhChuVi();
    cout << "\nDien tich: " << tg.TinhDienTich();

    cout << "\nTinh tien (dx, dy) = (" << dx << ", "  << dy << ")\n"; 
    (tg.TinhTien(dx, dy)).Xuat();

    cout << "\nQuay mot goc rad = " << rad << endl;
    (tg.Quay(rad)).Xuat();

    cout << "\nPhong to " << k << " lan\n";
    (tg.PhongTo(k)).Xuat();

    if (_k == 0) {
        cout << "He so _k = 0! Khong the thu nho";
    } else {
        cout << "\nThu nho " << _k << " lan\n";
        (tg.ThuNho(_k)).Xuat();
    }

    cout << "\n----------------------------------";
    return 0;
}