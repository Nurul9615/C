#include <stdio.h>      //Including the
#include <stdlib.h>     //Pre-processor directives

void my_strcpy(char[], char[]);                                         //Declaring a function that will return nothing with 2 character type arguments
int my_strcmp(char[], char[]);                                          //Declaring a function that will return an integer (0 or -1) with 2 character type arguments


int main(){                                                             //Main function which will return an integer with no arguments

    char string1[500],string2[500],string3[500],string4[500],command;   //Create character variables with the string(n) variables containing 500 indexes
    int temp;                                                           //Create a integer variable

    printf("What would you like to do? \n");                            //Ask user which function they would like to do
    printf("A: Copy String\nB: Compare String\n");                      //Shows which functions are available

    scanf("%s", &command);                                              //Stores their answer in the command char variable

    switch (command){                                                   //Switch statement on their answer to open the function they chose

    case 'A':                                                           //In the case that their answer was A (First function), do the following

        printf("Enter a string: \n");                                   //Enter the string they want to be copied
        scanf("%s", string1);                                           //Store their answer in the char string1 variable

        my_strcpy(string2,string1);                                     //Call the my_strcpy function while passing these arguments to it

        printf("Your string:    \"%s\"\n", string1);                    //Print the original string they entered
        printf("Copied string:  \"%s\"\n", string2);                    //Print the new string which is a copy of the original

        break;                                                          //Stop the case if the statements are run and carry on to the next function

    case 'B':                                                           //In the case that their answer was B (Second function), do the following

        printf("Enter your first string: \n");                          //Enter the first string to compare
        scanf("%s", string3);                                           //Store first string in the string3 char variable

        printf("Enter your second string: \n");                         //Enter the second string to compare first to
        scanf("%s", string4);                                           //Store second string in the string4 char variable

        temp = my_strcmp(string3,string4);                              /*This integer variable will contain either -1,0,1 depending on if the strings
                                                                          are equal which is acquired by calling the function with these input arguments */

        if (temp == 0)                                                  //If function saying that if the strings are equal, do the following
            printf("Both the strings are equal. \n");                   //Print this if condition is met
        else                                                            //Do this instead if previous condition is not met, which is when the value is -1 or 1
            printf("Both the strings are not equal. \n");               //Print this if previous condition was not met

        break;                                                          //Stop the case if the statements are run and carry on to the next function

    return 0;                                                           //Int main function will return nothing
}
}

void my_strcpy(char string2[], char string1[]){                         //String copy function with 2 character type arguments which will contain the strings

    int p = 0;                                                          //Placeholder variable created which is assigned to each index of the character arrays

    while (string1[p] != '\0'){                                         //While the pth index of the users inputted string is not equal to the final null index terminator, do the following

        string2[p] = string1[p];                                        /*Make the pth index of the copied string equal the pth index of the users inputted string,
                                                                          so each character of the inputted string is copied to the corresponding index of the new copied string */
        p++;                                                            //Increment the p variable placeholder which will happen until p reaches the index of the null terminator, each increment will allow the next index to be evaluated
    }

    string2[p] = '\0';                                                  //Once p has reached the maximum value, change the last index of the new string to the null terminator so the program does not crash when run
}

int my_strcmp(char t[], char u[]){                                      //String compare function with 2 character inputs

    int r = 0;                                                          //Creating a placeholder variable to evaluate each index of the character arrays

    while (t[r] == u[r]){                                               //While function will run while each index of the first string is equal to the corresponding index of the second string
        if (t[r] == '\0' || u[r] == '\0')                               //While the above condition is met, if function will run if the rth index of any string becomes the null string terminator
            break;                                                      //If the index does reach the null terminator, break the if loop
        r++;                                                            //Increment this placeholder variable until the max r is reached where it equals the null terminator
    }

    if (t[r] == '\0' && u[r] == '\0')                                   //If function will execute if the rth index of BOTH strings is equal to the null terminator meaning they have the same amount of characters with \0 at the same position
        return 0;                                                       //Return 0 if the rth index of the null terminator is the same
    else                                                                //Else do the below statement if previous condition not met
        return -1;                                                      //Return -1 if the rth index of the null terminator is different for both strings
}





