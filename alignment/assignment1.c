#include <stdio.h>
#include <stdint.h>

int main() {
    // 1. Declare variables of different primitive data types
    char   c = 'A';
    short  s = 10;
    int    i = 100;
    double d = 3.14159;

    printf("Data type sizes and memory addresses:       \n");
    printf("%-10s %-12s %-18s %-10s\n", "Type", "Size (bytes)", "Address (Hex)", "Address (Decimal)");

    // Print size and address using %p (Hex) and uintptr_t (Decimal)
    printf("%-10s %-12lu %-18p %-10lu\n", "char",   sizeof(c), (void *)&c, (uintptr_t)&c);
    printf("%-10s %-12lu %-18p %-10lu\n", "short",  sizeof(s), (void *)&s, (uintptr_t)&s);
    printf("%-10s %-12lu %-18p %-10lu\n", "int",    sizeof(i), (void *)&i, (uintptr_t)&i);
    printf("%-10s %-12lu %-18p %-10lu\n", "double", sizeof(d), (void *)&d, (uintptr_t)&d);

    printf("Alignment boundary check\n");
    // Memory address modulo data type size equals 0 if naturally aligned
    printf("char   address %% %lu = %lu (Aligned to 1-byte boundary)\n",  sizeof(c), (uintptr_t)&c % sizeof(c));
    printf("short  address %% %lu = %lu (Aligned to %lu-byte boundary)\n", sizeof(s), (uintptr_t)&s % sizeof(s), sizeof(s));
    printf("int    address %% %lu = %lu (Aligned to %lu-byte boundary)\n", sizeof(i), (uintptr_t)&i % sizeof(i), sizeof(i));
    printf("double address %% %lu = %lu (Aligned to %lu-byte boundary)\n", sizeof(d), (uintptr_t)&d % sizeof(d), sizeof(d));

    return 0;
}