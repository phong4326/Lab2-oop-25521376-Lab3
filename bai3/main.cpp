#include"cDSPhanSo.h"

using namespace std;

int main() {
    cDSPhanSo list;

    cout << "Nhap danh sach phan so!\n";
    list.Nhap();

    cout << "---Thong-tin-danh-sach---\n";
    list.Xuat();
    if (list.getter() == 0) return 0;

    cout << "\nTong cac phan so trong danh sach: ";
    list.TongPs().Xuat();

    cout << "\nPhan so lon nhat la: ";
    list.PsMax().Xuat();

    cout << "\nPhan so nho nhat la: ";
    list.PsMin().Xuat();

    cout << "\nPhan so co tu la so nguyen to lon nhat la: ";
    list.PsNguyenTo().Xuat();

    cout << "\nDanh sach phan so tang dan la: ";
    list.SapXepTangDan();
    list.Xuat();

    cout << "\nDanh sach phan so giam dan la: ";
    list.SapXepGiamDan();
    list.Xuat();

    return 0;
}
//cd bai3
//g++ PhanSo.cpp cDSPhanSo.cpp main.cpp -o main