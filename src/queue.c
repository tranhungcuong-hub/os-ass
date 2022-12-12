#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q->size == MAX_QUEUE_SIZE)
		return;
	q->proc[q->size] = proc;
	q->size++;
	return;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	uint32_t priority = 100000;
	int flag = 0;
	for(int i = 0; i < q->size; i++){
		if(q->proc[i]->priority < priority){
			priority = q->proc[i]->priority;
			flag = i;
		}
	}
	struct pcb_t * data = q->proc[flag];
	for(int i = flag; i < q->size; i++){
		if(i + 1 > q->size)
			break;
		q->proc[i] = q->proc[i+1];
	}
	q->size--;
	return data;
}

