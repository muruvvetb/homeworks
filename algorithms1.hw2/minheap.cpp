//Mürüvvet Bozkurt 150160133
//This file contains functions of Minheap class. This is Minheap algorithm.
#include "event.cpp"

using namespace std;

Minheap::Minheap(vector<Event> heaparr1){
	heapsize = 0;
	heaparr = heaparr1;

}
int Minheap::leftchild(int i){  
	return 2*i + 1;
}
int Minheap::rightchild(int i){
	return 2*i + 2;
}
int Minheap::parent(int i){
	return (i-1) / 2;
}

void swap(Event* x, Event* y) { //swap function
    Event temp = *x; 
    *x = *y; 
    *y = temp; 
} 

bool Minheap::insert(Event key){  //insert new elements to heap tree.We will use to create heap tree.

	heapsize = heapsize + 1; 
	heaparr[heapsize - 1]=key;
	HeapifyUp(heapsize -1);  //correction according to minheap algoritm.
	return true;
}

void Minheap::HeapifyUp(int i){  //correction according to minheap algoritm.
	if(i == 0){
		return;
	}
	int p = parent(i);
	if(heaparr[p].getTime() > heaparr[i].getTime()){
		swap(&heaparr[i], &heaparr[p]);
		HeapifyUp(p);  // call recursively HeapifyUp fuct until parent is smaller than child.
	}
}
Event Minheap::drop(){
	Event root= heaparr[0];
	heaparr[0]=heaparr[heapsize-1]; // swap each other first element and last element of heap tree 
	heapsize= heapsize - 1; // Thus, we cannot reach last elements.
	
	HeapifyDown(0); // delete first element of heap tree every time.
	return root;
} 
void Minheap::HeapifyDown(int i){   //correction according to minheap algoritm.
	int l = leftchild(i);
	int r = rightchild(i);
	int min; //hangi düðümdeyim

	if(r >= heapsize){
		if(l >= heapsize) return;
		else min = l;
	}

	else{
		if(heaparr[l].getTime() <= heaparr[r].getTime()){
			min = l;
		}
		else{
			min = r;
		} 
	}
	if(heaparr[min].getTime() < heaparr[i].getTime()){
		swap(&heaparr[i], &heaparr[min]);
		HeapifyDown(min);
	}
}


