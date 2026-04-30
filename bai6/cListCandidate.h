#ifndef CLISTCANDIDATE_H
#define CLISTCANDIDATE_H

#include"cCandidate.h"
#include<vector>

class cListCandidate
{
private:
    std::vector<cCandidate> list;
public:
    cListCandidate() : list() {}
    friend std::istream& operator>>(std::istream& in, cListCandidate& l);
    friend std::ostream& operator<<(std::ostream& out, const cListCandidate& l);
    void xuatYeuCau();
    cCandidate TimTongDiemMax() const;
    void SapXepGiamDan();
    ~cListCandidate() {}
};

#endif