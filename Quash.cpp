#include "Quash.h"
#include <iostream>

using namespace std;

    Quash::Quash(){
        numElements = 0;
        heap = new node*[20]{nullptr};
        hashtable = new node*[43]{nullptr};
    }

    void Quash::setLinks(node* H, node* hea){

        H->link=hea;
        hea->link = H;
        
        return;
        }
    void Quash::insert(int item){
        cout << "insert" << endl;
        node* h = insertHeap(item);
        node* ha = insertHash(item);
        setLinks(h,ha);

    }
    node* Quash::insertHeap(int item){
        //insert heap
        node* *h = heap;
        cout << "heap" << endl;
        // if heap is empty
        if(numElements == 0){
            h[0] = new node(item,1);
            cout << "insert new heap" <<endl;
            numElements++;
            return h[0];
            cout << h[0]->value << " heap " << h[0]->count << endl;
        
            //n->link = h[0];
            //cout << h[0]->value << endl;
        }
        //if element exists
        else{
        for(int j = 0; j<numElements;j++){
            if(heap[j]->value == item){
                heap[j]->count++;
                cout << "element exists in heap" << endl;
                cout << h[j]->value << " heap " << h[j]->count << endl;
                return heap[j];
            }
        }
        }
        //add element to end of heap
        numElements++;
        int i = numElements-1;
        heap[i] = new node(item,1);
        //fix
        int parent = i/2;
        while(i!=0 &&heap[parent]>heap[i]){
            int temp = heap[i]->value;
            heap[i]->value = heap[parent]->value;
            heap[parent]->value = heap[temp]->value;
            i = parent;
        }
        cout << "heap fix" << endl;
        return heap[i];
        //n->link = heap[i];
        cout << " heap value " << heap[i]->value  << heap[i]->count << endl;


    }

	node* Quash::insertHash(int item){
        //insert in hash
        int hashF = abs(item%43);//get hash value
        if(item < 0){
            hashF += 43;
        }
        if(hashtable[hashF]==NULL){
            cout << "null " << endl;
        }
         node* n = hashtable[hashF];//point to linked list at hash

        
         //if no value in list
        if(n == NULL){
            n = new node(item,1);
            
            cout << "insert hash new node" << n->value << " " << n->count<<  endl;
            return n;
        }
        
         // if it doesnt exist

          if(lookup(item)==NULL){
            cout<<" it doesnt exist yet"<< endl;
            while(n->next != NULL){
                n = n->next;
            }
            n->next = new node(item,1);
        }
         return n->next;
        }


    

        //searched hashtable for item and returns pointer to node of found item or NULL
		node* Quash::lookup(int item){
            int hashF = abs(item%43);//get hash value
        if(item < 0){
            hashF += 43;
        }
        node* n = hashtable[hashF];
        while(n!=NULL){
            if(n->value == item){
                n->count++;
                cout << "item found, count = " << n->count << endl;
                return n;
            }
            n = n->next;
        }
        cout << "item not found" << endl;
        return n;
        }  // returns count of i in quash




		int deleteItem(int i){
            return 0;
        }
		void print(){
            return;
        }