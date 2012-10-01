#include "rationalnumber.h"


bool rnIsValid(RationalNumber n){
    return n.denominator!=0;
}

bool rnEqual(RationalNumber a, RationalNumber b){
    a = rnNormalize(a);
    b = rnNormalize(b);
    return (a.numerator == b.numerator && a.denominator == b.denominator);
}

bool rnLessThan(RationalNumber a, RationalNumber b){
    int n;
    int m;
    n = a.numerator * b.denominator;
    m = a.denominator * b.numerator;
    return n<m;
}

RationalNumber rnNormalize (RationalNumber r){
    int t = r.denominator;
    int a = r.numerator;
    int b = r.denominator;

    while (b != 0){
           t = b;
           b = a % b;
           a = t;
        }
    r.numerator = r.numerator/a;
    r.denominator = r.denominator/a;

    return r;
}
