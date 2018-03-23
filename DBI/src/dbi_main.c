#include <stdio.h>


int func0(char *msg)
{
  printf("[*] In 'func0'\n");
  if(msg != NULL)
    printf("[*] msg - '%s'\n", msg);
  else
    printf("[*] msg not found\n");
}

int main(int argc, char **argv, char **envp)
{
  printf("[*] In 'main'\n");
  printf("[*] Argv[0] - '%s'\n", argv[0]);
  func0("Called from main");
  printf("[*] In 'main'\n");
  return 0;
}
