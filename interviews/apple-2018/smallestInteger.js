/*
Given a dynamic arraylist which contains integers, create a solution which finds the minimum value integer in O(1) complexity (not O(n))
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

var smallestIntegerMainFunction = function(numbers) {
	let stack = []; 
	let smallest = smallestInteger(stack,numbers,numbers.length - 1);
	return `the smallest integer is ${smallest}`;
}

var testCases = [[10,2,5,7,15,9,-34,66,-22], [99,1,2,3,4]];
for (let testCase of testCases){
	console.log(smallestIntegerMainFunction(testCase));
}

/*
Time complexity is O(n)
*/