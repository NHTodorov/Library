#pragma once
#include "AddBook.h"
#include "AvailableBooks.h"
#include "HelpfulFunc.h"
#include "CombinedFunc.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <limits>


// function to delete a book with all copies and remove it from the list
void DeleteBookPlusCopies() {
	std::string BookTitle, BookAuthor;
	std::cout << "Enter the title of the book you want to delete: " << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
	getline(std::cin, BookTitle); 
	BookTitle = StringConvert(BookTitle); // Convert the title to lower letters and remove spaces

	std::cout << "Enter author of the book: " << std::endl;
	getline(std::cin, BookAuthor);
	BookAuthor = StringConvert(BookAuthor); // Convert the author name to lower letters and remove spaces

	bool bookFound = false;
	for (auto iterator = AvailableBooksOBJ.Books.begin(); iterator != AvailableBooksOBJ.Books.end(); ) {
		// Convert stored title and author for comparison
		std::string storedTitle = StringConvert(iterator->getTitle());
		std::string storedAuthor = StringConvert(iterator->getAuthor());

		if (storedTitle == BookTitle && storedAuthor == BookAuthor) {
			iterator = AvailableBooksOBJ.Books.erase(iterator); // Erase and move to next
			std::cout << "Book with title: '" << BookTitle << "' and author: '" << BookAuthor << "' has been deleted!" << std::endl;
			bookFound = true;
		}
		else {
			++iterator; // Only increment if not erased
		}
	}

	if (!bookFound) {
		std::cout << "No book has been found with title: '" << BookTitle << "' and author: '" << BookAuthor << "'." << std::endl;
	}
}




// function to delete a specific number of copies of a book
void DeleteBookCopies() {

	// flag to track if book is found with the written title or author of the book
	bool ValidOption = false;
	do {
		std::cout << "You can delete maximum of all book copies minus 1 (to exist at least 1 book) " << std::endl;
		std::cout << "Insert title or author of the book: ";
		std::string input;
		std::cin.ignore();
		getline(std::cin, input);
		StringConvert(input); // transform to lower letters + remove all spaces 
		std::cout << std::endl;

		// for tracking if there are matching books
		std::vector<size_t> MatchingBooks;

		// search by title or author
		for (size_t i = 0; i < AvailableBooksOBJ.Books.size(); ++i) {
			std::string ExistingTitle = AvailableBooksOBJ.Books[i].getTitle();
			std::string ExistingAuthor = AvailableBooksOBJ.Books[i].getAuthor();

			StringConvert(ExistingTitle); // transform to lower letters + remove all spaces 
			StringConvert(ExistingAuthor); // transform to lower letters + remove all spaces 

			// if ExistingTitle is found or ExistingAuthor is found push_back in the vector MatchingBooks
			if (ExistingTitle.find(input) != std::string::npos || ExistingAuthor.find(input) != std::string::npos) { 
				MatchingBooks.push_back(i); 
				ValidOption = true;
			}
		}

		if (MatchingBooks.size() == 0) { // if no matching books found
			std::cout << "No books have been found with the given criteria! " << std::endl;
			return;
		}
		else { // if ValidOption = true and found MatchingBooks
			// making a numeration of all found books starting from 1
			std::cout << "Books matching your search are: " << std::endl;
			for (size_t i = 0; i < MatchingBooks.size(); ++i) {
				size_t index = MatchingBooks[i];
				// cout the found book / books (if more than 1 found)
				std::cout << i + 1 << ". " << AvailableBooksOBJ.Books[index].getTitle() << " by " << AvailableBooksOBJ.Books[index].getAuthor() << std::endl;
			}

			// from the made array, cout all found books numerated from 1 to the amount of found books
			int choice;
			std::cout << "Enter the number of the book you want to delete copies of: " << std::endl;;
			std::cin >> choice;
			std::cin.ignore();

			if (choice > 0 && choice <= MatchingBooks.size()) {
				size_t BookIndex = MatchingBooks[choice - 1];
				int DeletionCopies;
				std::cout << "How many copies do you want to delete? " << std::endl;;
				std::cin >> DeletionCopies;

				if (DeletionCopies < AvailableBooksOBJ.Books[BookIndex].getCopies()) {
					AvailableBooksOBJ.Books[BookIndex].setCopies(AvailableBooksOBJ.Books[BookIndex].getCopies() - DeletionCopies);
					std::cout << "Deletion successful!" << std::endl;
				}
				else {
					std::cout << "Cannot delete more copies than available!" << std::endl;
				}
			}
			else {
				std::cout << "Invalid choice!" << std::endl;
				return;
			}
		}
	} while (!ValidOption);
}



void SearchOptions() {
	int choice;
	do {
		std::cout << "Choose an option from below: " << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cout << "1. Search a book by title." << std::endl;
		std::cout << "2. Search a book by author." << std::endl;
		std::cout << "3. Search a book by genre." << std::endl;
		std::cout << "4. Search a book by year." << std::endl;
		std::cout << "5. One step back. " << std::endl;
		std::cout << "---------------------------------" << std::endl;
		std::cin >> choice;
		
		if (choice == 1) {
			SearchByTitle();
		}
		else if (choice == 2) {
			SearchByAuthor();
		}
		else if (choice == 3) {
			SearchByGenre();
		}
		else if (choice == 4) {
			SearchByYear();
		}
		else if (choice == 5) {
			return;
		}
		else {
			std::cout << "Invalid option, choose a valid option 1,2,3,4,5! " << std::endl;
		}
	} while (true);
}
