#include <stdio.h>
int E0=0,O0=1; // DFA states
int state = 0; // initial DFA state
char input,count;
int main() {

   printf("Enter a string of 0 s and 1s: ");
   while (1) {

      scanf("%c", &input);

      if (input == '\n') // if end-of-line exit loop
         break;

      if ( (input != '0') && (input != '1') )  //Invalid input
         break;

      if (state==0)
         state=(input== '0')?O0:E0;

      else
        state=(input=='0')?E0:O0;
   }
      if (state == 0)
         printf("Input accepted\n");
      else
         printf("Input rejected\n");

   return 0;
}