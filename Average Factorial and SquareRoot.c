#include <stdio.h>
#include <stdlib.h>

float average(float a, float b, float c);
int factorial(int j);
int sqrt(int square);


int main(void){

    char answer;

    printf("What would you like to do? \n");

    printf("A: Average\nB: Square Root\nC: Factorial\nD: Exit\n");

    scanf("%s",&answer);

    float f,g,h;    //These are for the average statement
    int s,k;        //These are for the square root and factorial statement respectively

    switch (answer){

    case 'A':

        printf("Enter the first number: ");
        scanf("%f", &f);

        printf("Enter the second number: ");
        scanf("%f", &g);

        printf("Enter the third number: ");
        scanf("%f", &h);

        printf("The average is %f \n", average(f,g,h));

        break;

    case 'B':

        printf("Enter an integer: \n");

        scanf("%d", &s);

        printf("The square root is %d \n", sqrt(s));

        break;

    case 'C':

        printf("Enter an integer: \n");

        scanf("%d", &k);

        printf("The factorial is %d \n", factorial(k));

        break;

    case 'D':

        break;

    }

    return 0;
}

float average(float a, float b, float c){

    float avg = (a + b + c) / 3;

    return avg;

}

int factorial(int v){

    int r = 1;

    while (v >= 1){
    r *= v;
    v--;

    }
    return r;
}

int sqrt(int square){

    int q;

    for (q=0; q <= square; q++){
        if (square == q * q){
            return q;
        }
    }
    return -1;
}
