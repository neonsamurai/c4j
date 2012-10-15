#ifndef RATIONALNUMCOLLECTION_H
#define RATIONALNUMCOLLECTION_H

struct RationalNumberCollection {
    const int length = 2000;
    RationalNumber rnList[length];
    int totalUniqueCount;
    int totalCount;
    RationalNumber sum;
    RationalNumber average;

};

rncInit(RationalNumberCollection* c);

#endif // RATIONALNUMCOLLECTION_H
