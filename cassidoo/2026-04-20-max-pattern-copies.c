#include <stdio.h>
#include <string.h>

int maxPatternCopies(const char *s, const char *pattern) {
  int freqS[26] = {0};
  int freqP[26] = {0};
  int wildcards = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '?') {
      wildcards++;
    } else {
      freqS[s[i] - 'a']++;
    }
  }

  for (int i = 0; pattern[i] != '\0'; i++) {
    freqP[pattern[i] - 'a']++;
  }

  int sLen = (int)strlen(s);
  int pLen = (int)strlen(pattern);

  if (pLen == 0)
    return 0;

  int low = 0;
  int high = sLen / pLen;
  int ans = 0;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    int needed = 0;

    for (int i = 0; i < 26; i++) {
      int need = freqP[i] * mid;
      if (need > freqS[i]) {
        needed += need - freqS[i];
      }
    }

    if (needed <= wildcards) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}

int main(int argc, char **argv) {
  printf("%d\n", maxPatternCopies("abcabc???", "ac"));
  printf("%d\n", maxPatternCopies("aab??", "aab"));
  printf("%d\n", maxPatternCopies("??????", "abc"));
}
