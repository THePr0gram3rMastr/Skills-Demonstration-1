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
#include <string>

#if defined (_WIN32) || (_WIN64)
	#include <Windows.h>
#endif

int examData[6][6] = {
	50,50,50,50,50,50,
	60,80,75,50,60,75,
	80,55,65,59,70,70,
	60,68,75,50,60,55,
	60,70,70,67,70,70,
	90,90,90,90,90,90
};

class Validate {
private:
	unsigned int userID;
	uint16_t PAC, userPAC;
	uint16_t ATTEMPTS_REMAINING;

public:

	Validate()
		:userID(0), PAC(0), userPAC(0) {
	}

	Validate(unsigned int userID) {
		this->userID = userID;
	}

	bool testID() const;
	void idValidation(const Validate& otherValidate) const;
	void userInput(uint16_t* PAC, uint16_t* userPAC, uint16_t ATTEMPS_REMAINING);
	bool testPAC() const;
	bool pacValidation(const Validate& otherValidate) const;
	bool validateExamMarks(float subjectMark);
};

class Exams : public Validate {
private:
	float subjectMark, CAOpoints;
	std::string grade;
	std::string subjectName[6] = {
		"OOP",
		"Web A",
		"Work Exp",
		"DB",
		"Math",
		"Soft A"
	};

public:
	Exams() {

	}

	Exams(float subjectMark) {
		this->subjectMark = subjectMark;
		validateExamMarks(subjectMark);
	}

	void printReportHeadings(unsigned int report);
	std::string testGrade();

};

bool Validate::testID() const {
	if (userID == 12345678) {
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

	if ((this->PAC == 1 && this->userPAC == 1) || (this->PAC == 2 && this->userPAC == 1) || (this->PAC == 3 && this->userPAC == 0)
		|| (this->PAC == 4 && this->userPAC == 8) || (this->PAC == 5 && this->userPAC == 8)) {

		return true;

	} else {

		return false;
	}
}

bool Validate::pacValidation(const Validate& otherValidate) const {

	if (otherValidate.testPAC() == true) {
		std::cout << "|" << std::setw(45) << "|" << std::endl;
		std::cout << "| PAC is valid" << std::setw(32) << "|" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;

		return true;
	} else {
		std::cout << "|" << std::setw(45) << "|" << std::endl;

		if (ATTEMPTS_REMAINING > 0) {
			std::cout << "| PAC is invalid. Try again." << std::setw(18) << "|" << std::endl;
			std::cout << "----------------------------------------------" << std::endl;
		} else if (ATTEMPTS_REMAINING == 0) {
			std::cout << "| PAC is invalid. No attempts remaining." << std::setw(6) << "|" << std::endl;
		}

		std::cout << "|" << std::setw(45) << "|" << std::endl;
		std::cout << "|" << ATTEMPTS_REMAINING << std::setw(22) << " attempts remaining...." << std::setw(21) << "|" << std::endl;
		std::cout << "|" << std::setw(45) << "|" << std::endl;

		return false;
	}
}

bool Validate::validateExamMarks(float subjectMark) {
	if (subjectMark <= 100 && subjectMark >= 0) {

		return true;
	} else {
		std::cout << "A GRADE IS INVALID!" << std::endl;
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

std::string Exams::testGrade() {

	if (subjectMark >= 80) {
		grade = "D";
	} else if (subjectMark > 64 && subjectMark < 80) {
		grade = "M";
	} else if (subjectMark >= 50 && subjectMark < 65) {
		grade = "P";
	} else if (subjectMark < 30) {
		grade = "U";
	}

	return grade;
}

void Exams::printReportHeadings(unsigned int report) {
	if (report == 1) {
		std::cout << "-----------------------------------------------------------------------------" << std::endl;
		std::cout << std::setw(44) << "Report 1" << std::endl;
		std::cout << std::setw(8) << "Modules ";

		for (int i = 0; i < 6; i++) {
			std::cout << std::left << std::setw(10) << subjectName[i];
		}

		std::cout << std::setw(10) << "Average ";

		std::cout << std::endl;

	} else if (report == 2) {
		std::cout << std::setw(44) << "Report 2" << std::endl;
		std::cout << std::setw(8) << "Modules ";

		for (int i = 0; i < 6; i++) {
			std::cout << std::left << std::setw(10) << subjectName[i];
		}

		std::cout << std::endl;

	}
}

void testGrades() {
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 6; j++) {
			Exams validate(examData[i][j]);
		}
	}
}

void openReport() {

	testGrades();

	const unsigned int noRows = 6;
	const unsigned int noColumns = 6;

	unsigned int rowTotal, rowAverage;
	unsigned int columnTotal[6];

	std::string name[6] = {
		"D James",
		"S Aguero",
		"M Alonso",
		"J McClean",
		"B Johnson",
		"S Duffy"
	};

	Exams students[6];

	Exams reports;
	reports.printReportHeadings(1);

	for (int row = 0; row < noRows; row++) {
		rowTotal = 0;
		std::cout << std::setw(10) << name[row];

		for (int column = 0; column < noColumns; column++) {

			std::cout << std::setw(10) << examData[row][column];

			rowTotal = rowTotal + examData[row][column];

		}

		rowAverage = rowTotal / noColumns;
		std::cout << std::setw(10) << rowAverage;
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "End of Report 1...." << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	reports.printReportHeadings(2);

	for (int row = 0; row < noRows; row++) {
		rowTotal = 0;
		std::cout << std::setw(10) << name[row];

		for (int column = 0; column < noColumns; column++) {

			Exams report2(examData[row][column]);

			std::cout << std::setw(10) << report2.testGrade();

		}

		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "End of Report 2...." << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;

}

int main(int argc, char** argv) {

#if defined (_WIN32) || (_WIN64)
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 185);
#endif

	unsigned int userID;
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
			openReport();
			break;
		}
	}

	return 0;
}
