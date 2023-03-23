//PA2 by Robert McCurdy for CSCI 423
//Instructor: Dr. Feng Wang
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	if(argc != 2) //checks if the amount of cmd line arguments are correct
	{
		printf("Usage: ./b.out <starting value>\n");
		return -1;
	}

	char *a = argv[1]; //creates a pointer char at the 2nd cmd line argument
	int n = atoi(a); //casts that pointer to int

	printf("Programing starting... using %d as the <starting value>\n", n);

	pid_t p;	//our value for the index of the fork process
	p = fork(); //sets to fork

	if(n < 0) //checks to see if n is a positive integer, if it isn't states error message and exits code
	{
		printf("<starting value> should be a positive integer. Integer received %d\n", n);
		return -1;
	}

	if(p == -1) //error in fork, exits code
	{
		printf("An error occured while calling the fork() function.");
		return -1;
	} else if (p == 0) { //exec fork
		
		printf("%d, ", n); //print starting value
		while (n != 1) //while n doesn't = 1
		{
			if (n % 2 == 0) //checks if n is even
			{
				n = n / 2; //if it is does this math
			} else if (n % 2 == 1) { //if it isn't checks if its odd
				n = 3 * n + 1; //if it is does this math
			}
			printf("%d", n); // prints updated value
			if(n > 1){ //adds a comma and space to output if n > 1
				printf(", ");
			} else { //if it isn't does a new line since we're done
				printf("\n");
			}
		}
	}

	wait(); //parent waits for child process to complete

	return 0;
}
	