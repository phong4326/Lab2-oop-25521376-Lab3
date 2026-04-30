#include"cDaGiac.h"
#include<cmath>
#include<algorithm>
 
using namespace std;

#define EPSILON 1e-9

void cDaGiac::Nhap() { 
    cout << "Nhap so dinh: "; 
    do { 
        cin >> n; 
        if (n < 3) cout << "Loi! Vui long nhap lai: "; 
    } while (n < 3); cout << "----------Hop-le----------\n"; 
    points.clear(); // xoa cho chac 
    for (int i = 0; i < n; i++) { 
        cDiem p; 
        cout << "Nhap diem thu " << i+1 << " : "; 
        p.Nhap(); points.push_back(p); 
    } 
} 

void cDaGiac::Xuat() const { 
    cout << "Da giac co " << n << " dinh: "; 
    for (int i = 0; i < n; i++) { 
        points[i].Xuat(); 
        if (i < n - 1) cout << ", "; 
        else cout << "."; 
    } 
}

string cDaGiac::PhanLoai() const {
    if (n == 3) return "Tam giac";

    bool isPositive = false;
    bool isNegative = false;

    auto cross = [](const cDiem p1, cDiem p2, cDiem p3) {
        return (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
    }; //tich co huong cua hai vecto ke nhau

    for (int i = 0; i < n; i++) {
        double cp = cross(points[i], points[(i+1)%n], points[(i+2)%n]);

        if (cp > EPSILON) isPositive = true;
        else if (cp < -EPSILON) isNegative = true;

        if (isPositive && isNegative) return "Da giac lom(Concave)";
        //neu co hai vector cat nhau thi da giac lom
        //lam vay vi neu xe tu giac ngu giac hi
        //phai xe them vuong, hcn, deu rat phuc tap
    }
    return "Da giac loi(Convex)";
}

double cDaGiac::TinhChuVi() const {
    double c = 0;
    auto dist = [](const cDiem& d1, const cDiem& d2) {
        return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2));
    };//cong thuc toan co ban
    for (int i = 0; i < n; i++) {
        c += dist(points[i], points[(i+1)%n]);
    }
    return c;
}

double cDaGiac::TinhDienTich() const {
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += points[i].x * points[(i+1)%n].y 
            - points[(i+1)%n].x * points[i].y;
    }
    return s;
} // VNOI + chatGPT + Gemini -> su dung cong thuc shoelace(buoc day giay)

cDaGiac cDaGiac::TinhTien(double dx, double dy) const {
    cDaGiac poly = *this;
    for (auto &p : poly.points) {
        p.x += dx; p.y += dy;
    }
    return poly;
}
cDiem cDaGiac::TrongTam() const {
    double x = 0, y = 0;
    for (auto &p : points) {
        x += p.x; y += p.y;
    }
    return cDiem(x/(double)n, y/(double)n);
}

cDaGiac cDaGiac::PhongTo(double k) const {
    //ca buoc thuc hien nhu la voi tam giac
    cDaGiac poly = TinhTien(-1*TrongTam().x, -1*TrongTam().y);
    for (auto &p : poly.points) {
        p.x *= k; p.y *= k;
    }
    return poly.TinhTien(TrongTam().x, TrongTam().y);
}

cDaGiac cDaGiac::ThuNho(double k) const {
    return PhongTo(1.0/k);
}
cDaGiac cDaGiac::Quay(double rad) const {
    cDaGiac poly = TinhTien(-1*TrongTam().x, -1*TrongTam().y);
    auto rotate = [](cDiem& d, double r) {
        double x_old = d.x;
        d.x = x_old * cos(r) - d.y * sin(r);
        d.y = x_old * sin(r) + d.y * cos(r);
    };
    for (auto &p : poly.points) {
        rotate(p, rad);
    }
    return poly.TinhTien(TrongTam().x, TrongTam().y);
}