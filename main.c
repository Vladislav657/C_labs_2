#include "dict.h"
#include <stdlib.h>
#include <stdio.h>


int main(void){
    dict *dictionary = createDict();

    int *a3 = (int *) malloc(3 * sizeof(int));
    int *a5 = (int *) malloc(6 * sizeof(int));

    a3[0] = 2;
    a5[0] = 5;

    for (int i = 1; i < 6; ++i) {
        a3[i] = 10;
        a5[i] = 9;
    }

    int a = 547;
    char *c = "fswrwwwwwf";
    char *f = "fsrrrrrrrrrrrrrf";

    add(dictionary, "a", &a, 1);
    add(dictionary, "c", a5, 4);
    add(dictionary, "b", c, 3);
    add(dictionary, "f", a3, 4);
    add(dictionary, "d", f, 3);
    add(dictionary, "b", "Hello", 3);

    delByKey(dictionary, "f");

    keyValue *kv = getByKey(dictionary, "b");
    keyValue *kv_copy = copyKeyValue(kv);
    keyValue *kv_c = getByKey(dictionary, "c");
    keyValue *kv_d = getByKey(dictionary, "d");

    printDict(dictionary);

    printKeyValue(kv_copy);

    printf("\n%d\n%d\n%d", compareKeyValue(kv, kv_copy), compareKeyValue(kv, kv_c), compareKeyValue(kv, kv_d));

    delDict(dictionary);
    delKeyValue(kv);
    delKeyValue(kv_copy);
    delKeyValue(kv_c);
    delKeyValue(kv_d);
    free(a3);
    free(a5);

    return 0;
}
