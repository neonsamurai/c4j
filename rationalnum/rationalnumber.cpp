#include "rationalnumber.h"

<<<<<<< HEAD
/*
returns true if the rn is valid
*/
=======

>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
bool rnIsValid(RationalNumber n){
    return n.denominator!=0;
}

<<<<<<< HEAD
/*
returns true if the two rn are equal
*/
=======
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
bool rnEqual(RationalNumber a, RationalNumber b){
    a = rnNormalize(a);
    b = rnNormalize(b);
    return (a.numerator == b.numerator && a.denominator == b.denominator);
}

<<<<<<< HEAD
/*
returns true if the first rn is less than the second rn
*/
=======
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
bool rnLessThan(RationalNumber a, RationalNumber b){
    int n = a.numerator * b.denominator;
    int m = a.denominator * b.numerator;
    if (a.denominator * b.denominator < 0) {
        n *= -1;
        m *= -1;
    };
    return n<m;
}

<<<<<<< HEAD
/*
adds two rn and returns the result
*/
=======
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
RationalNumber rnAdd (RationalNumber r1, RationalNumber r2) {
    int numerator1 = r1.numerator * r2.denominator;
    int numerator2 = r2.numerator * r1.denominator;
    RationalNumber sum = {numerator1 + numerator2, r1.denominator * r2.denominator};
    return rnNormalize(sum);
}

<<<<<<< HEAD
/*
subtracts two rn and returns the result
*/
=======
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
RationalNumber rnSubtract (RationalNumber r1, RationalNumber r2) {
    int numerator1 = r1.numerator * r2.denominator;
    int numerator2 = r2.numerator * r1.denominator;
    RationalNumber difference = {numerator1 - numerator2, r1.denominator * r2.denominator};
    return rnNormalize(difference);
}

<<<<<<< HEAD
/*
multiplies two rn and returns the result
*/
=======
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
RationalNumber rnMultiply (RationalNumber r1, RationalNumber r2) {
    RationalNumber product = {r1.numerator * r2.numerator, r1.denominator * r2.denominator};
    return rnNormalize(product);
}

<<<<<<< HEAD
/*
divides two rn and returns the result
*/
=======
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
RationalNumber rnDivide (RationalNumber r1, RationalNumber r2) {
    RationalNumber inverse = {r2.denominator, r2.numerator};
    return rnMultiply(r1, inverse);
}

<<<<<<< HEAD
/*
returns the normalized rn
*/
=======
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
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
<<<<<<< HEAD

/*
returns the float value of the rn
*/
float rnGetValue (RationalNumber r) {
    float a = (float)r.numerator / (float)r.denominator;
    return a;
}
=======
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
