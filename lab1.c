/*
    Course: CSCI 247 Spring 2019
    File Name: lab1.c
*/

//These are preprocessor directives, which tell the preprocessor to go and find the standard io header and string
//header files, as we need some of the functions written in those files. After it finds those files it replaces
//the two lines below with the contents of those files. Specifically printf is in stdio.h, after looking online
//I'm not sure why we need the string.h file 
#include <stdio.h>
#include <string.h>

//Here we are declaring a macro, so everytime we write "CHAR_DATA_TYPE" somwhere 
//in this file, we replace that with "char", this is handy when wanting to change a 
//value of a variable that is used multiples times quickly and easily. Similar to
//ctrl f'ing and replacing all the instances of a word.
#define CHAR_DATA_TYPE "double"

//Here we use a forward declaration of the function "DataTypeSizes" in order for the C compiler, gcc, 
//to be able to check that we are calling the function with the proper arguments and return values.
//In order for a forward declaration to work, it needs to be written before the function call, as I'm
//assuming this forward declaration is saved into memory and referred back to each time we call the function.
void DataTypeSizes(void);

char* GetStringFromStdin(char* str);
void DisplayString(const char* str);

int main (int argc, char* argv[])
{
    printf("This is argc: %i\n", argc);
    //I'll be honest I pulled the line below off stack overflow
    //I assume while(*argv) means while the pointer to argv does not point
    //to null, continue looping, in that loop we print argv, use a new line
    //for each argv and increment argv to the next char in the array
    while (*argv) printf("%s\n", *argv++);    

    printf("Wow! This is my first C Program!\r\n");

    DataTypeSizes();

    char str[100];
    GetStringFromStdin(str);
    DisplayString(str);

    //"return" is a keyword in C, meaning you can't use "return" as a variable or
    //something else like that. 
    return(0);
}

//Here we make a function 'DataTypeSizes" which takes in void and returns void, or 
//it doesn't need anything to call it and doesn't return anything when called.
//Writing this function here, rather than in main is nice if in the future we need to reuse
//this code for another purpose, we could write "#include lab1.c" in that file and then 
//we'd have access to the functions in "lab1.c".

//"void" is also a keyword in C, we can't use "void" as a variable name
void DataTypeSizes(void)
{
    //In this printf call we use "\"%s\" in order to include the quotes around char when printed
    //This is necessary due to how C handles characters outside of the ASCII character set
    //in order to include a "" or double quote you need to have a \ to let the compiler know 
    //that you are using an escape sequence. I used GeeksForGeeks to find this info, my understanding
    //might be wrong. 

    //The use of 'sizeof" in the print statement below is an operator in C, it is 
    //not a function or a macro and is evaluated at compile time. 

    //The significance of the display in the context of our program is that we want 
    //to include a newline after each print statement so it is easier to read in the terminal
    //Both \r and \n are used because in Windows a newline is a combination of both
    //At least I'm assuming that's why we write both as this way our code will work
    //on both Windows and Linux/Unix systems. This info was from Quora.
    printf("\"%s\" is a standard C datatype. Size of a \"%s\" data type is = %ld\r\n",
                                                CHAR_DATA_TYPE, CHAR_DATA_TYPE,sizeof(char));
}

char* GetStringFromStdin(char* str)
{
    fgets(str, 100, stdin);
    printf("FGET^ string is: %s\n", str);
}

void DisplayString(const char* str)
{
    fputs(str, stdout);
    printf("FPUT^ string is: %s\n", str);
}