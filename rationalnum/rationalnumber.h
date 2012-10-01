#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber {
    int numerator;
    int denominator;
};

bool rnIsValid(RationalNumber n);
bool rnEqual(RationalNumber a, RationalNumber b);
bool rnLessThan(RationalNumber a, RationalNumber b);
RationalNumber rnNormalize (RationalNumber r);

#endif // RATIONALNUMBER_H
