#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include "ModeratorUI.h"
#include "UserUI.h"


void Entry() {
	std::cout << "Welcome to Cosmic Con Library! " << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "If you are user please type 'user'.  " << std::endl;
	std::cout << "If you are admin please type 'moderator'.  " << std::endl;
	std::cout << "For exit type 0. " << std::endl;
	std::string input;
	std::cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);	// transform all input letters to lower

	// check if invalid input written

	while (input != "user" && input != "moderator" && input != "0") {
		std::cout << "Invalid option, please try again! " << std::endl;
		std::cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::tolower);	// transform all input letters to lower
	}

	while (input == "user") {
		UserUI();
	}

	while (input == "moderator") {
		ModeratorUI();
	}

	while (input == "0") {
		std::cout << "Exiting program... " << std::endl;
		exit(0);
	}
}