#include "rationalnumcollection.h"
#include <stdio.h>

/*
initializes a new rationalnumbercollection for 1000
rational numbers, the array has the structur:
[rational number 1],[amount of rn1],[rational number 2],[amount of rn2],...
*/
void rncInit(RationalNumberCollection* c){
    RationalNumber  rnZero = { 0, 1 };
    c->length = 2000;
    for (int i = 0; i < c->length; i++) {
        c->rnList[i] = rnZero;
    }
    c->average = rnZero;
    c->sum = rnZero;
    c->median = rnZero;
    c->totalCount = 0;
    c->totalUniqueCount = 0;
}

/*
returns the index of the given rational number in the collection
or returns -1 if it's not in the collection
*/
int rncExists(RationalNumberCollection* c, RationalNumber r){
    for (int i = 0; i < c->length; i = i+2){
        if(rnEqual(r, c->rnList[i])){
            return i;
        }
    }
    return -1;
}

/*
returns the amount of the given rational number in the collection
or returns 0 if it's not in the collection
*/
int rncCount(RationalNumberCollection* c, RationalNumber r){
    int index = rncExists(c, r);
    if(index == -1){
        return 0;
    }else{
        return c->rnList[index+1].numerator;
    }
}

/*
adds a new rational number to the collection or raises
the count by one
*/
void rncAdd(RationalNumberCollection* c, RationalNumber r){
    if(!rnIsValid(r)) {
        return;
    }
    RationalNumber  rnOne = { 1, 1 };
    RationalNumber  rnZero = { 0, 1 };
    if(c->totalUniqueCount == 0){
        c->rnList[0] = r;
        c->rnList[1]= rnOne;
        rncAdded(c, r, true);
    }else{
        int index = rncExists(c, r);
        if(index != -1){
            if (rnEqual(r,rnZero) && rncCount(c,r) == 0) {
                rncAddSorted(c,r);
                rncAdded(c, r, true);
            } else {
                c->rnList[index+1] = rnAdd(c->rnList[index+1],rnOne);
                rncAdded(c, r, false);
            }
        } else {
            if (c->totalUniqueCount == 1000) {
                return;
            }
            //c->rnList[(c->totalUniqueCount)*2] = r;
            //c->rnList[(c->totalUniqueCount)*2+1] = rnOne;
            rncAddSorted(c,r);
            rncAdded(c, r, true);
        }
    return;
    }
}

/*
calculates the new values for the members of the given collection, after
a rational number was added
*/
void rncAdded(RationalNumberCollection* c, RationalNumber r, bool isNew){
    if(isNew){
        c->totalUniqueCount++;
    }
    c->totalCount++;
    c->sum = rnAdd(c->sum, r);
    RationalNumber  rnDivisor = { c->totalCount, 1 };
    c->average=rnDivide(c->sum, rnDivisor);
    rncCalcMedian(c);
    return;
}

/*
reduce the count of the given rational number by one and removes
the rational number if the count reaches zero
*/
void rncRemove(RationalNumberCollection* c, RationalNumber r){
    if(!rnIsValid(r) || c->totalUniqueCount==0){
        return;
    }else{
        int index = rncExists(c, r);
        if(index == -1){
            return;
        }else{
            RationalNumber rnOne = { 1,1 };
            c->rnList[index+1] = rnSubtract(c->rnList[index+1], rnOne);
            if(c->rnList[index+1].numerator == 0){
                rncCleanUp(c,index);
                rncRemoved(c, r, true);
            }else{
                rncRemoved(c, r, false);
            }
        }
    return;
    }
}

/*
calculates the new values for the members of the given collection, after
a rational number was removed
*/
void rncRemoved(RationalNumberCollection* c, RationalNumber r, bool isZero){
    if(isZero){
        c->totalUniqueCount--;
    }
    c->totalCount--;
    if(rncTotalCount(c) < 1) {
        RationalNumber rnZero = { 0,1 };
        c->sum = rnZero;
        c->average = rnZero;
    } else {
        c->sum = rnSubtract(c->sum, r);
        RationalNumber  rnDivisor = { c->totalCount, 1 };
        c->average = rnDivide(c->sum, rnDivisor);
    }
    rncCalcMedian(c);
    return;
}

/*
returns the amount of all rational numbers in the given collection
*/
int rncTotalCount(RationalNumberCollection* c){
    return c->totalCount;
}

/*
returns the amount of different rational numbers in the given collection
*/
int rncTotalUniqueCount(RationalNumberCollection* c){
    return c->totalUniqueCount;
}

/*
returns the sum of all rational numbers in the given collection
*/
RationalNumber rncSum(RationalNumberCollection* c) {
    return c->sum;
}

/*
returns the average of all rational numbers in the given collection
*/
RationalNumber rncAverage(RationalNumberCollection* c) {
    return c->average;
}

/*
console print of the collection
*/
void rncPrint(RationalNumberCollection* c) {
    for (int i = 0; i < c->totalUniqueCount*2; i = i+2) {
        printf("\n%ix[%i/%i]",c->rnList[i+1].numerator, c->rnList[i].numerator, c->rnList[i].denominator);
    }
    return;
}

/*
adds a new rational number in the collection and sorts it by the rn-values,
starting with the lowest
*/
void rncAddSorted(RationalNumberCollection* c, RationalNumber r) {
    float value = rnGetValue(r);
    int index = c->totalUniqueCount*2;
    RationalNumber rnOne = { 1,1 };
    for (int i = 0; i < c->totalUniqueCount*2 ;i=i+2) {
        if (value < rnGetValue(c->rnList[i])) {
            index = i;
            break;
        }
    }
    for (int i = c->totalUniqueCount*2; i >= index; i = i-2) {
        c->rnList[i+2] = c->rnList[i];
        c->rnList[i+1+2] = c->rnList[i+1];
    }
    c->rnList[index] = r;
    c->rnList[index+1] = rnOne;
    return;
}

/*
cleans the collection by eliminating an empty space at the given index in the collection
*/
void rncCleanUp(RationalNumberCollection* c, int index) {
    for (int i = index; i < c->totalUniqueCount*2; i++) {
        c->rnList[i] = c->rnList[i+2];
        c->rnList[i+1] = c->rnList[i+1+2];
    }
    return;
}

/*
starts a recursive binary search for the given rational number in the collection,
returns the index of the given rational number in the collection
or returns -1 if it's not in the collection
*/
int rncBinarySearch(RationalNumberCollection* c, RationalNumber r) {
    return rncBinarySearch(c, r, 0, c->totalUniqueCount*2);
}

/*
returns the index of the given rational number in the collection
or returns -1 if it's not in the collection,
search method: recursive binary search
*/
int rncBinarySearch(RationalNumberCollection* c, RationalNumber r, int min, int max) {
    if (max < min) {
        return -1;
    } else {
        float value = rnGetValue(r);
        int mid = (min + max) / 2;
        if (mid%2 != 0) {
            mid = mid-1;
        }
        float midValue = rnGetValue(c->rnList[mid]);
        if (midValue > value) {
            return rncBinarySearch(c, r, min, mid-2);
        } else if (midValue < value){
            return rncBinarySearch(c, r, mid+2, max);
        } else {
            return mid / 2;
        }
    }
}

/*
calculates the median for the given collection
*/
void rncCalcMedian(RationalNumberCollection* c) {
    if (c->totalCount == 0) {
        RationalNumber rnZero = { 0,1 };
        c->median = rnZero;
        return;
    } else if (c->totalCount == 1) {
        c->median = c->rnList[0];
        return;
    } else if (c->totalCount % 2 == 0) {
        int medianDeepness = c->totalCount / 2;
        for (int i = 0; i < c->totalUniqueCount*2; i = i+2) {
            int count = c->rnList[i+1].numerator;
            while(count > 0) {
                medianDeepness--;
                count--;
                if(medianDeepness == 0) {
                    RationalNumber rn1 = c->rnList[i];
                    RationalNumber rn2 = c->rnList[i+2];
                    RationalNumber rnDivisor = { 2,1 };
                    if (count != 0) {
                        rn2 = c->rnList[i];
                    }
                    c->median = rnDivide(rnAdd(rn1,rn2),rnDivisor);
                    return;
                }
            }
        }
        return;
    } else {
        int medianDeepness = c->totalCount / 2 + 1;
        for (int i = 0; i < c->totalUniqueCount*2; i = i+2) {
            medianDeepness = medianDeepness - c->rnList[i+1].numerator;
            if (medianDeepness <= 0) {
                c->median = c->rnList[i];
                return;
            }
        }
        return;
    }
}

/*
returns the median of the given collection
*/
RationalNumber rncMedian(RationalNumberCollection* c) {
    return c->median;
}
