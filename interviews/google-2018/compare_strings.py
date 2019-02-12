#!/usr/bin/env python
import argparse
import __builtin__

# Given two different strings, one with backspaces (keypresses), find if they are equivalent or not

def main():
    parser = argparse.ArgumentParser(description="Enter two strings without or without backspaces")
    parser.add_argument("s1", type=str, help="The first string.")
    parser.add_argument("s2", type=str, help="The second string.")
    args = parser.parse_args()
    print(compare(args.s1, args.s2))

def compare(s1, s2):
    BACKSPACE = '\b'
    cursor = 0;
    pointer1 = 0; pointer2 = 0; # current position in backspaced string. 

    cannon_len1 = len(s1); cannon_len2 = len(s2); # length of the cannonical string

    num_diff = 0
    while True:
        if s1[pointer1] == BACKSPACE or s2[pointer2] == BACKSPACE:
            # decrement the cursor and undo the previous compare
            cursor -= 1; 
            if s1[cursor] != s2[cursor]:
                num_diff -= 1
            # decrement the cannonical lengths appropriately
            cannon_len1 -= 2 if s1[pointer1] == BACKSPACE else 0
            cannon_len2 -= 2 if s2[pointer2] == BACKSPACE else 0
        else:

            if s1[pointer1] != s2[pointer2]:
                num_diff += 1
            cursor += 1

        # increment the pointers, making sure we don't run off then end 
        pointer1 += 1; pointer2 += 1;
        if pointer1 == len(s1) and pointer2 == len(s2):
            break
        if pointer1 == len(s1): pointer1 -= 1
        if pointer2 == len(s2): pointer2 -= 1

    return num_diff == 0 and cannon_len1 == cannon_len2

if __name__ == "__main__":
    main()