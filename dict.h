#ifndef C_LABS_2_LAB_1_DICT_H

#define C_LABS_2_LAB_1_DICT_H


typedef struct {
    int valueType; // 1 : int, 2 : float, 3 : string, 4, int array, 5 : float array
    char *key;
    void *value;
} keyValue;


keyValue *createKeyValue(char *, void *, int);


void delKeyValue(keyValue *);


keyValue *copyKeyValue(keyValue *);


int compareKeyValue(keyValue *, keyValue *);


void printKeyValue(keyValue *);


typedef struct{
    int len;
    keyValue **dict_list;
} dict;


dict *createDict();


void delDict(dict *);


void add(dict*, char *, void *, int);


void delByKey(dict*, char *);


keyValue *getByKey(dict*, char *);


void printDict(dict *);

#endif //C_LABS_2_LAB_1_DICT_H
