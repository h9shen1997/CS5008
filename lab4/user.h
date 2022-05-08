#ifndef USER_HEADER_FILE
#define USER_HEADER_FILE

struct user_info
{
  char *first_name;
  char *last_name;
  int id;
  char *location;
};

typedef struct user_info User;

void StandardGreeting(User *);
void FormalGreeting(User *);
void InformalGoodbye(User *);
void FormalGoodbye(User *);

#endif