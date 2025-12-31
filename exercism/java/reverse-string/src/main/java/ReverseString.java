class ReverseString {

    String reverse(String inputString) {
    	inputString = validate(inputString);
        int counter = inputString.length()-1;
        String reverseString = "";
        while (counter >= 0) {
        	reverseString = reverseString + inputString.charAt(counter);
        	counter--;
        }
        return reverseString;
    }

    private String validate(String input) {
    	if (input == null){
    		throw new NullPointerException("Input is null");
    	}
    	input = input.trim();
    	return input;
    }
}