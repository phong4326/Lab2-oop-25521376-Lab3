#include"cListNhanVienSX.h"
#include<fstream>
#include<iomanip>

using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Loi: Khong mo duoc file input.txt\n";
        return 1;
    }

    cListNhanVienSX ds;
    fin >> ds;
    fin.close();
    cout <<"\n----------DANH SACH NHAN VIEN VAN PHONG----------";
    cout << ds << endl;

    cout << "\n----------NHAN VIEN CO LUONG THAP NHAT----------\n"
         << ds.luongThapNhat() << "\n";
 
    cout << "\nTONG LUONG CONG TY PHAI TRA: "
         << fixed << setprecision(0) << ds.tongLuong() << " VND\n";
 
    cout << "\n----------NHAN VIEN CO TUOI CAO NHAT----------\n"
         << ds.tuoiCaoNhat() << "\n";
    
    ds.sapXepTangDan();
    cout << "\n-----DANH SACH SAP XEP TANG DAN THEO LUONG-----\n"
         << ds << "\n";
    return 0;
}
//g++ cNhanVienSX.cpp cListNhanVienSX.cpp main.cpp -o main