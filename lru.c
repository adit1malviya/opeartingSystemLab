#include <stdio.h>

int main(void)
{
    int pages[100];
    int frames[20];
    int lastUsed[20];

    int n, f;
    int i, j;

    int faults = 0;
    int time = 0;

    printf("Enter reference string length: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        frames[i] = -1;
        lastUsed[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for (i = 0; i < n; i++)
    {
        int found = -1;

        time++;

        for (j = 0; j < f; j++)
        {
            if (frames[j] == pages[i])
            {
                found = j;
                break;
            }
        }

        if (found != -1)
        {
            lastUsed[found] = time;
        }
        else
        {
            int position = -1;

            for (j = 0; j < f; j++)
            {
                if (frames[j] == -1)
                {
                    position = j;
                    break;
                }
            }

            if (position == -1)
            {
                position = 0;

                for (j = 1; j < f; j++)
                {
                    if (lastUsed[j] <
                        lastUsed[position])
                    {
                        position = j;
                    }
                }
            }

            frames[position] = pages[i];
            lastUsed[position] = time;

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