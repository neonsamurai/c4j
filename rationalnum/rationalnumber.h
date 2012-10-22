#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

struct RationalNumber {
    int numerator;
    int denominator;
};

bool rnIsValid(RationalNumber n);
bool rnEqual(RationalNumber a, RationalNumber b);
bool rnLessThan(RationalNumber a, RationalNumber b);
<<<<<<< HEAD
RationalNumber rnNormalize (RationalNumber r);
RationalNumber rnAdd (RationalNumber r1, RationalNumber r2);
RationalNumber rnSubtract (RationalNumber r1, RationalNumber r2);
RationalNumber rnMultiply (RationalNumber r1, RationalNumber r2);
RationalNumber rnDivide (RationalNumber r1, RationalNumber r2);
float rnGetValue (RationalNumber r);
=======
RationalNumber rnAdd (RationalNumber r1, RationalNumber r2);
RationalNumber rnSubtract (RationalNumber r1, RationalNumber r2);
RationalNumber rnMultiply(RationalNumber r1, RationalNumber r2);
RationalNumber rnDivide (RationalNumber r1, RationalNumber r2);
RationalNumber rnNormalize (RationalNumber r);
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124

#endif // RATIONALNUMBER_H
