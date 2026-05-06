#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char *s) {
  // uppercase starts at 65, lowercase starts at 97

  char *new_s =
      malloc(strlen(s) +
             1); // original code had new_s undefined leading to runtime error
  if (!new_s)
    return false; // empty string zero case check

  int i = 0;
  while (*s != '\0') {
    // incorrect - originally compared ascii codes to pointer (s) instead of
    // char which breaks everything
    char c = *s;
    // add 25 and 9, not 26 and 10, else some test cases fail due to off by 1
    if (65 <= c && c <= (65 + 25)) {
      // convert to lowercase
      c = c + 32;
    } else if (97 <= c && c <= (97 + 25)) {
      // lowercase
      // c = s; // not required original code
    } else if (48 <= c && c <= (48 + 9)) {
      // numbers
      // c = s; // not required original code
    } else {
      // skip alphanumeric
      s++; // missed this increment
      continue;
    }
    // incorrect - moves the pointer, does not append a char
    // new_s += c;

    // runtime error: store to null pointer of type 'char'
    // original code never allocated new_s
    new_s[i] = c;
    i++;
    // if (!new_s_head) new_s_head[0] = new_s;
    s++;
  }
  // new_s += '\0' // error - add numeric 0, not null terminator
  new_s[i] = '\0';

  // storing reversed string not necessary. compare in-place with two pointers
  // char reversed_s[strlen(new_s)];

  int l = 0, r = strlen(new_s) - 1;

  while (l < r) {
    if (new_s[l] != new_s[r]) {
      free(new_s);
      return false;
    }
    l++;
    r--;
  }
  free(new_s);
  return true;
}
