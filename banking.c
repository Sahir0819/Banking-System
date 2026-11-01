#include <stdio.h>
#include <string.h>

struct Account {
    char name[50];
    char accountNumber[20];
    float balance;
};

int main() {
    struct Account user;
    int choice;
    float amount;
    int created = 0;

    while (1) {
        printf("\n===== MINI BANKING SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (created) {
                    printf("Account already exists!\n");
                    break;
                }

                printf("Enter your name: ");
                scanf(" %49[^\n]", user.name);

                printf("Enter account number: ");
                scanf("%19s", user.accountNumber);

                printf("Enter initial deposit: Rs. ");
                scanf("%f", &user.balance);

                if (user.balance < 0) {
                    printf("Invalid initial deposit!\n");
                    break;
                }

                created = 1;
                printf("Account created successfully!\n");
                break;

            case 2:
                if (created)
                    printf("Balance: Rs. %.2f\n", user.balance);
                else
                    printf("Please create an account first.\n");
                break;

            case 3:
                if (!created) {
                    printf("Please create an account first.\n");
                    break;
                }

                printf("Enter deposit amount: Rs. ");
                scanf("%f", &amount);

                if (amount > 0) {
                    user.balance += amount;
                    printf("Deposit successful!\n");
                } else {
                    printf("Enter a valid amount.\n");
                }
                break;

            case 4:
                if (!created) {
                    printf("Please create an account first.\n");
                    break;
                }

                printf("Enter withdrawal amount: Rs. ");
                scanf("%f", &amount);

                if (amount <= 0) {
                    printf("Enter a valid amount.\n");
                } else if (amount > user.balance) {
                    printf("Insufficient balance!\n");
                } else {
                    user.balance -= amount;
                    printf("Withdrawal successful!\n");
                }
                break;

            
            case 5:
              if (created) {
               printf("\n--- Account Details ---\n");
               printf("Name: %s\n", user.name);
               printf("Account Number: %s\n", user.accountNumber);
               printf("Balance: Rs. %.2f\n", user.balance);
             } 
             else {
               printf("Please create an account first.\n");
             }
              break;

 

            case 6:
                printf("Thank you for using Mini Banking System!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
