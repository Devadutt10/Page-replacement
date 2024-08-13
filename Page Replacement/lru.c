#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
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

    int pages[num_pages], frames[capacity], time[capacity];
    int counter = 0, faults = 0, hit = 0;

    printf("Start entering the pages...\n");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < num_pages; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                hit++;
                counter++;
                time[j] = counter; 
                found = 1;
                break;
            }
        }
        if (!found) {
            if (faults < capacity) {
                frames[faults] = pages[i];
                time[faults] = counter;
                faults++;
            } else {
                int lru = findLRU(time, capacity);
                frames[lru] = pages[i];
                time[lru] = counter;
            }
            counter++;
        }

    printf("\nThe number of page faults are: %d\n", faults);
    printf("The number of hits are: %d\n", hit);

    return 0;
    }
}
