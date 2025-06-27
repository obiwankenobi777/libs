#include <stdio.h>
#include <stdlib.h>

static int gcd(int a, int b) {
    if (b == 0)
        return a;
    else 
        gcd(b, b % a);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        perror("Ausencia de parametros");
        return 1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));

    return 0;
}
