#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//As we learned in OOP course
//Const of the program
#define ALPHBETNUM  26
#define NUMBERS 10


//Global Variables
_Bool debug = 1, sign = 1; //Initialize debug to True And sign to + 
  char noKey = '0', keyLen = 0; //Initialize noKey to 0 and keyLen to 0
  char* key = NULL;
  FILE * input = NULL;
  FILE * output= NULL;
  

char Calculate(char c, int add);
void initArguments(int argc, char **argv);


int main(int argc, char **argv) {
  int i,c;
  //initialize the arguments
  initArguments(argc, argv);



  for(i=0; i<argc; i++){
    
    if(strcmp(argv[i], "-k") == 0){
      key = argv[i+1];
    }

    if(strcmp(argv[i], "-d") == 0){
      debug = 0;
    }
  }
  
  

  return 0;
}


void initArguments(int argc, char **argv){
  
  for(int i=0; i<argc; i++){
    

    //Case 1: Key is given in the command line
    if((strcmp(argv[i][0], "-") == 0) &&(strcmp(argv[i][1], "e") == 0) && (strcmp(argv[i][2], "/0") == 0)){
      key = argv[i] + 2;//key = argv[i][2];
      sign = -1;
    }

    else if((strcmp(argv[i][0], "+") == 0) &&(strcmp(argv[i][1], "e") == 0)&& (strcmp(argv[i][2], "/0") == 0)){ //
      key = argv[i] + 2;//key = argv[i][2];
      sign = 1;
    }

    // Case 2: Debug is given in the command line (I dont need to Check +D because it is not necessary cause it is the *default* value)
    else if(strcmp(argv[i], "-D") == 0){
      debug = 0;
    }

    else if(strcmp(argv[i], "+D") == 0){
      debug = 1;
    }

    //Case 3: Input File is given in the command line
    else if(strcmp(argv[i], "-i") == 0){
      input = fopen(argv[i+1], "r");
    }

    //Case 4: Output File is given in the command line
    else if(strcmp(argv[i], "-o") == 0){
      output = fopen(argv[i+1], "w");
    }



  }

  if (key == NULL)
  {
    key= &noKey;
  }
  
}



char Calculate(char c, int add){

    //Case 1: char is Lower case charachter
    if(c >= 'a' && c <= 'z'){
        c += add;
        if(c < 'a')
            c += AlphaBetNum;
        else if(c > 'z')
            c -= AlphaBetNum;
    }

    //Case 2: char is Upper case charachter
    else if(c >= 'A' && c <= 'Z'){
        c += add;
        if(c < 'A')
            c += AlphaBetNum;
        else if(c > 'Z')
            c -= AlphaBetNum;
    }

    //Case 3: char is Number
    else{
        c += add;
        if(c < '0')
            c += Numbers;
        else if(c >'9')
            c -= Numbers;
    }

    return c;
}