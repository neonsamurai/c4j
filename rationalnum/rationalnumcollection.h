#ifndef RATIONALNUMCOLLECTION_H
#define RATIONALNUMCOLLECTION_H

<<<<<<< HEAD
#include "rationalnumber.h"

struct RationalNumberCollection {
    int length;
    RationalNumber rnList[2000];
=======
struct RationalNumberCollection {
    const int length = 2000;
    RationalNumber rnList[length];
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124
    int totalUniqueCount;
    int totalCount;
    RationalNumber sum;
    RationalNumber average;
<<<<<<< HEAD
    RationalNumber median;
};

void rncInit(RationalNumberCollection* c);
int rncCount(RationalNumberCollection* c, RationalNumber r);
void rncAdd(RationalNumberCollection* c, RationalNumber r);
void rncAdded(RationalNumberCollection* c, RationalNumber r, bool isNew);
void rncRemove(RationalNumberCollection* c, RationalNumber r);
void rncRemoved(RationalNumberCollection* c, RationalNumber r, bool isZero);
int rncTotalCount(RationalNumberCollection* c);
int rncTotalUniqueCount(RationalNumberCollection* c);
RationalNumber rncSum(RationalNumberCollection* c);
RationalNumber rncAverage(RationalNumberCollection* c);
void rncPrint(RationalNumberCollection* c);
void rncAddSorted(RationalNumberCollection* c, RationalNumber r);
void rncCleanUp(RationalNumberCollection* c, int index);
int rncBinarySearch(RationalNumberCollection* c, RationalNumber r);
int rncBinarySearch(RationalNumberCollection* c, RationalNumber r, int min, int max);
void rncCalcMedian(RationalNumberCollection* c);
RationalNumber rncMedian(RationalNumberCollection* c);
=======

};

rncInit(RationalNumberCollection* c);
>>>>>>> 13ea6fc5d13c471d90def642066a4facc0be4124

#endif // RATIONALNUMCOLLECTION_H
