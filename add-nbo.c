#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t read_32bit_number(FILE* file) {
    uint32_t number;
    fread(&number, sizeof(uint32_t), 1, file);
    return ntohl(number);
}

int main(int argc, char* argv[]) {
    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    if (file1 == NULL || file2 == NULL) {
        printf("No file\n");
        return 1;
    }

    uint32_t number1 = read_32bit_number(file1);
    uint32_t number2 = read_32bit_number(file2);

    fclose(file1);
    fclose(file2);

    uint32_t total = number1 + number2;

    printf("Sum : %u\n", total);

    return 0;
}
