Programming Assignment #2 ReadME
Robert McCurdy
CSCI 423
Dr. Feng Wang

In this program, we take in a command line argument as an integer and use that to start the Collatz conjecture until we get to the integer 1. To run this program, you must first compile it in your Linux terminal by doing gcc PA2.c, during this step you can also add
-o whatevernameyouwant to name your program. Now to run your program we do ./programname <startingvalue> which will start the program.
An example would be like this :

gcc PA2.c -o PA_2_Test1

./PA_2_Test1 3

The program would then output this : 

Programing starting... using 3 as the <starting value>
3, 10, 5, 16, 8, 4, 2, 1

These are all the steps necessary to run this program. Some errors that can occur during the calling the program step : 1.) too many/too little command line arguments (i.e. ./PA_2_Test1 or ./PA_2_Test1 3 4), 2.) The starting value declared isn't a positive integer (i.e. ./PA_2_Test1 -3). Both of those wil return errors and the program will exit before running the fork.

In the program, we take in the 2nd command line argument as our starting value and set it to a char pointer variable. We then cast this variable to a integer to be able to compare it to other numbers. We then create an index for our fork processes and set it to fork(). We then check to see if n (the 2nd command line argument) is positive. If it isn't, we exit the program and post an error before running the fork. Now we actually get to run the fork. We check to see if p is = -1 and if it is we post an error has occured running the fork and exit the program. If p == 0 though, we will start our child process. In our child process, we print the current n which is our starting value. Then after printing that, we start a while loop to run while n != 1. In this while loop, we check to see if n is even by doing n % 2 to get a remainder of 0. If it is even and doesn't equal 1, we will do n = n / 2. If it isn't even, we move onto the odd portion of the if statement where we do n = 3 * n + 1. We then print the updated value of n. We continue this until n = 1 effectively closing the while loop. Then outside the child process we have a wait() call for the parent process to wait for the child process to complete.