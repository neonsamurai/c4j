#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber {
    int numerator;
    int denominator;
};

bool rnIsValid(RationalNumber n);
bool rnEqual(RationalNumber a, RationalNumber b);
bool rnLessThan(RationalNumber a, RationalNumber b);
RationalNumber rnAdd (RationalNumber r1, RationalNumber r2);
RationalNumber rnSubtract (RationalNumber r1, RationalNumber r2);
RationalNumber rnMultiply(RationalNumber r1, RationalNumber r2);
RationalNumber rnDivide (RationalNumber r1, RationalNumber r2);
RationalNumber rnNormalize (RationalNumber r);

#endif // RATIONALNUMBER_H
