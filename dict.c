#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


keyValue *createKeyValue(char *key, void *value, int valueType){
    // 1 : int, 2 : float, 3 : string, 4, int array, 5 : float array
    keyValue *key_value = malloc(sizeof(keyValue));
    if (key_value == NULL) return NULL;
    key_value->valueType = valueType;
    key_value->key = key;
    key_value->value = value;
    return key_value;
}


void delKeyValue(keyValue *key_value){
    free(key_value);
}


keyValue *copyKeyValue(keyValue *key_value){
    keyValue *key_value_copy = createKeyValue(key_value->key, key_value->value, key_value->valueType);
    return key_value_copy;
}


int compareKeyValue(keyValue *key_value_1, keyValue *key_value_2){
    if (key_value_1->valueType != key_value_2->valueType) return 0;
    if (strcmp(key_value_1->key, key_value_2->key) != 0) return 0;
    int res;
    int *arrI1 = (int *) key_value_1->value;
    int *arrI2 = (int *) key_value_2->value;
    double *arrF1 = (double *) key_value_1->value;
    double *arrF2 = (double *) key_value_2->value;
    switch (key_value_1->valueType) {
        case 1:
            res = key_value_1->value == key_value_2->value ? 1 : 0;
            break;
        case 2:
            res = key_value_1->value == key_value_2->value ? 1 : 0;
            break;
        case 3:
            res = strcmp(key_value_1->value, key_value_2->value) == 0 ? 1 : 0;
            break;
        case 4:
            if(arrI1[0] != arrI2[0]){
                res = 0;
                break;
            }
            for (int i = 1; i < arrI1[0] + 1; ++i){
                if (arrI1[i] != arrI2[i]){
                    res = 0;
                    break;
                } else res = 1;
            }
            break;
        case 5:
            if(arrF1[0] != arrF2[0]){
                res = 0;
                break;
            }
            for (int i = 1; i < (int)arrF1[0] + 1; ++i)
                if (arrF1[i] != arrF2[i]){
                    res = 0;
                    break;
                } else res = 1;
            break;
    }
    return res;
}


void printKeyValue(keyValue *key_value){
    // 1 : int, 2 : float, 3 : string, 4, int array, 5 : float array
    printf("%s: ", key_value->key);
    switch (key_value->valueType) {
        case 1:
            printf("%d", *(int *)key_value->value);
            break;
        case 2:
            printf("%lf", *(double *)key_value->value);
            break;
        case 3:
            printf("%s", (char *)key_value->value);
            break;
        case 4:
            printf("[");
            int *arrInt = (int *) key_value->value;
            for (int i = 1; i < arrInt[0] + 1; ++i) {
                if (i == 1)
                    printf("%d", arrInt[i]);
                else
                    printf(", %d", arrInt[i]);
            }
            printf("]");
            break;
        case 5:
            printf("[");
            double *arrFloat = (double *) key_value->value;
            for (int i = 1; i < (int)arrFloat[i] + 1; ++i) {
                if (i == 1)
                    printf("%lf", arrFloat[i]);
                else
                    printf(", %lf", arrFloat[i]);
            }
            printf("]");
            break;
    }
}


dict *createDict(){
    dict *d = malloc(sizeof(dict));
    if (d == NULL) return NULL;
    d->len = 0;
    d->dict_list = NULL;
    return d;
}


void add(dict* d, char *key, void *value, int valueType){
    // 1 : int, 2 : float, 3 : string, 4, int array, 5 : float array
    if (valueType < 1 || valueType > 5) return;
    keyValue *key_value = createKeyValue(key, value, valueType);
    int index = 0;
    for (int i = 0; i < d->len; ++i) {
        if (strcmp(d->dict_list[i]->key, key) == 0){
            d->dict_list[i]->value = value;
            d->dict_list[i]->valueType = valueType;
            return;
        } else if (strcmp(d->dict_list[i]->key, key) < 0)
            index++;
    }

    d->len++;
    d->dict_list = (keyValue **) realloc(d->dict_list, d->len * sizeof(keyValue *));

    if (index < d->len - 1) for (int i = d->len - 1; i > index; --i) d->dict_list[i] = d->dict_list[i - 1];
    d->dict_list[index] = key_value;
}


void delByKey(dict* d, char *key){
    if (d->len == 0) return;
    for (int i = 0; i < d->len; ++i) {
        if (strcmp(d->dict_list[i]->key, key) == 0){
            delKeyValue(d->dict_list[i]);
            if (i < d->len - 1)
                for (int j = i + 1; j < d->len; ++j) d->dict_list[j - 1] = d->dict_list[j];
            d->len--;
            d->dict_list = (keyValue **) realloc(d->dict_list, d->len * sizeof(keyValue *));
            return;
        }
    }
}


void delDict(dict *d){
    for (int i = 0; i < d->len; ++i) {
        delByKey(d, d->dict_list[i]->key);
    }
    free(d);
}


keyValue *getByKey(dict *d, char *key){
    for (int i = 0; i < d->len; ++i)
        if (strcmp(d->dict_list[i]->key, key) == 0) return copyKeyValue(d->dict_list[i]);
    return NULL;
}


void printDict(dict *d){
    printf("{");
    for (int i = 0; i < d->len; ++i) {
        if (i != 0) printf(", ");
        printKeyValue(d->dict_list[i]);
    }
    printf("}\n");
}
