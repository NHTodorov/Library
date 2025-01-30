#pragma once
#include "AddBook.h"
#include "AvailableBooks.h"
#include "HelpfulFunc.h"

#include <iostream>
#include <limits>
// The following 4 subfunctionsare subfunctions in the both functions UserUI() and ModeratorUI()

// 1. Subfunction to search a book by title
void SearchByTitle() {
	std::string TitleSearch;
	std::cout << "Please enter the title of the book: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, TitleSearch);
	TitleSearch = StringConvert(TitleSearch); // transform to lower letters + remove all spaces 

	bool FoundByTitle = false;

	for (size_t i = 0; i < AvailableBooksOBJ.Books.size(); ++i) {
		std::string ExistingTitle = AvailableBooksOBJ.Books[i].getTitle();
		ExistingTitle = StringConvert(ExistingTitle); // transform to lower letters + remove all spaces 
		if (ExistingTitle.find(TitleSearch) != std::string::npos) { // if searched title is found
			AvailableBooksOBJ.Books[i].display(); // display
			FoundByTitle = true;
		}
	}
	if (!FoundByTitle) {
		std::cout << "No books found with title: " << TitleSearch << std::endl;
	}
}

// 2. Subfunction to search a book by author
void SearchByAuthor() {
	std::string AuthorSearch;
	std::cout << "Please enter the author of the book: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, AuthorSearch);
	AuthorSearch = StringConvert(AuthorSearch); // transform to lower letters + remove all spaces 

	bool FoundByAuthor = false;

	for (size_t i = 0; i < AvailableBooksOBJ.Books.size(); ++i) {
		std::string ExistingAuthor = AvailableBooksOBJ.Books[i].getAuthor();
		ExistingAuthor = StringConvert(ExistingAuthor); // transform to lower letters + remove all spaces 
		if (ExistingAuthor.find(AuthorSearch) != std::string::npos) { // if searched author is found
			AvailableBooksOBJ.Books[i].display(); // display
			FoundByAuthor = true;
		}
	}
	if (!FoundByAuthor) {
		std::cout << "No books found for the author: " << AuthorSearch << std::endl;
	}
}

// 3. Subfunction to search a book by genre
void SearchByGenre() {
	std::string GenreSearch;
	std::cout << "Please enter the genre of the book: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(std::cin, GenreSearch);
	GenreSearch = StringConvert(GenreSearch); // transform to lower letters + remove all spaces 

	bool FoundByGenre = false;

	for (size_t i = 0; i < AvailableBooksOBJ.Books.size(); ++i) {
		std::string ExistingGenre = AvailableBooksOBJ.Books[i].getGenre();
		ExistingGenre = StringConvert(ExistingGenre); // transform to lower letters + remove all spaces 
		if (ExistingGenre.find(GenreSearch) != std::string::npos) { // if searched genre is found
			AvailableBooksOBJ.Books[i].display(); // display 
			FoundByGenre = true;
		}
	}
	if (!FoundByGenre) {
		std::cout << "No books found with the genre: " << GenreSearch << std::endl;
	}
}

// 4. Subfunction to search a book by year
void SearchByYear() {
	int YearSearch;
	std::cout << "Please enter the year of the book: ";
	std::cin >> YearSearch;

	bool FoundByYear = false;

	for (size_t i = 0; i < AvailableBooksOBJ.Books.size(); ++i) {
		if (AvailableBooksOBJ.Books[i].getYear() == YearSearch) {
			AvailableBooksOBJ.Books[i].display();
			FoundByYear = true;
		}
	}
	if (!FoundByYear) {
		std::cout << "No books found for the year: " << YearSearch << std::endl;
	}
}
