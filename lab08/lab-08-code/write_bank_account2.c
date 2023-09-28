#include <stdio.h>
#include <stdlib.h>

struct bank_account {
    int acct_num;
    char acct_name[20];
    double acct_balance;
};

int main() {
    // a bank_account instance
    //   struct bank_account account = {123456, "John Doe", 1000.50};

    //! We cannot directly initialise a pointer to a struct. We should define an array of structs first and then assign its address to the pointer
    struct bank_account account[4] = {{123456, "John Doe", 1000.50}, {123455, "Sam", 1666.3}, {123454, "Lisa", 8888.0}, {123453, "James", 666.5}};

    const char *filename = "bank_account.bin";

    // open binary file for writing
    FILE *ofp = fopen(filename, "wb");

    if (ofp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // write 'account' to file; there's 1 element to write,
    // which has size 'sizeof(struct bank_account)'.
    size_t els_written = fwrite(account, sizeof(struct bank_account), 4, ofp);

    if (els_written != 4) {
        perror("Error writing to file");
        fclose(ofp);
        return 1;
    }

    fclose(ofp);

    printf("Bank account struct written to '%s'\n", filename);

    exit(EXIT_SUCCESS);
}
