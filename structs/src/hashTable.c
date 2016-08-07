#include "../header/hashTable.h"
#include <stdlib.h>
#include <stdio.h>

HashTable newHashTableInt(unsigned int size){

    HashTable ht = (HashTable) malloc(sizeof(struct _HashTable_));
    if(!ht){
    	perror("malloc");
    	exit(1);
	}

    ht->table = NULL;
    ht->size = size;
    return ht;
}

void deleteHashTableInt(HashTable ht){
    free(ht);
}

unsigned int calcHashHashTableInt(unsigned int size, int value){
    return value % size;
}
