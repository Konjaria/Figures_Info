#include<iostream>
#include <cmath>
#include "Figures.h"
#ifndef Assign4_Figures_Quadriliteral_h
#define Assign4_Figures_Quadriliteral_h
//preprocessor Directive
float degreesToRadians(float degrees)
{
	return degrees * PI / 180;
}
//shortly after for calculating the areas and some properties  For example  i am going 
//to use sine and cosine , things which in cmath takes radians as a parameters actually 
//I need them to be in degrees
bool isQuadrilateral(float fir, float seco, float thir, float four, float degr1, float degr2, float degr3, float degr4) {
	bool result = true;
	if (fir <= 0  || seco <=0 || thir <= 0  || four <= 0  || degr1 <=0  || degr2 <=0  || degr3 <=0  || degr4 <=0 || (degr1+degr2+degr3+degr4)!=360) {
		result = false;
	}
	
	return result;
}
//chechk by the properties if it is triangle or not Useful in a constructor for example
//based Class for all inherited Quadriliterals , called Quadriliterals  which is inherited by figures Based Class by itself
class Quadriliteral : public figures {
protected:
	float 
		first_side =1 , second_side=1 , third_side=1 , fourth_side=1 ,
		Angle1 =1, Angle2=1, Angle3=1, Angle4=1;
	    std::string type_of_figure;
public:

	Quadriliteral(float fir, float seco, float thir, float four, float degr1, float degr2, float degr3, float degr4, std::string ty) {
//with helping of booleanfinction i used it as a parameter in the constructor and valdiate Quadtiliteral
		if (!isQuadrilateral(fir,seco,thir,four,degr1,degr2,degr3,degr4)){
			return;
		}
		else {
			this->first_side = fir;
			this->second_side = seco;
			this->third_side = thir;
			this->fourth_side = four;
			this->Angle1 = degr1;
			this->Angle2 = degr2;
			this->Angle3 = degr3;
			this->Angle4 = degr4;
			this->type_of_figure = ty;
		}
	}
	virtual float Calculate_area() = 0; //pure virtual method makes  this class as an abstract class
//and also it is hard to calculate the area for all types of wuadriliterals
	 
	virtual float Calculate_perimeter() {
		return first_side + second_side + third_side;
	}
//virtual method for calculating the parameter

//traversing the elements
	virtual void display_properties(std::ostream&) = 0;
};
//class paralelogram - Quadriliteral - figures
class Paralelogram : public  Quadriliteral {

public:

	Paralelogram(float fir, float  sec, float gr1=10, float gr2=170, std::string t = " Paralelogram ")
		: Quadriliteral(fir, sec, fir, sec, gr1, gr2, gr1, gr2, t) {
	}

	virtual float Calculate_area() {
		//return this->second_side * this->first_side * sin(degreesToRadians(this->Angle1));
		return second_side * Calculate_height();
	}

	virtual float Calculate_perimeter() {
		return 2 * (first_side + second_side);
	}

	float Calculate_height() {
		return first_side * sin(degreesToRadians(Angle2));
	}
// Especially for the paralelogram i created an unique method that calculates the heigh

	virtual void display_properties(std::ostream& COUT) {
	
		if (!isQuadrilateral(first_side, second_side, third_side, fourth_side, Angle1, Angle2, Angle3, Angle4)){ 
			std::cout << "This is not a Quadriliteral" << std::endl; return;
		}
			
		int Angle_sign = 3322;
		int square = 253;

		std::cout << "\n\t***********************************************************************************\n";
		std::cout << "\n\tType Of Figure -------------------------------" << std::setw(4) << this->type_of_figure << std::endl;
		std::cout << "\n\tLength of First Side -------------------------" << std::setw(4) << this->first_side << " cm" << std::endl;
		std::cout << "\n\tLength of Second Side ------------------------" << std::setw(4) << this->second_side << " cm" << std::endl;
		std::cout << "\n\tAngle 1 --------------------------------------" << std::setw(4) << this->Angle1 << (char)Angle_sign << std::endl;
		std::cout << "\n\tAngle 2 --------------------------------------" << std::setw(4) << this->Angle2 << (char)Angle_sign << std::endl;
		std::cout << "\n\tArea -----------------------------------------" << std::setw(4) << Calculate_area() << " cm" << (char)square << std::endl;
		std::cout << "\n\tPerimeter ------------------------------------" << std::setw(4) << Calculate_perimeter() << " cm" << std::endl;
		std::cout << "\n\tHeight ---------------------------------------" << std::setw(4) << Calculate_height() << " cm" << (char)square << std::endl;
		std::cout << "\n\t***********************************************************************************\n";

	}
};
//class Rectangle - paralelogram - Quadriliteral - figures
class Rectangle : public Paralelogram {
public:

	Rectangle(float fir, float  sec, float gr1 = 90, std::string ty = " Rectangle ")
		: Paralelogram(fir, sec, gr1, gr1, ty) {
	}



	virtual float Calculate_area() {
		return Paralelogram::Calculate_area(); //sin(90 in rad)=1;
	}

	virtual float Calculate_perimeter() {
		return 2 * (first_side + second_side);
	}

	virtual void display_properties(std::ostream& COUT) {
		if (!isQuadrilateral(first_side, second_side, third_side, fourth_side, Angle1, Angle2, Angle3, Angle4))
		{std::cout << "Invalid Properties for The Quadrilateral" << std::endl;	return;
	}
		
		int Angle_sign = 3322;
		int square = 253;

		std::cout << "\n\t***********************************************************************************\n";
		std::cout << "\n\tType Of Figure -------------------------------" << std::setw(4) << this->type_of_figure << std::endl;
		std::cout << "\n\tLength of First Side -------------------------" << std::setw(4) << this->first_side << " cm" << std::endl;
		std::cout << "\n\tLength of Second Side ------------------------" << std::setw(4) << this->second_side << " cm" << std::endl;
		std::cout << "\n\tAngle ----------------------------------------" << std::setw(4) << this->Angle1 << (char)Angle_sign << std::endl;
		std::cout << "\n\tArea -----------------------------------------" << std::setw(4) << Calculate_area() << " cm" << (char)square << std::endl;
		std::cout << "\n\tPerimeter ------------------------------------" << std::setw(4) << Calculate_perimeter() << " cm" << std::endl;
		std::cout << "\n\t***********************************************************************************\n";
	}
};
//class Square - Rectangle - paralelogram - Quadriliteral - figures
class Square : public Rectangle {

public:

	Square(float fir, float gr1 = 90, std::string ty = " Square ")
		: Rectangle(fir, fir, gr1, ty) {
	}

	float Calculate_area() {
		return first_side * first_side;
	}

	float Calculate_perimeter() {
		return 4 * first_side;
	}

	void display_properties(std::ostream& CIN) {
		if (!isQuadrilateral(first_side, second_side, third_side, fourth_side, Angle1, Angle2, Angle3, Angle4))
		{std::cout << "Invalid Properties for The Quadrilateral" << std::endl;	return;
	}
			return;
		int Angle_sign = 3322;
		int square = 253;

		std::cout << "\n\t***********************************************************************************\n";
		std::cout << "\n\tType Of Figure -------------------------------" << std::setw(4) << this->type_of_figure << std::endl;
		std::cout << "\n\tLength of the Sides --------------------------" << std::setw(4) << this->first_side << " cm" << std::endl;
		std::cout << "\n\tAngle ----------------------------------------" << std::setw(4) << this->Angle2 << (char)Angle_sign << std::endl;
		std::cout << "\n\tArea -----------------------------------------" << std::setw(4) << Calculate_area() << " cm" << (char)square << std::endl;
		std::cout << "\n\tPerimeter ------------------------------------" << std::setw(4) << Calculate_perimeter() << " cm" << std::endl;
		std::cout << "\n\t***********************************************************************************\n";

	}

};
#endif
