#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//As we learned in OOP course
//Const of the program
#define ALPHBETNUM  26
#define NUMBERS 10


//Global Variables
_Bool debug = 1, sign = 1,defKey = 1; //Initialize debug to True And sign to + 
  char noKey = '0', keyLen = 0; //Initialize noKey to 0 and keyLen to 0
  char* key = NULL;
  FILE * input = NULL;
  FILE * output= NULL;
  
//Function Prototypes
char keyLength();
char encode(char c, int add);
void initArguments(int argc, char **argv);


int main(int argc, char **argv) {
  char index = 0,c;
  char line[1024];
  //initialize the arguments
  initArguments(argc, argv);
  

    //Read the input file and encode it
    while (fgets(line, sizeof(line), input) != NULL) {
            // Loop through each character in the line
            for (int i = 0; line[i] != '\0'; i++) {
                c = line[i];

                // If EOF is reached, stop processing and exit
                if (feof(input)) {
                    if (debug) {
                        fprintf(stderr, "End of file reached. Exiting.\n");
                    }
                    fclose(input);
                    fclose(output);
                    return 0;
                }
            
            //Case 2: Not end of file
            else {
                
                //Debugging
                if (debug)
                    {
                        fprintf(stderr, "Handeling charachter %c \n", c);
                    }

                //Case 1: Key is not given
                if(defKey == 1){

                    fputc(encode(c, (*key - '0')), output);
                }
                
                //Case 2: Key is given
                else{
                int KTA = *((key + (index%keyLen))) - '0'; //Key To Add
                fputc(encode(c, sign * KTA), output);
                index++;
                }
                }
            }
        }

  return 0;
}


//Function to initialize the arguments
void initArguments(int argc, char **argv){
  
  for(int i=0; i<argc; i++){
        //Case 1: Key is given in the command line
        if((argv[i][0] == '-') &&(argv[i][1] == 'E')){
        key = argv[i] + 2;//key = argv[i][2];
        keyLen = keyLength();
        sign = -1;
        defKey = 0; //Key is given
        }

        else if((argv[i][0] == '+') &&(argv[i][1] == 'E')){ //
        key = argv[i]+2;//key = argv[i][2];
        keyLen = keyLength();
        sign = 1;
        defKey = 0;//Key is given
        }

        // Case 2: Debug is given in the command line (I dont need to Check +D because it is not necessary cause it is the *default* value)
        else if((argv[i][0] == '-')&&(argv[i][1] == 'D')){
        debug = 0;
        }

        else if((argv[i][0] == '+')&&(argv[i][1] == 'D')){
        debug = 1;
        }

        //Case 3: Input File is given in the command line
        else if((argv[i][0] == '-') && (argv[i][1] == 'i')){
        input = fopen(argv[i] + 2, "r");
            if(input == NULL){
                fprintf(stderr, "Error: Can not open file to read properly\n");
                exit(1);
            }
        }

        //Case 4: Output File is given in the command line
        else if((argv[i][0] == '-') && (argv[i][1] == 'o')){
        output = fopen(argv[i] + 2, "w");
            if(output == NULL){
                fprintf(stderr, "Error: Can not open file to write on properly\n");
                exit(1);
            }
        }
              
    }

    //Checking after the loop
    if (key == NULL || keyLen == 0)
    {
        key= &noKey;
        defKey = 1;
    }

    if (input == NULL)
    {
        input = stdin;
    }
  
    if (output == NULL)
    {
        output = stdout;
    }
    
   
}

//Function to calculate the length of the key
char keyLength(){
    int i = 0;
    while(key[i] != '\0'){
        i++;
    }
    return i;
}

//Function to calculate the new charachter according to the given key
char encode(char c, int add){

    //Case 1: char is Lower case charachter
    if(c >= 'a' && c <= 'z'){
        c += add;
        if(c < 'a')
            c += ALPHBETNUM;
        else if(c > 'z')
            c -= ALPHBETNUM;
    }

    //Case 2: char is Upper case charachter
    else if(c >= 'A' && c <= 'Z'){
        c += add;
        if(c < 'A')
            c += ALPHBETNUM;
        else if(c > 'Z')
            c -= ALPHBETNUM;
    }

    //Case 3: char is Number
    else{
        c += add;
        if(c < '0')
            c += NUMBERS;
        else if(c >'9')
            c -= NUMBERS;
    }

    return c;
}