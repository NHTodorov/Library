#pragma once
#include "CombinedFunc.h"

void UserUI() {
    int choice;
    do {
        std::cout << "Choose an option from below: " << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "1. Search a book by title." << std::endl;
        std::cout << "2. Search a book by author." << std::endl;
        std::cout << "3. Search a book by genre." << std::endl;
        std::cout << "4. Search a book by year." << std::endl;
        std::cout << "5. View all available books." << std::endl;
        std::cout << "6. Exit. " << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cin >> choice;

        switch (choice) {
        default:
            std::cout << "Invalid option! Please select a valid option. (1, 2, 3, 4)" << std::endl;
            break;

        case 1:
            SearchByTitle();
            break;

        case 2:
            SearchByAuthor();
            break;

        case 3:
            SearchByGenre();
            break;

        case 4:
            SearchByYear();
            break;

        case 5:
            AvailableBooksOBJ.PrintAllBooks();
            break;
        case 6:
            std::cout << "Exiting... " << std::endl;
            exit(0);
            break;
        }
    } while (true);
}