#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
    FILE *a = fopen(argv[1], "rb");
    FILE *b = fopen(argv[2], "rb");

    if (!a || !b) {
        fprintf(stderr, "파일 열기 실패\n");
        return 0;
    }

    uint32_t aa, bb;

    if (fread(&aa, sizeof(uint32_t), 1, a) !=1 | fread(&bb, sizeof(uint32_t), 1, b) != 1) {
        fprintf(stderr, "파일 읽기 실패\n");
        return 0;
    }

    fclose(a);
    fclose(b);

    uint32_t aaa = ntohl(aa), bbb = ntohl(bb);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", aaa, aaa, bbb, bbb, aaa+bbb, aaa+bbb);

    return 0;
}

