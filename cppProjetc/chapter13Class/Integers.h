
// Specification file for the Integers class.
#ifndef INTEGERS_H
#define INTEGERS_H
using namespace std;

class Integers
{
	private:
		int *list; // Pointer to the array.
	public:
		Integers(); // Constructor
		~Integers(); // Destructor
		void setUserEntry();
		bool validate(string); 
		void displayIntegers() const;
		void getLargestSmallestIntegers() const;
};
#endif
