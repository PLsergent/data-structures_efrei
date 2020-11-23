#include <stdio.h>
#include <string.h>

/* 

expr : term | term + term
term : factor | factor * factor
factor : a | ( expr )

*/

int expr(char **str);
int term(char **str);
int factor(char **str);


/*
precondition : none

return value : 1 if true, 0 if false

postcondition : 
  str points to the remainder of the string that has not been handled yet

*/
int expr(char **str)
{

  if (! term(str))
    return 0;

  
  char c = (*str)[0];
  
  if (c != '+') 
      return 1; // found the longest expression, a single term

  (*str)++;

  return term(str);
}


/*
precondition : none

return value : 1 if true, 0 if false

postcondition : 
  str points to the remainder of the string that has not been handled yet

*/
int term(char **str)
{
      printf("%c ", (*str)[0]);
  if (! factor(str))
    return 0;
  
  char c = (*str)[0];
  
  if (c != '*') 
    return 1; // found the longest term, a single factor

  (*str)++;
  return factor(str);
}


/*
precondition : none

return value : 1 if true, 0 if false

postcondition : 
  str points to the remainder of the string that has not been handled yet

*/
int factor(char **str)
{

  char c = (*str)[0];
    
  if (c == 0) return 0; // end of string, error
  (*str)++;
  
  
  if (c == 'a' || c == '(') { 
  
    if (c == 'a')
      return 1;

    if (expr(str) && (*str)[0] == ')' ) {
      (*str)++;
      return 1;
    } else
      return 0;
    
  }

  return 0;
}


// a+a+a not valid
// a+a*a valid
// (a+a+a) not valid
// (a*a+a*a)+(a*(a)+a) valid

int main(int argc, char **argv)
{
  char *str = argv[1];

  if (expr(&str) && str[0] == 0)
    printf("expr %s is valid\n", argv[1]);
  else
    printf("expr %s is not valid\n", argv[1]);
 
}


