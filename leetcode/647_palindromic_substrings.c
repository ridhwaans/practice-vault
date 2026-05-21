#include <string.h>

int countSubstrings(char *s) {
  int l, r;
  int size = strlen(s);
  int freq = 0;
  for (int i = 0; i < size; i++) {
    // odd
    l = i, r = i;
    while (0 <= l && r < size && s[r] == s[l]) {
      freq++;
      l--;
      r++;
    }
    // even
    l = i, r = i + 1;
    while (0 <= l && r < size && s[r] == s[l]) {
      freq++;
      l--;
      r++;
    }
  }
  return freq;
}
