#include "shell.h"

// the PATH
// TODO: change to your PATH, your current working directory
// Since we cannot change the shell.h is one of the requirement
// There is another PATH we need to change at "/shellPrograms/shellDaemonize_code.c"
#define PATH "/Users/anasiangangster/Desktop/AnAsianGangsterShell"

// PATH for different function calls
#define FIND "/shellPrograms/find"
#define DISPLAY "/shellPrograms/display"
#define LISTDIRALL "/shellPrograms/listdirall"
#define LISTDIR "/shellPrograms/listdir"
#define COUNTLINE "/shellPrograms/countline"
#define SUMMOND "/shellPrograms/summond"
#define CHECKDAEMON "/shellPrograms/checkdaemon"
/*
 List all files matching the name in args[1] under current directory and subdirectories
*/
int shellFind(char **args)
{

  printf("shellFind is called!\n");
  // while ( *args ) printf( "----->%s<-----\n", *args++ );

  /** TASK 4 **/
  // 1. Execute the binary program 'find' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellFind if execvp fails to allow loop to continue
  const char *full_path = PATH FIND;
  // printf("-->%s<--", full_path);
  if(execvp(full_path, args) == -1){
    printf("error with find.");
  }
  return 1;
}

/**
 Allows one to display the content of the file
 */
int shellDisplayFile(char **args)
{
  printf("shellDisplayFile is called!\n");
  // while ( *args ) printf( "----->%s<-----\n", *args++ );

  /** TASK 4 **/
  // 1. Execute the binary program 'display' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDisplayFile if execvp fails to allow loop to continue
  const char *full_path = PATH DISPLAY;
  if(execvp(full_path, args) < 0){
    printf("error with display.");
  }

  return 1;
}

/*
	List the items in the directory and subdirectory
*/
int shellListDirAll(char **args)
{

  printf("shellListDirAll is called!\n");
  // while ( *args ) printf( "----->%s<-----\n", *args++ );

  /** TASK 4 **/
  // 1. Execute the binary program 'listdirall' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDirAll if execvp fails to allow loop to continue
  const char *full_path = PATH LISTDIRALL;
  if(execvp(full_path, args) < 0){
    printf("error with listdirall.");
  }

  return 1;
}

/*
	List the items in the directory
*/
int shellListDir(char **args)
{
  printf("shellListDir is called!\n");
  // while ( *args ) printf( "----->%s<-----\n", *args++ );

  /** TASK 4 **/
  // 1. Execute the binary program 'listdir' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDir
  const char *full_path = PATH LISTDIR;
  if(execvp(full_path, args) < 0){
    printf("error with listdir.");
  }
  return 1;
}

/**
   Counts how many lines are there in a text file. 
   A line is terminated by \n character
**/
int shellCountLine(char **args)
{
  printf("shellCountLine is called!\n");
  // while ( *args ) printf( "----->%s<-----\n", *args++ );

  /** TASK 4 **/
  // 1. Execute the binary program 'countline' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCountLine if execvp fails to allow loop to continue
  const char *full_path = PATH COUNTLINE;
  if(execvp(full_path, args) < 0){
    printf("error with countline.");
  }
  return 1;
}

/**
 * Allows one to create a daemon process
 */
int shellSummond(char **args)
{
  printf("shellDaemonize is called!\n");
  // while ( *args ) printf( "----->%s<-----\n", *args++ );

  /** TASK 4 **/
  // 1. Execute the binary program 'summond' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDaemonize if execvp fails to allow loop to continue
  const char *full_path = PATH SUMMOND;
  if(execvp(full_path, args) < 0){
    printf("error with summond.");
  }

  return 1;
}


/**
 * Allows one to check daemon process
 * 
 */
int shellCheckDaemon(char **args)
{
  printf("shellCheckDaemon is called!\n");
  // while ( *args ) printf( "----->%s<-----\n", *args++ );

  /** TASK 4 **/
  // 1. Execute the binary program 'checkdaemon' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCheckDaemon if execvp fails to allow loop to continue
  const char *full_path = PATH CHECKDAEMON;
  if(execvp(full_path, args) < 0){
    printf("error with checkdaemon.");
  }

  return 1;
}

/**
   Allows one to change directory 
 */
int shellCD(char **args)
{
  printf("shellCD is called! \n");
  if (args[1] == NULL)
  {
    fprintf(stderr, "CSEShell: expected argument to \"cd\"\n");
  }
  else
  {
    // chdir() changes the current working directory of the calling process
    // to the directory specified in path.
    if (chdir(args[1]) != 0)
    { //use chdir
      perror("CSEShell:");
    }
  }

  return 1;
}

/**
   Prints out the usage and
   list of commands implemented
 */
int shellHelp(char **args)
{
  printf("shellHelp is called! \n");
  int i;
  printf("CSE Shell Interface\n");
  printf("Usage: command arguments\n");
  printf("The following commands are implemented:\n");

  for (i = 0; i < numOfBuiltinFunctions(); i++)
  {
    printf("  %s\n", builtin_commands[i]); //print all the commands that have been implemented in the shell program
  }

  return 1;
}

/**
  Returns 0, to terminate execution from the shellLoop
 */
int shellExit(char **args)
{
  return 0;
}


/*
  Builtin function implementations.
*/
int shellUsage(char **args)
{
  int functionIndex = -1;

  // Check if the commands exist in the command list
  for (int i = 0; i < numOfBuiltinFunctions(); i++)
  {
    if (strcmp(args[1], builtin_commands[i]) == 0)
    {
      //pass it to the functions
      functionIndex = i;
    }
  }

  switch (functionIndex)
  {
  case 0:
    printf("Type: cd directory_name\n");
    break;
  case 1:
    printf("Type: help\n");
    break;
  case 2:
    printf("Type: exit\n");
    break;
  case 3:
    printf("Type: usage command\n");
    break;
  case 4:
    printf("Type: display filename\n");
    break;
  case 5:
    printf("Type: countline filename\n");
    break;
  case 6:
    printf("Type: listdir\n");
    printf("Type: listdir -a to list all contents in the current dir and its subdirs\n");
    break;
  case 7:
    printf("Type: listdirall\n");
    break;
  case 8:
    printf("Type: find filename_keyword\n");
    break;
  case 9:
    printf("Type: summond \n");
    break;
  case 10:
    printf("Type: checkdaemon \n");
    break;
  default:
    printf("Command %s not found\n", args[0]);
    break;
  }

  return 1;
}
/*
  End of builtin function implementations.
*/

/**
   Execute inputs when its in the default functions
   Otherwise, print error message and return to loop
 */
int shellExecuteInput(char **args)
{
  /** TASK 3 **/

  // 1. Check if args[0] is NULL. If it is, an empty command is entered, return 1
  // 2. Otherwise, check if args[0] is in any of our builtin_commands, and that it is NOT cd, help, exit, or usage.
  // 3. If conditions in (2) are satisfied, perform fork(). Check if fork() is successful.
  // 4. For the child process, execute the appropriate functions depending on the command in args[0]. Pass char ** args to the function.
  // 5. For the parent process, wait for the child process to complete and fetch the child's return value.
  // 6. Return the child's return value to the caller of shellExecuteInput
  // 7. If args[0] is not in builtin_command, print out an error message to tell the user that command doesn't exist and return 1
  int fork_ID;

  // check empty
  if(args[0] == NULL){
    return 1;
  } else {
    int valid_input_indicator = 1;  // state
    for(int i = 0; i < numOfBuiltinFunctions(); i++){
      int comp_result = strcmp(args[0], builtin_commands[i]);
      if(comp_result == 0){
        valid_input_indicator = 0;
        if(i < 4){
          int result = builtin_commandFunc[i](args);
          // exit(1);
          return result;
        } else {
          fork_ID = fork();
          if (fork_ID < 0){
            printf("error with fork()\n");
          }
          else if(fork_ID == 0){
            builtin_commandFunc[i](args);
          }
          else{
            printf("Fork works, waiting for child\n");
            int status;

            waitpid(fork_ID, &status, WUNTRACED); 

            int exit_status = 0;
            //if child terminates properly, WIFEXITED(status) returns TRUE
            if (WIFEXITED(status)){
            exit_status = WEXITSTATUS(status);
            }
            // exit(exit_status);
            return exit_status;
          }
        }
      } else {
        valid_input_indicator = 1;
      }
    }
    if(valid_input_indicator == 1){
      printf("Invalid command received, Type help to see what commands are implemented.\n");
      // exit(1);
      return 1;
    }
    return valid_input_indicator;
  }
}

/**
   Read line from stdin, return it to the Loop function to tokenize it
 */
char *shellReadLine(void)
{
  /** TASK 1 **/
  // read one line from stdin using getline()

  // 1. Allocate a memory space to contain the string of input from stdin using malloc. Malloc should return a char* that persists even after this function terminates.
  // 2. Check that the char* returned by malloc is not NULL
  // 3. Fetch an entire line from input stream stdin using getline() function. getline() will store user input onto the memory location allocated in (1)
  // 4. Return the char*

  char *buffer = NULL;
  size_t bufsize = 256;
  buffer = (char *)malloc(bufsize * sizeof(char));

  if(buffer != NULL){
    getline(&buffer, &bufsize, stdin);
  }

  // free(buffer);
  return buffer;
}

/**
 Receives the *line, and return char** that tokenize the line
**/

char **shellTokenizeInput(char *line)
{
  int len = strlen(line);
  if(line[len-1] == '\n'){
    line[len-1] = 0;
  }
  /** TASK 2 **/
  // 1. Allocate a memory space to contain pointers (addresses) to the first character of each word in *line. Malloc should return char** that persists after the function terminates.
  // 2. Check that char ** that is returend by malloc is not NULL
  // 3. Tokenize the *line using strtok() function
  // 4. Return the char **
  char **token_positions = malloc(sizeof(char *) * 256);
  char *token = strtok(line, SHELL_INPUT_DELIM);

  int index = 0;
 
  token_positions[index] = token;
  index++;
  while (token != NULL)
  {
    // printf("#####\n");
    // Tokenize the rest of the command
    token = strtok(NULL, " ");      //continue finding the next token
    token_positions[index] = token; //store the position
    index++;
  }

  token_positions[index - 1] = NULL;
  // token_positions[index - 2] = NULL;
  token_positions[index] = NULL; //dont forget to NULL terminate.
  return token_positions;
}

/**
  The main loop where one reads line,
  tokenize it, and then executes the command
 */
void shellLoop(void)
{
  //instantiate local variables
  char *line;  // to accept the line of string from user
  char **args; // to tokenize them as arguments separated by spaces
  int status;  // to tell the shell program whether to terminate shell or not

  /** TASK 4 **/
  //write a loop where you do the following:

  // 1. print the message prompt
  // 2. clear the buffer and move the output to the console using fflush
  // 3. clear the buffer to accept a new string in readLine()
  // 4. invoke shellReadLine() and store the output at line
  // 5. invoke shellTokenizeInput(line) and store the output at args**
  // 6. execute the tokens using shellExecuteInput(args)

  // 7. free memory location containing the strings of characters
  // 8. free memory location containing char* to the first letter of each word in the input string
  // 9. check return value of shellExecuteInput. If 1, continue the loop (point 1) again and prompt for another input. Else, exit shell. 


  // printf("    ______    _______  _______            _______  __    __   _______  __       __     \n"); 
  // printf("  /      |   /       ||   ____|          /       ||  |  |  | |   ____||  |     |  |     \n");
  // printf(" |  ,----'  |   (----`|  |__            |   (----`|  |__|  | |  |__   |  |     |  |     \n");
  // printf(" |  |        \\   \\    |   __|            \\   \\    |   __   | |   __|  |  |     |  |     \n");
  // printf(" |  `----.----)   |   |  |____       .----)   |   |  |  |  | |  |____ |  `----.|  `----.\n");
  // printf("  \\______|_______/    |_______|      |_______/    |__|  |__| |_______||_______||_______|\n");                                                                
  // printf("$ ");
                                                                                            
                                                                                            

  printf("           /$$$$$$  /$$   /$$  /$$$$$$               /$$$$$$  /$$   /$$ /$$$$$$$$ /$$       /$$      \n");
  printf("          /$$__  $$| $$  /$$/ /$$__  $$             /$$__  $$| $$  | $$| $$_____/| $$      | $$      \n");
  printf("         | $$  \\ $$| $$ /$$/ | $$  \\ $$            | $$  \\__/| $$  | $$| $$      | $$      | $$      \n");
  printf("         | $$  | $$| $$$$$/  | $$$$$$$$            |  $$$$$$ | $$$$$$$$| $$$$$   | $$      | $$      \n");
  printf("         | $$  | $$| $$  $$  | $$__  $$             \\____  $$| $$__  $$| $$__/   | $$      | $$      \n");
  printf("         | $$  | $$| $$\\  $$ | $$  | $$             /$$  \\ $$| $$  | $$| $$      | $$      | $$      \n");
  printf("         |  $$$$$$/| $$ \\  $$| $$  | $$            |  $$$$$$/| $$  | $$| $$$$$$$$| $$$$$$$$| $$$$$$$$\n");
  printf("          \\______/ |__/  \\__/|__/  |__/             \\______/ |__/  |__/|________/|________/|________/\n");
  printf("Secret code: 00100000 01000110 01010101 01000011 01001011 01000101 01010010 00100000 01010011 01001000 01000101 01001100 01001100\n");
  char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working directory: %s\n", cwd);
   } else {
       perror("getcwd() error");
   }
  printf("$ ");

  fflush(stdin);

  line = shellReadLine();

  args = shellTokenizeInput(line);
  // printf("↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\nThe first token is    -->%s<-- \n", args[0]);
  // printf("The second token is   -->%s<-- \n↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑\n", args[1]);

  // handle empty command
  if(args[0] == NULL){
    free(line);
    free(args);
    shellLoop();
  }

  int comp_result = strcmp(args[0], builtin_commands[3]);
  // int comp_result_countline = strcmp(args[0], builtin_commands[5]);
  // int comp_result = comp_result_usage + comp_result_countline;
  if(comp_result == 0 && args[1] == NULL){
    printf("usage input error\n");
    free(line);
    free(args);
    shellLoop();
  } else {
    if(shellExecuteInput(args) != 0){
      free(line);
      free(args);
      shellLoop();
    } else {
      exit(1);
    }
  }
}


int main(int argc, char **argv)
{
 
 printf("Shell Run successful. Running now: \n");
 
 // Run command loop
 shellLoop();
 return 0;
}
