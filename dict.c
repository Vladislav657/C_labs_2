#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


keyValue *createKeyValue(char *key, int value){
    keyValue *key_value = malloc(sizeof(keyValue));
    key_value->key = key;
    key_value->value = value;
    return key_value;
}

void delKeyValue(keyValue *key_value){
    free(key_value);
}

keyValue *copyKeyValue(keyValue *key_value){
    keyValue *key_value_copy = malloc(sizeof(keyValue));
    key_value_copy->key = key_value->key;
    key_value_copy->value = key_value->value;
    return key_value_copy;
}

int compareKeyValue(keyValue *key_value_1, keyValue *key_value_2){
    return strcmp(key_value_1->key, key_value_2->key);
}

dict *createDict(){
    dict *d = malloc(sizeof(dict));
    d->len = 0;
    d->dict_list = NULL;
    return d;
}

void add(dict* d, char *key, int value){
    keyValue *key_value = createKeyValue(key, value);

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
    int index = 0;
    for (int i = 0; i < d->len; ++i) {
        if (strcmp(d->dict_list[i].key, key) == 0){
            if (index < d->len - 1)
                for (int j = index + 1; j < d->len; ++j) d->dict_list[j - 1] = d->dict_list[j];
            d->len--;
            d->dict_list = (keyValue *) realloc(d->dict_list, d->len * sizeof(keyValue));
            return;
        }
        else index++;
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
    for (int i = 0; i < d->len; ++i)
        if (i == d->len - 1) printf("%s: %d", d->dict_list[i].key, d->dict_list[i].value);
        else printf("%s: %d, ", d->dict_list[i].key, d->dict_list[i].value);
    printf("}");
}
