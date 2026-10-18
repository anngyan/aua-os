#include <stdio.h>
#include <stddef.h>

// 1. Default alignment (No #pragma pack)
struct DefaultStruct {
    char a;    // 1 byte
    int b;     // 4 bytes
    double c;  // 8 bytes
};

// 2. Packed alignment: 1-byte boundary (No padding)
#pragma pack(push, 1)
struct Packed1Struct {
    char a;    // 1 byte
    int b;     // 4 bytes
    double c;  // 8 bytes
};
#pragma pack(pop)

// 3. Packed alignment: 2-byte boundary
#pragma pack(push, 2)
struct Packed2Struct {
    char a;    // 1 byte
    int b;     // 4 bytes
    double c;  // 8 bytes
};
#pragma pack(pop)

// 4. BONUS: Packed alignment: 4-byte boundary
#pragma pack(push, 4)
struct Packed4Struct {
    char a;    // 1 byte
    int b;     // 4 bytes
    double c;  // 8 bytes
};
#pragma pack(pop)

int main(void) {
    struct DefaultStruct d;
    struct Packed1Struct p1;
    struct Packed2Struct p2;
    struct Packed4Struct p4;

    printf("Data alignment with #pragma pack demonstration:\n");

    // Default Alignment
    printf("1. Default alignment (No #pragma pack):\n");
    printf("   Total Size: %lu bytes\n", sizeof(d));
    printf("   Field Addresses & Offsets:\n");
    printf("     - char a   : Address = %p | Offset = %lu byte\n",  (void*)&d.a, offsetof(struct DefaultStruct, a));
    printf("     - int b    : Address = %p | Offset = %lu bytes\n", (void*)&d.b, offsetof(struct DefaultStruct, b));
    printf("     - double c : Address = %p | Offset = %lu bytes\n\n", (void*)&d.c, offsetof(struct DefaultStruct, c));

    // #pragma pack(1)
    printf("2. #pragma pack(1) (1-Byte Alignment / No Padding):\n");
    printf("   Total Size: %lu bytes\n", sizeof(p1));
    printf("   Field Addresses & Offsets:\n");
    printf("     - char a   : Address = %p | Offset = %lu byte\n",  (void*)&p1.a, offsetof(struct Packed1Struct, a));
    printf("     - int b    : Address = %p | Offset = %lu bytes\n", (void*)&p1.b, offsetof(struct Packed1Struct, b));
    printf("     - double c : Address = %p | Offset = %lu bytes\n\n", (void*)&p1.c, offsetof(struct Packed1Struct, c));

    // #pragma pack(2)
    printf("3. #pragma pack(2) (2-Byte Alignment Boundary):\n");
    printf("   Total Size: %lu bytes\n", sizeof(p2));
    printf("   Field Addresses & Offsets:\n");
    printf("     - char a   : Address = %p | Offset = %lu byte\n",  (void*)&p2.a, offsetof(struct Packed2Struct, a));
    printf("     - int b    : Address = %p | Offset = %lu bytes\n", (void*)&p2.b, offsetof(struct Packed2Struct, b));
    printf("     - double c : Address = %p | Offset = %lu bytes\n\n", (void*)&p2.c, offsetof(struct Packed2Struct, c));

    // #pragma pack(4)
    printf("4. #pragma pack(4) (4-Byte Alignment Boundary):\n");
    printf("   Total Size: %lu bytes\n", sizeof(p4));
    printf("   Field Addresses & Offsets:\n");
    printf("     - char a   : Address = %p | Offset = %lu byte\n",  (void*)&p4.a, offsetof(struct Packed4Struct, a));
    printf("     - int b    : Address = %p | Offset = %lu bytes\n", (void*)&p4.b, offsetof(struct Packed4Struct, b));
    printf("     - double c : Address = %p | Offset = %lu bytes\n\n", (void*)&p4.c, offsetof(struct Packed4Struct, c));

    return 0;
}