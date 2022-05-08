#include <stdio.h>

#include "user.h"

// print a informal goodbye message
void InformalGoodbye(User *user)
{
  printf("See ya later %s!\n", user->first_name);
}

// print a formal goodbye message
void FormalGoodbye(User *user)
{
  printf("Good bye, ID: %d\n", user->id);
  printf("Name: %s, %s\n", user->last_name, user->first_name);
}