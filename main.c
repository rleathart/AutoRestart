/* Automatically try to restart the given shell commmand every few seconds
 * after it exits with non-zero status. */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t Flag = 0;

void InterruptHandler(int Signal)
{
  Flag = 1;
}

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "You must provide an argument\n");
    exit(1);
  }

  /* Preserve the return value of the system process if we terminate with
   * Ctrl-C. */
  signal(SIGINT, InterruptHandler);

  char* Command = argv[1];

  int ExitCode;
  do
  {
    if (Flag)
    {
      printf("\nInterrupt caught! Exiting %d ...\n", ExitCode);
      exit(ExitCode);
    }

    printf("Starting process '%s'\n", Command);
    /* Take ExitCode mod 255 since shell stores return value as 1 byte */
    ExitCode = system(Command) % 255;
    printf("Process exited: %d\n", ExitCode);
    sleep(2);
  } while (ExitCode);

  return ExitCode;
}
