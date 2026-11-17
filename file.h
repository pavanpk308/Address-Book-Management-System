#ifndef FILE_H
#define FILE_H

#include "contact.h"

// Save all contacts in the address book to a CSV file
void saveContactsToFile(AddressBook *addressBook);

// Load contacts from a CSV file into the address book
void loadContactsFromFile(AddressBook *addressBook);

#endif
