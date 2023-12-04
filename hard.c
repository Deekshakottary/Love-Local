#include <stdio.h>

// Function to count the total number of digit 1 in the range [1, n]
int countDigitOne(int n) {
    int count = 0;

    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num > 0) {
            if (num % 10 == 1) {
                count++;
            }
            num /= 10;
        }
    }

    return count;
}

int main() {
    int n;

    // Get user input for the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Count the total number of digit 1 in the range [1, n]
    int result = countDigitOne(n);

    // Print the result
    printf("Total number of digit 1 from 1 to %d: %d\n", n, result);

    return 0;
}