#include <stdio.h>

int main(void)
{
    int pages[100];
    int frames[20];

    int n, f;
    int i, j;

    int pointer = 0;
    int faults = 0;

    printf("Enter reference string length: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++)
    {
        int found = 0;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            frames[pointer] = pages[i];

            pointer = (pointer + 1) % f;

            faults++;
        }

        printf("%d\t", pages[i]);

        for (j = 0; j < f; j++)
        {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}
