#include <iostream>
#include <vector>
 
using namespace std;
void moveNums(vector<int>& arr, int num){
    int insertPos = 0;
    for (int i = 0;i < arr.size(); i++){
       if (arr[i] != num) { 
               arr[insertPos] = arr[i]; 
                insertPos++;
       } 
    }
    
    for (int i = (arr.size() - insertPos) + 1; i < arr.size(); i++){
        arr[i] = num;
    }
}

void printArr(vector<int>& arr){
    cout << "[";
    for (int i = 0; i < arr.size(); i++){
            cout << arr[i];
            if (i != arr.size()- 1){
                    cout << ", ";
            }

    }
    cout << "]";

} 
int main(int argc, char** argv){
        vector<int> arr = {0,2,0,3,10};
        int num = 0;
        vector<int> expected = {2,3,10,0,0};
        cout << "moveNums\n" << "input: ";
        printArr(arr);
        cout << ", " << num << "\nexpected: ";
        printArr(expected);
        moveNums(arr,num);
        cout <<  "\noutput: ";
        printArr(arr);
        cout << "\n";
}


