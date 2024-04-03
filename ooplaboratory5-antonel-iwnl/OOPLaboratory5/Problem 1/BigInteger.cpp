#include "BigInteger.h"

#include <cctype> // for isdigit
#include <iostream>
#include <iomanip>
using namespace std;


BigInteger::BigInteger(string D) {
    Size = D.length();
    sign = (D[0] == '-') ? -1 : 1;
    D.erase(0, 1);
    digits = new int[Size];
    for (int i = 1; i < Size; i++) {
        digits[i] = D[i] - '0';
    }
}

BigInteger::BigInteger(const BigInteger& other) {
    Size = other.Size;
    sign = other.sign;
    digits = new int[Size];
    for (int i = 0; i < Size; i++) {
        digits[i] = other.digits[i];
    }
}

BigInteger::~BigInteger() {
    delete [] digits;
}

int BigInteger::sgn() {
    if (sign == 1) {
        return 1;
    }
    if (sign == -1) {
        return -1;
    }
}

int BigInteger::compare(const BigInteger& N) const {
    if (sign == N.sign) {
        if (Size == N.Size) {
            for (int i = Size - 1; i >= 0; i--) {
                if (digits[i] > N.digits[i]) {
                    return 1;
                }
                if (digits[i] < N.digits[i]) {
                    return -1;
                }
            }
            return 0;
        }
        if (Size > N.Size) {
            return 1;
        }
        if (Size < N.Size) {
            return -1;
        }
    }
    if (sign == 1) {
        return 1;
    }
    if (sign == -1) {
        return -1;
    }
}

void BigInteger::PrependZeros(int n) {
    int* aux = new int[Size + n];
    for (int i = 0; i < n; i++) {
        aux[i] = 0;
    }
    for (int i = n; i < Size + n; i++) {
        aux[i] = digits[i - n];
    }
    delete[] digits;
    digits = aux;
    Size += n;
}

void BigInteger::negate() {
    sign = -sign;
}


BigInteger BigInteger::add(const BigInteger& N) {
    BigInteger result;
    if (sign == N.sign) {
        result.sign = sign;
        result.Size = (Size > N.Size) ? Size : N.Size;
        result.digits = new int[result.Size + 1];
        int carry = 0;
        for (int i = 0; i < result.Size; i++) {
            int sum = carry + (i < Size ? digits[i] : 0) + (i < N.Size ? N.digits[i] : 0);
            result.digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            result.digits[result.Size] = carry;
            result.Size++;
        }
    }
    else {
        if (sign == -1) {
            BigInteger aux = N;
            aux.sign = 1;
            result = sub(aux);
        }
        else {
            BigInteger aux = *this;
            aux.sign = 1;
            result = sub(aux);
        }
    }
    return result;
}

BigInteger BigInteger::sub(const BigInteger& N) {
    BigInteger result;
    if (sign == N.sign) {
        if (sign == 1) {
            if (compare(N) == 1) {
                result.sign = 1;
                result.Size = Size;
                result.digits = new int[result.Size];
                int borrow = 0;
                for (int i = 0; i < result.Size; i++) {
                    int diff = digits[i] - borrow - (i < N.Size ? N.digits[i] : 0);
                    if (diff < 0) {
                        diff += 10;
                        borrow = 1;
                    }
                    else {
                        borrow = 0;
                    }
                    result.digits[i] = diff;
                }
                while (result.Size > 1 && result.digits[result.Size - 1] == 0) {
                    result.Size--;
                }
            }
            else {
                if (compare(N) == -1) {
                    result.sign = -1;
                    result.Size = N.Size;
                    result.digits = new int[result.Size];
                    int borrow = 0;
                    for (int i = 0; i < result.Size; i++) {
                        int diff = N.digits[i] - borrow - (i < Size ? digits[i] : 0);
                        if (diff < 0) {
                            diff += 10;
                            borrow = 1;
                        }
                        else {
                            borrow = 0;
                        }
                        result.digits[i] = diff;
                    }
                    while (result.Size > 1 && result.digits[result.Size - 1] == 0) {
                        result.Size--;
                    }
                }
                else {
                    result.sign = 1;
                    result.Size = 1;
                    result.digits = new int[1];
                    result.digits[0] = 0;
                }
            }
        }
        else {
            if (compare(N) == 1) {
                result.sign = -1;
                result.Size = Size;
                result.digits = new int[result.Size];
                int borrow = 0;
                for (int i = 0; i < result.Size; i++) {
                    int diff = digits[i] - borrow - (i < N.Size ? N.digits[i] : 0);
                    if (diff < 0) {
                        diff += 10;
                        borrow = 1;
                    }
                    else {
                        borrow = 0;
                    }
                    result.digits[i] = diff;
                }
                while (result.Size > 1 && result.digits[result.Size - 1] == 0) {
                    result.Size--;
                }
            }
            else {
                if (compare(N) == -1) {
                    result.sign = 1;
                    result.Size = N.Size;
                    result.digits = new int[result.Size];
                    int borrow = 0;
                    for (int i = 0; i < result.Size; i++) {
                        int diff = N.digits[i] - borrow - (i < Size ? digits[i] : 0);
                        if (diff < 0) {
                            diff += 10;
                            borrow = 1;
                        }
                        else {
                            borrow = 0;
                        }
                        result.digits[i] = diff;
                    }
                    while (result.Size > 1 && result.digits[result.Size - 1] == 0) {
                        result.Size--;
                    }
                }
                else {
                    result.sign = 1;
                    result.Size = 1;
                    result.digits = new int[1];
                    result.digits[0] = 0;
                }
            }
        }
    }
    else {
        if (sign == -1) {
            BigInteger aux = N;
            aux.sign = -1;
            result = add(aux);
        }
        else {
            BigInteger aux = N;
            aux.sign = 1;
            result = add(aux);
        }
    }
    return result;
}


BigInteger operator+ (const BigInteger& N1, const BigInteger& N2) {
    BigInteger result;
    result = result.add(N1);
    result = result.add(N2);
    return result;
}

BigInteger operator+= (BigInteger& N1, const BigInteger& N2) {
    N1 = N1.add(N2);
    return N1;
}

BigInteger operator- (const BigInteger& N1, const BigInteger& N2) {
    BigInteger result;
    result = result.sub(N1);
    result = result.sub(N2);
    return result;
}

BigInteger operator-= (BigInteger& N1, const BigInteger& N2) {
    N1 = N1.sub(N2);
    return N1;
}

bool operator== (const BigInteger& N1, const BigInteger& N2) {
    if (N1.compare(N2) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool operator< (const BigInteger& N1, const BigInteger& N2) {
    if (N1.compare(N2) == -1) {
        return true;
    }
    else {
        return false;
    }
}

bool operator> (const BigInteger& N1, const BigInteger& N2) {
    if (N1.compare(N2) == 1) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<= (const BigInteger& N1, const BigInteger& N2) {
    if (N1.compare(N2) == -1 || N1.compare(N2) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>= (const BigInteger& N1, const BigInteger& N2) {
    if (N1.compare(N2) == 1 || N1.compare(N2) == 0) {
        return true;
    }
    else {
        return false;
    }
}