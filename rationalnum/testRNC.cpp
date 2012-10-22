/*
   Simple Unit Test for type RationalNumberCollection
*/

#include <stdio.h>
#include <assert.h>

#include "rationalnumcollection.h"
#include "rationalnumcollection2.h"

int main()
{

    printf("Performing unit tests for RationalNumberCollection...");
    fflush(stdout);

    RationalNumber  n1 = { 1, 4 },
                    n2 = { 2, 4 },
                    n3 = { 3, 4 },
                    n4 = { -9, -6 },
                    n5 = { 6, 8 },
                    n6 = { 9, 4 },
                    n7 = { 789, 15 },
                    n8 = { 4567, 45677 },
                    n9 = { -2, -4 },
                    result1 = { 3, 8 },
                    result2 = { 6, 4 },
                    rnDivisor = { 5, 1 },
                    n0 = { 0, 4 },
                    n02 = { 0, 5 },
                    nn = { 4, 0 };

    printf("\n---");
    printf("\nPart 1: add, remove, totalCount, totalUniqueCount");
    RationalNumberCollection c;
    rncInit(&c);
    rncAdd(&c, n1);
    rncAdd(&c, n1);
    rncAdd(&c, n1);
    rncRemove(&c, n1);
    rncRemove(&c, n1);
    rncRemove(&c, n1);
    rncRemove(&c, n1);
    assert(rncTotalUniqueCount(&c) == 0);
    assert(rncTotalCount(&c) == 0);
    rncAdd(&c, n1);
    rncAdd(&c, n1);
    assert(rncTotalUniqueCount(&c) == 1);
    assert(rncTotalCount(&c) == 2);
    rncAdd(&c, n2);
    rncAdd(&c, n3);
    assert(rncTotalUniqueCount(&c) == 3);
    assert(rncTotalCount(&c) == 4);
    rncRemove(&c, n2);
    rncRemove(&c, n1);
    assert(rncTotalUniqueCount(&c) == 2);
    assert(rncTotalCount(&c) == 2);
    rncAdd(&c, n4);
    rncAdd(&c, n5);
    rncAdd(&c, n6);
    rncAdd(&c, n7);
    rncAdd(&c, n8);
    rncAdd(&c, n9);
    rncAdd(&c, nn);
    rncAdd(&c, n0);
    rncAdd(&c, n02);
    assert(rncTotalUniqueCount(&c) == 8);
    assert(rncTotalCount(&c) == 10);
    rncPrint(&c);
    printf(" \nsuccessful!");
    printf("\n---");
    //------------------------------------------------------------------------------------------------
    printf("\nPart 2: binary search, sorted add");
    RationalNumberCollection c2;
    rncInit(&c2);
    rncAdd(&c2, n5);
    assert(rncBinarySearch(&c2, n5) == 0);
    rncAdd(&c2, n1);
    rncAdd(&c2, n0);
    rncAdd(&c2, n8);
    assert(rncBinarySearch(&c2, n0) == 0);
    assert(rncBinarySearch(&c2, n8) == 1);
    assert(rncBinarySearch(&c2, n1) == 2);
    assert(rncBinarySearch(&c2, n5) == 3);
    assert(rncBinarySearch(&c2, n9) == -1);
    rncPrint(&c2);
    printf(" \nsuccessful!");
    printf("\n---");
    //------------------------------------------------------------------------------------------------
    printf("\nPart 3: sum, average, median");
    RationalNumberCollection c3;
    rncInit(&c3);
    assert(rnEqual(rncSum(&c3), n0));
    assert(rnEqual(rncAverage(&c3), n0));
    assert(rnEqual(rncMedian(&c3), n0));
    rncAdd(&c3, n1);
    assert(rnEqual(rncSum(&c3), n1));
    assert(rnEqual(rncAverage(&c3), n1));
    assert(rnEqual(rncMedian(&c3), n1));
    rncAdd(&c3, n2);
    assert(rnEqual(rncSum(&c3), n3));
    assert(rnEqual(rncAverage(&c3), result1));
    assert(rnEqual(rncMedian(&c3), result1));
    rncAdd(&c3, n3);
    assert(rnEqual(rncSum(&c3), result2));
    assert(rnEqual(rncAverage(&c3), n2));
    assert(rnEqual(rncMedian(&c3), n2));
    rncAdd(&c3, n0);
    rncAdd(&c3, n0);
    assert(rnEqual(rncSum(&c3), result2));
    assert(rnEqual(rnDivide(rncSum(&c3),rnDivisor), rncAverage(&c3)));
    assert(rnEqual(rncMedian(&c3), n1));
    rncPrint(&c3);
    printf(" \nsuccessful!");
    printf("\n---");
    //------------------------------------------------------------------------------------------------
    printf("\nPart 4: create, extend, delete");
    RationalNumberCollection2* rnc2 = rncCreate(5);
    rncAdd(rnc2, n2);
    rncAdd(rnc2, n1);
    rncPrint(rnc2);
    printf("\narrayLength: %i ",rncGetLength(rnc2));
    printf("\n---");
    rncAdd(rnc2, n3);
    rncAdd(rnc2, n4);
    rncAdd(rnc2, n6);
    rncPrint(rnc2);
    printf("\narrayLength: %i ",rncGetLength(rnc2));
    printf("\n---");
    rncAdd(rnc2, n7);
    rncAdd(rnc2, n8);
    rncAdd(rnc2, n9);
    rncAdd(rnc2, rnDivisor);
    rncPrint(rnc2);
    printf("\narrayLength: %i ",rncGetLength(rnc2));
    printf("\n---");
    rncAdd(rnc2, result1);
    rncAdd(rnc2, n0);
    rncPrint(rnc2);
    printf("\narrayLength: %i ",rncGetLength(rnc2));

    rncDelete(rnc2);
    printf(" \nsuccessful!");
    printf("\n---");

    printf(" \nAll tests successful!\n");

    return 0;
}

