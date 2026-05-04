#include <stack>
#include <string>

using namespace std;
class Solution {
public:
  bool isValid(string s) {
    stack<char> brackets;

    // bug - failing edge case at time of bug "()[]{}"
    // fix - have one if else if structure in one loop for both logic.
    // for (char &c : s){
    //     if (c == '(' || c == '{' || c == '['){
    //         brackets.push(c);
    //     }
    // }

    for (char &c : s) {
      // deprecated -unnecessary
      // if (brackets.empty()) return false;

      if (c == '(' || c == '{' || c == '[') {
        brackets.push(c);
      }
      // bug - AddressSanitizer:DEADLYSIGNAL SEGV on unknown address
      // fix - check empty before calling top (peek)
      else if (c == ')') {
        if (brackets.empty() || brackets.top() != '(')
          return false;
        brackets.pop();
      } else if (c == '}') {
        if (brackets.empty() || brackets.top() != '{')
          return false;
        brackets.pop();
      } else if (c == ']') {
        if (brackets.empty() || brackets.top() != '[')
          return false;
        brackets.pop();
      }
    }
    // short form return brackets.empty();
    return (brackets.empty()) ? true : false;
  }
};
