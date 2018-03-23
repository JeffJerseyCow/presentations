#include <stdio.h>


void __libc_start_main(size_t *main_addr)
{
  printf("[*] In '__libc_start_main'\n");
}
