#include <stdio.h>                      //Standard Input-Output Stream
#include <stdlib.h>                     //Standard Utility Functions
#include "Custom.h"                     //Including a custom header file
#define MYNAME "Nurul Amin"
#define AGE 18

/*  These are pre processor directives ^^^ */

int main()
{

    char letters[11] = "Nurul Amin";                    //char is an array for a string, [11] - So 11 Bytes (1 extra for string terminator)
    printf("My name is %s \n", letters);                //%s is a place holder for strings
    printf("I ate %d burgers last night\n", 5);         //%d is a place holder for integers
    printf("Pi is approximately %.6f\n", 3.1415923);     //%f is a place holder for floats (# with decimal places)

    letters[2] = 'z';                                   //Replaces element 2 of char array with new letter
    printf("My name is %s \n", letters);

    char food[] = "tuna";                               //An array with no need to set bytes - automatically sets (5 Bytes in this case)
    printf("The best food is %s \n", food);

    strcpy(food, "bacon");                              //Assigning a new string to the array, Tuna --> Bacon
    printf("The best food is %s \n", food);


    int age;                                            //Creating integers which can store numbers
    int currentYear;
    int birthYear;


    currentYear = 2015;
    birthYear = 1996;
    age = currentYear - birthYear;                      //Stores a value for the integer 'age'

    printf("Nurul is %d years old\n", age);

    int girlsAge = (AGE / 2) + 7;
    printf("%s can date girls %d or older\n", MYNAME, girlsAge);        //Using the constant from the pre processor directives

    char firstName[20];
    char crush[20];
    int numberOfBabies;

    printf("What is your name? \n");
    scanf("%s", firstName);                         //Scans the users input and stores in the array 'firstName'

    printf("Who are you going to marry? \n");
    scanf("%s", crush);

    printf("How many kids will you have? \n");
    scanf("%d", &numberOfBabies);

    printf("%s and %s are in love and will have %d babies \n", firstName, crush, numberOfBabies);

    int a = 86;
    int b = 21;
    printf("%d \n", a/b);              //This will print out an integer but the answer may not be correct

    float c = 86.0;
    float d = 21.0;
    printf("%f \n", c/d);              //This will print out a float to the correct decimal places


    int x = 4 + 2 * 6;                 //The difference using operators (Parenthesis)
    printf("Result: %d \n", x);
    x = (4 + 2) * 6;
    printf("Result: %d \n", x);


    int f;
    int g;
    int h;

    f = g = h = 100;            //Reads from right to left

    printf("%d %d %d \n", f, g, h);

    float age1, age2, age3, average;
    age1 = age2 = 4.0;

    printf("Enter your age\n");
    scanf("%f", &age3);

    average = (age1 + age2 + age3) / 3;
    printf("\nThe average age of the group is %f \n", average);

    int pageViews = 0;

    pageViews = pageViews + 1;
    printf("Page views: %d \n", pageViews);


    float balance  = 1000.00;

    balance *= 1.1;                 //These are the same things
    balance  = balance * 1.1;
    printf("Balance is %f \n", balance);

    //Typecasting is changing data types
    float avgProfit;
    int priceOfPumpkin = 10;
    int sales = 59;
    int daysWorked = 7;

    avgProfit = (priceOfPumpkin * sales) / daysWorked;
    printf("Average daily profit: $%.2f \n", avgProfit);                      //Prints $84.00
    avgProfit = ( (float)priceOfPumpkin * (float)sales) / (float)daysWorked;  //Changes data types from int to float
    printf("Average daily profit: $%.2f \n", avgProfit);                      //Prints $84.29 (Real value)

    float grade1;
    float grade2;
    float grade3;

    printf("Enter your 3 test grades: \n");
    scanf(" %f", &grade1);
    scanf(" %f", &grade2);
    scanf(" %f", &grade3);

    float avg = (grade1 + grade2 + grade3) / 3;
    printf("Average: %.2f \n", avg);

    if(avg >= 90){
        printf("Grade: A \n");
    }else if (avg >= 80){                       //If there is more than one choice, use 'else if'
        printf("Grade: B \n");
    }else if (avg >= 70){
        printf("Grade: C \n");
    }else if (avg >= 60){
        printf("Grade: D \n");
    }else {
        printf("You have failed");
    }

    int hours = 60;  //10 or more
    int trouble = 0; //0 trouble

    if ( (hours>=10) && (trouble==0) ){      //Testing 2 conditions, BOTH must be true to run next line
            printf("You are a good student \n");
    }

    char answer;

    printf("Do you like cheese? (y/n) \n");
    scanf(" %c", &answer);

    if( (answer=='y') || (answer=='n') ){       // || Stands for or
       printf("Good, you entered either y or n. \n");
    }
    else{
        printf("You should only enter y or n. \n");
    }

    return 0;
}

/**************************************************************************************************************************************************************************************/
int main()
{
    char lastName[20];
    printf("Enter your last name: \n");
    scanf(" %s", lastName);

    (lastName[0] < 'M' ) ? printf("Blue Team \n") : printf("Red Team \n") ;       //Shorthand if else statement

    int friends = 1;

    printf("I have %d friend%s \n", friends, (friends != 1) ? "s" : "" );            //Using if else in a conversion character


    int a = 5, b = 10, answer = 0;      //++ adds one to the integer (-- does the opposite)(increment operator)
    answer = ++a * b;                   //Adds one to a before equation is run so (5+1) * 10 = 60
    printf("Answer: %d \n", answer);

    a = 5, b = 10, answer = 0;
    answer = a++ * b;                   //Adds one to a after it runs so (5*10) + 1 = 50 (Not 51 as it didn't print out new value)
    printf("Answer: %d \n", answer);


    int day  = 1;
    float amount = .01;

    while(day <= 5){                                            //While will keep running code until test becomes false
        printf("Day:%d \t Amount:$%0.02f \n", day, amount);     // \t will add a tab
        amount *=2;
        day++;
    }


    float grade = 0;
    float scoreEntered = 0;
    float numberOfTests = 0;
    float average = 0;

    printf("\nEnter 0 when you have entered all test scores. \n\n");

    do{                                                                     //Do while function will run code at least ONCE until test is false
        printf("Tests:%.0f  Average:%.2f \n ", numberOfTests, average );
        printf("\nEnter test score: ");
        scanf("%f", &scoreEntered);
        grade += scoreEntered;
        numberOfTests++;
        average = grade / numberOfTests;

    }while(scoreEntered != 0);

    int food;

    for(food=0; food<=100; food+=8){                                          //for used when you know how many times to loop
        printf("Food is %d \n", food);
    }

    return 0;
}

/**************************************************************************************************************************************************************************************/
int main()
{
    //Creating a table
    int columns;
    int rows;

    for(rows=1; rows<=6; rows++){

        for(columns=1; columns<=4; columns++){
            printf("%d ", columns);
        }

        printf("\n");
    }

    int a;
    int howMany;
    int maxAmount = 10;

    printf("How many times do you want this loop to loop? (Up to 10) ");
    scanf(" %d", &howMany);

    for(a=1; a<=10; a++){

        printf("%d\n", a);

        if(a==howMany){
            break;                      //Break will stop the loop once condition is met
        }

    }

    int num = 1;

    do{

        if(num==6 || num==8){
            num++;
            continue;               //After this continue line runs, it goes back to the top and ignores anything below this
        }

        printf("%d is available \n", num);
        num++;

    }while(num<=10);

    char grade = 'C';

    switch (grade){                         //Test the variable that was created before
        case 'A' : printf("Sweet! \n");     //In the case that grade=A, print out this string (After the colon)
                   break;
        case 'B' : printf("Could have tried harder \n");
                   break;
        case 'C' : printf("I C you didn't study \n");
                   break;
        default  : printf("That doesn't make sense! \n");     //If previous lines of code do not run, this will run
    }

    int tuna = 'F';

    if( isalpha(tuna) ){                    //isalpha checks if it is in the alphabet

        if( isupper(tuna) ){                //isupper returns true if the string is uppercase
            printf("%c is an upper case letter \n", tuna);
        }else{
            printf("%c is a lower case letter \n", tuna);
        }

    }else{

        if( isdigit(tuna) ){
            printf("%c is a number", tuna);
        }else{
            printf("%c is a OMG WTF IS THAT", tuna);
        }
    }

    char d = 'a';
    char b = 'F';
    char c = '7';

    printf("%c \n", toupper(d) );           //toupper changes lowercase letter to uppercase
    printf("%c \n", toupper(b));
    printf("%c \n", toupper(c));

    char ham[100] = "Hey ";

    strcat(ham, "Nurul");                   //strcat Adds string to another string
    printf("%s \n", ham);

    strcpy(ham, "Bacon");                   //strcpy Replaces one string with another
    printf("%s \n", ham);

    char catsName[50];

    puts("Whats the cats name? ");          //prints
    gets(catsName);                         //scans

    float cheese1 = 5.643423;
    float cheese2 = 3.3;

    printf("cheese1 is %.2f \n", floor(cheese1) );         //floor Rounds down to nearest number
    printf("cheese2 is %.2f \n", floor(cheese2) );

    printf("cheese1 is %.2f \n", ceil(cheese1) );          //ceil rounds down
    printf("cheese2 is %.2f \n", ceil(cheese2) );

    int year1;
    int year2;
    int age;

    printf("Enter a year \n");
    scanf(" %d", &year1);

    printf("Enter another year \n");
    scanf(" %d", &year2);

    age = year1 - year2;
    printf("%d \n", age);
    age = abs(age);                 //abs is modulus
    printf("%d \n", age);

    printf("%f \n", pow(5,3) );     //pow puts 5^3
    printf("%f \n", sqrt(164) );    //prints square root

    int i;
    int diceRoll;

    for(i=0; i<20; i++){
        diceRoll = ( rand()%6 ) + 1;        //rand is random number
        printf("%d \n", diceRoll);
    }

    int h;
    int meatballs[5];
    int totalBalls = 0;

    for(h=0; h<5; h++){
        printf("How many meatballs did you eat on day %d \n", h+1);
        scanf(" %d", &meatballs[h]);
    }

     for(h=0; h<5; h++){
       totalBalls += meatballs[h];
    }

    int avg = totalBalls / 5;
    printf("\nYou ate %d meatballs total, thats an average of %d per day \n", totalBalls, avg);

    return 0;
}

/**************************************************************************************************************************************************************************************/
int main()
{
    int i, temp, swapped;
    int howMany = 10;
    int goals[howMany];

    for(i=0; i<howMany; i++){
        goals[i] = ( rand()%25 )+1;
        }

    printf("Original List\n");

    for(i=0; i<howMany; i++){
        printf("%d \n", goals[i]);
        }

    while(1){       //1 = true

        swapped = 0;

        for(i=0; i<howMany-1; i++){

            if(goals[i]>goals[i+1]){
                int temp = goals[i];
                goals[i] = goals[i+1];
                goals[i+1] = temp;
                swapped = 1;

            }
        }

        if(swapped==0){
            break;
        }
    }

    printf("\nSorted List\n");
    for(i=0; i<howMany; i++){
        printf("%d \n", goals[i]);
    }

    int tuna = 15;
    int * pTuna = &tuna;                  //pointer is a variable that stores the memory address

    printf("Address \t Name \t Value \n");
    printf("%p \t %s \t %d \n", pTuna, "tuna", tuna);
    printf("%p \t %s \t %p \n", pTuna, "pTuna", pTuna);

    printf("\n*pTuna: %d \n", *pTuna);      //dereferencing a pointer - gets the value of the variable

    *pTuna = 71;
    printf("\n*pTuna: %d \n", *pTuna);
    printf("\ntuna: %d \n\n", tuna);

    int n;
    int meatBalls[5] = {7,9,43,21,3};

    printf("Element \t Address \t Value \n");

    for(n=0; n<5; n++){
        printf("meatBalls[%d] \t %p \t %d \n", n, &meatBalls[n], meatBalls[n]);
    }

    printf("\nmeatBalls \t\t %p \n", meatBalls);
    printf("\n*(meatBalls+2) \t\t %d \n", *(meatBalls+2));

    char movie1[] = "The Return of Nurul";  //pointer constant
    char * movie2 = "Nurul is awesome";

    puts(movie2);

    movie2 = "New movie title"; //Changing string of pointer as it is variable

    puts(movie2);

    char movie [20];
    char *pMovie = movie;

    fgets(pMovie, 20, stdin);   //gets input from keyboard (stdin = standard input), 20 is maximum number of characters stored in pMovie
    puts(pMovie);

    int * points;   //Heap is leftover memory we can borrow when we need it and then give it back when program ends
    points = (int *) malloc(5 * sizeof(int));   //malloc allocates memory from the heap, (int *) is a int typecast pointer (changing data types)
    free(points);   //For 5 integers, sizeof gets the amount of bytes of the int
    //free returns the memory back to the computer

    return 0;
}
/**************************************************************************************************************************************************************************************/
struct user{        //structure is a group of variables
    int userID;
    int firstName[25];  //members of the structure
    int lastName[25];
    int age;
    float weight;
};

int main()
{
    int i, howMany;
    int total = 0;
    float average = 0.0;
    int * pointsArray;

    printf("How many numbers do you want to average?\n");
    scanf(" %d", &howMany);

    pointsArray = (int *) malloc(howMany * sizeof(int));

    printf("Enter them boss! \n");

    for(i=0; i<howMany; i++){
        scanf(" %d"), &pointsArray[i];
        total += pointsArray[i];
    }

    average = (float)total / (float)howMany;
    printf("Average is %f \n", average);

    struct user Nurul;
    struct user Amin;

    Nurul.userID = 91723;      //dot operator - access individual elements inside structure
    Amin.userID = 23233;

    puts("Enter the first name of user 1\n");
    gets(Nurul.firstName);
    puts("Enter the first name of user 2\n");
    gets(Amin.firstName);

    printf("User 1 id is %d\n", Nurul.userID);
    printf("User 2 first name is %d\n", Amin.firstName);

    FILE *  fPointer;
    fPointer = fopen("ham.txt", "w");   //opens and writes to a file, will overwrite previous
    fprintf(fPointer, "This is a file named ham\n Cheese \n");        //prints to a file

    fclose(fPointer); //closes to free some memory

    return 0;
} 
/**************************************************************************************************************************************************************************************/
void printSomething();                       //Prototypes the function
void convertToDollars(float euro);
int calculateBonus(int yearsWorked);
void passByValue(int i);
void passByAddress(int *i);

int tuna = 4;                                     //(Global) Variable above the function - all functions can use it

int main(){

    //**********************************************************************  
     
    bacon = 6; //Local variable, only usable by this function
    printf("I have %d tuna\n", tuna);

    printSomething();   //This is a function we made before
    printSomething();

    //**********************************************************************  

    float euroPrice1 = 1.00;
    float euroPrice2 = 5.50;

    convertToDollars(euroPrice1);   //Passes argument to function
    convertToDollars(euroPrice2);
    convertToDollars(23.3);  

     //**********************************************************************

    int nurulsBonus = calculateBonus(14);
    printf("I get %d", nurulsBonus);  

     //**********************************************************************  

    int tuna = 20;

    passByValue(tuna);
    printf("Passing by value, tuna is now %d \n", tuna);

    passByAddress(&tuna);
    printf("Passing by address, tuna is now %d \n", tuna);  

    //**********************************************************************  

    FILE *fPointer;
    fPointer = fopen("ham.txt", "w+");
    fputs("I ate 3 pumpkins", fPointer);

    fseek(fPointer, 7, SEEK_SET); //seek set puts cursor at beginning
    fputs(" munchkins on friday", fPointer);

    fseek(fPointer, -6, SEEK_END);
    fputs("tuesday", fPointer);

    fclose(fPointer);  

    //**********************************************************************  

    return 0;
}

void printSomething()             //A function that does something but doesnt return anything
{
    printf("I have %d tuna", tuna);
    printf("This is a function \n");
    return;
}

void convertToDollars(float euro)   //create a variable in the brackets
{
    float usd = euro * 1.37;
    printf("%.2f Euros - %.2f USD\n", euro, usd);

    return;
}

int calculateBonus(int yearsWorked)
{
    int bonus = yearsWorked * 250;

    if(yearsWorked > 10){
        bonus += 1000;
    }

    return bonus;
}

void passByValue(int i)
{
    i = 50;
    return;
}

void passByAddress(int *i)
{
    *i = 64;
    return;
}

