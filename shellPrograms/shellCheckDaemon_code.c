#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v tty > output.txt");

   // TODO: Execute the command using system(command) and check its return value
   int system_return = system(command);
   if(system_return == -1){
      return 1;
   } else {

   }

   free(command);

   int live_daemons = 0;
   // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
   // 1. Open the file
   // 2. Fetch line by line using getline()
   // 3. Increase the daemon count whenever we encounter a line
   // 4. Close the file
   // 5. print your result
   FILE *file = fopen("output.txt", "r");
   char *buffer = NULL;
   size_t bufsize = 256;
   buffer = (char *)malloc(bufsize * sizeof(char));

   while(getline(&buffer, &bufsize, file) != -1){
      live_daemons++;
   }

   if (live_daemons == 0)
      printf("No daemon is alive right now\n");
   else
   {
      printf("There are in total of %d live daemons \n", live_daemons);

      // print present daemon
      FILE *fp;
      char buf[1000];

      fp =fopen("output.txt","r");

      if (!fp){
         printf("CSEShell: File doesn't exist.\n");
         return 1;
      }

      while (fgets(buf,1000, fp)!=NULL)
         printf("%s",buf);

      printf("\n");

      fclose(fp);
   }


   // TODO: close any file pointers and free any statically allocated memory 
   int x;
   for (x = sysconf(_SC_OPEN_MAX); x>=0; x--){
   close(x);
   }

   return 1;
}

int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}