#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// This program finds the largest palindrome made from the product of two 3-digit numbers.
// It uses a brute-force approach to check all products of two 3-digit numbers.


bool is_palindrome(int n) {
    int reversed = 0, original = n;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

int largest_palindrome_product(int limit) {
    int max_palindrome = 0;
    for (int i = limit - 1; i >= 100; i--) {
        // printf("Checking products for %d\n", i);
        for (int j = i; j >= 100; j--) {
            int nbr = i * j;
            if (nbr <= max_palindrome) {
                break; // No need to check smaller products
            }
            if (is_palindrome(nbr)) {
                max_palindrome = nbr;
                break;
            }
        }
    }
    return max_palindrome;
}

int main() {
    int res = 0;
    time_t start, end;
    double cpu_time_used = 0.0;
    start = clock();

    res = largest_palindrome_product(1000);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Largest palindrome product of two 3-digit numbers: %d\n", res);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}
