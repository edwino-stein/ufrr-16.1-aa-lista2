#if !defined  _LINKEDLIST
#define _LINKEDLIST

    #include <stdbool.h>

    struct _LinkedListIntNode_{
        int value;
        struct _LinkedListIntNode_ *next;
        struct _LinkedListIntNode_ *prev;
    };

    typedef struct _LinkedListIntNode_ *LinkedListIntNode;

    struct _LinkedListInt_{
        LinkedListIntNode first;
        LinkedListIntNode last;
        unsigned int size;
    };

    typedef struct _LinkedListInt_ *LinkedListInt;

    LinkedListInt newLinkedListInt();
    void deleteLinkedListInt(LinkedListInt l);

    int insetBackLinkedListInt(LinkedListInt l, int value);
    int insetFrontLinkedListInt(LinkedListInt l, int value);

    bool removeLinkedList(LinkedListInt l, unsigned int index);
    bool removeLinkedListNode(LinkedListInt l, LinkedListIntNode n);

    LinkedListIntNode searchValueLinkedListInt(LinkedListInt l, int value);

    LinkedListIntNode getLinkedListIntNode(LinkedListInt l, unsigned int index);
    int getLinkedListIntValue(LinkedListInt l, unsigned int index);

    LinkedListIntNode newLinkedListIntNode(int value, LinkedListIntNode prev, LinkedListIntNode next);
    void deleteLinkedListIntNode(LinkedListIntNode n);

    bool isEmptyLinkedListInt(LinkedListInt l);

#endif
