/* David Bush, Rotating Array Assignment 1, CS 121, Bolden, 9/26/20
------------------------------------------------------------------
------------------------ Array2D Header -------------------------
------------------------------------------------------------------
*/

using namespace std;

//----------------------- Class for Array2D ---------------------
class Array2D {
private:
	int row, coll;
	int** ptr2Array;
	int** ptr2Right;
	int** ptr2Left;
public:
	Array2D(); // constructor
	~Array2D(); // destructor
	void readFile(string);
	int** allocate2D();
	void delete2D(int**);
	void rotateRight();
	void rotateLeft();
	void print(int**);
	int** getArray2D();
	int** getRight2D();
	int** getLeft2D();
};
