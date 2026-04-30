#include"cArray.h"
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

void cArray::TaoNgauNhien() {
    int n;
    cout << "Nhap so phan tu mang(n >= 0): ";
    do {
        cin >> n;
        if (!(n >= 0)) cout << "Loi! Vui long nhap lai: ";
    } while (!(n >= 0));

    data.clear();
    srand(time(0));//tao seed theo thoi gian thuc de moi lan tao ko bi trung lap
    //neu truyen srand(1) thi mot lan deu tao ra cung mot mang ngau nhien giong nhau
    //voi mot gtri truyen vao srand se cho mot day khac nhau nen dung thoi gian thuc
    for (int i = 0; i < n; i++) {
        data.push_back(rand()%21 - 10);
        //tao ngau nhie gia tri (-100, 100)
        //rand() tao ra gia tri tu 0 den RAND_MAX
        // %201 de so du tu 0 den 200, tru 100 de duoc -100 den 100
        //100 la so rat dep va trong khoang nay snt phan bo day' nhat
    }
}

void cArray::Xuat() const {
    for (auto& x : data) cout << x << " ";
    //in ra nhu binh thuong
}

int cArray::DemX(int x) const {
    int cnt = 0;
    for (auto& val : data) { //data = { 1 2 3 4 2 6 2 8} x = 2
        if (val == x) cnt++; // cnt = 3
    } // mot lan gap val = x tang cnt (co ban)
    return cnt;
}

bool cArray::KiemTraTangDan() const {
    if (data.size() < 2) return true;
    int n = data.size();

    for (int i = 0; i < n - 1; i++) {
        if (data[i] > data[i + 1]) return false;
    } // chi can check neu co pha tu dung truoc lon hon thi return false luon
    // vd: data = {1, 2, 4, 8, 5, 9, 10} chay den i = 3 return false
    return true;
}

int cArray::TimMinLe() const {
    int ans = 1e9; // set gtri bien ans = max_int
    for (auto& x : data) {
        if (x % 2 != 0 && x < ans) { // neu thoa hai dk thi thay doi gtri ans
            ans = x;
        }
    }
    return ans; // luon return ve ans roi kiem tra trong ham main()
    // vd: data = {1, 2, 4, 8, 5, 9, 10} chay het den 10 va return 9
}

int cArray::TimMaxSNT() const {
    auto isPrime = [] (int n) { // viet mot lambda kiem tra snt
        for (int i = 2; i <= sqrt(n); i++) 
            if (n % i == 0) return false;
        return n > 1; // thuat toan co ban ai cx biet
    };

    int ans = -1e9; //thuc chat co the dat be hon -100 la ok roi nhung lam cho dung ban chat
    for (auto& x : data) {
        if (isPrime(x) && x > ans) ans = x;
    }
    return ans;
}

//day la mot ham nam ngoai class
int partition(vector<int>& a, int l, int r, bool tangdan) {
    // thua toan quicksort voi Hoare partiron
    // dung cai nay vi em thay thuat toan kha hay(top1 sort)
    // thua toan su dung mot vach ngay de chia mang thanh hai nua so voi pivot
    // de quy chia nho va so sanh tung hai nua se duoc
    int pivot = a[l];
    int i = l - 1, j = r + 1;
    if (tangdan) { // neu tangdan = true su dung thuat toan o tren
        while (1) {
            do { i++; } while (a[i] < pivot);
            do { j--; } while (a[j] > pivot);
            if (i < j) swap(a[i], a[j]);
            else return j;
        }
    } else { // neu tangdan = false su dung thua toan o day
        while (1) {
            do { i++; } while (a[i] > pivot);
            do { j--; } while (a[j] < pivot);
            if (i < j) swap(a[i], a[j]);
            else return j;
        }
    }
}
void quicksort(vector<int>& a, int l, int r, bool tangdan) {
    if (l >= r) return; 
    int p = partition(a, l, r, tangdan);
    quicksort(a, l, p, tangdan);
    quicksort(a, p+1, r, tangdan);
}

void cArray::cArrayQuicksort(bool TangDan) {
    quicksort(data, 0, data.size() - 1, TangDan);
}

int cArray::getter() {
    return data.size();
}
