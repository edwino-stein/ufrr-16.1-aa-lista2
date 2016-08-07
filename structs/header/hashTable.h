#if !defined  _HASHTABLE
#define _HASHTABLE

    #include <stdbool.h>

    struct _HashTable_{
        void **table;
        unsigned int size;
    };

    typedef struct _HashTable_ *HashTable;

    HashTable newHashTableInt(unsigned int size);
    void deleteHashTableInt(HashTable ht);

    unsigned int calcHashHashTableInt(unsigned int size, int value);

#endif
