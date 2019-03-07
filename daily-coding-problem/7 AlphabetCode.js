/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
 */
 
AlphabetCode = function() {
	var mapping = {}
	var sentence = 'abcdefghijklmnopqrstuvwxyz';
	for (var i = 0; i < sentence.length; i++) {
	  mapping[sentence.charAt(i)] = (sentence.charCodeAt(i) -96)
	}

}

AlphabetCode.prototype.decode_helper = function(message,k) {
	
	if (k == 0 || k == 1) return 1;

	index = message.length - k; // current index left to right sequentially
	console.log("k", k, "current character",parseInt(message.charAt(index)));

	result = AlphabetCode.prototype.decode_helper(message, k-1);
	if ((k >= 2) && (parseInt(message.substring(index,index+2)) <= 26)){
		result += AlphabetCode.prototype.decode_helper(message, k-2);
	}
	return result; 
};

AlphabetCode.prototype.decode = function(message) {
	// BASE CASE: if empty or contains zeroes, it is not valid
	if (/^[1-9]+$/.test(message) == false){
		return "invalid"
	}
	return AlphabetCode.prototype.decode_helper(message,message.length);
}

var alphabetCode = new AlphabetCode();
console.log("result", alphabetCode.decode('112'));


//aab kb al lb