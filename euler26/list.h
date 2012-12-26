#ifndef LIST_H
#define LIST_H

typedef struct node {
	void *data;
	struct node *next;
} node;

typedef void (*destroyDataFunc)(void *data);
typedef struct list {
	node *head;
	destroyDataFunc destroyData;
} list;

list *createList(destroyDataFunc destroyData);
node *enlist(list *inputList, void *data);
node *delist(list *inputList);
void destroyList(list *old);

#endif