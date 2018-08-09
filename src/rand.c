/*
 *
 * rand.c - rand
 *
 * (c) 2018 gdifiore <difioregabe@gmail.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// characters avalible to generate password
char *charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-=_+,./<>?;:[]|{}";

int main(int argc, char **argv) {

    struct timespec ts; // struct for interval in nanoseconds
    int length = 8; // set default lentgh to 8
    int i;

    if (argc > 1) {
        if  (sscanf(argv[1], "%d", &length) != 1) {
            printf("[!] Error with arguments\n");
            printf("Usage: %s [length]", argv[0]);
        }
    }

    // random generator seed will be current nanoseconds
    if (clock_gettime(CLOCK_REALTIME, &ts) != 0) {
        perror("clock_gettime()");
        return 1;
    }
    srand(ts.tv_nsec);

    for (i = 0; i < length; i++) {
        printf("%c", charSet[rand() % strlen(charSet)]);
    }
    printf("\n");

    return 0;
}
