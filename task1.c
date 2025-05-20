#include <stdio.h>
#include <time.h>

// PROBLEM STATEMENT:
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6, and 9.
// The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.

// // version 1
// int main() {
//     int i = 1;
//     int res = 0;
//     clock_t start, end;
//     double cpu_time_used = 0.0;

//     start = clock();
//     while(i <= 1000) {
//         if (i % 3 == 0 || i % 5 == 0)
//             res += i;
//         i++;
//     }
//     end = clock();
//     cpu_time_used = (double)(end-start) / CLOCKS_PER_SEC;

//     printf("RESULT: %d\nRUNTIME = %f\n", res, cpu_time_used);
//     return 0;
// }

// version 2
int main() {
    int i = 0;
    int res = 0;
    time_t start, end;
    double cpu_time_used = 0.0;

    start = clock();
    while (i <= 1000) {
        res += i;
        i += 3;
        // printf("res = %d\n", res);
    }
    i = 0;
    while (i <= 1000) {
        res += i;
        i += 5;
    }
    i = 0;
    while (i <= 1000) {
        res -= i;
        i += 15;
    }
    end = clock();
    cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("RESULT: %d\nRUNTIME: %f", res, cpu_time_used);

    return 0;
}
