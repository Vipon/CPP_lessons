#include <cstdio>
#include <cstdint>

int main()
{
    uint32_t a32 = -1;
    auto b32 = a32;
    printf("sizeof(a32) = %zu\n", sizeof(a32));
    printf("sizeof(b32) = %zu\n", sizeof(b32));


    uint64_t a64 = -1;
    auto b64 = a64;
    printf("sizeof(a64) = %zu\n", sizeof(a64));
    printf("sizeof(b64) = %zu\n", sizeof(b64));

    auto val0 = 1;
    auto val1 = (uint64_t)1;
    printf("sizeof(val0) = %zu\n", sizeof(val0));
    printf("sizeof(val1) = %zu\n", sizeof(val1));

    return 0;
}
