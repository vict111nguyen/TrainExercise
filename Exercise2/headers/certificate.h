#pragma once
#include <iostream>

class Certificate{
public: 
    Certificate(int CertificatedID, std::string CertificateName, std::string CertificateRank, std::string CertificatedDate);
private: 
    int CertificatedID;
    std::string CertificateName;
    std::string CertificateRank;
    std::string CertificatedDate;
};
