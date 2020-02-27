/*
Given an array of integers, find the first missing positive integer in linear time and constant space. 
In other words, find the lowest positive integer that does not exist in the array. 
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

MissingPositive = function() {}

MissingPositive.prototype.first = (nums) => {
	try{
		validate(nums);
		
		var map = [];
	    for (i = 0, l = nums.length; i <= l - 1; i++) {
	        if (nums[i] > 0) {
	            map[nums[i]] = true;
	        }
	    }
	    for (i = 1, l = map.length; i <= l - 1; i++) {
	        if (!map[i]) {
	            return i;
	        }
	    }
	    return i;

	}
	catch(err){
		console.log(err);
		return false;
	}
};

function validate(list){
	if (list && list.length > 0){
		checkInteger = function(element){
			return Number.isInteger(element);
		}

		if (list.every(checkInteger) == false){
			throw "List does not contain integers";
		}
	} else {
		throw "List is not valid";
	}
}

// module.exports = MissingPositive

/*
See also:
https://www.geeksforgeeks.org/find-the-first-missing-number/
 */