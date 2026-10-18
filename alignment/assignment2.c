#include <stdio.h>
#include <stddef.h>

// Struct 1: Original Order (char, int, double)
struct StructOriginal {
    char a;    // 1 byte
    int b;     // 4 bytes
    double c;  // 8 bytes
};

// Struct 2: Unoptimized Order (char, double, int) -> Forces maximum padding
struct StructUnoptimized {
    char a;    // 1 byte
    double c;  // 8 bytes
    int b;     // 4 bytes
};

// Struct 3: Optimized Order (double, int, char) -> Minimal padding (descending size)
struct StructOptimized {
    double c;  // 8 bytes
    int b;     // 4 bytes
    char a;    // 1 byte
};

int main() {
    struct StructOriginal s1;
    struct StructUnoptimized s2;
    struct StructOptimized s3;

    printf("Struct memory layout & padding:\n");
    // Struct 1 
    printf("1. Original struct (char a, int b, double c):\n");
    printf("   Total Size: %lu bytes\n", sizeof(s1));
    printf("   Field Addresses & Offsets:\n");
    printf("     - char a   : Address = %p | Offset = %lu byte\n",  (void*)&s1.a, offsetof(struct StructOriginal, a));
    printf("     - int b    : Address = %p | Offset = %lu bytes\n", (void*)&s1.b, offsetof(struct StructOriginal, b));
    printf("     - double c : Address = %p | Offset = %lu bytes\n\n", (void*)&s1.c, offsetof(struct StructOriginal, c));

    // Struct 2 
    printf("2. Unoptimized struct (char a, double c, int b):\n");
    printf("   Total Size: %lu bytes\n", sizeof(s2));
    printf("   Field Addresses & Offsets:\n");
    printf("     - char a   : Address = %p | Offset = %lu byte\n",  (void*)&s2.a, offsetof(struct StructUnoptimized, a));
    printf("     - double c : Address = %p | Offset = %lu bytes\n", (void*)&s2.c, offsetof(struct StructUnoptimized, c));
    printf("     - int b    : Address = %p | Offset = %lu bytes\n\n", (void*)&s2.b, offsetof(struct StructUnoptimized, b));

    // Struct 3 
    printf("3. Optimized struct (double c, int b, char a):\n");
    printf("   Total Size: %lu bytes\n", sizeof(s3));
    printf("   Field Addresses & Offsets:\n");
    printf("     - double c : Address = %p | Offset = %lu byte\n",  (void*)&s3.c, offsetof(struct StructOptimized, c));
    printf("     - int b    : Address = %p | Offset = %lu bytes\n", (void*)&s3.b, offsetof(struct StructOptimized, b));
    printf("     - char a   : Address = %p | Offset = %lu bytes\n\n", (void*)&s3.a, offsetof(struct StructOptimized, a));

    return 0;
}