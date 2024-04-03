#pragma once
#include<string>
#include<iostream>


class BigInteger{

public:

    BigInteger(): digits(nullptr), sign(0), Size(0), nr(0) {};
    BigInteger(std::string D);
    BigInteger(const BigInteger& other);
    
    ~BigInteger();

    int sgn();
    
    int compare(const BigInteger& N) const;

    void PrependZeros(const int n);
    void negate();

    BigInteger add(const BigInteger& N);
    BigInteger sub(const BigInteger& N);
    

    
    
    friend BigInteger operator+(const BigInteger& a, const BigInteger& b);
    friend bool operator+=(const BigInteger& a, const BigInteger& b);
    friend BigInteger operator-(const BigInteger& a, const BigInteger& b);
    friend bool operator-=(const BigInteger& a, const BigInteger& b);
    
    friend bool operator==(const BigInteger& a, const BigInteger& b);
    friend bool operator<(const BigInteger& a, const BigInteger& b);
    friend bool operator<=(const BigInteger& a, const BigInteger& b);
    friend bool operator>(const BigInteger& a, const BigInteger& b);
    friend bool operator>=(const BigInteger& a, const BigInteger& b);

private:

    int* digits;
    int sign;
    unsigned long Size;
    unsigned long nr;
    
};
