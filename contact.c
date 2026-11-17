#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook, int sortChoice) 
{
    /* Display all contacts in the address book. The user is asked to choose a sorting criterion, then a
     bubble sort is performed before printing the results.*/

    //menu to sort the contact.
    printf("\nSort list Menu:\n");
    printf("1. Sort by Name\n");
    printf("2. Sort by Phone Number\n");
    printf("3. Sort by Email\n");
    printf("4. Sort by Address\n");
    printf("\nEnter your sortChoice: ");
    scanf("%d", &sortChoice);           // reading the sorting option.

    //loop for bubble sort for selected option.
    for(int i = 0; i < addressBook->contactCount - 1; i++)
    {
        for(int j = 0; j < addressBook->contactCount - i - 1; j++)
        {
            // sorting through name.
            if(sortChoice == 1)
            {
                if(strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0)
                {
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
            }

            //sorting through phone number.
            else if(sortChoice == 2)
            {
                //comparing the phone number with the user entered input
                if(strcmp(addressBook->contacts[j].phone, addressBook->contacts[j + 1].phone) > 0)
                {
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
            }

            //sorting through email.
            else if(sortChoice == 3)
            {
                if(strcmp(addressBook->contacts[j].email, addressBook->contacts[j + 1].email) > 0)
                {
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
            }

            //sorting through address.
            else if(sortChoice == 4)
            {
                if(strcmp(addressBook->contacts[j].address, addressBook->contacts[j + 1].address) > 0)
                {
                    Contact temp = addressBook->contacts[j];
                    addressBook->contacts[j] = addressBook->contacts[j + 1];
                    addressBook->contacts[j + 1] = temp;
                }
            }
        }
    }

    //printing the all sorted contact.
    for(int i=0; i < addressBook->contactCount; i++)
    {
        printf("name = %s  phone = %s  email = %s  Address = %s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email, addressBook->contacts[i].address);
    }
    // Sort contacts based on the chosen criteria
    
}

void initialize(AddressBook *addressBook) 
{
    // Initialize the address book structure and load any existing
    // contacts from persistent storage.
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) 
{
    // Save the current state of contacts to disk, then exit.
    //printf("Contact count = %d\n", addressBook->contactCount);
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    char name1[50];    //name declaration.
    char number[20];   //phone number declaration.
    char email1[50];   //email delaration.
    char address1[150];   //address declaration.
    int result1, result2, result3;

    printf("Enter the Name: ");
    scanf(" %[^\n]", name1);     //reading name.

    do
    {
        printf("Enter the Phone Number: ");
        scanf("%s", number);         //reading phone number.

        // collecting the output of phone validation 
        result1 = validate_phone(addressBook, number);

        if(result1 == 0)
        {
            printf("Enter proper Phone Number\n\n");
        }

    } while(result1 != 1);

    do
    {
        printf("Enter Email Address: ");
        scanf("%s", email1);

        result2 = validate_email(addressBook, email1);

        if(result2 == 0)
        {
            printf("Enter proper Email\n\n");
        }

    } while(result2 != 1);

    
    do
    {
        printf("Enter the Address: ");
        scanf(" %[^\n]", address1);

        result3 = validate_address(addressBook, address1);

        if(result3 == 0)
        {
            printf("Enter proper Address\n\n");
        }

    } while(result3 != 1);

    strcpy(addressBook->contacts[addressBook->contactCount].name, name1);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, number);
    strcpy(addressBook->contacts[addressBook->contactCount].email, email1);
    strcpy(addressBook->contacts[addressBook->contactCount].address, address1);
    addressBook->contactCount++;

    printf("Contact created successfully\n\n");

	/* Define the logic to create a Contacts */
}

int searchContact(AddressBook *addressBook, int option) 
{
    // menu to choose search criterion and perform the search
    // return 1 if any contact matches the query, otherwise 0
    printf("\nSearch contact Menu:\n");
    printf("1. Search through Name\n");
    printf("2. Search through Phone Number\n");
    printf("3. Search through Email\n");
    printf("4. Search through Address\n");
    printf("\nEnter your search option: ");
    scanf("%d", &option);

    char search[150];

    int flag = 0; // flag becomes 1 when contact is found

    if(option == 1)
    {
        printf("Enter Name: ");
        scanf(" %[^\n]",search);

        for(int i=0; i < addressBook->contactCount; i++)
        {
            if(strcmp(search, addressBook->contacts[i].name) == 0)
            {
                printf("\nIndex = %d,  Name = %s,  Phone Number = %s,  Email = %s,  Address = %s\n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email, addressBook->contacts[i].address);
                    flag = 1; // found a name match
            }
        }
    }

    else if(option == 2)
    {
        printf("Enter Phone Number: ");
        scanf("%s",search);

        for(int i=0; i < addressBook->contactCount; i++)
        {
            if(strcmp(search, addressBook->contacts[i].phone) == 0)
            {
                printf("\nIndex = %d,  Name = %s,  Phone Number = %s,  Email = %s,  Address = %s\n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email, addressBook->contacts[i].address);
                flag = 1;
                flag = 1; // found phone match
                break; // phone numbers are unique so we can stop
            }
        }
    }

    else if(option == 3)
    {
        printf("Enter Email: ");
        scanf("%s",search);
         
        for(int i=0; i < addressBook->contactCount; i++)
        {
            if(strcmp(search, addressBook->contacts[i].email) == 0)
            {
                printf("\nIndex = %d,  Name = %s,  Phone Number = %s,  Email = %s,  Address = %s\n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email, addressBook->contacts[i].address);
                flag = 1;
                flag = 1; // found email match
                break; // email should be unique
            }
        }
    }

    else if(option == 4)
    {
        printf("Enter Address: ");
        scanf(" %[^\n]",search);

        for(int i=0; i < addressBook->contactCount; i++)
        {
            if(strcmp(search, addressBook->contacts[i].address) == 0)
            {
                printf("\nIndex = %d,  Name = %s,  Phone Number = %s,  Email = %s,  Address = %s\n", i, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email, addressBook->contacts[i].address);
                flag = 1;
                flag = 1; // found address match
            }
        }
    }

    if(flag == 0)
    {
        printf("\nNot found the contact\n");
    }
    
    return flag;
    /* Define the logic for search */
}

void editContact(AddressBook *addressBook, int option)
{
    // Modify an existing contact's fields. A successful search is
    // required before proceeding to editing.
    int result;
    result = searchContact(addressBook, option);

    if(result == 1)
    {
        int index;
        printf("\nEnter the Index of the contact which you want to edit: ");
        scanf("%d",&index);

        printf("\nEdit contact Menu:\n");
        printf("1. Edit Name\n");
        printf("2. Edit Phone Number\n");
        printf("3. Edit Email\n");
        printf("4. Edit Address\n");
        printf("\nEnter your edit option: ");
        scanf("%d", &option);

        int result1, result2, result3;
        char edit[150]; // temporary buffer for new field value

        if(option == 1)
        {
            printf("Enter Name: ");
            scanf("%s",edit);

            strcpy(addressBook->contacts[index].name, edit);
            printf("Name edited successfully\n\n");
        }

        else if(option == 2)
        {
            do
            {
                printf("Enter Phone Number: ");
                scanf(" %[^\n]",edit);
            
                result1 = validate_phone(addressBook, edit);
            
                if(result1 == 0)
                {   
                    printf("Enter proper Phone Number\n\n");
                }
            } while(result1 != 1);

                strcpy(addressBook->contacts[index].phone, edit);
                printf("Phone Number edited successfully\n\n");

                return;
        }

        else if(option == 3)
        {
            do
            {
                printf("Enter Email: ");
                scanf("%s",edit);

                result2 = validate_email(addressBook, edit);

                if(result2 == 0)
                {
                    printf("Enter proper Email\n\n");
                }
            } while(result2 != 1);

                strcpy(addressBook->contacts[index].email, edit);
                printf("Email edited successfully\n\n");

                return;
        }

        else if(option == 4)
        {
            do
            {
                printf("Enter Address: ");
                scanf(" %[^\n]",edit);

                result3 = validate_address(addressBook, edit);

                if(result3 == 0)
                {
                    printf("Enter proper Address\n\n");
                }
            } while(result3 != 1);

                strcpy(addressBook->contacts[index].address, edit);
                printf("Address edited successfully\n\n");

                return;
        }

        else
        {
            printf("Invalid option\n\n");
        }

    }

    else
    {
        printf("Can't able to edit the contact\n\n");
    }

	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook, int option)
{
    // Search for a contact and, if found, remove it by shifting
    // subsequent entries down and decrementing the count.
    int result;
    result = searchContact(addressBook, option);

    if(result == 1)
    {
        int index;
        printf("\nEnter the Index of the contact which you want to delete: ");
        scanf("%d",&index);

        for(int i=index; i < addressBook->contactCount - 1; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        addressBook->contactCount--;

        printf("Contact deleted successfully\n\n");

    }

    else
    {
        printf("Can't able to delete the contact\n\n");
    }
	/* Define the logic for deletecontact */
   
}

int validate_phone(AddressBook *addressBook, char *phone_no)
{
    // check phone number length, numeric content, and uniqueness
    int length = strlen(phone_no);

    if (length != 10)
    {
        return 0; // must be exactly 10 digits
    }

    for (int i = 0; i < length; i++)
    {
        if (phone_no[i] < '0' || phone_no[i] > '9')
        {
            return 0; // invalid character found
        }
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(phone_no, addressBook->contacts[i].phone) == 0)
        {
            return 0; // duplicate phone not allowed
        }
    }

    return 1;
}


int validate_email(AddressBook *addressBook , char *email)
{
    // normalize and verify basic email structure (one '@', valid chars)
    char flag = 0;

    int length = strlen(email);

    for(int j=0; email[j] != '\0'; j++)
    {
        if(email[j] >= 'A' && email[j] <= 'Z')
        {
            email[j] = email[j] + 32;
        }
    }

    if (length == 0)
    {
        return 0; // empty string not acceptable
    }

    if (!((email[0] >= 'a' && email[0] <= 'z') || (email[0] >= '0' && email[0] <= '9')))
    {
        return 0; // first character must be alphanumeric
    }

    if (!((email[length - 1] >= 'a' && email[length - 1] <= 'z') || (email[length - 1] >= '0' && email[length - 1] <= '9')))
    {
        return 0; // last character must be alphanumeric
    }

    for (int i = 0; i < length; i++)
    {
        if (email[i] == ' ')
        {
            return 0; // no spaces allowed in email
        }

        else if (email[i] == '@')
        {
            flag++;

            if (i > 0 && i < length - 1)
            {
                if (!((email[i + 1] >= 'a' && email[i + 1] <= 'z')) || !(((email[i - 1] >= 'a' && email[i - 1] <= 'z') || (email[i - 1] >= '0' && email[i - 1] <= '9'))))
                {
                    return 0; // invalid characters around '@'
                }
            }
        }

        else if (email[i] == '.')
        {
            if (i > 0 && i < length - 1)
            {
                if (!(((email[i + 1] >= 'a' && email[i + 1] <= 'z') || (email[i + 1] >= '0' && email[i + 1] <= '9'))) || !(((email[i - 1] >= 'a' && email[i - 1] <= 'z') || (email[i - 1] >= '0' && email[i - 1] <= '9'))))
                {
                    return 0;
                    // invalid characters around '.'
                }
            }
        }
    }

    if (flag != 1)
    {
        return 0; // must contain exactly one '@'
    }

    return 1;
}

int validate_address(AddressBook *addressBook, char *addr)
{
    // basic address validation: not empty/leading space and only permitted characters
    if(addr[0] == '\0' || addr[0] == ' ')
    {
        return 0; // invalid starting character
    }

    int i = 0;
    while(addr[i] != '\0')
    {
        if(!((addr[i] >= 'A' && addr[i] <= 'Z') || (addr[i] >= 'a' && addr[i] <= 'z') || (addr[i] >= '0' && addr[i] <= '9') || addr[i] == ' ' || addr[i] == ',' || addr[i] == '.' || addr[i] == '-' || addr[i] == '/'))
        {
            return 0; // disallowed character encountered
        }
        i++;
    }
    return 1;
}