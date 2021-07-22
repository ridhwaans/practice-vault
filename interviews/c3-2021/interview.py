'''
Create a function to generate a random, 8-character password.
It should satisfy the following requirements:

1) There should be exactly two characters from each of the following categories:
- Uppercase letters
- Lowercase letters
- Numerals 0 - 9
- Special Characters from the string “!@#$%^&*”

2) No two character categories should be adjacent.
bad example: AXyu74$^

3) The categories should be randomly ordered.
good example: 8b&U6Nz!  NLSUNULS
'''
import string
import random

categories = "ULNS"
prev = curr = None
passwd = ""
used = {}
for category in categories:
    used[category] = 0

while len(passwd) != 8: 
    while prev == curr:
        curr = random.choice(categories)

    if curr == "U":
        passwd += random.choice(list(string.ascii_uppercase))
    if curr == "L":
        passwd += random.choice(list(string.ascii_lowercase))
    if curr == "N":
        passwd += random.choice([str(i) for i in range(10)])
    if curr == "S":
        passwd += random.choice([s for s in "!@#$%^&*"])
    
    used[curr] += 1
    if used[curr] == 2: 
        used.pop(curr)
        categories = "".join(list(used.keys()))
    prev = curr
        
print(passwd)