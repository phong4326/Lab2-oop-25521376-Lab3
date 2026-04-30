#include"cTamGiac.h"
#include<cmath>

using namespace std;

#define EPSILON 1e-9

void cTamGiac::Nhap() {
    auto isHople = [](const cDiem& d1, const cDiem& d2, const cDiem& d3) {
        double a = sqrt(pow(d2.x - d3.x, 2) + pow(d2.y - d3.y, 2));
        double b = sqrt(pow(d1.x - d3.x, 2) + pow(d1.y - d3.y, 2));
        double c = sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
        //bat dang thuc tam giac
        return (a + b > c + EPSILON && a + c > b + EPSILON && b + c > a + EPSILON);
    };

    do {
        cout << "Nhap dinh A: "; A.Nhap();
        cout << "Nhap dinh B: "; B.Nhap();
        cout << "Nhap dinh C: "; C.Nhap();
        if (!isHople(A, B, C)) //egde case
            cout << "Khong hop le, vui long nhap lai\n";
    } while(!isHople(A, B, C));
}

void cTamGiac::Xuat() const {
    cout << "Tam giac: ";
    A.Xuat(); cout << ", ";
    B.Xuat(); cout << ", ";
    C.Xuat(); 
}

//dung EPSILON de tranh 3^2 + 4^2 = 24.999999999
string cTamGiac::PhanLoai() const {
    double a = sqrt(pow(B.x - C.x, 2) + pow(B.y - C.y, 2));
    double b = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
    double c = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
    
    bool can = (abs(a - b) < EPSILON || abs(a - c) < EPSILON || abs(b - c) < EPSILON);
    bool deu = (abs(a - b) < EPSILON && abs(b - c) < EPSILON);
    
    // Kiem tra vuong bang đinh ly Pythagoras
    bool vuong = (abs(a*a + b*b - c*c) < EPSILON || 
                  abs(a*a + c*c - b*b) < EPSILON || 
                  abs(b*b + c*c - a*a) < EPSILON);

    if (deu) return "tam giac deu";
    if (vuong && can) return "tam giac vuong can";
    if (vuong) return "tam giac vuong";
    if (can) return "tam giac can";
    return "tam giac thuong";
}

double cTamGiac::TinhChuVi() const {
    auto dist = [](const cDiem& d1, const cDiem& d2) {
        return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
    };//cong thuc toan co ban

    return dist(A, B) + dist(B, C) + dist(C, A);
}

double cTamGiac::TinhDienTich() const {
    // truy cap truc tiep x, y
    return 0.5 * abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}
    
cTamGiac cTamGiac::TinhTien(double dx, double dy) const {
    cTamGiac tg = *this;
    tg.A.x += dx; tg.A.y += dy;
    tg.B.x += dx; tg.B.y += dy;
    tg.C.x += dx; tg.C.y += dy;
    return tg;
}

cDiem cTamGiac::TrongTam() const {
    return cDiem((A.x + B.x + C.x)/3, (A.y + B.y + C.y)/3);
}

cTamGiac cTamGiac::PhongTo(double k) const {
    cTamGiac tg = TinhTien(-1*TrongTam().x, -1*TrongTam().y); //de don gian thi tinh tien tam giac ve O
    tg.A.x *= k; tg.A.y *= k;
    tg.B.x *= k; tg.B.y *= k;
    tg.C.x *= k; tg.C.y *= k;
    return tg.TinhTien(TrongTam().x, TrongTam().y); //sau do tinh tien ve lai tam cu
}

cTamGiac cTamGiac::ThuNho(double k) const {
    return PhongTo(1.0 / k);
}

//quay tuong tu voi viec phong to nha
cTamGiac cTamGiac::Quay(double rad) const {
    cTamGiac tg = TinhTien(-1*TrongTam().x, -1*TrongTam().y);
    auto rotate = [](cDiem& d, double r) {
        double x_old = d.x;
        d.x = x_old * cos(r) - d.y * sin(r);
        d.y = x_old * sin(r) + d.y * cos(r);
    };
    rotate(tg.A, rad); rotate(tg.B, rad); rotate(tg.C, rad);
    return tg.TinhTien(TrongTam().x, TrongTam().y);
}