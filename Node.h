// node.h

#ifndef NODE_H
#define NODE_H

struct node {
    public: 
	node(int val,int cou){
        value = val;
        count = cou;
        next = nullptr;
        link = nullptr;

    } 
    node(){
        value = 0;
        count = 0;
        next = nullptr;
        link = nullptr;

    }

	int value;
	int count;
	node *next;  // pointer to next node in linkedlist (points to nullptr in heapArray nodes)
	node *link;  // pointer to hashArray/heapArray's corresponding node
};

#endif