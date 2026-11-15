#include <stdio.h>

int main(void)
{
    int n, i;
    int bt[20], wt[20], tat[20];

    float avgWT = 0.0;
    float avgTAT = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n",
               i + 1,
               bt[i],
               wt[i],
               tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n",
           avgWT / n);

    printf("Average Turnaround Time = %.2f\n",
           avgTAT / n);

    return 0;
}
