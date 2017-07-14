#include <stdio.h>      //Including the
#include <stdlib.h>     //Pre-processor directives

void add_matrices(int m1[][15], int m2[][15], int destination_matrix[][15], int n_rows, int n_columns); //Declare function which will return nothing with these 5 arguments

int main(){                                                                     //Main function which will return an integer with no input arguments

    int mac1[15][15],mac2[15][15],mac3[15][15],k,p,rows,columns;                //Create 3 integer arrays with 15x15 indexes and some placeholder variables

    printf("How many rows do you want in your matrices? \n");                   //Ask user what they want
    scanf("%d", &rows);                                                         //Store user input into the variable rows
    printf("How many columns do you want in your matrices? \n");                //Same as above
    scanf("%d", &columns);                                                      //Same as above

    printf("Enter numbers for first matrix: \n");                               //Ask users what numbers they want in first matrix
        for(k = 0; k < rows; k++){                                              //Keep incrementing k until it reaches the number of rows user inputted
            for(p = 0; p < columns; p++){                                       //While above function is executing, also increment p until it reaches number of columns user inputted
                scanf("%d", &mac1[k][p]);                                       //Store the users inputted values one by one with the k and p corresponding to each row and column until it reaches the max
            }
        }

     printf("Enter numbers for second matrix: \n");                             //Same as above but for second matrix
        for(k = 0; k < rows; k++){                                              //Same as above
            for(p = 0; p < columns; p++){                                       //Same as above
                scanf("%d", &mac2[k][p]);                                       //Same as above
            }
        }

    add_matrices(mac1,mac2,mac3,rows,columns);                                  //Call the adding matrices function with the input arguments shown

    printf("The two matrices added together is: \n");                           //Print the result
        for(k = 0; k < rows; k++){                                              //For function which will increment until the number of rows inputted
                for(p = 0; p < columns; p++){                                   //This will also increment until number of columns inputted if above function is still running
                    printf("%10d", mac3[k][p]);                                 //Print the final matrice with a width of 10 with the corresponding inputted values
                }
                printf("\n");                                                   //Print a new line after each row is done
        }

    return 0;                                                                   //Return nothing
}

void add_matrices(int m1[][15], int m2[][15], int destination_matrix[][15], int n_rows, int n_columns){     //Function to add matrices with 3 array arguments

        int i,j;                                                                //Placeholder integer variables

        for(i = 0; i < n_rows; i++ ){                                           //Keep incrementing i until it reaches the number of rows inputted
            for(j = 0; j < n_columns; j++){                                     //Keep incrementing j until it reaches number of columns inputted while the above runs
                destination_matrix[i][j] = m1[i][j] + m2[i][j];                 //If above is true, add the corresponding index values of matrix 1 and matrix 2 into the final matrix
            }

        }

}
