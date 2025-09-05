#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 31

typedef struct node
{
    int count;
    struct node *children[26];
} node;

node *createNode()
{
    node *t = (node *)malloc(sizeof(node));
    t->count = 0;
    for (int i = 0; i < 26; i++)
        t->children[i] = NULL;
    return t;
}

void insert(node *trie, char str[], int k)
{
    if (str[k] == '\0')
    {
        trie->count++;
        return;
    }

    int ind = str[k] - 'a';
    if (!trie->children[ind])
        trie->children[ind] = createNode();
    insert(trie->children[ind], str, k + 1);
}

int search(node *trie, char key[], int k)
{
    if (key[k] == '\0')
        return trie->count;

    int ind = key[k] - 'a';
    if (!trie->children[ind])
        return 0;

    return search(trie->children[ind], key, k + 1);
}

int isEmpty(node *trie)
{
    for (int i = 0; i < 26; i++)
    {
        if (trie->children[i])
            return 0;
    }
    return 1;
}

node *delete(node *trie, char key[], int k)
{
    if (!trie)
        return NULL;

    if (key[k] == '\0')
    {
        if (trie->count > 0)
            trie->count--;

        if (isEmpty(trie) && trie->count == 0)
        {
            free(trie);
            trie = NULL;
        }
        printf("\ndeleted %s\n", key);
        return trie;
    }

    int ind = key[k] - 'a';
    trie->children[ind] = delete (trie->children[ind], key, k + 1);

    if (isEmpty(trie) && trie->count == 0)
    {
        free(trie);
        trie = NULL;
    }
    return trie;
}

void printAll(node *trie, char cur[])
{
    if (!trie)
        return;

    if (trie->count > 0)
        for (int i = 0; i < trie->count; i++)
            printf("\n%s", cur);

    int len = strlen(cur);
    for (int i = 0; i < 26; i++)
    {
        cur[len] = (char)('a' + i);
        cur[len + 1] = '\0';
        printAll(trie->children[i], cur);
    }
}

int wordsEndWithQ(node *trie)
{
    if (!trie)
        return 0;

    int sum = 0;
    for (int i = 0; i < 26; i++)
    {
        sum += wordsEndWithQ(trie->children[i]);
    }
    if (trie->children[16])
        sum += trie->children[16]->count;
    return sum;
}

int nodesReq(node *trie, char str[])
{
    int i, len = strlen(str);
    for (i = 0; i < len; i++)
    {
        int ind = str[i] - 'a';
        if (trie->children[ind])
            trie = trie->children[ind];
        else
            break;
    }
    return len - i;
}

int main(void)
{
    node *trie = createNode();

    int numWords;
    scanf("%d", &numWords);

    printf("\nscanning file...\n");
    for (int i = 0; i < numWords; i++)
    {
        char str[SIZE];
        scanf("%s", str);
        insert(trie, str, 0);
    }
    printf("\nscanned!\n");

    while (1)
    {
        printf("\nsearch? (0/1):");
        int cmd;
        scanf("%d", &cmd);
        if (!cmd)
            break;

        printf("\nenter word to search: ");
        char key[SIZE];
        scanf("%s", key);
        printf("word count (%s): %d", key, search(trie, key, 0));
    }

    while (1)
    {
        printf("\ndelete? (0/1):");
        int cmd;
        scanf("%d", &cmd);
        if (!cmd)
            break;

        printf("\nenter word to delete: ");
        char key[SIZE];
        scanf("%s", key);
        delete (trie, key, 0);
    }

    while (1)
    {
        printf("\nsearch? (0/1):");
        int cmd;
        scanf("%d", &cmd);
        if (!cmd)
            break;

        printf("\nenter word to search: ");
        char key[SIZE];
        scanf("%s", key);
        printf("word count (%s): %d", key, search(trie, key, 0));
    }

    char cur[SIZE];
    cur[0] = '\0';
    printAll(trie, cur);
    printf("\nWords that end with Q: %d", wordsEndWithQ(trie));
}