#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int32_t (*callback)(int32_t);

extern int32_t power(int32_t a,int32_t b, callback cb);

int32_t pryntik(int32_t c){
    if(c == -1){
        fprintf(stderr, "overflow");
        return 0;
    }
    printf("%d\n", c);
    return 0;
}

uint32_t powerization(int32_t a,int32_t b, callback cb){
    if(b == 1){
        printf("%d\n", a);
        return 0;
    }

    if (b == 0) {
        printf("1\n");
        return 0;
    }


    if (b < 0) {
        fprintf(stderr, "Wrong input, only for non negative index\n");
        return 0;
    }
    if(a == 1){
        printf("1\n");
        return 0;
    }

    if (a == 0) {
        if (b == 0) {
            printf("1\n");
            return 0;
        } else {
            printf("0\n");
            return 0;
        }
    }

    if((a < 0) && (b % 2 == 0)){
        power(abs(a), b, cb);
        return 0;
    }
    power(a, b, cb);
    return 0;
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Try to input %s <A> <B>\n", argv[0]);
        return 1;
    }

    char *a = argv[1];
    char *b = argv[2];

    int32_t int_a = (int32_t) strtol(a, NULL, 10);
    int32_t int_b = (int32_t) strtol(b, NULL, 10);

    powerization(int_a, int_b, pryntik);
    return 0;

}
