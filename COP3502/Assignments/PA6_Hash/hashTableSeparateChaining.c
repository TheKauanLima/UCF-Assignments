// CS1: implementing separate chaining hashing
// Arup Guha Edited on 3/31/08 to implement a hashtable of strings.
// Further edited Tanvir Ahmed 4/8/2025 bug fixing and some reformatting

/*
Use the file (htableinput.txt) provided on webcouses. You can pass the following inputs during testing
htableinput.txt
1 cs
2 cs
3 cs
1 cs
3 cs
2 cs
1 cs
3 cs
4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 39
#define TABLE_SIZE 59999

// Struct used to form a linked list of strings
struct ll
{
    char word[MAX_SIZE + 1];
    struct ll *next;
};

struct htable
{
    struct ll *entries[TABLE_SIZE]; // array of linked list
};

// Linked List Functions
void dellist(struct ll *p);
int search(struct ll *front, const char word[]);
struct ll *insert_front(struct ll *front, const char word[]);
struct ll *delete(struct ll *front, const char word[]);

// Hash Table Functions
void initTable(struct htable *h);
int hashvalue(const char word[]);
void insertTable(struct htable *h, const char word[]);
int searchTable(struct htable *h, const char word[]);
void deleteTable(struct htable *h, const char word[]);
void killTable(struct htable *h);

int main()
{
    char filename[MAX_SIZE + 1], temp[MAX_SIZE + 1];
    FILE *ifp;
    int numwords, i;
    struct htable mytable;
    int ans;

    // Get the file name
    printf("What is the name of the dictionary file?\n");
    scanf("%s", filename);
    ifp = fopen(filename, "r");
    if (ifp == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    // Read the number of words
    fscanf(ifp, "%d", &numwords);
    printf("%d words\n", numwords);

    // Initialize the hash table and read words from the file
    initTable(&mytable);
    for (i = 0; i < numwords; i++)
    {
        fscanf(ifp, "%s", temp);
        insertTable(&mytable, temp);
    }

    fclose(ifp);

    // Allow the user to make changes to the hash table
    do
    {
        printf("Do you want to 1) search word, 2) add word, 3) delete a word?\n");
        scanf("%d", &ans);

        // Search for a word
        if (ans == 1)
        {
            printf("What word are you looking for?\n");
            scanf("%s", temp);

            if (searchTable(&mytable, temp))
            {
                printf("%s was found.\n", temp);
            }
            else
            {
                printf("%s was NOT found.\n", temp);
            }
        }

        // Add a word
        else if (ans == 2)
        {
            printf("What word do you want to add?\n");
            scanf("%s", temp);
            if (searchTable(&mytable, temp))
                printf("%s was ALREADY in the table\n", temp);
            else
                insertTable(&mytable, temp);
        }

        // Delete a word
        else if (ans == 3)
        {
            printf("What word do you want to delete?\n");
            scanf("%s", temp);
            deleteTable(&mytable, temp);
            printf("%s deletion processed\n", temp);
        }

    } while (ans >= 1 && ans <= 3);

    // Cleanup the hash table
    killTable(&mytable);

    printf("\nTable distroyed. Exiting...\n");

    return 0;
}

// print a given linked list (debugging purpose)
void print(struct ll *front)
{

    printf("Printing a list: ");
    while (front != NULL)
    {
        printf("%s ", front->word);
        front = front->next;
    }
    printf("\n");
}

// Initializes the hash table to be empty
void initTable(struct htable *h)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        h->entries[i] = NULL; // initialized the head each linked list to NULL
    }
}

// Cleans up all the memory used by the hash table
void killTable(struct htable *h)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        dellist(h->entries[i]);
    }
}

// Calculates the hash value of a word
int hashvalue(const char word[])
{
    int sum = 0;

    // Basically represents the value of word in base 128 (according to ascii
    // values) and returns its value mod the TABLE_SIZE.
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum = (128 * sum + (int)(word[i])) % TABLE_SIZE;
    }
    return sum;
}

// Inserts a word into the hash table
void insertTable(struct htable *h, const char word[])
{
    int hashval = hashvalue(word);
    h->entries[hashval] = insert_front(h->entries[hashval], word);
}

// Searches for a word in the hash table
int searchTable(struct htable *h, const char word[])
{
    int hashval = hashvalue(word);            // get the index of the linked list for searching
    return search(h->entries[hashval], word); // return the search result
}

// Deletes a word from the hash table
void deleteTable(struct htable *h, const char word[])
{
    int hashval = hashvalue(word);
    // printf("==before== %p ==", h->entries[hashval]);
    //   print(h->entries[hashval]);
    h->entries[hashval] = delete (h->entries[hashval], word);
    //  printf("==after== %p ==", h->entries[hashval]);
    //  print(h->entries[hashval]);
}

// Recursively frees all the memory used by a linked list
void dellist(struct ll *p)
{
    // Recursively free each element in the list.
    if (p != NULL)
    {
        dellist(p->next);
        free(p);
    }
}

// loop version
//  void dellist(struct ll *p) {
//      while (p) {
//          struct ll *temp = p;
//          p = p->next;
//          free(temp);
//      }
//  }

// Searches for a word in a linked list
int search(struct ll *front, const char word[])
{
    while (front)
    {
        if (strcmp(front->word, word) == 0)
        {
            return 1;
        }
        front = front->next;
    }
    return 0;
}

// Inserts a word at the front of the linked list
struct ll *insert_front(struct ll *front, const char word[])
{
    struct ll *temp;

    // Create temp node and link it to front.
    temp = (struct ll *)malloc(sizeof(struct ll));
    strcpy(temp->word, word);
    temp->next = front;

    // Return the new front of the list.
    return temp;
}

// Received the head of a linked list and deletes a given word from a linked list
struct ll *delete(struct ll *front, const char word[])
{
    struct ll *temp = front, *del;
    // nothing to do if the list is empty
    if (!temp)
        return NULL;

    // if the item is at the root
    if (temp && strcmp(temp->word, word) == 0)
    {
        front = temp->next;
        free(temp);
        return front;
    }

    // otherwise walk until you find the item to be deleted
    while (temp->next)
    {
        if (strcmp(temp->next->word, word) == 0)
        {
            del = temp->next;
            temp->next = temp->next->next;
            free(del);
            return front;
        }
        temp = temp->next;
    }

    return front;
}
