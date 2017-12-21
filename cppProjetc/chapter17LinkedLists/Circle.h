#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
	public:
		//constructor
		Circle();
		//overloaded constructor
		Circle(int radius);

		//destructor
		~Circle();

		//getters
		int getCircleCount() const;
		int getCircleRadius() const;
		//setters
		void setCircleRadius(int radius);
		//exception class
		class ErrorAllocatingMemory
		{
		private:
			int value;
		public:
			ErrorAllocatingMemory(int val)
			{
				value = val;
			}
			int getValue()const
			{
				return value;
			}
		};

		Circle *nextNodeLink;//points to the next circle object in the list if there is one; else it points to NULL
	private:
		int circleRadius;//make this a double if it makes you feel better
		static int circleCount;//keeps track of the number of circle objects
};
#endif
