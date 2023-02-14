#include <stdio.h>
#include <stdlib.h>

int is_sparse(int** a, int i, int j);
int main ()
{
    int **a;
    int i = 10, j = 10;
    int x, y;
    int is_true = 0;

    a = (int**)malloc(i * sizeof(int*));

    for(x = 0; x < 10; x++){
        a[x] = (int*)malloc(j*sizeof(int)); 
    }

    //FILL THE MATRIX
    
    for (x = 0; x < i; x++){
        for(y = 0; y < j; y++){
            a[x][y] = rand();
        }
    }
    for (x = 0; x < i; x++){
            a[x][2] = 0;
            a[x][3] = 0;
            a[x][5] = 0;
            a[x][7] = 0;
            a[x][9] = 0;
    }
    is_true = is_sparse(a, i, j);
    if (is_true){
        printf("SPARSE MATRIX");
    } else {
        printf("NOT SPARSE MATRIX"); 
    }
    for (x = 0; x < i; x++){
        if (a[x])
        free(a[x]);
    }
    return 0;
}


int is_sparse(int **x, int i, int j){
    
    int c_t = 0, c_z = 0, a, b;

    for(a = 0; a < i; a++){
        for(b = 0; b < j; b++){
            if (x[a][b] == 0){
                c_z++;
            }
            c_t++;
        }

    }
    if (c_z >= (c_t/2)){
        return 1;
    } else {
        return 0;
    }
}
