#include"cListCandidate.h"

using namespace std;

istream& operator>>(istream& in, cListCandidate& lc) {
    int n; in >> n;
    in.ignore(); // xoa '\n' con sot sau khi doc so nguyen
    lc.list.resize(n);
    for (int i = 0; i < n; i++) {
        in >> lc.list[i];
    }
    return in;
}
 
ostream& operator<<(ostream& out, const cListCandidate& lc) {
    for (int i = 0; i < (int)lc.list.size(); i++) {
        out << "\n " << i+1 << "\t";
        out << lc.list[i];
    }
    return out;
}

void cListCandidate::xuatYeuCau() {
    for (auto& c : list) {
        if (c.TongDiem() > 15) 
            cout << c << endl;;
    }
}

cCandidate cListCandidate::TimTongDiemMax() const {
    return *max_element(list.begin(), list.end());
}

void cListCandidate::SapXepGiamDan() {
    sort(list.begin(), list.end(), greater<cCandidate>());
}