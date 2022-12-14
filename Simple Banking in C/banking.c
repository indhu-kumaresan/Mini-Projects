#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct of one user detail
struct user
{
	char phone[15];
	char ac[15];
	char pwd[30];
	float bal;
};

int main()
{
	struct user usr, usr1;
	int opt, choice;
	FILE *fp;
	char filename[50], cell[15], password[30];
	char cnt = 'y';
	float amount;

	/*Register or Login,
	 You can only login after registering.
	 Register first and then run the program once again*/

	printf("***************** SIMPLE BANKING SYSTEM *****************");
	printf("\n\n\n What do you want to do?");
	printf("\n 1.Register an account");
	printf("\n 2.Login to an account");

	/*If the user logs in to account
	then the banking activities are displayed.*/

	printf("\n\n Your choice:\t");
	scanf("%d", &opt);

	if (opt == 1)
	{
		printf("Enter your account number:  ");
		scanf("%s", usr.ac);
		printf("Enter your phone number:    ");
		scanf("%s", usr.phone);
		printf("Enter your new pasword:     ");
		scanf("%s", usr.pwd);
		usr.bal = 0;
		strcpy(filename, usr.phone);
		fp = fopen(strcat(filename, ".dat"), "w");
		fwrite(&usr, sizeof(struct user), 1, fp);
		if (fwrite != 0)
			printf("\nAccount successfully registered");
		else
			printf("\nSomething went wrong please try again");
		fclose(fp);
	}

	if (opt == 2)
	{
		system("cls");
		printf("\nPhone number:\t");
		scanf("%s", cell);
		printf("\nPassword: \t");
		scanf("%s", password);
		strcpy(filename, cell);
		fp = fopen(strcat(filename, ".dat"), "r");
		if (fp == NULL)
			printf("No such account exists.Please try!");
		else
		{
			fread(&usr, sizeof(struct user), 1, fp);
			fclose(fp);
			if (!strcmp(password, usr.pwd))

				/*until user presses n or something other than y
				this loop ontinues and
				banking activity menu
				is displayed everytime */

				while (cnt == 'y')
				{
					system("cls");
					printf("\nPress 1 to check balance");
					printf("\nPress 2 to deposit ");
					printf("\nPress 3 to withdraw ");
					printf("\nPress 4 to transfer money");
					printf("\nPress 5 to change password");
					printf("\n\nyour choice:");
					scanf("%d", &choice);

					switch (choice)
					{
					case 1:
						printf("\nYour current balance is %.2f", usr.bal);
						break;
					case 2:
						printf("\nEnter the amount:");
						scanf("%f", &amount);
						usr.bal += amount;
						fp = fopen(filename, "w");
						fwrite(&usr, sizeof(struct user), 1, fp);
						if (fwrite != NULL)
							printf("\n\nSuccessfully deposited");
						fclose(fp);
						break;
					case 3:
						printf("\nEnter the amount:");
						scanf("%f", &amount);
						usr.bal -= amount;
						fp = fopen(filename, "w");
						fwrite(&usr, sizeof(struct user), 1, fp);
						if (fwrite != NULL)
							printf("\n\nYou have withdrawn %.2f", amount);
						fclose(fp);
						break;

					case 4:
						printf("\n Enter the phone no of the user to transfer:\t");
						scanf("%s", cell);
						strcpy(filename, cell);
						fp = fopen(strcat(filename, ".dat"), "r");
						if (fp)
						{
							printf("\nEnter the amount to transfer (min balance to maintain is 1000rupees):\t");
							scanf("%f", &amount);
							if (usr.bal - amount < 1000)
								printf("\nInsufficient Balance\t");
							else
							{
								strcpy(filename, cell);
								fp = fopen(strcat(filename, ".dat"), "r");
								fread(&usr1, sizeof(struct user), 1, fp);
								fclose(fp);
								usr1.bal += amount;
								fp = fopen(filename, "w");
								fwrite(&usr1, sizeof(struct user), 1, fp);
								fclose(fp);
								if (fwrite != NULL)
								{
									printf("\nTransaction is successfull");
									strcpy(filename, usr.phone);
									fp = fopen(strcat(filename, ".dat"), "w");
									usr.bal -= amount;
									fwrite(&usr, sizeof(struct user), 1, fp);
									fclose(fp);
								}
							}
						}
						else
							printf("\n No such Account exists! Please check the account details once again.");
						break;

					case 5:
						printf("\n Enter your present password: \t");
						scanf("%s", password);
						if (!(strcmp(password, usr.pwd)))
						{
							printf("\nPasswords Match! Now Enter your new Password:\t");
							scanf("%s", password);
							strcpy(filename, usr.phone);
							fp = fopen(strcat(filename, ".dat"), "w");
							strcpy(usr.pwd, password);
							fwrite(&usr, sizeof(struct user), 1, fp);
							fclose(fp);
							if (!(fwrite == NULL))
								printf("\n Password changed Successfully!");
							else
								printf("\n Error in Password change, Please try again!");
						}
						else
							printf("\nYour present passwords don't match!");
					}

					printf("\nDo you want to continue the transaction\t");
					scanf("%s", &cnt);
				}

			// if user password doesn't match then the program ends
			else
				printf("\n Password Incorrect! Please Check");
		}
	}
}