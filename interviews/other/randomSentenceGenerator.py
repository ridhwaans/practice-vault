'''
Implement a function generate_template(...)
The goal is to create a random word, phrase or full sentence from a given template data source

Template Data
[
    {
        "group_id": 154,
        "children": [234, 124, 36]
    },
    {
        "group_id": 234,
        "content": "I"
    },
    {
        "group_id": 234,
        "content": "You"
    },
    {
        "group_id": 234,
        "content": "We"
    },
    {
        "group_id": 124,
        "content": "like to"
    },
    {
        "group_id": 124,
        "content": "sometimes"
    },
    {
        "group_id": 36,
        "content": "jog"
    },
    {
        "group_id": 36,
        "children": [46, 242]
    },
    {
        "group_id": 46,
        "content": "eat"
    },
    {
        "group_id": 242,
        "content": "sandwiches"
    },
    {
        "group_id": 242,
        "content": "eggs"
    }
]
Visual representation of template_data https://i.imgur.com/srwj1a0.jpg

Here are some examples returned by generate_template(...) if it were given the above template data

generate_template(46, template_data) would return
"eat"

generate_template(124, template_data) would return one of the following
"like to"
"sometimes"

generate_template(36, template_data) would return one of the following
"jog"
"eat sandwiches"
"eat eggs"

generate_template(154, template_data) would return one of the following
"I like to jog"
"We like to eat sandwiches"
"You sometimes eat eggs"
"I sometimes eat sandwiches"
[and many other possible sentences]

FAQ
Does generate_templates(...) always return a full sentence?
No. Depending on the given group_id it might return a single word, a sequence of words, or a coherent sentence

Does generate_template(...) return all possible outputs for a given group_id?
No. generate_template(...) should return only one of the possible outputs for a given template

Are the group IDs numbered in any meaningful way?
No. The group_id for each template is randomly generated & completely arbitrary

Hint
This is a tree-based algorithm, not a NLP problem
Focus on functional code
Python has a built-in random module. random.choice(arr) might come in handy
'''
#!/usr/bin/python3
import json
from collections import defaultdict
import random

def convertJsonTemplate(template_str: str) :
    entryMap = defaultdict(list) 

    entries = json.loads(template_str)
    # print(entries)
    for entry in entries:
        if "content" in entry :
            entryMap[int(entry["group_id"])].append(entry["content"])
        else :
            entryMap[int(entry["group_id"])].append(entry["children"])
    
    return entryMap

def generate_template(group_id: int, template: str) -> str:
    
    entryMap = convertJsonTemplate(template)
    return generate_template_recurse(group_id,entryMap)
    

def generate_template_recurse(group_id: int, entryMap) -> str:

    randomEntry = random.choice(entryMap[group_id])
    
    ret_str = ""
    if type(randomEntry) == str :
        ret_str = randomEntry
    else :
        str_list = []
        for child_groupid in randomEntry : 
            str_list.append(generate_template_recurse(child_groupid,entryMap))
        ret_str = ' '.join(str_list)
    return ret_str

x = '''
[
    {
        "group_id": 154,
        "children": [234, 124, 36]
    },
    {
        "group_id": 234,
        "content": "I"
    },
    {
        "group_id": 234,
        "content": "You"
    },
    {
        "group_id": 234,
        "content": "We"
    },
    {
        "group_id": 124,
        "content": "like to"
    },
    {
        "group_id": 124,
        "content": "sometimes"
    },
    {
        "group_id": 36,
        "content": "jog"
    },
    {
        "group_id": 36,
        "children": [46, 242]
    },
    {
        "group_id": 46,
        "content": "eat"
    },
    {
        "group_id": 242,
        "content": "sandwiches"
    },
    {
        "group_id": 242,
        "content": "eggs"
    }
]
'''

print(generate_template(46,x))
print(generate_template(124,x))
print(generate_template(36,x))
print(generate_template(154,x))
'''
See also:
https://leetcode.com/discuss/interview-question/799347/Sentence-Generator-or-Facebook-or-Online-OA-or-2019
'''