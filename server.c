#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



// int main() 
// {
//   printf("PID : %d\n", getpid());
//   while(1);
// }

void sig_handler(int sig)
{
	if (sig == SIGUSR1)
		()
}