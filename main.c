#include "dict.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
    dict *dictionary = createDict(3);

//    int *a1 = (int *) malloc(6 * sizeof(int));
//    int *a2 = (int *) malloc(6 * sizeof(int));
//    int *a3 = (int *) malloc(3 * sizeof(int));
//    int *a4 = (int *) malloc(6 * sizeof(int));
//    int *a5 = (int *) malloc(6 * sizeof(int));
//
//
//    a1[0] = 5;
//    a2[0] = 5;
//    a3[0] = 2;
//    a4[0] = 5;
//    a5[0] = 5;
//    for (int i = 1; i < 6; ++i) {
//        a1[i] = 2;
//        a2[i] = 3;
//        a3[i] = 10;
//        a4[i] = 5;
//        a5[i] = 9;
//    }

    char *a = "fsf";
    char *b = "fsbdsbf";
    char *d = "frwsf";
    char *c = "fswrwwwwwf";
    char *f = "fsrrrrrrrrrrrrrf";

    add(dictionary, "a", a);
    add(dictionary, "c", b);
    add(dictionary, "b", c);
    add(dictionary, "f", d);
    add(dictionary, "d", f);
    delByKey(dictionary, "c");

    printDict(dictionary);

    delDict(dictionary);

    return 0;
}
