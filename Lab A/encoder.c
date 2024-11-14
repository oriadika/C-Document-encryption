#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//As we learned in OOP course
#define AlphaBetNum = 26
#define Numbers = 10

char Calculate(char c, int add);

int main(int argc, char **argv) {
  int i,a,b,c;
  FILE * output=stdout;
  

  return 0;
}



char Calculate(char c, int add){

    //Case 1: char is Lower case charachter
    if(c >= 'a' && c <= 'z'){
        c+=add;
        if(c < 'a')
            c+=AlphaBetNum;
        else if(c > 'z')
            c -=AlphaBetNum;
    }

    //Case 2: char is Upper case charachter
    else if(c >= 'A' && c <= 'Z'){
        c+=add;
        if(c < 'A')
            c+=AlphaBetNum;
        else if(c > 'Z')
            c -=AlphaBetNum;
    }

    //Case 3: char is Number
    else{
        c+=add;
        if(c < '0')
            c+= Numbers;
        else if(c >'9')
            c-=Numbers;
    }

    return c;
}