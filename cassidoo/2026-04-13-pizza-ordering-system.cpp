#include <iostream>
#include <unordered_map>
#include <variant>
#include <vector>

using namespace std;

variant<bool, vector<string>> validatePizza(vector<string> &layers,
                                            vector<vector<string>> &rules) {
  unordered_map<string, int> layersMap;
  int nextKey = 0;
  for (const auto &l : layers) {
    layersMap[l] = nextKey++;
  }
  for (const auto &r : rules) {
    if (layersMap[r[1]] < layersMap[r[0]])
      return r;
  }
  return true;
}

int main(int argc, char **argv) {
  vector<string> layers = {"dough", "sauce", "cheese", "pepperoni", "basil"};

  vector<vector<string>> rules = {
      {"sauce", "cheese"}, {"cheese", "pepperoni"}, {"dough", "basil"}};

  vector<vector<string>> rules2 = {{"cheese", "pepperoni"},
                                   {"cheese", "sauce"}};

  for (auto rules : {rules, rules2}) {
    auto res = validatePizza(layers, rules);
    if (holds_alternative<bool>(res))
      cout << (get<bool>(res) ? "true\n" : "false\n");
    else {
      auto v = get<vector<string>>(res);
      cout << "[" << v[0] << ", " << v[1] << "]\n";
    }
  }
}
