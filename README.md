**Encoder Program - C Implementation**

**Overview**
This project implements a character encoding program in C for a Unix (Linux 32-bit) environment. The program reads characters from an input source (keyboard or file), applies an optional encoding scheme, and writes the encoded output to a destination (screen or file). It supports flexible command-line arguments, debug mode, and ASCII-based encoding.

**Features**
Command-Line Arguments Parsing
  Supports flags for debug mode, encoding, input file, and output file.
  Debug mode allows real-time insights into program behavior.
  
**Character Encoding
**  Encodes input using a cyclic numeric key (+E for addition, -E for subtraction).
  Supports wrap-around for alphanumeric characters (e.g., Z+1 = A, A-1 = Z).

**Flexible Input and Output**
  Reads input from stdin or a specified file.
  Outputs to stdout or a specified file.

**Usage**
**Compilation**
  Clone the repository and navigate to the project directory:
  bash
  Copy code
  git clone https://github.com/yourusername/encoder.git
  cd encoder
  Compile the program using the provided makefile:
  bash
  Copy code
  make encoder
  
**Running the Program**
  bash
  Copy code
  ./encoder [options]

**Options**
  +D / -D: Toggle debug mode on/off.
  +E{key} / -E{key}: Set encoding key for addition or subtraction.
  -i{filename}: Read input from a specified file instead of the keyboard.
  -o{filename}: Write output to a specified file instead of the screen.
  
  **Examples
  Basic Input and Output:**
  Echoes input directly to the output:
    bash
    Copy code
    ./encoder
  Input: Hello World!
  Output: Hello World!

**Encoding with Addition:**
Encodes input using the key 123:

  bash
  Copy code
  ./encoder +E123
  Input: ABCXYZ
  Output: BDFZAB

**Encoding with Subtraction:**
Encodes input using the key 54321:

  bash
  Copy code
  ./encoder -E54321
  Input: HELLO
  Output: CZGJM

**Using Files:**
Reads input from input.txt and writes output to output.txt:

  bash
  Copy code
  ./encoder -iinput.txt -ooutput.txt
  
**Debug Mode:**
  Prints debug information to stderr:
    bash
    Copy code
    ./encoder +D
    
** File Structure**
    encoder.c: Main program logic.
    makefile: Compilation and cleaning targets.
    
** Makefile Targets**
  Compile:
    bash
    Copy code
    make encoder
  Clean:
    Removes the compiled executable:
    bash
    Copy code
    make clean
    
**Notes**
Handles both uppercase and lowercase letters with wrap-around encoding.
Ignores non-alphanumeric characters during encoding but includes them in the output.
Command-line arguments can be specified in any order.
