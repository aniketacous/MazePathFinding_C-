#include "disjointSet.h"

DisjointSet::DisjointSet(int n) {

   		elements = new int[n];
   		rank = new int[n];
   		for(int i = 0; i < n; i++) {
   			elements[i] = i;
   			rank[i] = 0;
   		}	
}

DisjointSet::~DisjointSet() {
	delete[] elements;
	delete[] rank;
}

int DisjointSet::find(int a) {
	  if(elements[a] == a)
	  	return a;
	  else {
	  	 elements[a] = find(elements[a]);
	  	 return elements[a];
	  }       
}

void DisjointSet::Join(int a, int b) {
		a = find(a);
      	b = find(b);
      	if(!(a == b)) {
      		if(rank[a] < rank[b]) {
      			elements[a] = b;
      		}
      		else if(rank[a] > rank[b]) {
      			elements[b] = a;
      		}
      		else {
      			rank[a] = rank[a] + 1;
      			elements[b] = a;
      		}
      	}
        	
}