/* 
This question was asked by Compass, Karat (2021)

Given a list of words and a max line length, return a wrapped list with dash separated words

EXAMPLE
input:
["Tom","is","a","dragon","that","breathes","fire"]
maximum length of characters per line = 9

output:
["Tom-is-a-",
"dragon-t-",
"hat-brea-",
"thes-fire"]
*/
function wordWrap(words){
    console.log(words.join());
}

wordWrap("fluffy is a dragon that breathes fire".split())