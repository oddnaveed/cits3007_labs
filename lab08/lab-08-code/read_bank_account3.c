
#include <stdio.h>
#include <stdlib.h>

struct bank_account {
  int acct_num;
  char acct_name[20];
  double acct_balance;
};

int main() {
  // a bank_account instance to store the read data
  size_t n_accounts = 5;
  struct bank_account account[n_accounts];

  const char * filename = "bank_account.bin";

  // open the binary file for reading
  FILE *file = fopen(filename, "rb");

  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  // read from the file
  size_t els_read = fread(account, sizeof(struct bank_account), n_accounts, file);

  if (els_read != n_accounts) {
    perror("Error reading from file");
    fclose(file);
    exit(EXIT_FAILURE);
  }

  fclose(file);

  // display the first account's information
  printf("Account Number: %d\n", account[1].acct_num);
  printf("Account Name: %s\n", account[1].acct_name);
  printf("Account Balance: %.2f\n", account[1].acct_balance);

  return 0;
}
