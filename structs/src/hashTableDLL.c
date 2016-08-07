#include "../header/hashTableDLL.h"
#include <stdlib.h>
#include <stdio.h>

HashTableIntDll newHashTableIntDll(unsigned int size){

    HashTableIntDll ht = (HashTableIntDll) newHashTableInt(size);

    ht->table = malloc(sizeof(LinkedListInt) * size);
    if(!ht->table){
    	perror("malloc");
    	exit(1);
	}

    for(int i = 0; i < size; i++)
        setKeyHashTableIntDll(ht, i, NULL);

    return ht;
}

void deleteHashTableIntDll(HashTableIntDll ht){

    LinkedListInt lld = NULL;
    for(int i = 0; i < ht->size; i++){
        lld = getKeyHashTableIntDll(ht, i);
        if(lld != NULL) deleteLinkedListInt(lld);
        setKeyHashTableIntDll(ht, i, NULL);
    }

    free(ht->table);
    ht->table = NULL;
    deleteHashTableInt(ht);
}

LinkedListInt getKeyHashTableIntDll(HashTableIntDll ht, unsigned int key){
    return (key > ht->size) ? NULL : ((LinkedListInt *) ht->table)[key];
}

LinkedListInt setKeyHashTableIntDll(HashTableIntDll ht, unsigned int key, LinkedListInt dll){
    ((LinkedListInt *) ht->table)[key] = dll;
    return dll;
}

bool insertHashTableIntDll(HashTableIntDll ht, int value){

    unsigned int hash = calcHashHashTableInt(ht->size, value);
    LinkedListInt dll = getKeyHashTableIntDll(ht, hash);

    if(dll == NULL){
        dll = newLinkedListInt();
        setKeyHashTableIntDll(ht, hash, dll);
    }

    insetBackLinkedListInt(dll, value);
    return true;
}

bool hasValueHashTableIntDll(HashTableIntDll ht, int value){
    unsigned int hash = calcHashHashTableInt(ht->size, value);
    LinkedListInt dll = getKeyHashTableIntDll(ht, hash);

    if(dll == NULL) return false;
    LinkedListIntNode node = searchValueLinkedListInt(dll, value);
    return node != NULL;
}

void fPrintfLinkedListInt(LinkedListInt l, FILE * stream){
    LinkedListIntNode node = l->first;
    do{
        fprintf(stream, " %d,", node->value);
        node = node->next;
    }while(node != NULL);
}

void fPrintHashTableIntDll(HashTableIntDll ht, FILE * stream){
    LinkedListInt dll = NULL;

    for(int i = 0; i < ht->size; i++){
        fprintf(stream, "%d ->", i);
        dll = getKeyHashTableIntDll(ht, i);

        if(dll == NULL) fprintf(stream, " null;\n");
        else if(isEmptyLinkedListInt(dll)) fprintf(stream, " null;\n");
        else{
            fPrintfLinkedListInt(dll, stream);
            fprintf(stream, "\b;\n");
        }
    }
}
