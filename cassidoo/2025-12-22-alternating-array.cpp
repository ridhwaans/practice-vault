//An alternating array is a list of any length in which two (not necessarily different) values are alternating (all even-indexed items are equal, and all odd-indexed items are equal). Given an array, return true if it is alternating.
//
//Examples:
//
//[]             -> True
//[1]            -> True
//[1,1]          -> True
//[1,2,1]        -> True
//[10,5,10,5,10] -> True
//[2,2,3,3]      -> False
//[5,4,3,5,4,3]  -> False

#include <iostream>
#include <vector>
#include <algorithm>

bool check(const std::vector<int>& numbers){
        for (size_t i = 0; i < numbers.size(); ++i) {
                if (i > 1 && numbers[i - 2] != numbers[i]) {
                        return false;
                }
        }
        return true;
}

int main( int argc, char *argv[] ){
        std::vector<std::vector<int>> tests = {
        {},                  
        {1},                 
        {1, 1},              
        {1, 2, 1},           
        {10, 5, 10, 5, 10},
        {2, 2, 3, 3},  
        {5, 4, 3, 5, 4, 3}
    };

    std::cout << std::boolalpha;
    for (const auto& test : tests) {
        std::cout << check(test) << '\n';
    }
}


