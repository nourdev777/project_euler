#include <stdio.h>
#include <time.h>
#include <stdbool.h>


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
        for (int j = i; j >= 100; j--) {
            int product = i * j;
            if (product <= max_palindrome) {
                break; // No need to check smaller products
            }
            if (is_palindrome(product)) {
                max_palindrome = product;
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


}