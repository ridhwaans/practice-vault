#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string encode(vector<string> &strs) {
    string encoded;
    for (string &str : strs) {
      int strSize = str.size();
      encoded += to_string(strSize) + "#" + str;
    }
    return encoded;
  }

  vector<string> decode(string s) {
    vector<string> decoded;
    int encodedSize = s.size();
    int i = 0;
    while (i < encodedSize) {
      string strSize;
      while (s.at(i) != '#') {
        strSize += s.at(i);
        i++;
      }
      // string starts after #, take strSize chars
      string str = s.substr(i + 1, stoi(strSize));
      decoded.push_back(str);

      // next string starts, i is at #, add +1 because # is 1 before the start
      // of string
      i = i + 1 + stoi(strSize);
      // i = i + 2 + stoi(strSize)+1 // incorrect
    }
    return decoded;
  }
};
