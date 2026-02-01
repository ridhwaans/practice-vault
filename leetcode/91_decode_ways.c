#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int topDown( int i, char* word){
    // base cases
    if (i == strlen(word)) return 1;
    if (word[i] == '0') return 0;
    
    int count = topDown(i + 1, word);
    
    if ((i + 1) <= strlen(word) - 1){
        // numbers in ascii start at 48
        int doubleDigit = (((word[i] - '0') * 10) + (word[i+1] - '0'));
        if (doubleDigit >= 10 && doubleDigit <= 26){
            count += topDown(i + 2, word); 
        }
    }
    return count;
};

int numDecodings(char* s){
    return topDown(0, s);
}
int main(){
    char* inputs[3] = { "12", "226", "06" };
    int expected[3] = { 2, 3, 0 };

    printf("decode ways\n");
    for (int i = 0; i < 3; i++){
            printf("input=%s, expected=%d, actual=%d\n", inputs[i], expected[i], numDecodings(inputs[i]));
    }
}
