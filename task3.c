#include <stdio.h>
#include <math.h>
#include <time.h>

// This program finds the largest prime factor of a given number
// using a brute-force approach.
// The number is hardcoded as 600851475143.
// The program measures the time taken to find the largest prime factor.
// The algorithm iterates through all numbers from 2 to the square root of the number.
// If a number is a factor, it divides the number and continues checking.
// The largest prime factor found is printed at the end.
// The program uses the clock() function to measure the time taken for the computation.
// The time taken is printed in seconds.


int main() {
    long long nbr;
    printf("Enter a number to find its largest prime factor: ");
    scanf("%lld", &nbr);
    if (nbr < 2) {
        printf("The number is too small to have prime factors.\n");
        return 0;
    }

    double time_spent = 0.0;
    clock_t begin = clock();


    int division_limit = (int)(sqrt((double)nbr) + 1);
    printf("Divide until number: %d\n", division_limit);

    int largest_prime_factor = 0;
    for (int i = 2; i <= division_limit; i++) {
        if (nbr % i == 0) {
            largest_prime_factor = i;
            printf("Found factor: %d\n", largest_prime_factor);
            while (nbr % i == 0) {
                nbr /= i;
            }
        }
    }
    if (nbr > 1) {
        largest_prime_factor = nbr;
        printf("Found remaining prime factor: %d\n", largest_prime_factor);
    }
    clock_t end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Largest prime factor: %d\n", largest_prime_factor);
    printf("Time taken: %f seconds\n", time_spent);

    return 0;
}

