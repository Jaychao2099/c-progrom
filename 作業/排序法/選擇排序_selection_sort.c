# include <stdio.h>
# include <stdlib.h>

int main(){
    int count;
    printf("Enter the number of list: ");
    scanf("%d", &count);

    int *list = malloc( (count) * sizeof(int) );

    printf("Enter the list: \n");
    for(int i = 0; i < count; i++){
        scanf("%d", &list[i]);
    }

    for (int i = 0; i < count-1; i++){
        int min_index = i;
        for(int j = i+1; j < count; j++){
            min_index = list[j] < list[min_index] ? j : min_index;
        }

        if(min_index != i){
            int temp = list[i];
            list[i] = list[min_index];
            list[min_index] = temp;
        }
    }
    printf("Sorted list:");
    for(int i = 0; i < count; i++){
        printf(" %d", list[i]);
    }
    
    free(list);

    return 0;
}