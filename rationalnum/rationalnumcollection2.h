#ifndef RATIONALNUMCOLLECTION2_H
#define RATIONALNUMCOLLECTION2_H

#include "rationalnumber.h"

struct RationalNumberCollection2;

RationalNumberCollection2* rncCreate(int length);
void rncInit(RationalNumberCollection2* c);
void rncDelete(RationalNumberCollection2* c);
int rncExists(RationalNumberCollection2* c, RationalNumber r);
void rncAdd(RationalNumberCollection2* c, RationalNumber r);
void rncAdded(RationalNumberCollection2* c, RationalNumber r, bool isNew);
void rncRemove(RationalNumberCollection2* c, RationalNumber r);
void rncRemoved(RationalNumberCollection2* c, RationalNumber r, bool isZero);
int rncTotalCount(RationalNumberCollection2* c);
int rncTotalUniqueCount(RationalNumberCollection2* c);
RationalNumber rncSum(RationalNumberCollection2* c);
RationalNumber rncAverage(RationalNumberCollection2* c);
void rncPrint(RationalNumberCollection2* c);
void rncAddSorted(RationalNumberCollection2* c, RationalNumber r);
void rncCleanUp(RationalNumberCollection2* c, int index);
int rncBinarySearch(RationalNumberCollection2* c, RationalNumber r);
int rncBinarySearch(RationalNumberCollection2* c, RationalNumber r, int min, int max);
void rncCalcMedian(RationalNumberCollection2* c);
RationalNumber rncMedian(RationalNumberCollection2* c);
void rncExtendArray(RationalNumberCollection2* c);
RationalNumber* rncGetCopy(RationalNumber* list,int oldLength, int newLength);
int rncGetLength(RationalNumberCollection2* c);

#endif // RATIONALNUMCOLLECTION2_H
