/*
Daily Coding Problem: Problem #7

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/
 
var AlphabetCode = function(){};
AlphabetCode.prototype.decode = function(message) {
	//dp is optimal substructure, account for zero length string such as dp[0]
	let dp = Array(1+message.length).fill(0);
	//string is of length zero
	dp[0] = 1; // no ways to decode empty 
	//string is of length one
	dp[1] = parseInt(message[0]) == 0 ? 0 : 1; // there is no alphabet code for 0, 'a' starts at 1 

	//string is of length two or greater
	// go up to string length inclusive because index 0 is reserved for zero string
	for (let i = 2; i <= message.length; i++){
		let singleDigit = message.substring(i-1, i);
		let doubleDigit = message.substring(i-2, i);
		//console.log(singleDigit + ' ' + doubleDigit);
		//console.log(singleDigit[0]);
		if (1 <= parseInt(singleDigit)){
			dp[i] += dp[i-1];
			//console.log(dp[i]);
		}
		//console.log(doubleDigit[0]);
		if (doubleDigit[0] !='0' && parseInt(doubleDigit) <= 26){
			//console.log('double valid');
			dp[i] += dp[i-2];
		}
	}
	// filled out the dp array and returning the accumulation of all subproblems
	return dp[message.length];
};
combinations = new AlphabetCode();
console.log('Number of ways to decode 10 are: (1) ' + combinations.decode('10'));
console.log('Number of ways to decode 12 are: (2) ' + combinations.decode('12'));
console.log('Number of ways to decode 226 are: (3) ' + combinations.decode('226'));
console.log('Number of ways to decode 27 are: (1) ' + combinations.decode('27'));