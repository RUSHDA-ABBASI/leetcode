#include <stdio.h>
#include <string.h>

int numberOfBeams(char **bank, int bankSize) {
    int prev = 0;
    int result = 0;

    for (int i = 0; i < bankSize; i++) {
        int count = 0;

        // Count '1's in current row
        for (int j = 0; bank[i][j] != '\0'; j++) {
            if (bank[i][j] == '1') {
                count++;
            }
        }

        // If row has devices, calculate beams
        if (count > 0) {
            result += prev * count;
            prev = count;
        }
    }

    return result;
}

int main() {
    // Bank floor plan
    char *bank[] = {
        "011001",
        "000000",
        "010100",
        "001000"
    };

    int bankSize = 4;

    int beams = numberOfBeams(bank, bankSize);

    printf("Total Laser Beams: %d\n", beams);

    return 0;
}
