#ifndef HASH_H
#define HASH_H

#define BUCKET_SIZE (23)
#define TRUE (1)
#define FALSE (0)

typedef struct {
    int hash_map[BUCKET_SIZE];
    size_t count;
} hash_map_t;

void init_hash_map(hash_map_t* hm);
int has_value(const hash_map_t* hm, int value);
int add(hash_map_t* hm, int value);
int del(hash_map_t* hm, int value);
void clear(hash_map_t* hm);
void print_hash_map(hash_map_t* hm);

#endif /* HASH_H */
