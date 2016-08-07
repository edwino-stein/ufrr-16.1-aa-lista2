#include "../header/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

LinkedListInt newLinkedListInt(){

    LinkedListInt l = malloc(sizeof(struct _LinkedListInt_));

    if(!l){
    	perror("malloc");
    	exit(1);
	}

    l->first = NULL;
    l->last = NULL;
    l->size = 0;

    return l;
}

void deleteLinkedListInt(LinkedListInt l){


    if(l->first != NULL){

        LinkedListIntNode current = l->first;

        while (current->next != NULL) {
            current = current->next;
            deleteLinkedListIntNode(current->prev);
        }

        deleteLinkedListIntNode(current);
    }

    free(l);
}

int insetBackLinkedListInt(LinkedListInt l, int value){

    LinkedListIntNode n = NULL;

    if(isEmptyLinkedListInt(l)){
        n = newLinkedListIntNode(value, NULL, NULL);
        l->last = n;
        l->first = n;
    }
    else{
        n = newLinkedListIntNode(value, l->last, NULL);
        l->last->next = n;
        l->last = n;
    }

    return l->size++;
}

int insetFrontLinkedListInt(LinkedListInt l, int value){

    LinkedListIntNode n = NULL;

    if(isEmptyLinkedListInt(l)){
        n = newLinkedListIntNode(value, NULL, NULL);
        l->last = n;
        l->first = n;
    }
    else{
        n = newLinkedListIntNode(value, NULL, l->first);
        l->first->prev = n;
        l->first = n;
    }

    l->size++;
    return 0;
}

bool removeLinkedList(LinkedListInt l, unsigned int index){
    if(isEmptyLinkedListInt(l)) return false;

    LinkedListIntNode n = getLinkedListIntNode(l, index);
    if(n == NULL) return false;
    return removeLinkedListNode(l, n);
}

bool removeLinkedListNode(LinkedListInt l, LinkedListIntNode n){

    if(isEmptyLinkedListInt(l)) return false;

    if(l->size == 1){
        l->first = NULL;
        l->last = NULL;
    }

    else{
        if(l->first == n){
            l->first = n->next;
            l->first->prev = NULL;
        }

        else if(l->last == n){
            l->last = n->prev;
            l->last->next = NULL;
        }

        else{
            n->prev->next = n->next;
            n->next->prev = n->prev;
        }
    }

    deleteLinkedListIntNode(n);
    l->size--;
    return true;
}

LinkedListIntNode searchValueLinkedListInt(LinkedListInt l, int value){

    if(isEmptyLinkedListInt(l))return NULL;

    LinkedListIntNode n = l->first;
    while(n != NULL){
        if(n->value == value) break;
        n = n->next;
    }

    return n;
}

LinkedListIntNode getLinkedListIntNode(LinkedListInt l, unsigned int index){

    if(isEmptyLinkedListInt(l) || l->size <= index){
        return NULL;
    }

    LinkedListIntNode n = l->first;
    unsigned int i = 0;

    while(i < index && n != NULL){
        n = n->next;
        i++;
    }

    return n;
}

int getLinkedListIntValue(LinkedListInt l, unsigned int index){

    if(isEmptyLinkedListInt(l) || l->size <= index){
        printf("Indice fora do limite da lista");
        exit(1);
    }

    return getLinkedListIntNode(l, index)->value;
}

LinkedListIntNode newLinkedListIntNode(int value, LinkedListIntNode prev, LinkedListIntNode next){

    LinkedListIntNode n = malloc(sizeof(struct _LinkedListIntNode_));

    if(!n){
    	perror("malloc");
    	exit(1);
	}

    n->value = value;
    n->prev = prev;
    n->next = next;

    return n;
}

void deleteLinkedListIntNode(LinkedListIntNode n){
    free(n);
}

bool isEmptyLinkedListInt(LinkedListInt l){
    return l->size <= 0;
}
