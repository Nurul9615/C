#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct records{
    int studentmarks[20];                                                    //Numbers array to store marks for each student, up to 20 courses
    char studentname[20];                                                    //Name of upto 20 characters
    int studentnumber;                                                       //To store student ID number for each student
    struct records *next;                                                    //Points to the next node, it is a recursive pointer - pointing to structure of its same type
}*root;                                                                      //First root node structure which points to next node, it is a global variable

void insert_linked_list(int number, char name[]){                            //This is to insert a student into the linked list data structure

    int i = 0;
    struct records *conductor;                                               //Temporary pointer to traverse the list
    conductor = root;                                                        //Point to root first
    while(conductor != NULL){                                                //This will find the last node by traversing the list until it finds one which points to NULL
        i++;
        conductor = conductor->next;
    }
    if (i == 0){                                                                  //This is used to create the first student structure node 
        struct records *conductor2;                                               //Points to each node
        conductor2 = (struct records*)malloc(sizeof(struct records));             //Now contains the address of a memory block in the heap with the size of our records structure
        strcpy(conductor2->studentname, name);                                    //Memory block now contains data of arguments from the user
        conductor2->studentnumber = number;
        conductor2->studentmarks[0] = -10;                                        //First element of student marks array contains -10 (end of list), - is used as a positive number is something the user may enter as a mark
        if(root == NULL){                                                         //If list is empty
            root = conductor2;                                                    //If root points to address 0 (NULL), then make root point to the new node memory block (conductor2)
            root->next = NULL;                                                    //Next node will now point to NULL
        }
        else{                                                                     //List is not empty
            conductor2->next = root;                                              //If nodes already exist after root, make the memory block after conductor contain the address of root
            root = conductor2;                                                    //Root now contains the address of the new memory block - essentially inserting a new node at beginning of list
        }
    }
    else{                                                                        //Otherwise if list is not empty, use this function, This will add a node at the end which will point to NULL
        struct records *conductor3, *after;                                      //After is a temporary pointer to the node after root
        conductor3 = (struct records *)malloc(sizeof(struct records));           //Allocate a block of memory for the node and point the conductor to it
        conductor3->studentnumber = number;                                      //This will store the student number into the temporary node
        strcpy(conductor3->studentname, name);                                   //This will store the student name by string copying it into the temporary node
        conductor3->studentmarks[0] = -10;                                       //First element of student marks array will contain -10, which is the end of the array for now
        after = (struct records *)root;                                          //After pointer now contains typecasted address of root
        while(after->next != NULL){                                              //Traverse the list until the last node is found
            after = after->next;
        }
        after->next = conductor3;                                                //Replace the node pointing to null with the information stored in conductor
        after = conductor3;                                                      
        after->next = NULL;                                                      //Create new NULL at end of the list 
        }
}

void insert_binary_tree(int number, char name[]){                               //Insert a person using binary tree

    int i = 0;
    struct records *conductor;
    conductor = root;
    if(conductor == NULL){                                                  //If list is empty, create the first node after root using this
        struct records *conductor2;                                              
        conductor2 = (struct records*)malloc(sizeof(struct records));            
        strcpy(conductor2->studentname, name);                                   
        conductor2->studentnumber = number;
        conductor2->studentmarks[0] = -10;                                       
        if(root == NULL){                                                        
            root = conductor2;                                                    
            root->next = NULL;                                                   
        }
        else{                                                                    
            conductor2->next = root;                                             
            root = conductor2;                                                    
        }
    }
    else{                                                 //If list is not empty, traverse list until you reach the node with the student name entered by user, where i will reach the i'th node
        while(root != NULL)
            if (conductor->studentnumber < number){
                i++;
                conductor = conductor->next;
    }
    }
    if(i == 0){                                          //If its the first name, enter the first node using this 
        struct records *conductor3;                                              
        conductor3 = (struct records*)malloc(sizeof(struct records));            
        strcpy(conductor3->studentname, name);                                   
        conductor3->studentnumber = number;
        conductor3->studentmarks[0] = -10;                                       
        if(root == NULL){                                                        
            root = conductor3;                                                    
            root->next = NULL;                                                   
        }
        else{                                                                    
            conductor3->next = root;                                             
            root = conductor3;                                                    
        }
    }
    else if (i < maximum()){                               //If the name is at a node just less than the maximum nodes in the tree, use the add binary process below
        int place = ++i;                                   //place is now contains the position of the maximum node 
        int j;
        struct records *conductor5, *left, *right;
        right = root;                                                               //Right node of the parent node now contains address of root
        conductor5 = (struct records *)malloc(sizeof(struct records));
        conductor5->studentnumber = number;
        strcpy(conductor5->studentname, name);
        conductor5->studentmarks[0] = -10;

        for(j = 1; j < place; j++){                                                 //Loop will go through the binary tree until j is less than place, to reach the node where we want to add is found
            left= right;                                                            //The left node now contains address of the right node 
            right = right->next;                                                    //Right contains address of next right node until end
        }
        left->next = conductor5;                                                    //Point from our previous node to the conductor 
        left = conductor5;                                                          //Left node now becomes the data in conductor
        left->next = right;                                                         //Now point to the node on the right
        return;
    }
    else{                                              //If its not, use this function to add at end of list 
        struct records *conductor4, *after;                                     
        conductor4 = (struct records *)malloc(sizeof(struct records));      
        conductor4->studentnumber = number;                                  
        strcpy(conductor4->studentname, name);                                   
        conductor4->studentmarks[0] = -10;                                       
        after = (struct records *)root;                                        
        while(after->next != NULL){                                              
            after = after->next;
        }
        after->next = conductor4;                                                
        after = conductor4;                                                      
        after->next = NULL;  
    }
}

int remove_linked(char name[]){                                             //Remove person from linked list, return an integer

    struct records *conductor1, *conductor2;
    conductor1 = root;                                                        //Start conductor1 by pointing to root

    while(conductor1 != NULL){                                                //While conductor1 does not reach the end of the list at NULL
        if (strcmp(conductor1->studentname, name) == 0){                      //If the name the user entered is the same as the 'studentname' variable as it traverses the list, return true
            if (conductor1 == root){                                          //If it is first in list
                root = conductor1->next;                                      //Point root to the node appearing after the node you want to remove
                free(conductor1);                                             //Free the memory block that conductor1 is in
                return 1;                                                     //Program does not work if I don't put a return, so this function must return something, cannot be void
            }
            else{
                conductor2->next = conductor1->next;                          //If it has more nodes than just root, make the previous pointer point to the pointer after the node
                free(conductor1);
                return 1;
            }
        }
        else{
            conductor2 = conductor1;                                          //2 now contains address of 1, where the names are different
            conductor1 = conductor1->next;                                    //Traverse list until the name is found
        }
    }
    return 0;
}

void print_all(struct records *ROOT){                                                                   //To print all student reports currently on the records, receiving a pointer of struct records type

    while (ROOT != NULL){                                                                               //While it doesn't reach the end of the list
        int i = 0, h=0;
        printf("Student Name: %s \nStudent Number: %d \n", ROOT->studentname, ROOT->studentnumber);
        while(ROOT->studentmarks[i] != -10){                                                            //Will print the marks for each student, until it reaches -10 which indicate the end of the array
            printf("Mark[%d]:", h);
            printf(" %d\n", ROOT->studentmarks[i]);
            i++;
            h++;
        }
        ROOT = ROOT->next;                                                                              //Point to next node/student
    }
    printf("\n");
}

void printsingle(char name[]){                                                                         //Print one person

    int h = 0, i = 0, j = 0;
    struct records *conductor;
    conductor = root;
    printf("The person you are looking for is: \n");    
    while(conductor != NULL && i == 0){                                                                //Once the required node is printed, i becomes 1 to exit the loop                                                 
        if (strcmp(conductor->studentname, name) == 0){
            printf("Name: %s\nNumber: %d\n", conductor->studentname, conductor->studentnumber);
            while(conductor->studentmarks[j] != -10){                                                  //-10 is the end point in the array of marks stored for each student
                printf("Mark[%d]: %d\n", h, conductor->studentmarks[j]);                               //Keep printing mark for each course by incrementing the index of the marks array for each student
                j++;
                h++;
            }
            i=1;                                                                                       //Exit loop once everything is done
        }
        else{                                                                                          //Traverse the list if the above condition is not met
            conductor = conductor->next;
        }
    }
}

int maximum(){                                                          //Function used for binary tree, return integer

    struct records *conductor;
    int i = 0;
    conductor = root;
    while(conductor != NULL){
        conductor = conductor->next;                                              //Count how many nodes there are in the list and returns it to above function
        i++;
    }
    return i;   
}

void input_marks(char name[], int k){                                   //Input marks for each student

    int i = 0, j = 0;
    struct records *conductor;
    conductor = root;
    while (conductor != NULL && i == 0){                                //Add the mark they entered to the node until the end of the list
        if(strcmp(conductor->studentname, name) == 0){
            while(conductor->studentmarks[j] != -10){                   //Keep incrementing until we reach the last mark stored in the array
                j++;
            }
            conductor->studentmarks[j] = k;                             //Store the entered mark for the j'th element in the array, starting from element 1,2,3....
            j++;
            conductor->studentmarks[j] = -10;                           //Make the end of the array equal to -10 to indicate the end of list
            i = 1;                                                      //Exit the loop
        }
    else{
            conductor = conductor->next;
        }
    }
}

int main(int argc, char *argv[]){

    char name[20];
    char name2[20];
    int number, mark, answer = 0, answer0 = 0, answer2 = 0;

    if (strcmp(argv[1], "linked_list")){                                                    //Use either linked list or binary tree by entering this when running program at terminal
    root = NULL;                                                                            //Initally root points to nothing with an address of 0 (NULL) - Empty List

    while(answer != 7){            

    printf("\nWhat would you like to do?\n1: Introduce Student\n2: Remove Student\n3: Print Student Report\n4: Print Report For All Students\n5: Save to file\n6: Retrieve Data From File\n7: Exit\n");
    scanf("%d", &answer);
    switch(answer){

    case 1:

    printf("Would you like to enter a student or a mark? \n1: Student\n2: Mark\n");
    scanf("%d", &answer0);

    if(answer0 == 1){

    printf("Enter a student name and their ID number\n");
        scanf("%s", name);
        scanf(" %d", &number);   
        insert_linked_list(number, name);                                           //Use a linked list to enter students
    }

    else{
        printf("Enter a student name: \n");
        scanf("%s", name2);
        printf("Enter their mark: ");
        scanf(" %d", &mark);
        input_marks(name2, mark);
    }

    break;

    case 2:

    if(root == NULL)                                                                  //If root points to a node with no address (NULL), it is empty
        printf("There are currently no records available. \n");

    else{
        printf("Who would you like to remove? \n");                                   //If root doesn't point to NULL, there must be other nodes
        scanf("%s", name);
        if (remove_linked(name))                                                      //If the function returns 1 (true), print out this
            printf("%s has been removed. \n", name);
    }

    break;

    case 3:

    printf("Enter the name of whose student record would you like to see: \n");
    scanf("%s", name);
    printsingle(name);

    break;

    case 4:

    if(root == NULL){
        printf("There are currently no records available. \n");
    }
    else{
        printf("Current record for all students is: \n");
    }
    print_all(root);                                                                    //Call the print all function with the address of root as an argument 

    break;

    case 5: {                                                   //Save all current data in nodes to a file in the directory

    FILE *file = fopen("output", "wb");                         //Open a file in output format to store the data in wb mode
    struct records *conductor = root;                           //Point the conductor to the root node
    while(conductor != NULL){
        fwrite(conductor, sizeof(struct records), 1, file);     //Write all our data from each node pointed to by the traversing conductor to the file
        printsingle(conductor->studentname);
        conductor = conductor->next;                            //Traverse the list for each nodes data
    }
    fclose(file);                                               //Close the file so you don't lose the stored data
    }

    break;

    case 6: {                                                                       //Open our file from directory and retrieve all previous data that is stored

    struct records *conductor2 = (struct records*)malloc(sizeof(struct records));
    struct records *conductor3, *conductor4;
    FILE *file = fopen("output", "rb");                                                   //Open the file in read mode
    root = conductor2;                                                                    //Root now contains the address of a memory block
    if (file != NULL){
        do{                                                                               //Use this to read every node in the list
            fread(conductor2, sizeof(struct records), 1, file);                           //Read the value that conductor2 is pointing to
            conductor3 = root;                                                            //This now points to the root node
            conductor4 = root;
                while(conductor4->next != NULL){
                    conductor3 = (struct records *)malloc(sizeof(struct records));        //Point to each memory block until the end of list
                    fread(conductor3, sizeof(struct records), 1, file);                   //Read the value pointed to by conductor3
                    conductor4->next = conductor3;                                        //The next node that conductor4 points at now points to conductor3
                    conductor4 = conductor3;                                              //conductor4 now points to the node that conductor3 was pointing at before
                }
        }while(fread(conductor2, sizeof(struct records), 1, file) == 1);                  //Do this while nodes are available
    }
    }

    break;

    case 7:

    //Exit Program

    return 0;

    default:

    printf("That is not a possible option.\n");

    break;

    }
  }
}
    else if(strcmp(argv[1], "binary_tree")){                                          //Enter binary tree at command prompt to use this method

    while(answer != 7){   

    printf("\nWhat would you like to do?\n1: Introduce Student\n2: Remove Student\n3: Print Student Report\n4: Print Report For All Students\n5: Save to file\n6: Retrieve Data From File\n7: Exit\n");
    scanf("%d", &answer);
    switch(answer){

    case 1:

    printf("Would you like to enter a student or a mark? \n1: Student\n2: Mark\n");
    scanf("%d", &answer0);

    if(answer0 == 1){

    printf("Enter a student name and their ID number\n");
        scanf("%s", name);
        scanf(" %d", &number);
        insert_binary_tree(number, name);                                               //Insert a student using binary tree method instead
    }

    else{
        printf("Enter a students name: \n");
        scanf("%s", name2);
        printf("Enter their mark: ");
        scanf(" %d", &mark);
        input_marks(name2, mark);
    }

    break;

    case 2:

    if(root == NULL)                                                                  //If root points to a node with no address (NULL), it is empty
        printf("There are currently no records available. \n");

    else{
        printf("Who would you like to remove? \n");                                   //If root doesn't point to NULL, there must be other nodes
        scanf("%s", name);
        if (remove_linked(name))
            printf("%s has been removed. \n", name);
    }

    break;

    case 3:

    printf("Enter the name of whose student record would you like to see: \n");
    scanf("%s", name);
    printsingle(name);

    break;

    case 4:

    if(root == NULL){
        printf("There are currently no records available. \n");
    }
    else{
        printf("Current record for all students is: \n");
    }
    print_all(root);                                                                    //Call the print all function with the address of root as an argument 

    break;

    case 5: {                                                   //Save all current data in nodes to a file in the directory

    FILE *file = fopen("output", "wb");                         //Open a file in output format to store the data in wb mode
    struct records *conductor = root;                           //Point the conductor to the root node
    while(conductor != NULL){
        fwrite(conductor, sizeof(struct records), 1, file);     //Write all our data from each node pointed to by the traversing conductor to the file
        printsingle(conductor->studentname);
        conductor = conductor->next;                            //Traverse the list for each nodes data
    }
    fclose(file);                                               //Close the file so you don't lose the stored data
    }

    break;

    case 6: {                                                                       //Open our file from directory and retrieve all previous data that is stored

    struct records *conductor2 = (struct records*)malloc(sizeof(struct records));
    struct records *conductor3, *conductor4;
    FILE *file = fopen("output", "rb");                                                   //Open the file in read mode
    root = conductor2;                                                                    //Root now contains the address of a memory block
    if (file != NULL){
        do{                                                                               //Use this to read every node in the list
            fread(conductor2, sizeof(struct records), 1, file);                           //Read the value that conductor2 is pointing to
            conductor3 = root;                                                            //This now points to the root node
            conductor4 = root;
                while(conductor4->next != NULL){
                    conductor3 = (struct records *)malloc(sizeof(struct records));        //Point to each memory block until the end of list
                    fread(conductor3, sizeof(struct records), 1, file);                   //Read the value pointed to by conductor3
                    conductor4->next = conductor3;                                        //The next node that conductor4 points at now points to conductor3
                    conductor4 = conductor3;                                              //conductor4 now points to the node that conductor3 was pointing at before
                }
        }while(fread(conductor2, sizeof(struct records), 1, file) == 1);                  //Do this while nodes are available
    }
    }

    break;

    case 7:

    //Exit Program

    return 0;

    default:

    printf("That is not a possible option.\n");

    break;
    }    
  }
}
    return 0;
}

