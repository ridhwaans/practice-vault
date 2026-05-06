#include <stdlib.h>
#include <string.h>

char *longestPalindrome(char *s) {
  int size = strlen(s);
  int substrIdx[2] = {-1, -1};

  for (int i = 0; i < size; i++) {
    int l, r;
    // incorrect. A string’s total length parity has nothing to do with an
    // individual palindrome’s parity. A string can contain both odd-length
    // palindromes and even-length palindromes if (size % 2 != 0){ odd
    l = i, r = i;
    while (l >= 0 && r < size && s[l] == s[r]) {
      // original mistakes
      // putting s[l] != s[r] and s[l] == s[r] in an if statement inside while
      // loop and not inline with while need to stop expanding when not a
      // contigious match
      if ((r - l + 1) > (substrIdx[1] - substrIdx[0])) {
        substrIdx[0] = l;
        substrIdx[1] = r;
      }
      l--;
      r++;
    }
    // incorrect
    // break;
    // }

    // even
    l = i, r = i + 1;
    while (l >= 0 && r < size && s[l] == s[r]) {
      if ((r - l + 1) > (substrIdx[1] - substrIdx[0])) {
        substrIdx[0] = l;
        substrIdx[1] = r;
      }
      l--;
      r++;
    }
  }

  int len = substrIdx[1] - substrIdx[0] + 1;
  char *substr = malloc(len + 1); // +1 for null terminator
  if (!substr)
    return NULL; // !substr is empty string 0 len expression
  for (int i = 0; i < len; i++) {
    // substr[i] = s[i]; // bug - copies s from the start, not from the
    // palindrome start
    substr[i] = s[substrIdx[0] + i];
  }
  substr[len] = '\0'; // because substr starts at 0
  return substr;
}
