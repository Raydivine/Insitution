





typedef struct{

 void *head;

 void *tail;

 } LinkedList;







void List_addTail(LinkedList *list, void *element);

void *List_removeHead(LinkedList *list);

void List_create();
