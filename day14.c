#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    
    
    if (scanf("%d", &n) != 1) return 0;

    int matrix[n][n];
    bool is_identity = true;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                
                if (matrix[i][j] != 1) {
                    is_identity = false;
                    break;
                }
            } else {
               
                if (matrix[i][j] != 0) {
                    is_identity = false;
                    break;
                }
            }
        }
        if (!is_identity) break;
    }

    if (is_identity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}
