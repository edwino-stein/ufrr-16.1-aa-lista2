#include "../header/hashTableRBT.h"
#include <stdlib.h>
#include <stdio.h>

HashTableIntRbt newHashTableIntRbt(unsigned int size){

    HashTableIntRbt ht = (HashTableIntRbt) newHashTableInt(size);

    ht->table = malloc(sizeof(RBTreeInt) * size);
    if(!ht->table){
    	perror("malloc");
    	exit(1);
	}

    for(int i = 0; i < size; i++)
        setKeyHashTableIntRbt(ht, i, NULL);

    return ht;
}

void deleteHashTableIntRbt(HashTableIntRbt ht){

    RBTreeInt rbt = NULL;
    for(int i = 0; i < ht->size; i++){
        rbt = getKeyHashTableIntRbt(ht, i);
        if(rbt != NULL) deleteRBTreeInt(rbt);
        setKeyHashTableIntRbt(ht, i, NULL);
    }

    free(ht->table);
    ht->table = NULL;
    deleteHashTableInt(ht);
}

RBTreeInt getKeyHashTableIntRbt(HashTableIntRbt ht, unsigned int key){
    return (key > ht->size) ? NULL : ((RBTreeInt *) ht->table)[key];
}

RBTreeInt setKeyHashTableIntRbt(HashTableIntRbt ht, unsigned int key, RBTreeInt rbt){
    ((RBTreeInt *) ht->table)[key] = rbt;
    return rbt;
}

bool insertHashTableIntRbt(HashTableIntRbt ht, int value){

    unsigned int hash = calcHashHashTableInt(ht->size, value);
    RBTreeInt rbt = getKeyHashTableIntRbt(ht, hash);

    if(rbt == NULL){
        rbt = newRBTreeInt();
        setKeyHashTableIntRbt(ht, hash, rbt);
    }

    insertRBTreeInt(rbt, value);
    return true;
}

bool hasValueHashTableIntRbt(HashTableIntRbt ht, int value){
    unsigned int hash = calcHashHashTableInt(ht->size, value);
    RBTreeInt rbt = getKeyHashTableIntRbt(ht, hash);

    if(rbt == NULL) return false;
    RBTreeNodeInt node = searchRBTreeInt(rbt, value);
    return node != NULL;
}

void fPrintfRBTreeInt(RBTreeNodeInt n, FILE * stream){
    if(n == NULL) return;
    fPrintfRBTreeInt(n->left, stream);
    fprintf(stream, " %d,", n->value);
    fPrintfRBTreeInt(n->right, stream);
}

void fPrintHashTableIntRbt(HashTableIntRbt ht, FILE * stream){

    RBTreeInt rbt = NULL;

    for(int i = 0; i < ht->size; i++){
        fprintf(stream, "%d ->", i);
        rbt = getKeyHashTableIntRbt(ht, i);

        if(rbt == NULL) fprintf(stream, " null;\n");
        else if(isEmptyRBTreeInt(rbt)) fprintf(stream, " null;\n");
        else{
            fPrintfRBTreeInt(rbt->root, stream);
            fprintf(stream, "\b;\n");
        }
    }
}
