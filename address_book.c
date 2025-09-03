#include <stdio.h>
#include <stdlib.h> 
#include "address_book.h"

void print_person(const Person *person)
{
  printf("Name: %s\n", person->name);
  printf("Age: %d\n", person->age);
  printf("Phone number: %d\n", person->phone_number);
}

void print_address_book(const Address_book *address_book)
{
  printf("==== Address book (%d entries) =====\n\n", address_book->size);

  for (int i = 0; i < address_book->size; i++)
  {
    print_person(&address_book->people[i]);
    if (i != address_book->size - 1)
    {
      printf("\n");
    }
  }
}

Address_book *create_address_book(void)
{
  int num;

  printf("Enter the number of persons that you'd like to put into the address book: ");
  scanf("%d", &num);

  /* allocate ONE Address_book */
  Address_book *address_book = (Address_book *)malloc(sizeof(Address_book));
  if (!address_book)
  {
    return NULL;
  }

  address_book->size = num;
  address_book->people = (Person *)malloc((size_t)num * sizeof(Person));
  if (!address_book->people)
  {
    free(address_book);
    return NULL;
  }

  /* read each person */
  for (int j = 0; j < address_book->size; j++)
  {
    printf("\nPerson %d\n", j + 1);

    /* read full name (with spaces) */
    printf("Name: ");
    scanf(" %99[^\n]", address_book->people[j].name);

    printf("Age: ");
    scanf("%d", &address_book->people[j].age);

    printf("Phone number (digits only): ");
    scanf("%d", &address_book->people[j].phone_number);
  }

  return address_book;
}

void destroy_address_book(Address_book *address_book)
{
  if (!address_book)
    return;
  free(address_book->people);
  free(address_book);
}
