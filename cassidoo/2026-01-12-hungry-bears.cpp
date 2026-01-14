#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <array>

using namespace std;

struct Bear {
    char name[20];
    int hunger;
};

bool hungerComparator(const Bear  &a, const Bear  &b){
        return b.hunger > a.hunger;
}
bool nameComparator(const array<char, 20> &a, const array<char, 20> &b){
    return strcmp(a.data(), b.data()) < 0;
}


vector<array<char, 20>> hungryBears(vector<Bear>& bears){
    if (bears.empty()) return {};
    int avgHunger = 0;
    for (const auto bear : bears){
            avgHunger += bear.hunger;
    }
    avgHunger = round(avgHunger / bears.size());
    sort(bears.begin(), bears.end(), hungerComparator);
    vector<array<char, 20>> names;
    for (const auto &bear : bears){
            if (bear.hunger > avgHunger){
                array<char, 20> bearName{};
                strncpy(bearName.data(), bear.name, sizeof(bearName) - 1); // no overflow
                names.push_back(bearName);
            }
    }
    sort(names.begin(), names.end(), nameComparator);
    return names; 
}

int main(int argc, char **argv){
    vector<Bear> bears = {
            {"Baloo", 6},    
            {"Yogi", 9},
            {"Paddington", 4},
            {"Winnie", 10},
            {"Chicago", 20}
        };

    vector<array<char, 20>> answer = hungryBears(bears);
    cout << "Hungry bears: ";
    for (int i = 0; i < answer.size(); i++){
            if (i == 0) cout << "[ ";
            cout << answer[i].data();
            if (i != answer.size() - 1){
                    cout << ", ";
            } else {
                    cout << "]\n";
            }
    }
}
