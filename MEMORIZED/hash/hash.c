#include <stdio.h>
#include <limits.h>
#include "hash.h"

void init_hash_map(hash_map_t* hm)
{
    size_t i;
    for (i = 0; i < BUCKET_SIZE; i++) {
        hm->hash_map[i] = INT_MIN;
    }
    hm->count = 0;
}

int has_value(const hash_map_t* hm, int value)
{
    int start;
    int index = value % BUCKET_SIZE;
    
    if (index < 0) {
        index += BUCKET_SIZE;
    }

    start = index;
    do {
        if (hm->hash_map[start] == INT_MIN) {
            return FALSE;
        } else if (hm->hash_map[start] == value) {
            return TRUE;
        }
        start = (start + 1) % BUCKET_SIZE;
    } while (start != index);
    return FALSE;
}

int add(hash_map_t* hm, int value)
{
    int start;
    int index = value % BUCKET_SIZE;

    if (hm->count >= BUCKET_SIZE) {
        return FALSE;
    }

    if (index < 0) {
        index += BUCKET_SIZE;
    }

    start = index;
    do {
        if (hm->hash_map[start] == INT_MIN) {
            hm->hash_map[start] = value;
            hm->count++;
            return TRUE;
        } else if (hm->hash_map[start] == value) {
            return FALSE;
        }
        start = (start + 1) % BUCKET_SIZE;
    } while (start != index);
    return FALSE;
}

int del(hash_map_t* hm, int value)
{
    int start;
    int index = value % BUCKET_SIZE;
    
    if (hm->count == 0) {
        return FALSE;
    }    
    
    if (index < 0) {
        index += BUCKET_SIZE;
    }

    start = index;
    do {
        if (hm->hash_map[start] == INT_MIN) {
            return FALSE;
        } else if (hm->hash_map[start] == value) {
            hm->hash_map[start] = INT_MIN;
            hm->count--;
            return TRUE;
        }
        start = (start + 1) % BUCKET_SIZE;
    } while (start != index);
    return FALSE;
}

void clear(hash_map_t* hm)
{
    init_hash_map(hm);
}

void print_hash_map(hash_map_t* hm)
{
    size_t i;
    printf("Hash map : \n");
    for (i = 0; i < BUCKET_SIZE; i++) {
        if (hm->hash_map[i] == INT_MIN) {
            printf("INT_MIN ");
        } else {
            printf("%d ", hm->hash_map[i]);
        }
    }
    printf("\nCount : %lu\n", hm->count);
}
