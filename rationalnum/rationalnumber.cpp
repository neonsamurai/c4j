#include "rationalnumber.h"

/*
returns true if the rn is valid
*/
bool rnIsValid(RationalNumber n){
    return n.denominator!=0;
}

/*
returns true if the two rn are equal
*/
bool rnEqual(RationalNumber a, RationalNumber b){
    a = rnNormalize(a);
    b = rnNormalize(b);
    return (a.numerator == b.numerator && a.denominator == b.denominator);
}

/*
returns true if the first rn is less than the second rn
*/
bool rnLessThan(RationalNumber a, RationalNumber b){
    int n = a.numerator * b.denominator;
    int m = a.denominator * b.numerator;
    if (a.denominator * b.denominator < 0) {
        n *= -1;
        m *= -1;
    };
    return n<m;
}

/*
adds two rn and returns the result
*/
RationalNumber rnAdd (RationalNumber r1, RationalNumber r2) {
    int numerator1 = r1.numerator * r2.denominator;
    int numerator2 = r2.numerator * r1.denominator;
    RationalNumber sum = {numerator1 + numerator2, r1.denominator * r2.denominator};
    return rnNormalize(sum);
}

/*
subtracts two rn and returns the result
*/
RationalNumber rnSubtract (RationalNumber r1, RationalNumber r2) {
    int numerator1 = r1.numerator * r2.denominator;
    int numerator2 = r2.numerator * r1.denominator;
    RationalNumber difference = {numerator1 - numerator2, r1.denominator * r2.denominator};
    return rnNormalize(difference);
}

/*
multiplies two rn and returns the result
*/
RationalNumber rnMultiply (RationalNumber r1, RationalNumber r2) {
    RationalNumber product = {r1.numerator * r2.numerator, r1.denominator * r2.denominator};
    return rnNormalize(product);
}

/*
divides two rn and returns the result
*/
RationalNumber rnDivide (RationalNumber r1, RationalNumber r2) {
    RationalNumber inverse = {r2.denominator, r2.numerator};
    return rnMultiply(r1, inverse);
}

/*
returns the normalized rn
*/
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

/*
returns the float value of the rn
*/
float rnGetValue (RationalNumber r) {
    float a = (float)r.numerator / (float)r.denominator;
    return a;
}
