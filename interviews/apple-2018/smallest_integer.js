/*
Given a dynamic arraylist of integers, create a solution which finds the minimum value integer in O(1) complexity (not O(n))
*/
smallestInteger = (stack,numbers,k) => {
	if (stack.length == 0){
		stack.push(numbers[k]);
	}
	if (numbers[k] <= stack[stack.length-1]){
		stack.pop();
		stack.push(numbers[k]);
	} 
	return (k == 0) ? stack[stack.length-1] : smallestInteger(stack,numbers,k-1);
}

var smallestIntegerMain = function(numbers) {
	let stack = []; 
	let smallest = smallestInteger(stack,numbers,numbers.length - 1);
	return `the smallest integer is ${smallest}`;
}

var testCases = [[10,2,5,7,15,9,-34,66,-22], [99,1,2,3,4]];
for (let testCase of testCases){
	console.log(smallestIntegerMain(testCase));
}

/*
Time complexity is O(n)
Space complexity is O(n) where n is the number of items
*/

var Stack = function(object){
	this.items = [];
	this.smallest = [];
}

Stack.prototype.push = function(item){
	this.items.push(item);
	if (item <= this.smallest) this.smallest.push(item);
}

Stack.prototype.pop = () =>{
	if (this.items.length > 0) {
		// dont keep old/popped values in the smallest stack
		if (this.items[this.items.length-1] == this.smallest[this.smallest.length-1]) 
			{this.smallest.pop();}
		this.items[this.items.length-1].pop();
	}
}

Stack.prototype.peek = function(){
	return this.items[this.items.length-1];
}

Stack.prototype.getSmallest = function(){
	return this.smallest[this.smallest.length-1];
}

let stack = new Stack();
stack.push(10);
stack.push(2);
stack.push(5);
stack.push(7);
stack.push(15);
stack.push(9);
stack.push(-34);
stack.push(66);
stack.push(-22);

console.log(stack.getSmallest());

/*
Time complexity is O(1)
Space complexity is O(n)
*/