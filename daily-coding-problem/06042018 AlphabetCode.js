/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
 */

AlphabetCode = function() {}

AlphabetCode.prototype.decode = function(message) {
	try {
		validate(message);
		return true;
	} catch(err) {
		console.log(err);
		return false;
	}
}

validate = function(message) {
	if (message) {

	} else {
		throw "Not a valid message"
	}
}

var alphabetCode = new AlphabetCode();
console.log("message is undefined:", alphabetCode.decode(undefined) == false);
console.log("message is null:", alphabetCode.decode(null) == false);
console.log("message is blank:", alphabetCode.decode('') == false);
console.log("message has letters:", alphabetCode.decode('omg') == false);