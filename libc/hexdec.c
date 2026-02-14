#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; argv[i]; ++i) {
        printf("%s em hex: ", argv[i]);

        for (int j = 0; argv[i][j] != '\0'; ++j) {
            printf("%02x ", (unsigned char)argv[i][j]);
        }

        printf("\n%s em dec: ", argv[i]);
        for (int j = 0; argv[i][j] != '\0'; ++j) {
            printf("%d ", (unsigned char)argv[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}
