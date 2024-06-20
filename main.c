#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME 21
#define MAX_PASWORD 21

struct Account {
  char username[21];
  char password[21];
};

struct Account *account_create(const char *username, const char *password) {
  struct Account *self = (struct Account*) malloc(sizeof(struct Account));
  
  if (self == NULL) {
    fprintf(stderr, "Could not create an instance of Account(%s, %s)\n", username, password);
  }

  strcpy(self->username, username);
  strcpy(self->password, password);

  return self;
}

void account_destroy(struct Account *self) {
  printf("Destroying instance of Account\n");
  free((void*)self);
}

void account_print(struct Account *self) {
  if (self != NULL) {
    printf("struct Account {%s, %s}\n", self->username, self->password);
  }
}

int main(void) {
  struct Account *admin = account_create("admin1", "SOMEPASSWORD_123");
  account_print(admin);
  account_destroy(admin);
}