#include <stdio.h>

int findLFU(int freq[], int n) {
    int i, minimum = freq[0], pos = 0;

    for (i = 1; i < n; ++i) {
        if (freq[i] < minimum) {
            minimum = freq[i];
            pos = i;
        }
    }

    return pos;
}

int main() {
    int num_pages, capacity;

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the size of the frame: ");
    scanf("%d", &capacity);

    int pages[num_pages], frames[capacity], freq[capacity], time[capacity];
    int faults = 0, hit = 0, counter = 0;

    printf("Start entering the pages...\n");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
        freq[i] = 0;
        time[i] = 0;
    }

    for (int i = 0; i < num_pages; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                hit++;
                freq[j]++;
                time[j] = counter++; 
                found = 1;
                break;
            }
        }
        if (!found) {
            if (faults < capacity) {
                frames[faults] = pages[i];
                freq[faults] = 1;
                time[faults] = counter++;
                faults++;
            } else {
                int lfu = findLFU(freq, capacity);
                frames[lfu] = pages[i];
                freq[lfu] = 1;
                time[lfu] = counter++;
            }
        }
        printf("Step %d: ", i + 1);
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == -1)
                printf("-");
            else
                printf("%d", frames[j]);
            if (j < capacity - 1)
                printf(" ");
        }
        printf("\n");
    }

    printf("\nThe number of page faults are: %d\n", faults);
    printf("The number of hits are: %d\n", hit);

    return 0;
}
