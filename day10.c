#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[1000]; 
    if (scanf("%s", s) != 1) return 0;

    int left = 0;
    int right = strlen(s) - 1;
    bool is_palindrome = true;
  
    while (left < right) {
        if (s[left] != s[right]) {
            is_palindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (is_palindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
