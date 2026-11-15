#include <stdio.h>

int main(void)
{
    int n, i, j;
    int bt[20];
    int pid[20];
    int wt[20];
    int tat[20];

    float avgWT = 0.0;
    float avgTAT = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("Enter burst time for P%d: ",
               i + 1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                int temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

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
               pid[i],
               bt[i],
               wt[i],
               tat[i]);
    }

    printf("\nAverage WT = %.2f\n",
           avgWT / n);

    printf("Average TAT = %.2f\n",
           avgTAT / n);

    return 0;
}
