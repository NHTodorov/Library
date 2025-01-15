#pragma once
#include "AddBook.h"

#include <vector>

// randomly added few books
class AvailableBooks {
public:
	std::vector <AddBook> Books;

	AvailableBooks() {
		Books.push_back(AddBook("Under the Yoke", "Ivan Vazov", "Novel", 1888, 10));
		Books.push_back(AddBook("Bai Ganyo", "Ivan Vazov", "Novel", 1878, 11));
		Books.push_back(AddBook("Under the Monastery Bell", "Yordan Yovkov", "Novel", 1922, 8));
		Books.push_back(AddBook("For Youth", "Hristo Botev", "Poetry", 1875, 10));
		Books.push_back(AddBook("Burning", "Hristo Smirnenski", "Poetry", 1918, 12));
		Books.push_back(AddBook("The Teacher's Diary", "Konstantin Velichkov", "Memoir", 1957, 12));
	}

	int PrintAllBooks() {
		for (int i = 0; i < Books.size(); ++i) {
			Books[i].display();
		}
		return 0;
	}
};
AvailableBooks AvailableBooksOBJ;
