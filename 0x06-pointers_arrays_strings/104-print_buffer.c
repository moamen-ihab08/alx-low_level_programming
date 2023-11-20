#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r);

int main() {
    char n1[] = "12345678901234567890";
    char n2[] = "98765432101234567890";
    int size_r = 22;  // Adjust the buffer size accordingly

    char *result = infinite_add(n1, n2, (char *)malloc(size_r + 1), size_r);

    if (result != NULL) {
        printf("Sum: %s\n", result);
        free(result);
    } else {
        printf("Result cannot be stored in the buffer.\n");
    }

    return 0;
}

char *infinite_add(char *n1, char *n2, char *r, int size_r) {
    int len1 = strlen(n1);
    int len2 = strlen(n2);

    // Ensure enough space in the buffer for the result and null terminator
    if (size_r < len1 + 2 || size_r < len2 + 2) {
        return 0;  // Result cannot be stored in the buffer
    }

    int carry = 0;
    int index_r = 0;

    // Iterate through the numbers from right to left
    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry > 0; i--, j--) {
        int digit1 = (i >= 0) ? n1[i] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;

        r[index_r++] = sum % 10 + '0';  // Add the digit to the result
        carry = sum / 10;  // Update the carry for the next iteration
    }

    // Reverse the result string
    for (int i = 0, j = index_r - 1; i < j; i++, j--) {
        char temp = r[i];
        r[i] = r[j];
        r[j] = temp;
    }

    r[index_r] = '\0';  // Null-terminate the result string

    return r;
}
