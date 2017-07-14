#include <stdio.h>                                                  //Including the
#include <stdlib.h>                                                 //Pre-Processor Directives
#include <string.h>                                                 //String library for string compare

struct records{                                                     //Creating a structure called records which will contain all the different data types and arrays
    float marks[10];                                                //Floating numbers array to store marks for each student, up to 10 courses
    char name[1000];                                                //Character array to store names of each student
    int number;                                                     //For the student id numbers which will be integers
};

void main(){                                                        //Main function to return nothing with no input arguments

    struct records student[1000];                                   //Create a structure variable called student within records to contain up to 1000 students
    int answer = 0, u = 0, k, n;                                    //Placeholder variable for switch statement, for indexing structure array and for dummy variables for loops
    char name[1000];                                                //Character array to store names
    int mnum[1000] = {0};                                           //Integer array to store marks with all of them assigned to 0 initially for 1000 students

    do{                                                             //Do while loop will run at least once, and continue to run if the while condition is true after every execution

    printf("What would you like to do? \n1: Introduce new students\n2: Introduce marks\n3: Print report of all students\n4: Exit\n");
    scanf("%d", &answer);                                           //Ask the user what they want and store in the temporary variable

    switch(answer){                                                 //Switch their answer to choose their chosen function

    case 1:                                                         //Case to store a students name and number

        printf("Enter a student name & number \n");                 //Ask for inputs
        scanf("%s", student[u].name);                               //Store their name in the name variable in the structure in the first index and so on..
        scanf("%d", &student[u].number);                            //Same as above but with student number
        u++;                                                        //Increment the index integer so the next student can be added next time to the next index

    break;                                                          //Break the case if it is finished executing

    case 2:                                                         //Case to enter student marks

    printf("Enter the students name and their mark \n");            //Ask for user input and store it in the variable name
        scanf("%s", name);
        for(k = 0; k < u; k++){                                     //For loop which counts up to however many students there are
            if( (strcmp(student[k].name, name) == 0 ) ){            //If the name they entered equals the name in the kth index of the structure (and returns 0) , do the following
                scanf("%f", &student[k].marks[mnum[k]]);            //Scan the mark they enter into the marks variable in the structure for the kth student with the index of mnum[k]
                mnum[k]++;                                          //Increment the marks index of the structure for the next student for next time, so increment the course number
            }
}

    break;                                                                                            //Break the case if it is finished executing

    case 3:                                                                                           //Case to print out the results

    printf("Current record for all students is: \n");                                                 //Print statement
        for(k = 0; k < u; k++){                                                                       //For loop to count upto the max number of students
            printf("\nStudent Name: %s \nStudent Number: %d \n", student[k].name, student[k].number); //Print the kth students name and number each time this loop is executed
                for(n = 0; n < mnum[k]; n++){                                                         //For loop to count upto the kth marks index for each student
                    printf("Course %d: %f \n", n, student[k].marks[n]);     
                }                                                                                     //Print statement to print out for courses starting from 0 to N for each kth student with their list of nth marks
}
    break;                                                                                            //Break the case if it is finished executing
    }

}   while(answer != 4);                                                                               //Do this function over and over until the user inputs 4 at the start menu
    }