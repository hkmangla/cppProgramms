#include <stdio.h>

#define SIZE 13

int boyerMoore(int arr[]) {
    int current_candidate = arr[0], counter = 0, i;
    for (i = 0; i < 11; ++i) {
        if (current_candidate == arr[i]) {
            ++counter;
            printf("candidate: %i, counter: %i\n",current_candidate,counter);
        } else if (counter == 0) {
            current_candidate = arr[i];
            ++counter;
            printf("candidate: %i, counter: %i\n",current_candidate,counter);
        } else {
            --counter;
            printf("candidate: %i, counter: %i\n",current_candidate,counter);
        }
    }
    return current_candidate;
}

int main() {
    int numbers[SIZE] = {5,5,5,3,3,1,1,5,3,1,2,2};
    printf("majority: %i\n", boyerMoore(numbers));
    return 0;
}
