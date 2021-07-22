/* 
Given a string word, count the minimum number of characters that needs to be added to word to make it anadrome - a string which is an anagram of some palindrome. 

Examples:
word = "tatoo"
0
"tatoo" is already an anagram of a palindrome "otato"

word = "abcb"
1
Add either 'a' or 'c'. "abcba" is palindrome already, "abcbc" is an anagram of a palindrome "cbabc"

word = "abab"
0
"abab" is already an anagram of a palindrome "abba"

word = "abc"
2
Add 'a' and 'b' to the string word. "abcab" is an anagram of a palindrome "abcba"
*/

/*
tatoo
t -> 2
a -> 1
o -> 2
otato

abcb
a -> 2
b -> 2
c -> 1
abcba
*/
import java.io.*;
import java.util.*;

class Solution {
  public static int minimumCount(String input) {
    if(input == null || input.trim().isEmpty()) {
      return 0;
    }
    Map<Character, Integer> even = new HashMap<>();
    Map<Character, Integer> odd = new HashMap<>();
    for(char c:input.toCharArray()) {
      if(even.containsKey(c)) {
        odd.put(c, even.remove(c)+1);
      } else if(odd.containsKey(c)) {
        even.put(c, odd.remove(c)+1);
      } else {
        odd.put(c,1);
      }
    }
    System.out.println("Characters needed for " + input);
    if(odd.size()>1) {
      int count = odd.keySet().size();
      for(char c: odd.keySet()) {
        System.out.println(c);
        count--;
        if(count == 1) break;
      }
    }
    return (odd.size()>1)? odd.size()-1:0;
  }
  public static void main(String[] args) {
    System.out.println(minimumCount(null) == 0);
    System.out.println(minimumCount(" ") == 0);
    System.out.println(minimumCount("") == 0);
    System.out.println(minimumCount("tatoo") == 0);
    System.out.println(minimumCount("abcb") == 1);
    System.out.println(minimumCount("abab") == 0);
    System.out.println(minimumCount("abc") == 2);
  }
}

/*
Complexity: 
time: O(n)
space: O(n)
*/