#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void __libc_start_main(size_t *main_addr)
{
  printf("[*] In '__libc_start_main'\n");
  printf("[*] Main address - '%p'\n", main_addr);

  /* Create main function pointer */
  int (*main_ptr)(int, char **, char **);
  main_ptr = (void *) main_addr;

  /* Setup environment */
  char *name = (char *) malloc(20);
  memset(name, 0, 20);
  strcpy(name, "From pointer");
  char **argv_ptr;
  argv_ptr = &name;

  /* Call main */
  int ret = 0;
  ret = main_ptr(1, argv_ptr, NULL);
  printf("[*] In '__libc_start_main'\n");

  /* Create func0 function pointer */
  int (*func0_ptr)(char *);
  func0_ptr = (void *) ((unsigned char *) main_addr - 0x42);
  func0_ptr("Called from __libc_start_main");

  /* Clean up */
  printf("[*] In '__libc_start_main'\n");
  exit(ret);
}
