/* David Bush, Rotating Array Assignment 1, CS 121, Bolden, 9/26/20 
------------------------------------------------------------------
------------------------- Array Rotation -------------------------
------------------------------------------------------------------
-------------------------- Description ---------------------------
------------------------------------------------------------------
	This is the main file for the rotating array program.

	To Compile use g++ rotation.cpp Array2D.cpp -o rotation

	To Run use ./rotation input.txt

*/

#include <iostream>
#include "Array2D.h"
using namespace std;

int main(int argc, char** argv){
	// Reads in file name from command line and saves it
	string inFile = "";
	if(argc == 2)
		inFile = argv[1];
	else{
		cout << "Error with inputing file try again.\n";
		exit(-1);
	}

	// Testing Array2D class
	Array2D test;
	int** ptr2test=NULL;
	// Read in, allocate size of 2D array, and saves array
	test.readFile(inFile);
	// Set ptr2test to the ptr of the saved 2D array
	ptr2test = test.getArray2D();
	// Print the 2D array
	cout << "This is the 2D array saved from the file \n";
	test.print(ptr2test);
	// Clean up
	ptr2test  = NULL;
	
	// Rotates the saved array to the right
	test.rotateRight();
	// Sets the pointer to the 2D array 
	ptr2test = test.getRight2D();
	// Prints the 2D array
	cout << "\nThis is the 2D array rotated to the right \n";
	test.print(ptr2test);
	// Clean up
	ptr2test  = NULL;	

	// Rotates the saved array to the left
	test.rotateLeft();
	// Sets the pointer to the 2D array 
	ptr2test = test.getLeft2D();
	// Prints the 2D array
	cout << "\nThis is the 2D array rotated to the left \n";
	test.print(ptr2test);	
	// Clean Up
	//test.delete2D(ptr2test);
	delete ptr2test;
	return 0;
	
}