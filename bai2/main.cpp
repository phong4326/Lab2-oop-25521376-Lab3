#include"cDaGiac.h"

using namespace std;
 
int main() {
    cDaGiac polygon;
    double dx, dy, k, _k, rad;

    cout << "Tao mot da giac...\n";
    polygon.Nhap();
    cout << "NHAP THONG SO\n";
    cout << "\tNhap he so tinh tien dx, dy: "; cin >> dx >> dy;
    cout << "\tNhap he so quay: "; cin >> rad;
    cout << "\tNhap he phong to: "; cin >> k;
    cout << "\tNhap he thu nho: "; cin >> _k;

    polygon.Xuat();
    cout << "\nLoai: " << polygon.PhanLoai();
    cout << "\nChu vi: " << polygon.TinhChuVi();
    cout << "\nDien tich: " << polygon.TinhDienTich();

    cout << "\nTinh tien (dx, dy) = (" << dx << ", "  << dy << ")\n"; 
    (polygon.TinhTien(dx, dy)).Xuat();

    cout << "\nQuay mot goc rad = " << rad << endl;
    (polygon.Quay(rad)).Xuat();

    cout << "\nPhong to " << k << " lan\n";
    (polygon.PhongTo(k)).Xuat();

    if (_k == 0) {
        cout << "He so _k = 0! Khong the thu nho";
    } else {
        cout << "\nThu nho " << _k << " lan\n";
        (polygon.ThuNho(_k)).Xuat();
    }

    cout << "\n----------------------------------";
    return 0;
}
//cd bai2
//g++ cDaGiac.cpp main.cpp -o main
