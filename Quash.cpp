#include "Quash.h"
#include <iostream>

using namespace std;

    Quash::Quash(){
        numElements = 0;
        heap = new node*[100]{nullptr};
        hashtable = new node*[43]{nullptr};
    }


    void Quash::fixHeap(node * n){	

	return;
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
        node* n = heap[i];
        n = new node(item,1);
       n->index = i;
        //fixHeap(n);
        return n;
        


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

        cout << "null" << endl;
         //if no value in list
        if(hashtable[hashF] == NULL){
            cout << "now" << endl;
            node* x = new node(item,1);
            hashtable[5] = x;

            
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




		int Quash::deleteItem(int i){
            if(lookup(i)==NULL){
                cout << "item not in table" << endl;
                return -1;
            }
            node* n = lookup(i);
            n->count--;
            if(n->count == 0){
                //remove node from hash
            }
            return 0;
        }

        int Quash::deleteMin(){
            return 0;

        }
		void Quash::print(){
             node* *h = heap;
             cout << "heap content" << endl;
             for(int i = 0; i< numElements ; i++){
                 cout  << h[i]->value << " " << endl;
             }

            return;
        }