#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 30
typedef struct node {
    struct node *child[N];
    char *trans;
    int isEnd;
}node;

void create_tree(node *root) {
    int i;
    for(i=0; i<N; i++) {
        root->child[i] = NULL;
    }
    root->isEnd = 0;
    root->trans = NULL;
}

void add(node *root, char *str, char *tran) {
    int len, i;
    char ch;
    node *newnode;
    node *p;
    p = root;
    len = strlen(str);
    for(i=0; i<len; i++) {
        ch = str[i];
        if (p->child[ch - 'a'] != NULL)
        {
            p = p->child[ch - 'a'];
            continue;
        }
        newnode = (node*)malloc(sizeof(node));
        create_tree(newnode);
        p->child[ch-'a'] = newnode;
        p = newnode;
    }
    p->isEnd = 1;
    p->trans = tran;
}

int count_node(node *p) {
    int i, count;
    count = 0;
    if (p == NULL) {
        return count;
    }
    if (p->isEnd) {
        count++;
    }
    for(i = 0; i < N; i++) {
        count += count_node(p->child[i]);
    }
    return count;
}

int count_prefix(node *p, char *prefix) {
    int i, len;
    int count;
    node *q = p;
    char ch;
    len = strlen(prefix);
    count = 0;
    for(i = 0; i < len; i++) {
        ch = prefix[i];
        if (q->child[ch - 'a'] == NULL) {
            return 0;
        } else {
            q = q->child[ch - 'a'];
        }
    }
    return count_node(q);
}

void tranv(node *q) {
    int i;
    node *p;
    p = q;
    for(i = 0; i < N; i++) {
        if (p->child[i] == NULL){
            continue;
        } 
        printf("%c ", 'a' + i);
        tranv(p->child[i]);
    }
}

void freeall(node *p) {
    int i;
    for(i = 0; i < N; i++) {
        if(p->child[i] != NULL) {
            freeall(p->child[i]);
        }
    }
    free(p);
}

int find(node *p, char *str) {
    int i, len;
    char ch;
    node *p;
    p = q;
    len = strlen(str);
    for(i = 0; i < len; i++) {
        ch = str[i];
        if (p->child[ch - 'a'] != NULL) {
            p = p->child[ch - 'a'];
            if (p->isEnd) {
                printf("\n%s has been found!", str);
                printf("\nThe meaning of %s is %s!\n", str, p->trans);
                return 1;
            } else {
                break;
            }
        }
    }
    printf("\n%s has not been found!", str);
    return 0;
}

void get_prefix(node *p, char *prefix, char **out) {
    int i, len, j;
    char ch;
    char *common;
    node *q;
    q = p;
    len = strlen(prefix);
    if (count_prefix(p, prefix) == 0) {
        out = NULL;
        return;
    }
    common = (char*)malloc(sizeof(char)*len);
    for (i = 0; i < len; i++) {
        ch = prefix[i];
        q = q->child[ch - 'a'];
        common[i] = ch;
    }
    j = 0;
    if (q->isEnd) {
        out[j] = common;
    }
}

void main()
{
    node *p;
    char prefix[20];
    char xxx[] = "用户xxx";
    char baijian[] = "柏健";
    char ooo[] = "用户ooo";
    char keyword[20];
    p = (node*)malloc(sizeof(node));
    create_tree(p);
    add(p, "xxx", xxx);
    add(p, "baijian", baijian);
    add(p, "ooo", ooo);
    printf("Enter a name to serach:\n");
    scanf("%s", keyword);
    tranv(p);
    find(p, keyword);
    printf("\nEnter a prefix to search:\n");
    scanf("%s", prefix);
    printf("the prefix is %s\n", prefix);
    printf("The count of prefix '%s' is %d.\n", prefix, count_prefix(p, prefix));
    freeall(p);
}
