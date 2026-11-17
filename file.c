#include <stdio.h>
#include <stdlib.h>
#include "file.h"

/* Save all contacts from the address book to persistent storage. The file is opened in write mode (overwriting any existing data).
 Format: first line is contact count, then each contact on its own line with comma-separated fields. */

void saveContactsToFile(AddressBook *addressBook)
{
    FILE *fp; // file pointer
    
    // open CSV file for writing
    fp = fopen("contacts.csv", "w");

    // check if file opened successfully
    if(fp == NULL)
    {
        printf("Error: Failed to open the File\n");
        return; // exit on failure
    }

    // write the total contact count as the first line
    fprintf(fp, "%d\n", addressBook->contactCount);

    // write each contact's data as a comma-separated line
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email, addressBook->contacts[i].address);
    }

    // close the file after writing
    fclose(fp);

    // exit the program after successful save
    exit(0);
}

// Load contacts from persistent storage into the address book.
// Reads the CSV file: first line is count, then one contact per line
// with comma-separated fields (name, phone, email, address).
void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp; // file pointer
    
    // open CSV file for reading
    fp = fopen("contacts.csv", "r");

    // check if file opened successfully
    if(fp == NULL)
    {
        printf("Error: Failed to open the File\n");
        return; // exit on failure
    }

    // read the total contact count from the first line
    fscanf(fp, "%d\n", &addressBook->contactCount);

    // read each contact's data from a comma-separated line
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email, addressBook->contacts[i].address);
    }

    // close the file after reading
    fclose(fp);
}