/*
An XOR linked list is a more memory efficient doubly linked list. 
Instead of each node holding next and prev fields, it holds a field named both, 
which is an XOR of the next node and the previous node. Implement an XOR linked list; 
it has an add(element) which adds the element to the end, and a get(index) which 
returns the node at index.

If using a language that has no pointers (such as Python), you can assume you 
have access to get_pointer and dereference_pointer functions that converts between 
nodes and memory addresses.
 */

Node = function(prev, value, next){
	this.value = value;
	this.both = prev ^ next;
}


function XORLinkedList = () => {
	this.head = null;
	this.size = 0;
}

XORLinkedList.prototype.add(element){

}

XORLinkedList.prototype.get(index){

}


/*
4 6 7

000
100

100
110

010
*/