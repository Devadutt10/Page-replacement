#include <stdio.h>

int main() {
    int num_pages, capacity;

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the size of the frame: ");
    scanf("%d", &capacity);

    int pages[num_pages], frames[capacity];

    printf("Start entering the pages...\n");
    for (int i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    int faults = 0, hit = 0;
    int next_to_replace = 0;

    for (int i = 0; i < num_pages; i++) {
        int found = 0;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                hit++;
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[next_to_replace] = pages[i];
            next_to_replace = (next_to_replace + 1) % capacity;
            faults++;
        }
        
    printf("\nThe number of page faults are: %d\n", faults);
    printf("The number of hits are: %d\n", hit);

    return 0;
    }
}
