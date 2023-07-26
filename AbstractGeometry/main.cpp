#include<iostream>
using namespace std;

enum Color
{
	console_red = 0xCC,	// 0x - Hexadecimal
	console_green = 0xAA,
	console_blue = 0x99,
	console_default = 0x07
};

class Shape
{
	Color color;
public:
	Shape(Color color) :color(color) {};
	virtual ~Shape() {};
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const=0;
};

class Square :public Shape
{
	static const int MIN_SIDE = 2;
	static const int MAX_SIDE = 50;
	double side;
public:
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
	~Square() {};
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side < MIN_SIDE)side = MIN_SIDE;
		if (side > MAX_SIDE)side = MAX_SIDE;
		this->side = side;

	}
	double get_area()const override
	{
		return side * side;
	}
	double get_perimeter()const override
	{
		return side * 4;
	}
	void draw()const override
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::console_blue);
	Square square(5, Color::console_red);

}