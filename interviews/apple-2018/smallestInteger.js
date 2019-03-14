/*
Given a dynamic arraylist which contains integers, create a solution which finds the minimum value integer in O(1) complexity (not O(n))
*/
smallestInteger = (stack,numbers,k) => {
	if (numbers[k] > stack[stack.length-1]){
		stack.pop();
		stack.push(numbers[k]);
	}
	console.log("k:" + k);
	return (k == 0) ? stack[stack.length-1] : smallestInteger(stack,numbers,k-1);
}

var smallestInteger = function(numbers) {
	let stack = [];
	console.log(numbers); // is zero
	let smallest = smallestInteger(stack,numbers,numbers.length - 1);
	return `the smallest integer is ${smallest}`;
}

var testCases = [[10,2,5,7,15,9], [1,2,3,4]];
for (let testCase of testCases){
	console.log(testCase);
	console.log(smallestInteger(testCase));
}

