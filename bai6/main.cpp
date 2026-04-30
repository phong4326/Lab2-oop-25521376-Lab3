#include"cListCandidate.h"
#include<fstream>

using namespace std;

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cerr << "Loi: Khong mo duoc file input.txt\n";
        return 1;
    }

    cListCandidate lc;
    fin >> lc;
    fin.close();
    cout << "\n----------DANH SACH THI SINH-----------";
    cout << lc << endl;

    cout << "\n----------THI SINH CO TONG DIEM LON HON 15----------\n";
    lc.xuatYeuCau();
    
    cout << "\n----------THI SINH CO TONG DIEM CAO NHAT----------\n";
    cout << lc.TimTongDiemMax() << endl;

    lc.SapXepGiamDan();
    cout << "\n----------DANH SACH SAP XEP GIAM DAN----------"
         << lc << endl;

    return 0; 
}

//g++ cCandidate.cpp cListCandidate.cpp main.cpp -o main