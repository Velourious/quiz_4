#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

using namespace std;

//***************************
//    FUNCTION PROTOTYPES
//***************************
void displayMenu();
void userChoiceAction();
void createCircle(Circle &);
void createSquare(Square &square);
void createTriangle(Triangle &triangle);
void validateMenuSelection(string menuOptions[], string &userInput);
string validateIntInput(string userInput);
string filledInputCheck(string userInput);
void circPic(double radius);
void triPic(double base, double height);
void squarePic(double side);

//***************************
//     GLOBAL CONSTANTS
//***************************
const int CHOICE_SIZE = 2;
const int OPTIONS = 13;

int main()
{
	userChoiceAction();
	system("pause");
	return 0;
}//end main

//***************************
//    FUNCTION DEFINITIONS
//***************************

//Display menu
void displayMenu()
{
	cout << "C1. Create a circle\n"
		<< "C2. Increase radius by 1 unit\n"
		<< "C3. Decrease radius by 1 unit\n"
		<< "C4. Display circle properties";
	cout << "\n*************************************************\n";
	cout << "S1. Create a square\n"
		<< "S2. Increase side length by 1 unit\n"
		<< "S3. Decrease side length by 1 unit\n"
		<< "S4. Display square properties";
	cout << "\n*************************************************\n";
	cout << "T1. Create a triangle\n"
		<< "T2. Increase base and height length by 1 unit\n"
		<< "T3. Decrease base and height length by 1 unit\n"
		<< "T4. Display triangle properties";
	cout << "\n*************************************************\n";
	cout << "Q. Quit\n";
}

//Major switch statement that executes
//user menu choice
void userChoiceAction()
{
	string userChoice = "";
	string options[OPTIONS] = { "C1","C2","C3","C4","S1","S2","S3","S4","T1","T2","T3","T4", "Q" };
	int userChoiceAsInt;

	static Circle circle(0.0);
	static Square square(0.0);
	static Triangle triangle(0.0,0.0);

	displayMenu();

	//Empty input not accepted
	while (userChoice == "")
	{
		cout << "Please choose a menu option: ";
		getline(cin, userChoice);
	}
	
	//Convert user choice to uppercase
	for (int i = 0; i < CHOICE_SIZE; i++)
	{
		userChoice[i] = toupper(userChoice[i]);
	}

	//Make sure user chose a menu option
	validateMenuSelection(options, userChoice);

	//Convert userchoice to an int for major switch statement
	for (int i = 0; i < OPTIONS; i++)
	{
		if (userChoice == options[i]) {
			userChoiceAsInt = i;
		}
	}

	cout << "You chose: " << userChoice << endl;
	cout << endl;

	//Major switch statement
	switch (userChoiceAsInt)
	{
	case 0: //C1. create circle with user input
		system("cls");
		createCircle(circle);
		break;

	case 1: //C2. increase radius by 1 unit
		circle++;
		cout << "Circle radius is now " << circle.getRadius() << " unit(s)." << endl;
		break;

	case 2://C3. decrease radius by 1 unit
		circle--;
		cout << "Circle radius is now " << circle.getRadius() << " unit(s)." << endl;
		break;

	case 3://C4. display circle properties
		system("cls");
		circPic(circle.getRadius());
		cout << circle;
		break;

	case 4://S1. Create square with user input
		system("cls");
		createSquare(square);
		break;

	case 5://S2. increase square side length
		square++;
		cout << "Square side length is now " << square.getLength() << " unit(s)." << endl;
		break;

	case 6://S3. decrease square side length
		square--;
		cout << "Square side length is now " << square.getLength() << " unit(s)." << endl;
		break;

	case 7://S4. display square properties
		system("cls");
		squarePic(square.getLength());
		cout << square;
		break;

	case 8://T1. Create triangle with user input
		system("cls");
		createTriangle(triangle);
		break;

	case 9://T2. Increase base and height by 1 unit each
		triangle++;
		cout << "Triangle base is now " << triangle.getBase() << " unit(s)." << endl;
		cout << "Triangle height is now " << triangle.getHeight() << " unit(s)." << endl;
		break;

	case 10://T3. Decrease base and height by 1 unit each
		triangle--;
		cout << "Triangle base is now " << triangle.getBase() << " unit(s)." << endl;
		cout << "Triangle height is now " << triangle.getHeight() << " unit(s)." << endl;
		break;

	case 11://T4. Display triangle properties
		system("cls");
		triPic(triangle.getBase(), triangle.getHeight());
		cout << triangle;
		break;

	case 12://Q. quit
		exit(0);
		break;

	default:
		system("cls");
		userChoiceAction();
		break;
	}//end switch statement

	cout << endl;
	system("pause");
	system("cls");
	userChoiceAction();
}// end user action

//************************************************
//Sets circle with radius of
//1 unit, effectively 
//creating a circle
//************************************************
void createCircle(Circle &circle)
{
	double length = 0.0;
	string len;
	string validLen;

	//Reprompt for input when value 
	//less than 0 entered
	while (length <= 0.0)
	{
		cout << "Enter radius length: ";
		getline(cin, len);
		validLen = validateIntInput(len);
		length = stod(validLen);
	}

	//set radius length with valid input
	circle.setRadius(length);
	
	circPic(length);
	cout << "A circle with radius length, " << length << ", has been created.\n";
}

//************************************************
//Sets square with side length of
//1 unit, effectively 
//creating a square
//************************************************
void createSquare(Square &square)
{
	double length = 0.0;
	string len;
	string validLen;

	//Reprompt for input when value 
	//less than 0 entered
	while (length <= 0.0)
	{
		cout << "Enter side length: ";
		getline(cin, len);
		validLen = validateIntInput(len);
		length = stod(validLen);
	}
	//set side length with valid input
	square.setLength(length);

	squarePic(length);
	cout << "A square with side length, " << length << ", has been created.\n";
}

//************************************************
//Sets triangle with a base of 1 unit
//and height of 1 unit, effectively 
//creating a triangle
//************************************************
void createTriangle(Triangle &triangle)
{

	double baseLen = 0.0;
	double heightLen = 0.0;
	string len;
	string validLen;

	//Reprompt for input when value 
	//less than 0 entered
	while (baseLen <= 0.0)
	{
		cout << "Enter base length: ";
		getline(cin, len);
		validLen = validateIntInput(len);
		baseLen = stod(validLen);
	}
	//set base length with valid input
	triangle.setBase(baseLen);

	//Reprompt for input when value 
	//less than 0 entered
	while (heightLen <= 0.0)
	{
		cout << "Enter height: ";
		getline(cin, len);
		validLen = validateIntInput(len);
		heightLen = stod(validLen);
	}
	//set height length with valid input
	triangle.setHeigth(heightLen);

	triPic(baseLen, heightLen);
	cout << "A triangle with base length of " << baseLen << " and height of "
		<< heightLen << " has been created.\n";
}

//************************************************
//Validates that user selected an option
//on the menu, else error message displayed
//************************************************
void validateMenuSelection(string menuOptions[], string &userInput)
{
	bool matchFound = false;

	//if user selects menu option, mathFound is true
	//function exit
	for (int i = 0; i < OPTIONS; i++)
	{
		if (menuOptions[i] == userInput) 
		{
			matchFound = true;
		}
	}

	//if user entered a value not on menu,
	//display error message
	if (matchFound == false)
	{
		system("cls");
		cout << "******************************************************************************\n"
			<< "                  PLEASE CHOOSE AN OPTION ON THE MENU\n"
			<< "******************************************************************************" << endl;
		userChoiceAction();
	}
}//end validate input

 //Validate integer input
 //Accepts string parameter.
 //RETURNS NUMBERICAL INPUT AS STRING. MUST CONVERT TO INT FOR CALC
 //MUST INCLUDE CO-FUNCTION filledInputCheck, which accepts string
 //input, verifies that input is not empty, returns string.
string validateIntInput(string userInput)
{
	int counter = 0;
	string inputReenter;
	//Checks that input is not empty,
	//then stores input locally for manipulation
	string input = filledInputCheck(userInput);
	int inputLength = input.length();

	//Iterates over input
	//If any part of input is not a digit
	//prompts user to try again
	//empty input check included
	while (counter < inputLength)
	{
		if (!(isdigit(input[counter])))
		{
			cout << " INVALID" << endl;
			cout << "Enter a positive number value: ";
			getline(cin, input);
			inputReenter = filledInputCheck(input);
			input = inputReenter;
			inputLength = input.length();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}//end of outer loop
	return input;        //Number returned as string type
}

 //Check for empty input
 //Accepts string parameter.
 //Returns string.
string filledInputCheck(string userInput)
{
	string input = userInput;
	while (input.length() == 0)
	{
		cout << "You did not enter anything. Please try again: ";
		getline(cin, input);
	}
	return input;
}//end of empty input check

//Display cirlce pic
void circPic(double radius)
{
	cout << endl;
	cout << "         oo\n"
		<< "     oO      Oo\n"
		<< "  oO            Oo\n"
		<< " oO              Oo\n"
		<< "oO          " << setw(3) << radius << "   Oo\n"
		<< "oO        --------Oo\n"
		<< " oO              Oo\n"
		<< "  oO            Oo\n"
		<< "    oO       Oo\n"
		<< "        ooo\n";	
	cout << endl;
}

//Display triangle pic
void triPic(double base, double height)
{
	cout << endl;
	cout << "          /\\         |\n"
		<< "         /  \\        |\n"
		<< "        /    \\\n"
		<< "       /      \\      |\n"
		<< "      /        \\\n"
		<< "     /          \\   " << setw(3) << height <<"\n"
		<< "    /            \\\n"
		<< "   /              \\  |\n"
		<< "  /                \\\n"
		<< " /__________________\\|\n"
		<< " \\- - - -" << setw(3) << base << " - - - -/\n";
	cout << endl;
}

//Display square pic
void squarePic(double side)
{
	cout << endl;
	cout << "  _____________________\n"
		<< " |                     |\n"
		<< " |                     |\n"
		<< " |                     |\n"
		<< " |                     |\n"
		<< " |                     |\n"
		<< " |                     |\n"
		<< " |                     |\n"
		<< " |                     |\n"
		<< " |_____________________|\n";
	cout << " \\- - - - " << setw(3) << side << " - - - - -/\n";
	cout << endl;
}
