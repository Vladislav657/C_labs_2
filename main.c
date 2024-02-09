#include "dict.h"


int main(void){
    dict *a = createDict();

    add(a, "a", 1);
    add(a, "b", 2);

    add(a, "d", 4);
    add(a, "f", 5);
    add(a, "c", 5);

//    delByKey(a, "f");
    delByKey(a, "a");

    add(a, "c", 4);
//    add(a, "c", 6);

    keyValue *b = getByKey(a, "d");



    printDict(a);
}
