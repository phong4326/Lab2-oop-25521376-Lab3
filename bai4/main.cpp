#include"cArray.h"

using namespace std;

int main() {
    cArray a; int x;

    cout << "Tao mot mang ngau nhien!\n";
    a.TaoNgauNhien();

    cout << "---Thong-tin-mang---\n";
    cout << "Mang " << a.getter() << " phan tu: ";
    a.Xuat();
    if (a.getter() == 0) return 0;

    cout << "\nNhap gia tri x can dem: "; 
    cin >> x;
    cout << "So lan xuat hien cua " << x << " trong mang la " << a.DemX(x) << " lan.\n";

    cout << (a.KiemTraTangDan() ? "Mang dang tang dan" : "Mang khong tang dan");

    if (a.TimMinLe() != 1e9) cout << "\nSo le nho nhat trong mang la " << a.TimMinLe() << ".";
    else cout << "\nMang khong co phan tu le.";

    if (a.TimMaxSNT() != -1e9) cout << "\nSo nguyen to lon nhat trogn mang la " << a.TimMaxSNT() << ".";
    else cout << "\nMang khong co so nguyen to.";

    cout << "\nChon cach sap xep mang tang dan/giam dan tuong ung voi 1/0: ";
    do {
        cin >> x;
        if (!(x == 1 || x == 0)) cout << "\nLoi! CHI NHAP 1 HOAC 0: ";
    } while (!(x == 1 || x == 0));
    if (x) {
        cout << "Mang duoc sap xem tang dan: ";
        a.cArrayQuicksort(true);
        a.Xuat();
    } else {
        cout << "Mang duoc sap xem giam dan: ";
        a.cArrayQuicksort(false);
        a.Xuat();
    } 
    return 0;
}
