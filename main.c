#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int32_t (*callback)(int32_t);

extern int32_t power(int32_t a,int32_t b, callback cb);

int32_t pryntik(int32_t c){
    if(c == -1){
        printf("overflow");
        return 0;
    }
    printf("%d\n", c);
    return 0;
}

int32_t powerization(int32_t a,int32_t b, callback cb){
    power(a, b, cb);
    return 0;
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Try to input %s <A> <B>", argv[0]);
        return 1;
    }


    char *a = argv[1];
    char *b = argv[2];

    int32_t int_a = (int32_t) strtol(a, NULL, 10);
    int32_t int_b = (int32_t) strtol(b, NULL, 10);

    if (int_b < 0) {
        printf("Wrong input, only for positive grade");
        return 0;
    }
    if (int_a == 0) {
        if (int_b == 0) {
            printf("1\n");
            return 0;
        } else {
            printf("0\n");
            return 0;
        }
    }

    if(int_b == 1){
        printf("%d\n", int_a);
        return 0;
    }

    if (int_b == 0) {
        printf("1\n");
        return 0;
    }

    if(int_a == -1){
        if(int_b % 2 == 0){
            printf("1\n");
            return 0;
        } else {
            printf("-1\n");
            return 0;
        }
    }
    if ((int_a < 0) && (int_b % 2 != 0)){
        printf("-");
        powerization(abs(int_a), int_b, pryntik);
        return 0;
    }

    if((int_a < 0) && (int_b % 2 == 0)){
        powerization(abs(int_a), int_b, pryntik);
        return 0;
    }

    powerization(int_a, int_b, pryntik);
    return 0;

}
