/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
 */
 


AlphabetCode = function() {
	this.decodings = [];
	this.mapping = {};
	var letters = 'abcdefghijklmnopqrstuvwxyz';
	for (var i = 0; i < letters.length; i++) {
	  this.mapping[letters.charAt(i)] = (letters.charCodeAt(i) - 96)
	}
}

AlphabetCode.prototype.getDecodings = function() {
  return this.decodings;
};

AlphabetCode.prototype.decode_helper = function(message,k) {
	
	if (k == 0) return 1; // "" is 1

	index = message.length - k;
	if (parseInt(message.charAt(index)) == 0){
		return 0; // starting with "0" is 0
	}
	
	this.decodings.push(
		parseInt(message.charAt(index))
		);

	result = AlphabetCode.prototype.decode_helper(message, k-1);
	if ((k >= 2) && (parseInt(message.substring(index,index+2)) <= 26)){
		result += AlphabetCode.prototype.decode_helper(message, k-2);

		this.decodings.push(
			parseInt(message.substring(index,index+2))
			);

	}
	return result; 
};

AlphabetCode.prototype.decode = function(message) {
	if (/^[0-9]+$/.test(message) == false){
		return "invalid"
	}

	return AlphabetCode.prototype.decode_helper(message,message.length);
}

var alphabetCode = new AlphabetCode();
console.log(alphabetCode.getDecodings
console.log("result", alphabetCode.decode('12345'));


//aab kb al lb