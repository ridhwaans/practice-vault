/* 	
Given an array of integers, return a new array such that each element at 
index i of the new array is the product of all the numbers in the original
array except the one at i. For example, if our input was [1, 2, 3, 4, 5],
the expected output would be [120, 60, 40, 30, 24]. If our input was
[3, 2, 1], the expected output would be [2, 3, 6].
*/

var ProductArray = function() {};

ProductArray.prototype.calculate = function(list){
	try {
		validate(list);
		return getProduct(list,0,[]);
	} catch (err){
		console.error(err);
	}	
};

function getProduct(array, i, newArray){	
	// Base cases
	if (array.length < 2) {
		return array;
	}
	if (i == array.length) {
		return newArray;
	}

	let j = 0, product = 1;

	while (j < array.length) {
		if (j == i) {
			j++;
			continue;
		}	
		product = product * array[j];
		j++;
	}

	newArray.push(product);
	return getProduct(array, i+1, newArray);
}

validate = (list) => {
	if (list == undefined || list == null) {
		throw "Not a valid list";
	}

	isInteger = function(element) {
		return Number.isInteger(element);
	}

	if (list.every(isInteger) == false) {
		throw "List does not contain integers";
	}
};

var productArray = new ProductArray();
console.log(productArray.calculate(null)); 
console.log(productArray.calculate(undefined)); 
console.log(productArray.calculate([null, 4, 5])); 
console.log(productArray.calculate(['test', 4, 5])); 
console.log(productArray.calculate([0.4, 4, 5])); 
console.log(productArray.calculate([4]));  // output [ 4 ]
console.log(productArray.calculate([1,2,3,4,5])); // output [120, 60, 40, 30, 24]
console.log(productArray.calculate([10, 0, 3, 2, 1])); // output [ 0, 60, 0, 0, 0 ]

/*
See also:
https://www.geeksforgeeks.org/a-product-array-puzzle/
*/