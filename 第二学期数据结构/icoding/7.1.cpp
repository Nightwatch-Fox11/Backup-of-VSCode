#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef enum
{
    HASH_OK,
    HASH_ERROR,
    HASH_ADDED,
    HASH_REPLACED_VALUE,
    HASH_ALREADY_ADDED,
    HASH_DELETED,
    HASH_NOT_FOUND,
} HASH_RESULT;

typedef struct __HashEntry HashEntry;
struct __HashEntry
{
    union {
        char *str_value;
        double dbl_value;
        int int_value;
    } key;
    union {
        char *str_value;
        double dbl_value;
        int int_value;
        long long_value;
        void *ptr_value;
    } value;
    HashEntry *next;
};

struct __HashTable
{
    HashEntry **bucket;
    int size;
    HASH_RESULT last_error;
};
typedef struct __HashTable HashTable;

// 创建大小为hash_size的哈希表，创建成功后返回HashTable类型的指针，否则返回NULL。
HashTable *create_hash(int size)
{
    HashTable *a = (HashTable *)malloc(sizeof(HashTable));
    a->bucket = (HashEntry **)malloc(sizeof(HashEntry **) * size);
    if (!a->bucket)
    {
        free(a);
        return NULL;
    }
    memset(a, 0, sizeof(HashTable));
    a->size = size;
    return a;
}