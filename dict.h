#ifndef C_LABS_2_LAB_1_DICT_H

#define C_LABS_2_LAB_1_DICT_H


typedef struct {
    int valueType;
    char *key;

    int intValue;
    double floatValue;
    char *stringValue;
    int *intArrValue;
    double *floatArrValue;

    int intLen;
    int floatLen;
} keyValue;


keyValue *createKeyValue(char *, int, double, char *, int *, double *, int);


void delKeyValue(keyValue *);


keyValue *copyKeyValue(keyValue *);


int compareKeyValue(keyValue *, keyValue *);


void printKeyValue(keyValue *);


typedef struct{
    int valueType;
    int len;
    keyValue *dict_list;
} dict;


dict *createDict(int);


void delDict(dict *);


void add(dict*, keyValue *);


void delByKey(dict*, char *);


keyValue *getByKey(dict*, char *);


void printDict(dict *);

#endif //C_LABS_2_LAB_1_DICT_H
