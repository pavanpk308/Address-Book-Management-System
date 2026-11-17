# Address Book Management System (C)

A menu-driven **Address Book application written in C** that lets users
create, search, edit, delete, sort, and store contact information in a
CSV file.

## Features

-   **Create contacts** with name, 10-digit phone number, email address,
    and postal address.
-   **Validate input**:
    -   Phone numbers must contain exactly 10 digits and must be unique.
    -   Email addresses are checked for a basic email format.
    -   Addresses are checked for permitted characters.
-   **Search contacts** by name, phone number, email, or address.
-   **Edit contact details** after finding the contact.
-   **Delete contacts** from the address book.
-   **List and sort contacts** by name, phone number, email, or address
    using Bubble Sort.
-   **File storage**: load contacts from `contacts.csv` when the program
    starts and save them when the Save contacts option is selected.

## Technologies and Concepts

-   C programming language
-   Structures and arrays
-   Functions and pointers
-   String handling (`string.h`)
-   File handling (`stdio.h`)
-   Input validation
-   Searching and Bubble Sort

## Project Structure

``` text
AddressBook-NewDesign/
├── main.c                 # Main function and menu-driven interface
├── contact.c              # Contact operations, sorting, and validation
├── contact.h              # Contact structures, constants, and declarations
├── file.c                 # Loading and saving contacts
├── file.h                 # File-handling function declarations
├── populate.c             # Optional sample contact data
├── populate.h             # Sample-data function declaration
├── contacts.csv           # Contact data file used for persistence
└── README.md
```

## Build

Make sure GCC is installed. Open a terminal in the project directory and
run:

``` bash
gcc main.c contact.c file.c populate.c -o address_book
```

## Run

On Linux or macOS:

``` bash
./address_book
```

On Windows (MinGW):

``` bash
address_book.exe
```

## Menu Options

  Option   Operation
  -------- --------------------------------------------
  1        Create contact
  2        Search contact
  3        Edit contact
  4        Delete contact
  5        List all contacts (choose a sorting field)
  6        Save contacts and exit
  7        Exit

**Important:** Select option `6` to save the current contacts to
`contacts.csv`. Option `7` exits the program without calling the save
function, so unsaved changes may be lost.

## Data Storage

Contacts are stored in `contacts.csv`. The first line contains the
number of contacts. Each following line stores one contact as
comma-separated fields:

``` text
contact_count
name,phone,email,address
```

Keep `contacts.csv` in the same working directory from which the
executable is run.

## Notes

-   The address book defines a maximum capacity of **100 contacts**.
-   `populate.c` contains sample contact data, but the call to
    `populateAddressBook()` is commented out in `initialize()`. The
    program loads contacts from `contacts.csv` instead.
-   This is a console-based learning project demonstrating fundamental C
    programming concepts.

## Author

**Pavan Kumar N**
