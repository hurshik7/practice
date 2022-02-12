#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    node_t* next;
} node_t;

void print_list(const node_t* head) {
    const node_t* p = head;
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
}

void add_front(node_t** phead, int value) {
    node_t* new = (node_t*)malloc(sizeof(node_t));
    new->value = value;
    new->next = *phead;
    *phead = new;
}

void add_sorted(node_t** phead, int value) {
    if (phead == NULL) {
        add_front(phead, value);
        return;
    }

    node_t* new = (node_t*)malloc(sizeof(node_t));
    new->value = value;
    node_t** pp = phead;
    while (*pp != NULL) {
        if ((*pp)->value > value) {
            break;
        }
        pp = &(*pp)->next;
    }
    new->next = *pp;
    *pp = new;
}

bool remove_node(node_t** phead, int value) {
    node_t** pp = phead;
    bool isDeleted = false;
    while (*pp != NULL) {
        if ((*pp)->value == value) {
            node_t* temp = *pp;
            *pp = (*pp)->next;            
            free(temp);
            temp = NULL;
            isDeleted = true;
            break;
        }
        pp = &(*pp)->next;
    }
    if (isDeleted == true) {
        return true;
    }
    return false;
}

int search_node(node_t* phead, int value) {
    node_t* pp = phead;
    while (*pp != NULL) {
        if ((pp->value == value) {
            return true;
        }
        pp = pp->next;
    }
    return false;
}
