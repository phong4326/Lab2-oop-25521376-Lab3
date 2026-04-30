#include"cDSPhanSo.h"

using namespace std;

void cDSPhanSo::Nhap(){
    int n;
    cout << "Nhap so phan so(n >= 0): ";
    do {
        cin >> n;// neu nhap n loi se nhap lai
        if (!(n >= 0)) cout << "Loi! Vui long nhap lai: ";
    } while (!(n >= 0));

    for (int i = 0; i < n; i++) {
        cout << "Nhap phan so thu " << i + 1 << ": ";
        PhanSo ps; //thong bao nhap tung phan so
        ps.Nhap();
        DS.push_back(ps); // vi la vector neu co th push
    }   
}

void cDSPhanSo::Xuat() const {
    if (DS.size() == 0) {
        cout << "Danh sach khong co phan so nao!";
        return; // DS ko co ps nao van hop le nen van phai check
    }

    int n = DS.size();
    for (int i = 0; i < n; i++) {
        DS[i].Xuat();
        if (i < n -1 ) cout << ", ";
        else cout << ".";
    }//xuat cach nhau bo dau , (chu y ps cuoi cung)
}

PhanSo cDSPhanSo::TongPs() const { //dung method cong cua class PhanSo de cong don vao
    PhanSo ans;                 // khoi tao thi ans = 0/1
    for (auto& ps : DS) {       // 1/4, 2/4, 3/4
        ans = ans.Cong(ps);     // ans = 01 + 1/4 = 1/4
    }                           // ans = 1/4 + 2/4 = 3/4
    return ans;                 // ans = 3/4 + 3/4 = 6/4 rut gon con 3/2    
}

PhanSo cDSPhanSo::PsMax() const { // tim max sap xep tang dan r lay ps cuoi
    cDSPhanSo temp = *this;     // DS ={1/2, 1/4, 6/5, 3/4}
    temp.SapXepTangDan();       // DS -> {1/4, 1/2, 3/4, 6/5}    
    return temp.DS.back();      // lay 6/5
}// phai khai bao mot oj temp vi method co const

PhanSo cDSPhanSo::PsMin() const { // tuong tu logic nhu tim max vay
    cDSPhanSo temp = *this;
    temp.SapXepTangDan();
    return temp.DS.front();
}

PhanSo cDSPhanSo::PsNguyenTo() const {
    auto check = [](int p) {
        for (int i = 2; i <= sqrt(p); i++) {
            if (p % i == 0) return false;
        }
        return p > 1;
    }; // viet mot lambda de check so nguye to (qua co ban)
    PhanSo best(0,1);   //tao mot bien de so sanh va gan so lon nhat can tim
    bool found = false; // dat bien found de xem da co so ngto nao chua
                        // dung cho truong hop so nguyen to dau tien
    for (const auto& ps : DS) {        // DS ={1/2, 2/3, 7/5, 3/4}
        if (check(abs(ps.x))) {      // lan dau tien best = 2/3 
            if (!found || ps > best) { // la thu 2 best = 7/5
                best = ps;             // lan thu 3 kiem tra duoc 3 la snt 
                found = true;          // nhung < 7 nen best van la 7/5     
            } // chung ta co operator> nen co the so sanh > giua hai phan so
        }
    }
    return best;
}

void cDSPhanSo::SapXepTangDan(){
    sort(DS.begin(), DS.end());  // cai j co san thi minh dung #include<algorithm>
}
//Quicksort
void cDSPhanSo::SapXepGiamDan() { //vi co functor greater
    sort(DS.begin(), DS.end(), greater<PhanSo>());// nen chung ta phai co operator> 
}

int cDSPhanSo::getter() const {
    return DS.size();
}