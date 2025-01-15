#pragma once
#include <iostream>
#include <string>

class AddBook {
private:
	std::string title;
	std::string author;
	std::string genre;
	int year;
	short int copies;
public:
	AddBook(const std::string& _title, const std::string& _author, const std::string& _genre, const int _year, short int _copies)
		: title(_title), author(_author), genre(_genre), year(_year), copies(_copies) {
	}

	AddBook() = default;

	std::string getTitle() {
		return title;
	}

	std::string getAuthor() {
		return author;
	}

	std::string getGenre() {
		return genre;
	}

	int getYear() {
		return year;
	}

	int getCopies() {
		return copies;
	}

	void setCopies(short int newcopies) {
		copies = newcopies;
	}

	// get required info for new book add
	void getData() {
		std::cout << "Type the name of the book:   " << std::endl;
		getline(std::cin, title);
		std::cout << "Type the author of the book:   " << std::endl;
		getline(std::cin, author);
		std::cout << "Type the genre of the book:   " << std::endl;
		getline(std::cin, genre);
		std::cout << "Type the year of the book:   " << std::endl;
		while (true) {
			if (std::cin >> year && year > 0) {
				break; // valid year
			}
			else {
				std::cout << "Invalid year! Please enter a valid positive number: " << std::endl;
				std::cin.clear(); // clear the wrong input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removes remaining invalid input
			}
		}

		std::cout << "Type copies of the book: " << std::endl;
		while (true) {
			if (std::cin >> copies && copies > 0) {
				break; // valid input
			}
			else {
				std::cout << "Invalid number of copies! Please enter a valid positive number: " << std::endl;
				std::cin.clear(); // clear the wrong input
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removes remaining invalid input
			}
		}
	}

	void display() {
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Name: " << title << std::endl;
		std::cout << "Author: " << author << std::endl;
		std::cout << "Genre: " << genre << std::endl;
		std::cout << "Year: " << year << std::endl;
		std::cout << "Copies: " << copies << std::endl;
		std::cout << "-------------------------------------" << std::endl;
	}


	void ErrorCheck() {
		std::string choice;
		do {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Any errors? (Y/N)" << std::endl;
			std::cin >> choice;

			if (choice == "Y" || choice == "y") {
				std::cout << "Correct the errors: " << std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return getData();
			}
			else if (choice == "N" || choice == "n") {
				std::cout << "New book has been added! " << std::endl;
				break;
			}
			else {
				std::cout << "Invalid input. Please type 'Y' or 'N'." << std::endl;
			}
		} while (true);
	}

};
AddBook AddBookOBJ;