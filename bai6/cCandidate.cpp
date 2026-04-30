#include"cCandidate.h"

std::istream& operator>>(std::istream& in, cCandidate& c) {
    // Luu y: Neu truoc đo co dung cin >> n, phai goi in.ignore() truoc khi goi in >> c
    std::getline(in, c.id);
    std::getline(in, c.name);
    in >> c.birth >> c.math >> c.lit >> c.eng;
    // Sau khi nhap sa, ta nen xoa ky tu xuong dong con sot lai 
    // đe lan nhap chuoi tiep theo khong bi loi
    in.ignore(); 
    return in;
}

// Nap chong tosan tu xuat (cout << c)
std::ostream& operator<<(std::ostream& out, const cCandidate& c) {
    out << c.id << " | " << c.name << " | " << c.birth 
        << " | " << c.math << "   " << c.lit << "   " << c.eng;
    return out;
}

bool cCandidate::operator<(const cCandidate& p) const {
    double s = math + lit + eng;
    double sp = p.math + p.lit + p.eng;
    if (s != sp) return s < sp;
    // tie-breaker: compare name, then id
    if (name != p.name) return name < p.name;
    return id < p.id;
}

bool cCandidate::operator>(const cCandidate& p) const {
    return p < *this;
}

double cCandidate::TongDiem() { return math + lit + eng; }