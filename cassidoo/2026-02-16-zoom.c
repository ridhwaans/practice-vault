//cassidoo week of feb 16, 2026

#include <stdlib.h>
#include <stdio.h>

int** make2D(int rows, int cols, int data[][cols]){
    int **arr = malloc(rows * cols * sizeof(int*));
    for (int i=0;i<rows;i++){
            arr[i] = malloc(cols * sizeof(int));
            for (int j=0;j<cols;j++){
                    arr[i][j] = data[i][j];
            }
    }
    return arr;
}

void print2D(int** nums, int size, int colSize){
    printf("{\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < colSize; j++){
            if (j == 0) printf("{ ");
            if (j < colSize - 1) {
                printf("%d, ", nums[i][j]);
            } else {
                printf("%d },\n", nums[i][j]);
            }
        }
    }
    printf("}\n");
}

int** zoom(int** nums, int size, int colSize, int zoom){
    if (zoom < 2) return NULL;
    int newSize = size * zoom;
    int newColSize = colSize * zoom;
    int **result = malloc(newSize * sizeof(int*));
    for (int i = 0; i < newSize; i++){
        result[i] = malloc(newColSize * sizeof(int));
    }
    
    for (int i = 0; i < size; i++){
            for (int j = 0; j < colSize; j++){
                for (int m = 0; m < zoom;m++){
                    for (int n = 0; n < zoom;n++){
                            result[i*zoom + m][j*zoom + n] = nums[i][j];
                    }
                } 

            }
    } 
    return result;
}

int main(int argc, char** argv){
    printf("zoom\n\n");
    int tmp1[2][2] = {{1,2},{3,4}};
    int tmp2[1][3] = {{7,8,9}};
    int tmp3[2][1] = {{1},{2}};
    int **case1 = make2D(2, 2, tmp1);
    int **case2 = make2D(1, 3, tmp2);
    int **case3 = make2D(2, 1, tmp3);

    printf("input\n");
    print2D(case1, 2, 2);
    int** res1 = zoom(case1, 2, 2, 2);
    printf("result\n");
    print2D(res1, 4, 4);
    
    printf("input\n");
    print2D(case2, 1, 3);
    int** res2 = zoom(case2, 1, 3, 3);
    printf("result\n");
    print2D(res2, 3, 9);
    
    printf("input\n");
    print2D(case3, 2, 1);
    int** res3 = zoom(case3, 2, 1, 3);
    printf("result\n");
    print2D(res3, 6, 3);
}

