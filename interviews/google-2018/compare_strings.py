'''
Given two different strings, one with backspaces (keypresses), find if they are equivalent or not
'''
import __builtin__

def main():
    true_testcases = (
    ("abc", "abc"),
    ("abc", "abcde\b\b"),
    ("abcdef", "\b\babcdef\bf"),
    ("", "\b\b\b"),
    ("Toronto", "Torooo\b\bntt\bo"))

    false_testcases = (
    ("a", "a\b"),
    ("a", "a\b\b"),
    ("abc", "abc\bd\be"),
    )

    print([compare(s1, s2) for s1, s2 in true_testcases])
    print([compare(s1, s2) for s1, s2 in false_testcases])

def compare(s1, s2):
    BACKSPACE = '\b'
    i, j = len(s1) - 1, len(s2) - 1

    while i >= 0 or j >= 0:
        ignore = 0
        while i >= 0:
            if s1[i] == BACKSPACE:
                ignore += 1
            elif ignore > 0:
                ignore -= 1
            else:
                break
            i -= 1

        ignore = 0
        while j >= 0:
            if s2[j] == BACKSPACE:
                ignore += 1
            elif ignore > 0:
                ignore -= 1
            else:
                break
            j -= 1

        if i < 0 and j < 0:
            # No more characters to try and match
            return True

        if (i < 0 and j >= 0) or (i >= 0 and j < 0):
            # One string exhausted before the other
            return False

        if s1[i] != s2[j]:
            return False

        i -= 1
        j -= 1

    return True

if __name__ == "__main__":
    main()