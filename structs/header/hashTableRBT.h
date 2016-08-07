#if !defined  _HASHTABLE_RBT
#define _HASHTABLE_RBT

    #include "hashTable.h"
    #include "RBTree.h"
    #include <stdio.h>

    typedef struct _HashTable_ *HashTableIntRbt;

    HashTableIntRbt newHashTableIntRbt(unsigned int size);
    void deleteHashTableIntRbt(HashTableIntRbt ht);

    RBTreeInt getKeyHashTableIntRbt(HashTableIntRbt ht, unsigned int key);
    RBTreeInt setKeyHashTableIntRbt(HashTableIntRbt ht, unsigned int key, RBTreeInt rbt);

    bool insertHashTableIntRbt(HashTableIntRbt ht, int value);
    bool hasValueHashTableIntRbt(HashTableIntRbt ht, int value);

    void fPrintHashTableIntRbt(HashTableIntRbt ht, FILE * stream);
    void fPrintfRBTreeInt(RBTreeNodeInt n, FILE * stream);

#endif
