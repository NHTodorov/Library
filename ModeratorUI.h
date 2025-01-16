#pragma once
#include "AddBook.h"
#include "AvailableBooks.h"
#include "ModeratorFunc.h"

#include <iostream>


void ModeratorUI() {
		std::string password = {"1234"};
		std::string input;
		do {
			std::cout << "Insert password: " << std::endl;
			if (std::cin.peek() == '\n') { // check if next symbol is new line, ignore it and continue 
				std::cin.ignore(); // skip the new line 
			}
			getline(std::cin, input); // read the whole input + spaces
			if (input != password) { // check for errors with password
				std::cout << "Incorrect password! " << std::endl;
			}
		} while (input != password); // repeat it until input == password

	do {
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Select an option from below: " << std::endl;
		std::cout << "1. Add new book. " << std::endl;
		std::cout << "2. Delete currently existing book. (+ All copies) " << std::endl;
		std::cout << "3. Delete a specific number of copies of currently existing book. " << std::endl;
		std::cout << "4. Search a book  " << std::endl;
		std::cout << "5. Show all books " << std::endl;
		std::cout << "6. Exit program " << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		short int choice;
		std::cin >> choice;

		switch (choice) {
		default:
                	std::cin.clear();
                	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                	std::cout << "Invalid option! Please select a valid option. (1, 2, 3, 4)" << std::endl;
                	return;

		case 1:
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			AddBookOBJ.getData();
			AddBookOBJ.display();
			AddBookOBJ.ErrorCheck();
			AvailableBooksOBJ.Books.push_back(AddBookOBJ);
			std::cout << "The following book has been successfully added: " << std::endl;
			AddBookOBJ.display();
			break;
		case 2:
			DeleteBookPlusCopies();
			break;
		case 3:
			DeleteBookCopies();
			break;
		case 4:
			SearchOptions();
			break;
		case 5:
			AvailableBooksOBJ.PrintAllBooks();
			break;
		case 6:
			std::cout << "Exiting program... " << std::endl;
			exit(0);
		}
	} while (true);
}
