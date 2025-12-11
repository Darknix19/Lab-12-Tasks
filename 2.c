#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n, newSize, i;
    char choice;

    /* Ask user for initial size */
    printf("Enter how many integers you want to store: ");
    scanf("%d", &n);

    /* Allocate memory using calloc so all values start at 0 */
    arr = (int*)calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    /* Display initial values (all zeros) */
    printf("\nInitial array values:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Ask user if they want to enlarge the array */
    printf("\nDo you want to enlarge the array? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Enter the new size (must be greater than %d): ", n);
        scanf("%d", &newSize);

        if (newSize <= n) {
            printf("New size must be greater than the old size.\n");
        } else {
            /* Resize memory block using realloc */
            int *temp = realloc(arr, newSize * sizeof(int));

            if (temp == NULL) {
                printf("Reallocation failed. Keeping original array.\n");
            } else {
                arr = temp;

                /* Initialize newly added elements */
                printf("\nEnter %d new elements:\n", newSize - n);
                for (i = n; i < newSize; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }

                n = newSize;  /* Update size */
            }
        }
    }

    /* Display updated array */
    printf("\nUpdated array values:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Free allocated memory */
    free(arr);

    return 0;
}
