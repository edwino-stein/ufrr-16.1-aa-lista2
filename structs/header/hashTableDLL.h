#if !defined  _HASHTABLE_DLL
#define _HASHTABLE_DLL

    #include "hashTable.h"
    #include "linkedList.h"
    #include <stdio.h>

    typedef struct _HashTable_ *HashTableIntDll;

    HashTableIntDll newHashTableIntDll(unsigned int size);
    void deleteHashTableIntDll(HashTableIntDll ht);

    LinkedListInt getKeyHashTableIntDll(HashTableIntDll ht, unsigned int key);
    LinkedListInt setKeyHashTableIntDll(HashTableIntDll ht, unsigned int key, LinkedListInt dll);

    bool insertHashTableIntDll(HashTableIntDll ht, int value);
    bool hasValueHashTableIntDll(HashTableIntDll ht, int value);

    void fPrintHashTableIntDll(HashTableIntDll ht, FILE * stream);
    void fPrintfLinkedListInt(LinkedListInt l, FILE * stream);

#endif
