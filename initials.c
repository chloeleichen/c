#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
  problem: http://cdn.cs50.net/2016/x/psets/2/pset2/pset2.html#initializing
  check50 2015.fall.pset2.initials initials.c
 */

int main(void)
{
  string names = GetString();
  char initials[10];
  int index = 0;
  int nameLength = (int)strlen(names);
  int j = 0;

  initials[0] = names[0];

  
  for(int i = 0; i < nameLength; i ++){
      if(names[i] == ' ' && i < (int)strlen(names) - 1){
          ++index;
          initials[index] = names[ i + 1 ];
      }
  }

  initials[index+1] = '\0';

  while(initials[j])
   {
      putchar (toupper(initials[j]));
      j++;
   }
   printf("\n");
}



