#include <stdio.h>
#define rows 15
#define columns 30


int menuOption();
void showChart ();
const char unavailable = '*';
const char available = '#';
char map [rows][columns];
double price;
int total = 0;
int seat = 450;
int seat2 = 0;
int quit = 1;

int main ()
{
	int rowNum = 15;
	float price [rowNum];
	int row2, column2;
	float cost;
	int answer;

    printf("Welcome to the theater!\n");

    for (int count = 0; count < rows; count++)
    {
    	printf("Please enter the price for row %d: ", count + 1);
        fflush(stdout);
        scanf("%f", &price [count]);
    }

    for (int x = 0; x < rows; x++)
    {
    	for (int y = 0; y < columns; y++)
    	{
    		map [x][y] = available;
        }
    }


   int choice = 0;

   do
   {
	   choice = menuOption();

	   switch (choice)
       {
            case 1:
            printf("View seat prices\n\n");

            for (int count = 0; count < rows; count++)
            {
            	printf("The price for row %d is $%.2f.", count + 1, price [count]);
            }
            break;

            case 2:

            printf("Purchase a ticket\n\n");

            do
            {
            	printf("Please select the row you would like to sit in: ");
                fflush(stdout);
                scanf("%d", &row2);

                printf("Please select the seat you would like to sit in: ");
                fflush(stdout);
                scanf("%d", &column2);

                if (map [row2] [column2] == '*')
                {
                	printf("Sorry that seat is not available.\n");
                }

                else
                {
                	cost = price [row2] + 0;
                    total = total + cost;

                    printf("This ticket costs: $%.2f\n", cost);
                    printf("Confirm purchase? Enter (1 = YES / 2 = NO)");
                    fflush(stdout);
                    scanf("%d", &answer);

                    seat = seat - answer;
                    seat2 += answer;

                    if (answer == 1)
                    {
                    	printf("Your ticket purchase has been confirmed.\n");
                        map [row2][column2] = unavailable;
                    }

                    else if (answer == 2)
                    {
                            printf("Would you like to look at another seat? (1 = Yes / 2 = No)\n");
                            fflush(stdout);
                            scanf("%d", &quit);
                    }

                    printf("Would you like to look at another seat? (1 = Yes / 2 = No)");
                    fflush(stdout);
                    scanf("%d", &quit);
                }
            }while (quit == 1);
            break;

            case 3:

            printf("View available seats\n\n");
            showChart();
            break;

            case 4:

            printf("Total ticket sales: %d.\n\n", total);
            break;

            case 5:

            printf("quit\n");
            break;

            default : printf("Error input\n");
        }
   }while(choice != 5);

   return 0;
}

int menuOption()
{
    int menuChoice;

    printf(" \tMenu Options\n");

    printf(" 1. View Seat Prices.\n");
    printf(" 2. Purchase a Ticket.\n");
    printf(" 3. View Available Seats.\n");
    printf(" 4. View Ticket Sales.\n");
    printf(" 5. Quit the program.\n");

    scanf("%d", &menuChoice);

    return menuChoice;
}

void showChart()
{
    printf("\tSeats\n");
    printf("   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n");

    for (int count = 0; count < 15; count++)
    {
    	printf("Row %d", count + 1);

    	for (int count2 = 0; count2 < 30; count2++)
        {
    		printf(" %d", map [count] [count2]);
        }
    }

    printf("\n");
}
