#ifndef C_LABS_2_LAB_1_DICT_H

#define C_LABS_2_LAB_1_DICT_H

typedef struct {
    char *key;
    int value;
} keyValue;

keyValue *createKeyValue(char *, int);

void delKeyValue(keyValue *);

keyValue *copyKeyValue(keyValue *);

int compareKeyValue(keyValue *, keyValue *);

typedef struct{
    int len;
    keyValue *dict_list;
} dict;

dict *createDict();

void delDict(dict *);

void add(dict*, char *, int);

void delByKey(dict*, char *);

keyValue *getByKey(dict*, char *);

void printDict(dict *);

#endif //C_LABS_2_LAB_1_DICT_H
