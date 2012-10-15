#include "rationalnumcollection.h"

void rncInit(RationalNumberCollection *c){
    c->average = RationalNumber(0,1);
    c->sum=RationalNumber(0,1);
    c->totalCount=0;
    c->totalUniqueCount=0;
}

int rncExists(RationalNumberCollection *c, RationalNumber r){
    for (int i = 0; i < c->length; i = i+2){
        if(rnEqual(r,c->rnList[i])){
            return i;
        }
    }
    return -1;
}

int rncCount(RationalNumberCollection *c, RationalNumber r){
    int index = rncExists(&c, r);
    if(index == -1){
        return 0;
    }else{
        return rmList[index+1].numerator;
    }
}

void rncAdd(RationalNumberCollection *c, RationalNumber r){
    if(c->totalUniqueCount==0){
        c->rnList[0]=r;
        c->rnList[1]=RationalNumber(1,1);
        rncAdded(&c, r, true);
    }else{
        int index = rncExists(&c, r);
        if(index == -1){
            c->rnList[(c->totalUniqueCount+1)*2]=r;
            c->rnList[(c->totalUniqueCount+1)*2+1]=RationalNumber(1,1);
            rncAdded(&c, r, true);
        }else{
            c->rnList[index+1]=rnAdd(rnList[index+1],RationalNumber(1,1));
            rncAdded(&c, r, false);
        }
    return;
    }
}
void rncAdded(RationalNumberCollection *c, RationalNumber r, bool isNew){
    if(isNew){
        c->totalUniqueCount++;
    }
    c->totalCount++;
    c->sum=rncAdd(c->sum, r);
    c->average=rnDivide(c->sum, RationalNumber(c->totalCount),1);
    return
}

void rncRemove(RationalNumberCollection *c, RationalNumber r){
    if(c->totalUniqueCount==0){
        return;
    }else{
        int index = rncExists(&c, r);
        if(index == -1){
            return;
        }else{
            c->rnList[index+1]=rnSubtract(rnList[index+1],RationalNumber(1,1));
            if(c->rnList[index+1].numerator == 0){
                c->rnList[index]=RationalNumber(0,1);
                rncRemoved(&c, r, true);
            }else{
                rncRemoved(&c, r, false);
            }

        }
    return;
    }
}

void rncRemoved(RationalNumberCollection *c, RationalNumber r, bool isZero){
    if(isZero){
        // TODO: Array aufräumen
        c->totalUniqueCount--;
    }
    c->totalCount--;
    c->sum=rncSubtract(c->sum, r);
    c->average=rnDivide(c->sum, RationalNumber(c->totalCount),1);
    return
}

int rncTotalCount(RationalNumberCollection *c){
    return c->totalCount;
}

int rncTotalUniqueCount(RationalNumberCollection *c){
    return c->totalUniqueCount;
}
