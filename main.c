// main.c
#include <stdio.h>
#include "address_book.h"

int main(void)
{
  Address_book *ab = create_address_book();
  if (!ab)
  {
    fprintf(stderr, "Failed to create address book.\n");
    return 1;
  }

  printf("\n");
  print_address_book(ab);

  destroy_address_book(ab);
  return 0;
}
