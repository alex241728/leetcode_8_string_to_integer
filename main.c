#include <stdio.h>
#include <string.h>
#include <limits.h>

int myAtoi(char*);

int main() {
    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("   -42"));
    printf("%d\n", myAtoi("4193 with words"));
    printf("%d\n", myAtoi("+1"));

    return 0;
}

int myAtoi(char* s) {
    int is_negative = 1; // if negative, -1 & if positive, 1
    int i = 0; // pointer

    // check the front space
    while (i < strlen(s) && s[i] == ' ') {
        i++;
    }
    if (i >= strlen(s)) {
        return 0;
    }

    // check sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            is_negative = -1;
        }
        i++;
    }
    if (i >= strlen(s)) {
        return 0;
    }

    // get the number
    int res = 0; // number itself
    while (i < strlen(s)) {
        int digit = s[i] - '0'; // each digit

        // check if it is a number
        if (digit >= 0 && digit <= 9) {
            // check overflow
            if ( ( res > ( INT_MAX / 10 ) ) ||  ( (res == ( INT_MAX / 10 ) ) && ( digit > ( INT_MAX % 10 ) ) ) ) {
                return is_negative == 1 ? INT_MAX : INT_MIN;
            }

            // get the num
            int new_res = res * 10 + digit;
            res = new_res;
            i++;
        }
        else {
            break;
        }
    }

    return res * is_negative;
}