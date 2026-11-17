#include <stdio.h>
#include "contact.h"

// Main program: provides an interactive menu-driven interface for managing contacts in the address book
int main() {
    int choice;      // user's menu selection
    int sortChoice;  // sorting preference for listing contacts
    int option;      // search/edit/delete option
    
    AddressBook addressBook; // the address book data structure
    initialize(&addressBook); // Initialize the address book

    do {
        // Display the main menu
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List all contacts\n");
    	printf("6. Save contacts\n");		
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Process user's menu choice
        switch (choice) {
            case 1:
                // Create a new contact
                createContact(&addressBook);
                break;
            case 2:
                // Search for an existing contact
                searchContact(&addressBook, option);
                break;
            case 3:
                // Modify an existing contact
                editContact(&addressBook, option);
                break;
            case 4:
                // Remove a contact
                deleteContact(&addressBook, option);
                break;
            case 5:
                // Display all contacts with sorting option
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                // Save all contacts to file and exit
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
       return 0;
}
