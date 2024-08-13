// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include <stdio.h>
// malloc, free
#include <stdlib.h>
// strcpy
#include <string.h>
// strcasecmp
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int i = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int j = hash(word);
    node*n = table[j];
    // 遍历链表
    while(n != NULL)
    {
        if(strcasecmp(n->word, word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE*file = fopen(dictionary,"r");
    char store[LENGTH + 1];

    if(file == NULL)
    {
        return false;
    }
    else
    {
        node*n = malloc(sizeof(node));
        if(n != NULL)
        {
            do
            {
                fscanf(file, "%s", store);
                strcpy(n->word, store);
                int number = hash(store);
                n->next = table[number];
                table[number] = n;
                i++;
            }while(fscanf(file, "%s", store)!= EOF);
        }
        else
        {
            return false;
        }

    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return i;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int k = 0; k<N;  k++)
    {
        node*n = table[k];
        while(n != NULL)
        {
            tmp = n->next;
            free(n);
            n = tmp;
        }         //且
        if(k = n-1 && n == NULL)
        {
            return true;
        }
    }
    //如果没有提前返回 true，则函数返回 false
    return false;
}
