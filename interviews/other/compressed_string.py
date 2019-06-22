'''
Given a non-empty string, create a function to return a compressed string that contains each letter and its occurence in order. 
For example, given the string 'aaabbbbcca', return 'a3b4c2a'. Assume that the function takes in only letters case insensitive, 
and compressed string has to be smaller than the original string
'''
def compress_string(original_string):
    try:
        validate(original_string)
        compressed_string = '' 
        current_letter = ['',0]
        for index, letter in enumerate(original_string):
            # if beginning of string, initialize
            if index == 0:
                current_letter[0] = letter
                current_letter[1] = 1
            # if letter has changed, update compressed substring
            elif current_letter[0] != letter:
                compressed_string += current_letter[0] + str(current_letter[1])
                current_letter[0] = letter
                current_letter[1] = 1
            else:
                current_letter[1] += 1 # increment counter
        
        # if end of string, update compressed substring
        compressed_string += current_letter[0] + str(current_letter[1])
        
        if len(compressed_string) < len(original_string):
            return 'The compressed string is {0}.'.format(compressed_string)
        else:
            raise ValueError('Compressed string is not smaller than the original string')
    except Exception as e:
        return e
    

def validate(string):
    # isalpha() checks for trimmed whitespace, special characters, numbers
    if not string.isalpha():
        raise ValueError('String is not valid')

# Driver program to test good and bad cases
test_cases = ['1234',' ','?()','a7r','yy%','aaabbbbcca','AZTEEER', 'QWERTY']
for test_case in test_cases:
    print 'Given {0}. {1}'.format(test_case, compress_string(test_case))


'''
other questions
https://stackoverflow.com/questions/43841930/in-react-what-is-the-difference-between-setstate-and-forceupdate
'''