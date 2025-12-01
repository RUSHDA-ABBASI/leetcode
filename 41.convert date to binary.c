#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toBinary(int num, char *buffer, int bufferSize) {
    int i = 0;
    if (num == 0) {
        if (bufferSize < 2) return;
        buffer[i++] = '0';
        buffer[i] = '\0';
        return;
    }

    char rev[64];
    int j = 0;
    while (num > 0 && j < (int)sizeof(rev)) {
        rev[j++] = (num % 2) + '0';
        num /= 2;
    }

    // Now reverse into buffer
    while (j > 0 && i < bufferSize - 1) {
        buffer[i++] = rev[--j];
    }
    buffer[i] = '\0';
}

int main(void) {
    char date[20];

    printf("Enter date in yyyy-mm-dd format: ");
    if (scanf("%19s", date) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int year, month, day;
    if (sscanf(date, "%d-%d-%d", &year, &month, &day) != 3) {
        printf("Invalid date format.\n");
        return 1;
    }

    char yearBin[32], monthBin[16], dayBin[16];

    toBinary(year, yearBin, sizeof(yearBin));
    toBinary(month, monthBin, sizeof(monthBin));
    toBinary(day, dayBin, sizeof(dayBin));

    printf("Binary date: %s-%s-%s\n", yearBin, monthBin, dayBin);

    return 0;
}
