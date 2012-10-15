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
    int n = a.numerator * b.denominator;
    int m = a.denominator * b.numerator;
    if (a.denominator * b.denominator < 0) {
        n *= -1;
        m *= -1;
    };
    return n<m;
}

RationalNumber rnAdd (RationalNumber r1, RationalNumber r2) {
    int numerator1 = r1.numerator * r2.denominator;
    int numerator2 = r2.numerator * r1.denominator;
    RationalNumber sum = {numerator1 + numerator2, r1.denominator * r2.denominator};
    return rnNormalize(sum);
}

RationalNumber rnSubtract (RationalNumber r1, RationalNumber r2) {
    int numerator1 = r1.numerator * r2.denominator;
    int numerator2 = r2.numerator * r1.denominator;
    RationalNumber difference = {numerator1 - numerator2, r1.denominator * r2.denominator};
    return rnNormalize(difference);
}

RationalNumber rnMultiply (RationalNumber r1, RationalNumber r2) {
    RationalNumber product = {r1.numerator * r2.numerator, r1.denominator * r2.denominator};
    return rnNormalize(product);
}

RationalNumber rnDivide (RationalNumber r1, RationalNumber r2) {
    RationalNumber inverse = {r2.denominator, r2.numerator};
    return rnMultiply(r1, inverse);
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
