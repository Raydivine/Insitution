#ifndef LinkedList_H
#define LinkedList_H

typedef struct{
	void *head;
	void *tail;
	} LinkedList;

LinkedList *list;

void List_addTail(LinkedList *list, void *element);
void *List_removeHead(LinkedList *list);




#endif // LinkList_H
