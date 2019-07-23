//Matrices using a Multidimensional Array
//Jason Eddy N'Guessan
#include<stdio.h>

int main(){
    //for loop identifiers
    int i, j, k;
    //Check
    int check = 0; //check = 1 is true
    //variables
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
    
    
    //Entering Row
    if(check == 0){
        
        printf("ROW # MUST EQUAL # OF COLUMN \n");
        printf("\n");

        printf("Enter # of row for matrix 1: ");
        scanf("%d", &row1);
        printf("Enter # of column for matrix 1: ");
        scanf("%d", &col1);
        
        
        printf("Enter # of row for matrix 2: ");
        scanf("%d", &row2);
        printf("Enter # of column for matrix 2: ");
        scanf("%d", &col2);
        
        if(row1 == col2){
            check = 1;
        }
        else{
        printf("\n");
            //Correcting For misinputs
        while (check == 0) {
            
            printf("ROW # MUST EQUAL # OF COLUMN \n");
            printf("Re enter Row of Matrix 1: ");
            scanf("%d", &row1);
            printf("Re enter Column of Matrix 2: ");
            scanf("%d", &col2);
            
            printf("\n");

            
            if(row1 == col2){
                check = 1;
                
            }
        }
        }
        
        
        //Add row/col nums to arrays   - results identifies rows1 * columns2
        int matrix1[row1][col1], matrix2[row2][col2], results[row1][col2];
        
        printf("\n");
        
        //Add to matrix1
        for (i = 0; i < row1; i++) {
            for ( j = 0; j < col1; j++) {
                printf("Enter element for matrix1[%d][%d]: ", i, j);
                scanf("%d", &matrix1[i][j]);
                
            }
        }
        
        printf("\n");
        
        //Add to matrix2
        for (i = 0; i < row2; i++) {
            for ( j = 0; j < col2; j++) {
                printf("Enter element for matrix2[%d][%d]: ", i, j);
                scanf("%d", &matrix2[i][j]);
                
            }
        }
        
        //Add to ma
        for (i = 0; i < row2; i++) {
            for ( j = 0; j < col2; j++) {
                printf("%d \t", matrix2[i][j]);
                
            }
        }
        
    
        
        //innitialize results as we know dot product is row * column
        for (i = 0; i < row1; i++) {
            for ( j = 0; j < col2; j++) {
                results[i][j] = 0;
            }

        }
        
        for (i = 0; i < row1; i++) {
            for ( j = 0; j < col1; j++) {
                for (k = 0; k < row2; k++) {
                    
                    results[i][j] += matrix1[i][k] * matrix2[k][j];
                  //  printf("i: %d, j: %d, k: %d ||", i, j, k);
                }
            }
        }
            
            printf("\n");
            
            for (i = 0; i < row1; i++) {
                for (j = 0; j < col2; j++) {
                    printf("%d ", results[i][j]);
                    
                
                }
            }
        

        
    }
  
    
    
}
