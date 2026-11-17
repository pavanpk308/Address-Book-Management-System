#include "contact.h"

// Dummy contact data for testing purposes
// Contains a pre-defined array of sample contacts
static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};

/* Populate the address book with dummy contacts from the static array.
   This function loads up to MAX_CONTACTS entries into the given
   address book structure. */
void populateAddressBook(AddressBook* addressBook)
{
    // calculate the number of dummy contacts available
    int numDummyContacts = sizeof(dummyContacts) / sizeof(dummyContacts[0]);
    
    // copy each dummy contact into the address book if there's space
    for (int i = 0; i < numDummyContacts && addressBook->contactCount < MAX_CONTACTS; ++i) {
        addressBook->contacts[addressBook->contactCount++] = dummyContacts[i];
    }
}