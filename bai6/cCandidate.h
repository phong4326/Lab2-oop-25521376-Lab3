#ifndef CCANDIDATE_H
#define CCANDIDATE_H

#include"cDay.h"
#include<iostream>
#include<string>

class cCandidate
{
private:
    std::string id, name;
    cDay birth; //composition
    double math, lit, eng; 
public:
    cCandidate() : name(""), id(""), math(0), lit(0), eng(0) {}
    cCandidate( const std::string& name, const std::string& id, 
                const cDay& birth, double math, double lit, double eng)
    : name(name), id(id), birth(birth), math(math), lit(lit), eng(eng) {}

    friend std::istream& operator>>(std::istream& in, cCandidate& c);
    friend std::ostream& operator<<(std::ostream& out, const cCandidate& c);

    bool operator<(const cCandidate& p) const; 
    bool operator>(const cCandidate& p) const;

    double TongDiem();
    ~cCandidate() {}
};

#endif
