#include <stdio.h>

typedef struct node {
    const char *key;
    int value;
    struct node *next;
}node;

typedef struct table {
    struct node *first;
}table;

struct table *create(void) {
    struct table *t;
    t = (struct table*)malloc(sizeof(struct table));
    t->first = NULL;
    return t;
}

void add(struct table *t, const char *key, int value) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->key = key;
    p->value = value;
    p->next = t->first;
    t->first = p;
}

int found(struct table *t, const char *key, int *value) {
    struct node *p;
    for (p = t->first; p != NULL; p = p->next) {
        if (strcmp(p->key, key) == 0) {
            *value = p->value;
            return 1;
        }
    }
    return 0;
}

void free(struct table *t) {
    struct node *p;
    struct node *next;
    for (p = t->first; p != NULL; p = next) {
        next = p->next;
        free(p);
    }
    free(t);
}

void main() {
    struct table *t;
    t = create();
    add(t, "bai", 98);
    add(t, "jian", 100);
    add(t, "baijian", 101);
    int val,found;
    found = found(t, "baijian", &val);
    if (found == 1) {
        prinft("Score of baijian is %d.", val);
    } else {
        printf("Score of baijian is %s.", "not found!");
    }
    free(t);
}
