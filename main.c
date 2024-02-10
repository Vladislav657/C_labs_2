#include "dict.h"
#include <stdio.h>
#include <stdlib.h>


int main(void){
    dict *dictionary = createDict(4);

    int *arr = (int *) malloc(5 * sizeof(int));

    for (int i = 0; i < 5; ++i) {
        arr[i] = 1;
    }

    keyValue *kv1 = createKeyValue("a", 0, 0, NULL, arr, NULL, 4);
    kv1->intLen = 5;
    add(dictionary, kv1);
    delByKey(dictionary, "a");

    int *arr2 = (int *) malloc(5 * sizeof(int));
    for (int i = 0; i < 5; ++i) {
        arr2[i] = 2;
    }
    keyValue *kv2 = createKeyValue("b", 0, 0, NULL, arr2, NULL, 4);
    kv2->intLen = 5;

    add(dictionary, kv2);
    add(dictionary, kv1);

    printDict(dictionary);

    return 0;
}
