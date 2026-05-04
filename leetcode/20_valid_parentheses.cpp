#include <stack>
#include <string>

using namespace std;
class Solution {
public:
  bool isValid(string s) {
    stack<char> brackets;

    // bug - have one loop for both logic. passes edge case "()[]{}"
    // for (char &c : s){
    //     if (c == '(' || c == '{' || c == '['){
    //         brackets.push(c);
    //     }
    // }
    for (char &c : s) {
      // bug - not necessary
      // if (brackets.empty()) return false;
      if (c == '(' || c == '{' || c == '[') {
        brackets.push(c);
      }
      // bug - AddressSanitizer:DEADLYSIGNAL SEGV on unknown address
      // fix - check empty before calling pop
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
