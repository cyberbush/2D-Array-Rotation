/* David Bush, Rotating Array Assignment 1, CS 121, Bolden, 9/26/20
------------------------------------------------------------------
-------------------- Array2D Implementation ---------------------
------------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Array2D.h"
using namespace std;

// Constructor intializing values
Array2D :: Array2D(){
	row = coll = 0;
	ptr2Array = NULL;
	ptr2Right = NULL;
	ptr2Left = NULL;
}

// Destructor removing allocated memory
Array2D :: ~Array2D(){
	delete2D(ptr2Array);
	delete2D(ptr2Right);
	delete2D(ptr2Left);

}

// Function to read in file, save size, and set array values
void Array2D::readFile(string fileName){
	ifstream inputFile;
	int num=0;
	inputFile.open(fileName);
	// Read array's rows and collumns first	
	inputFile >> row;
	inputFile >> coll;
	// Only can allocate after we have the size of the array
	ptr2Array = allocate2D();
	// Set 2D array values from file
	for(int i=0; i<row; i++){
		for(int j=0; j<coll; j++){
			inputFile >> num;
			ptr2Array[i][j] = num;
		}
	}
	inputFile.close();	
}

// Allocated 2D array using an array of pointers to arrays 	
int** Array2D::allocate2D(){
	int** ptr2 = new int*[row];
	for(int z=0; z<row; z++)
		ptr2[z] = new int[coll];
	return ptr2;
}

// Function for deleting all pointers in the array
void Array2D::delete2D(int** ptr2){
		for(int j=0; j<row ; j++)
			delete ptr2[j];
	delete ptr2;
}

// This function rotates the array's entries to the right 
void Array2D::rotateRight(){
	// Don't forget to allocate ptr2Right! 
	ptr2Right = allocate2D();
	int x=0, y=0;
	// I was able to recognize patterns looking at 
	// the x1,y1 --> x,y rotation coordinates
	// (2,1 = 1,1) / (1,0 = 0,2) / (0,1 = 1,3) / (1,1 = 1,2)  
	for(int y1=0; y1<row; y1++){
		for(int x1=0; x1<coll; x1++){
			if(x1==y1)
				x = x1;
			else
				x = y1;
			y = row - 1 - x1;
			ptr2Right[y1][x1] = ptr2Array[y][x];
		}
	}
}

// This function rotates all entries of a 2D array to the left
void Array2D::rotateLeft(){
	// Don't forget to allocate the pointer
	ptr2Left = allocate2D();
	int x=0, y=0;
	for(int y1=0; y1<row; y1++){
		for(int x1=0; x1<coll; x1++){
			// I inverted all the x's and y's from the 
			// rotation right function
			if(y1==x1)
				y = y1;
			else
				y = x1; 
			x = coll - 1 - y1;
			ptr2Left[y1][x1] = ptr2Array[y][x];
		}
	}
}

// Function that takes a int** and prints the contents
void Array2D::print(int** ptr2D)
{
	for (int i=0; i<row ; i++) {
		for(int j=0; j<coll ; j++)
			cout << ptr2D[i][j] << "\t"; 
			// tabs are better than spaces :)
		cout << "\n\n";
	}
}

// Used to get the 2D array saved 
int** Array2D::getArray2D(){
	return ptr2Array;
}

// Used to get the right rotation 
int** Array2D::getRight2D(){
	return ptr2Right;
}

// Used to get the left rotation 
int** Array2D::getLeft2D(){
	return ptr2Left;
}
