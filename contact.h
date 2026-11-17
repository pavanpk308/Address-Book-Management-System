#ifndef CONTACT_H
#define CONTACT_H

// Maximum number of contacts that can be stored
#define MAX_CONTACTS 100

// Structure representing a single contact
typedef struct {
    char name[50];
    char phone[20];
    char email[50];
    char address[150];
} Contact;

// Structure representing the entire address book
typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

// Create a new contact and add it to the address book
void createContact(AddressBook *addressBook);

// Search for a contact by name, phone, email, or address
int searchContact(AddressBook *addressBook, int option);

// Edit an existing contact's information
void editContact(AddressBook *addressBook, int option);

// Delete a contact from the address book
void deleteContact(AddressBook *addressBook, int option);

// Display all contacts, sorted by user's choice
void listContacts(AddressBook *addressBook, int sortChoice);

// Initialize the address book and load from file
void initialize(AddressBook *addressBook);

// Save contacts to persistent storage
void saveContactsToFile(AddressBook *AddressBook);

// Validate phone number format and uniqueness
int validate_phone(AddressBook *addressBook, char *phone_no);

// Validate email format
int validate_email(AddressBook *addressBook, char *email);

// Validate address format
int validate_address(AddressBook *addressBook, char *addr);

#endif
