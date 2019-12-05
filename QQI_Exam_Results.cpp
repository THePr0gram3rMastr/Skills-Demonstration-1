/**
 * File:    OOP_Exam_Results.cpp
 *
 * Author:  Cian Martin Bohan (@cianmarbo)
 * College: Rathmines College of Further Education
 * Date:    Decemeber 2019
 *
 * Summary of File:
 *
 *    This file is part of Object Orineted Programming
 *    Skills Demonstration 1.
 *
 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#if defined (_WIN32) || (_WIN64)
	#include <Windows.h>
#endif

class Validate {
private:
	uint16_t userID;
	uint16_t PAC, userPAC;
	uint16_t ATTEMPTS_REMAINING;

public:

	Validate()
		:userID(0), PAC(0), userPAC(0) {
	}

	Validate(uint16_t userID) {
		this->userID = userID;
	}

	bool testID() const;
	void idValidation(const Validate& otherValidate) const;
	void userInput(uint16_t* PAC, uint16_t* userPAC, uint16_t ATTEMPS_REMAINING);
	bool testPAC() const;
	bool pacValidation(const Validate& otherValidate) const;
};

bool Validate::testID() const {
	if (userID == 1234) {
		return true;
	} else {
		return false;
	}
}

void Validate::idValidation(const Validate& otherValidate) const {
	if (otherValidate.testID() == true) {
		std::cout << "|         User ID is valid          |" << std::endl;
	} else {
		std::cout << "|        User ID is invalid         |" << std::endl;
	}
}

void Validate::userInput(uint16_t* PAC, uint16_t* userPAC, uint16_t ATTEMPTS_REMAINING) {

	this->ATTEMPTS_REMAINING = ATTEMPTS_REMAINING-1;

	if (ATTEMPTS_REMAINING > 0) {
		std::cout << "| Enter digit " << *PAC << ": ";
		std::cin >> *userPAC;
	}

	this->PAC = *PAC;
	this->userPAC = *userPAC;
}

bool Validate::testPAC() const {

	if ((this->PAC == 1 && this->userPAC == 9) || (this->PAC == 2 && this->userPAC == 9) || (this->PAC == 3 && this->userPAC == 8)
		|| (this->PAC == 4 && this->userPAC == 8) || (this->PAC == 5 && this->userPAC == 1)) {

		return true;

	} else {

		return false;
	}
}

bool Validate::pacValidation(const Validate& otherValidate) const {

	if (otherValidate.testPAC() == true) {
		std::cout << "| PAC is valid" << std::setw(32) << "|" << std::endl;

		return true;
	} else {
		std::cout << "|" << std::setw(45) << "|" << std::endl;
		
		if (ATTEMPTS_REMAINING > 0) {
			std::cout << "| PAC is invalid. Try again." << std::setw(18) << "|" << std::endl;
		} else if (ATTEMPTS_REMAINING == 0) {
			std::cout << "| PAC is invalid. No attempts remaining." << std::setw(6) << "|" << std::endl;
		}

		std::cout << "|" << std::setw(45) << "|" << std::endl;
		std::cout << "|" << ATTEMPTS_REMAINING << std::setw(22) << " attempts remaining...." << std::setw(21) << "|" << std::endl;
		std::cout << "|" << std::setw(45) << "|" << std::endl;

		return false;
	}
}

void random(uint16_t* pac1, uint16_t* pac2, uint16_t* pac3) {

start: srand(time(0));

	*(pac1) = (1 + (rand() % 5));
	*(pac2) = (1 + (rand() % 5));
	*(pac3) = (1 + (rand() % 5));


	if (*pac1 == *pac2 || *pac1 == *pac3 || *pac2 == *pac3) {

		goto start;
	}
}

int main(int argc, char** argv) {

#if defined (_WIN32) || (_WIN64)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
#endif

	unsigned short int userID;
	uint16_t pacs[3];
	uint16_t userPAC[3];

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "|  QQI Examination Results System   |" << std::endl;

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "|" << std::setw(36) << "|" << std::endl;
	std::cout << "| Please enter your password.....";
	std::cin >> userID;
	std::cout << "|" << std::setw(36) << "|" << std::endl;

	Validate user(userID);
	user.idValidation(user);

	std::cout << "|" << std::setw(36) << "|" << std::endl;
	std::cout << "-------------------------------------" << std::endl;

	//End of password section

	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "| Please login. Three attempts remaining.... |" << std::endl;
	std::cout << "|" << std::setw(45) << "|" << std::endl;

	random(&pacs[0], &pacs[1], &pacs[2]);

	std::sort(pacs, pacs + 3);

	Validate user1;

	for (int i = 3; i > 0; i--) {
		for (int j = 0; j < 3; j++) {
			user1.userInput(&pacs[j], &userPAC[j], i);
		}

		if (user1.pacValidation(user1) == true) {
			break;
		}
	}

	std::cout << "|" << std::setw(45) << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	return 0;
}
