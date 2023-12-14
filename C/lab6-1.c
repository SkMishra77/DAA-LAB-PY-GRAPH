#include <stdio.h>

void greedy_activity_selector(int start_time[], int finish_time[], int n) {
    int arr[n];
    int count=1;
    int j=0;
    int i;
    arr[0] = 1;

    printf("Selected Activity : \n");

    for (i = 1; i < n; i++) {
        if (start_time[i] >= finish_time[j]) {
            arr[count] = i+1;
            count++;
            j = i;
        }
    }
    
    for(int i=0;i<count;i++){
        printf("-------");
    }
    printf("\n");
    for(int i=0 ; i<count ; i++){
        printf("  P%d  |", arr[i]);
    }
    printf("\n");
    for(int i=0;i<count;i++){
        printf("-------");
    }
    printf("\n");


}

int main() {
    int start_times[] = {1, 3, 0, 5, 8, 5,11,15};
    int finish_times[] = {2, 4, 6, 7, 9, 9,14,18};
    int n = sizeof(start_times) / sizeof(start_times[0]);

    greedy_activity_selector(start_times, finish_times, n);

    return 0;
}
