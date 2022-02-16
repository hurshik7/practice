#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LENGTH (5)

/* not sorted */
int isFlush(char* hand) {
    if (hand == NULL) {
        return -1;
    }
    char input[5];
    for (int i = 0; i < 5; i++) {
        if (hand[i] == 'A') {
            input[i] = 'a';
        } else if (hand[i] == '0') {
            input[i] = ':';
        } else {
            input[i] = hand[i];
        }
    }

    char cards[13] = {'2', '3', '4', '5', '6', '7', '8', '9', ':', 'J', 'Q', 'K', 'a'};    

    /* Find MIN */
    char min = '}';
    int minIndex = -1;
    for (int i = 0; i < LENGTH; i++) {
        if (input[i] < min) {
            min = input[i];
            for (int j = 0; j < 13; j++) {
                if (cards[j] == min) {
                    minIndex = j;
                }
            }
        }
    }
    
    int nextIndex = (minIndex + 1) % 13;
    bool isFoundUpper[4] = {false, false, false, false};
    for (int t = 0; t < 4; t++) {
        char next = cards[nextIndex]; 
        for (int i = 0; i < LENGTH; i++) {
            if (next == input[i]) {
                isFoundUpper[t] = true;
            }
        }
        nextIndex = (nextIndex + 1) % 13;
    }
    
    nextIndex = (minIndex - 1);
    if (nextIndex < 0) {
        nextIndex += 13;
    }
    bool isFoundLower[4] = {false, false, false, false};
    for (int t = 0; t < 4; t++) {
        char next = cards[nextIndex]; 
        for (int i = 0; i < LENGTH; i++) {
            if (next == input[i]) {
                isFoundLower[t] = true;
            }
        }
        nextIndex = (minIndex - 1);
        if (nextIndex < 0) {
            nextIndex += 13;
        }
    }
    
    bool isLower = true;
    bool isUpper = true;
    for (int i = 0; i < 4; i++) {
        isLower &= isFoundLower[i];
        isUpper &= isFoundUpper[i];
    }

    if (isLower || isUpper) {
        return 1;
    }
    return 0;
}

int main(void) {
    printf("%d\n", isFlush("A2345"));
    printf("%d\n", isFlush("5304A"));
    printf("%d\n", isFlush("0JQKA"));
    printf("%d\n", isFlush("JQKA2"));
    return 0;
}
