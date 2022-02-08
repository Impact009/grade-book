// Grade Book.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Function prototypes.
void getStudentNames(string[], int);
int getTestScores(string[], double[], int, int);
int calculateAverages(double[], char[], string[], int, int);

int main()
{
	// Declare variables to store values for the numbers of floors, occupied rooms, unoccupied rooms, and the percentage of rooms that are occupied.
	const int NUM_STUDENTS = 5, NUM_TESTS = 4;
	char letterGrades[NUM_STUDENTS];
	double student1[NUM_TESTS], student2[NUM_TESTS], student3[NUM_TESTS], student4[NUM_TESTS], student5[NUM_TESTS];
	string studentNames[NUM_STUDENTS];
	char reply = 'n';
	int calculateAveragesCount = 0, getScoresCount = 0;


	// Program information and example.
	cout << "This program is a grade book that will hold the names and " << NUM_TESTS << " test scores from\n"
		 << "each student for a total of " << NUM_STUDENTS << " students. It also will calculate the averages of\n"
		 << "their respective test scores and assign each of them a letter grade based on\n"
		 << "their averages.\n"
		 << endl
		 << "For example, if Brooke has test scores of 80, 85, 95, and 100, then her average\n"
		 << "is a 90, and her letter grade is an \"A.\"\n"
		 << endl

	// Ask the user if he or she wants to enter information.
		 << "This program requires " << NUM_STUDENTS << " students' names and " << NUM_TESTS << " of their test scores.\n"
		 << "Would you like to enter this information? (y/n) ";
	cin  >> reply;

	// Clear keyboard buffer.
	cin.ignore();

	cout << endl;

	if (reply == 'y' || reply == 'Y')
	{
		// Clear the screen.
		system("cls");

		// Get the students' names.
		getStudentNames(studentNames, NUM_STUDENTS);

		// Get the students' test scores.
		getScoresCount = getTestScores(studentNames, student1, NUM_TESTS, getScoresCount);
		getScoresCount = getTestScores(studentNames, student2, NUM_TESTS, getScoresCount);
		getScoresCount = getTestScores(studentNames, student3, NUM_TESTS, getScoresCount);
		getScoresCount = getTestScores(studentNames, student4, NUM_TESTS, getScoresCount);
		getScoresCount = getTestScores(studentNames, student5, NUM_TESTS, getScoresCount);

		// Calculate the students' respective test score averages and letter grades.
		calculateAveragesCount = calculateAverages(student1, letterGrades, studentNames, NUM_TESTS, calculateAveragesCount);
		calculateAveragesCount = calculateAverages(student2, letterGrades, studentNames, NUM_TESTS, calculateAveragesCount);
		calculateAveragesCount = calculateAverages(student3, letterGrades, studentNames, NUM_TESTS, calculateAveragesCount);
		calculateAveragesCount = calculateAverages(student4, letterGrades, studentNames, NUM_TESTS, calculateAveragesCount);
		calculateAveragesCount = calculateAverages(student5, letterGrades, studentNames, NUM_TESTS, calculateAveragesCount);
	}
	cout << "Have a great day!\n\n";
	return 0;
}

// Get the students' names.
void getStudentNames(string names[], int namesSize)
{
	// Accumulator for display purposes.
	int studentCount = 0;

	for (int index = 0; index < namesSize; index++)
	{
		studentCount++;
		cout << "Enter student " << studentCount << "'s name: ";
		getline(cin, names[index]);
	}
	cout << endl;
}

// Get the student's test scores.
int getTestScores(string names[], double testScores[], int testScoresSize, int studentCount)
{
	const int MINIMUM_SCORE = 0, MAXIMUM_SCORE = 100;
	// Accumulator for display purposes.
	int testCount = 0;

	for (int indexScore = 0; indexScore < testScoresSize; indexScore++)
	{
		testCount++;
		cout << "Enter " << names[studentCount] << "'s score for test " << testCount << ": ";
		cin  >> testScores[indexScore];

		// Input validation.
		while (testScores[indexScore] < MINIMUM_SCORE || testScores[indexScore] > MAXIMUM_SCORE)
		{
			cout << "Error! Test scores must be between 0 inclusive and 100 inclusive!\n"
				 << "Enter " << names[studentCount] << "'s score for test " << testCount << ": ";
			cin >> testScores[indexScore];
		}
	}
	cout << endl;

	studentCount++;
	return studentCount;
}

// Calculate a student's letter grade.
int calculateAverages(double testScores[], char letterGrades[], string names[], int testScoresSize, int calculateAveragesCount)
{
	double average, total = 0;

	for (int index = 0; index < testScoresSize; index++)
		total += testScores[index];
	average = total / testScoresSize;

	if (average < 60)
	{
		letterGrades[calculateAveragesCount] = 'F';
		cout << "Student Name:        " << names[calculateAveragesCount] << endl
			 << "Test Scores Average: " << average << endl
			 << "Letter Grade:        " << letterGrades[calculateAveragesCount];
	}
	else if (average < 70)
	{
		letterGrades[calculateAveragesCount] = 'D';
		cout << "Student Name:        " << names[calculateAveragesCount] << endl
			 << "Test Scores Average: " << average << endl
			 << "Letter Grade:        " << letterGrades[calculateAveragesCount];
	}
	else if (average < 80)
	{
		letterGrades[calculateAveragesCount] = 'C';
		cout << "Student Name:        " << names[calculateAveragesCount] << endl
			 << "Test Scores Average: " << average << endl
			 << "Letter Grade:        " << letterGrades[calculateAveragesCount];
	}
	else if (average < 90)
	{
		letterGrades[calculateAveragesCount] = 'B';
		cout << "Student Name:        " << names[calculateAveragesCount] << endl
			 << "Test Scores Average: " << average << endl
			 << "Letter Grade:        " << letterGrades[calculateAveragesCount];
	}
	else if (average <= 100)
	{
		letterGrades[calculateAveragesCount] = 'A';
		cout << "Student Name:        " << names[calculateAveragesCount] << endl
			 << "Test Scores Average: " << average << endl
			 << "Letter Grade:        " << letterGrades[calculateAveragesCount];
	}
	cout << endl
		 << endl;

	calculateAveragesCount++;
	return calculateAveragesCount;
}