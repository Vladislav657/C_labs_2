#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


keyValue *createKeyValue(char *key, void *value, int valueType){
    // 1 : int, 2 : float, 3 : string, 4, int array, 5 : float array
    keyValue *key_value = malloc(sizeof(keyValue));
    key_value->valueType = valueType;
    key_value->key = key;
    key_value->value = value;
    return key_value;
}


void delKeyValue(keyValue *key_value){
    free(key_value->value);
    free(key_value);
}


keyValue *copyKeyValue(keyValue *key_value){
    keyValue *key_value_copy = malloc(sizeof(keyValue));
    key_value_copy->value = key_value->value;
    key_value_copy->key = key_value->key;
    return key_value_copy;
}


int compareKeyValue(keyValue *key_value_1, keyValue *key_value_2){
    return strcmp(key_value_1->key, key_value_2->key);
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


dict *createDict(int valueType){
    if (valueType < 1 || valueType > 5) return NULL;
    dict *d = malloc(sizeof(dict));
    d->valueType = valueType;
    d->len = 0;
    d->dict_list = NULL;
    return d;
}


void add(dict* d, char *key, void *value){
    keyValue *key_value = createKeyValue(key, value, d->valueType);
    int index = 0;
    for (int i = 0; i < d->len; ++i) {
        if (strcmp(d->dict_list[i].key, key) == 0){
            d->dict_list[i].value = value;
            return;
        } else if (strcmp(d->dict_list[i].key, key) < 0)
            index++;
    }

    d->len++;
    d->dict_list = (keyValue *) realloc(d->dict_list, d->len * sizeof(keyValue));

    if (index < d->len - 1) for (int i = d->len - 1; i > index; --i) d->dict_list[i] = d->dict_list[i - 1];
    d->dict_list[index] = *key_value;
}


void delByKey(dict* d, char *key){
    if (d->len == 0) return;
    for (int i = 0; i < d->len; ++i) {
        if (strcmp(d->dict_list[i].key, key) == 0){
            if (i < d->len - 1)
                for (int j = i + 1; j < d->len; ++j) d->dict_list[j - 1] = d->dict_list[j];
            d->len--;
            d->dict_list = (keyValue *) realloc(d->dict_list, d->len * sizeof(keyValue));
            return;
        }
    }
}


void delDict(dict *d){
    for (int i = 0; i < d->len; ++i) {
        delByKey(d, d->dict_list[i].key);
    }
    free(d);
}


keyValue *getByKey(dict *d, char *key){
    for (int i = 0; i < d->len; ++i)
        if (strcmp(d->dict_list[i].key, key) == 0) return &d->dict_list[i];
    return NULL;
}


void printDict(dict *d){
    printf("{");
    for (int i = 0; i < d->len; ++i) {
        if (i != 0) printf(", ");
        printKeyValue(&d->dict_list[i]);
    }
    printf("}");
}
