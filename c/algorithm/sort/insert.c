#include <stdio.h>

struct list
{
    struct list *   next;
    int             val;
};
struct list * insert_sort(struct list * p);
struct list * insert_sort2(struct list * p);

int main(void)
{
}

struct list * insert_sort(struct list * p)
{
    if (p == NULL || p->next == NULL) {
        return p;
    }
    struct list * head = NULL;
    while(p != NULL) {
        struct list * current = p;
        p = p->next;
        if (head == NULL || current->val < head->val) {
            current->next = head;
            head = current;
        } else {
            struct list * pl = head;
            while(pl != NULL) {
                if (pl->next == NULL || current->val < pl->next->val) {
                    current->next = pl->next;
                    pl->next = current;
                    break;
                }
                pl = pl->next;
            }
        }
    }
    return head;
}

struct list * insert_sort2(struct list * p)
{
    if (p == NULL || p->next == NULL) {
        return p;
    }
    struct list * head = NULL;
    while(p != NULL) {
        struct list * current = p;
        struct list ** phead = &head;
        p = p->next;
        while(*phead != NULL && (*phead)->val != NULL && current->val > (*phead)->val) {
            phead = &(*phead)->next;
        }
        current->next = *phead;
        *phead = current;
    }
    return head;
}
