
// Quash.h

#ifndef QUASH_H
#define QUASH_H
#include "Heap.h"
#include "Node.h"
#include "Hashtable.h"
#include <utility>

class Quash {

	public:
		Quash();
		//~Quash();
		
		// PUBLIC METHODS
        void fixHeap(node* n);
        void setLinks(node *H, node* hea);
		node* insertHash(int item); 
        void insert(int item);
        node* insertHeap(int item); // returns count of i in quash after insert
		node* lookup(int item);  // returns count of i in quash
		int deleteItem(int i);  // returns count of i in quash after delete, -1 if not found
		int deleteMin();  // .first=(the item deleted) .second=(new count of min item, -1 if empty table)
		void print();  // prints Minheap array with elements seperated by whitespace

	
        int index;
        int numElements;
		node* *heap;  // minheap implemented as array of nodes
		node* *hashtable;  // hashtable implemented as array of nodes

};

#endif