#include <iostream>
#include <iomanip>
#include "Figures.h"
#ifndef Assign4_Figures_Triangles_h
#define Assign4_Figures_Triangles_h
//global function useful everywhere
bool isTriangle(float first_side, float second_side, float third_side, float angle1, float angle2, float angle3) {
	if ( first_side > 0 && second_side > 0 && third_side > 0 && angle1 > 0 && angle2 > 0 && angle3 > 0)
	{
		// The sides of a triangle rule asserts that the sum of
		// the lengths of any two sides of a triangle has to be greater than the length of the third side.Mar 9, 2021
		if ( ((first_side + second_side) > third_side) &&  ((first_side + third_side) > second_side)  &&   ((second_side + third_side ) > first_side)) {
			if (angle1 + angle2 + angle3 == 180) {

				if ((first_side == second_side ) &&  (first_side == third_side)  && ( second_side == third_side))
					//if we say that triangle is equilateral all the angles should be 60
				{
					if (angle1 == 60 && angle2 == 60 && angle3 == 60)
						return true;
					return false;
				}
				else if ( ( first_side == second_side ) &&  ( first_side != third_side ) && (second_side != third_side) ) // a b
					// if we say that some two side of triangle is equal to each other but not all of them are equal we are targeting the isosceles triangle
				{
					if (angle1 == angle2 && angle1 != angle3 && angle2 != angle3)
						return true;
					return false;
				}
				else if ( ( second_side == third_side ) && ( second_side != first_side ) &&  ( third_side != first_side )) // b c 
				{
					if (angle2 == angle3 && angle2 != angle1 && angle3 != angle1)
						return  true;
					return false;
				}
				else if ( ( first_side == third_side ) && (  first_side != second_side ) && ( third_side != second_side )) // a c 
				{
					if ( ( angle1 == angle3 )&& (angle1 != angle2) && (angle3 != angle2))
						return  true;
					return false;
				}
				//if we gonna say that the triangle is iscolene none of the angles should be equal to each other
				else if (first_side != second_side && first_side != third_side && second_side != third_side)
				{
					if (angle1 != angle2 && angle1 != angle3 && angle2 != angle3)
						return true;
					return false;
				}
			}
			else 
				return false;
		}
		else 
			return false; 
	}
	else  return false;
	return false;
	}
//checking the properties of the triangle useful in the constructor(s)
//class triangle -> figures 
class triangle : public figures {
protected:
	float first_side = 1, second_side = 1, base =1 , Angle1  , Angle2  , Angle3  ;
	//initialize some member variable
	std::string type_of_figure;

public:

	triangle(float first, float second, float Base, float gr1, float gr2, float gr3, std::string Type) {
//
//			Triangle Rule 
// 
// The sum of the lengths of any two sides of a triangle is greater than the length of the third side.
//validate  first
		if (!isTriangle(first,second,Base,gr1,gr2,gr3))
		{
			std::cout << " Such type of Triangle doesn't exists , Please Check the properties " << std::endl;
			return;
		}
		else {
			this->first_side = first;
			this->second_side = second;
			this->base = Base;
			this->Angle1 = gr1;
			this->Angle2 = gr2;
			this->Angle3 = gr3;
			this->type_of_figure = Type;
		}
	}

	virtual float Calculate_area_of_triangles() {
		return Calculate_area();
	}

	virtual float Calculate_area() {
		float half_parameter = (first_side + second_side + base) / 2;
		return  sqrt(half_parameter * (half_parameter - first_side) * (half_parameter - second_side) * (half_parameter - base));
	} // pure virtual because i have three types of a triangles and three different  sometimes the same calculations 

	virtual float Calculate_perimeter() {
		return first_side + second_side + base;
	}

	//for not to write a lot i Have the same boolean that was upward as a global but this one has no paramters  you see so ,it is more convenient for 
	//me when manipualting into the class
	bool check_Triangle_Properties() {
		return
			!first_side || !second_side || !base || !Angle1 || !Angle2 || !Angle3 ||
			((Angle1 + Angle2 + Angle3) != 180) || ((Angle1 + Angle2 + Angle3) <= 0) ||
			((first_side + second_side) <= base) || ((first_side + base) <= second_side) || ((base + second_side) <= first_side);
	}

	void  check_tyoe_of_triangle() {
		//try - throw - catch used for exception error handling
		try {
			if ((Angle1 == 90 || Angle2 == 90 || Angle3 == 90)) {
				if ((Angle1 + Angle2 + Angle3 != 180) || Angle1 == 0 || Angle2 == 0 || Angle3 == 0)
					throw std::logic_error(" \a Such Traingle doesn't exists");
				std::cout << " Righ angled";
			}
			else if ((Angle1 > 90 && Angle1 < 180) || (Angle2 > 90 && Angle2 < 180) || (Angle3 > 90 && Angle3 < 180)) {
				if ((Angle1 + Angle2 + Angle3 != 180) || Angle1 == 0 || Angle2 == 0 || Angle3 == 0)
					throw " \a Such Traingle doesn't exists";
				std::cout << " Obtuse-angled ";
			}
			else if ((Angle1 > 0 && Angle1 < 90) && (Angle2 > 0 && Angle2 < 90) && (Angle3 > 0 && Angle3 < 90)) {
				if ((Angle1 + Angle2 + Angle3 != 180) || Angle1 == 0 || Angle2 == 0 || Angle3 == 0)
					throw " \a Such Traingle doesn't exists";
				std::cout << " Acute-angled ";
			}
		}
		catch (const char* e) {
			std::cerr << e << std::endl;
		}
	}

	virtual void display_properties(std::ostream&) = 0;

};
//class  isosceles_triangeles -> triangle -> figures 
class Isosceles_triangle :  public   triangle {
public:

	Isosceles_triangle(float first_and_second, float Base, float gr_bases, std::string p = " Isosceles Triangle ") :
		triangle(first_and_second, first_and_second, Base, gr_bases, gr_bases,(180-2*gr_bases), p) {
		//in this constructor I am not taking into account the cosine theorem I am manipulating after that
	// I took into account that the user collects the correct data 
	
}

	float Calculate_area() {
		return triangle::Calculate_area();
	}

	float Calculate_perimeter() {
		return 2 * triangle::first_side + base;
	}

	void display_properties(std::ostream&)
	{
		if (!isTriangle(this->first_side, this->second_side, this->base, this->Angle1, this->Angle2, this->Angle3))
			return;
		int Angle_sign = 3322;
		int square = 253;

		std::cout <<"\n\tType Of Figure -------------------------------"<<std::setw(10); check_tyoe_of_triangle(); std::cout<< this->type_of_figure << std::endl;
		std::cout <<"\n\tLength(es) of the Sides Near Bases -----------"<<std::setw(10)<<this->first_side << " cm" << std::endl;
		std::cout <<"\n\tLength of the Base ---------------------------"<<std::setw(10)<<this->base << " cm" << std::endl;
		std::cout <<"\n\tAngle Near Bases------------------------------"<<std::setw(10)<<this->Angle1 << (char)Angle_sign << std::endl;
		std::cout <<"\n\tAngle to The summit---------------------------"<<std::setw(10)<<this->Angle3 << (char)Angle_sign << std::endl;
		std::cout <<"\n\tArea -----------------------------------------"<<std::setw(10)<<Calculate_area() << " cm" << (char)square << std::endl;
		std::cout <<"\n\tPerimeter ------------------------------------"<<std::setw(10)<<Calculate_perimeter() << " cm" << std::endl;
		std::cout <<"\n\tTriangle Rule Necessary Condition-------------"<<std::setw(10)<<std::boolalpha << !check_Triangle_Properties() << std::endl;
	}

	float Calculate_area_of_triangles() {
		return triangle::Calculate_area();
	} // pure virtual because i have three types of a triangles and three different  sometimes the same calculations 

	bool check_Triangle_Properties() {
		return
			!triangle::first_side || !triangle::second_side || !triangle::base || !triangle::Angle1 || !triangle::Angle2 || !triangle::Angle3 ||
			((triangle::Angle1 + triangle::Angle2 + triangle::Angle3) != 180) || ((triangle::Angle1 + triangle::Angle2 + triangle::Angle3) <= 0) ||
			((triangle::first_side + triangle::second_side) <= triangle::base) || ((triangle::first_side + triangle::base) <= triangle::second_side) || ((triangle::base + triangle::second_side) <= triangle::first_side);
	}


};
//class  equilateral_triangeles -> triangle -> figures 
class Equilateral_triangle :  public triangle  {

public:

	Equilateral_triangle(float side, float gr3 = 60.0, std::string T = " Equilateral Triangle ")
		: triangle(side, side, side, gr3, gr3, gr3, T) {

	}

	float Calculate_area_of_triangles() {
		return (sqrt(3) * pow(base, 2))/ 4;
	}

	float Calculate_area() {
		return triangle::Calculate_area();
	}

	float Calculate_perimeter() {
		return 2 * triangle::first_side + base;
	}

	virtual void display_properties(std::ostream& Cout)
	{
		if (!isTriangle(this->first_side, this->second_side, this->base, this->Angle1, this->Angle2, this->Angle3))
			return;
		int Angle_sign = 3322;
		int square = 253;
		std::cout << "\n\t***********************************************************************************\n";
		std::cout << "\n\tType Of Figure -------------------------------" << std::setw(10); check_tyoe_of_triangle(); std::cout << this->type_of_figure << std::endl;
		std::cout << "\n\tLength(es) of the Sides ----------------------" << std::setw(10) << this->first_side << " cm" << std::endl;
		std::cout << "\n\tAngle ----------------------------------------" << std::setw(10) << this->Angle1 << (char)Angle_sign << std::endl;
		std::cout << "\n\tArea -----------------------------------------" << std::setw(10) << Calculate_area() << " cm" << (char)square << std::endl;
		std::cout << "\n\tPerimeter ------------------------------------" << std::setw(10) << Calculate_perimeter() << " cm" << std::endl;
		std::cout << "\n\tTriangle Rule Necessary Condition-------------" << std::setw(10) << std::boolalpha << !check_Triangle_Properties() << std::endl;
		std::cout << "\n\t***********************************************************************************\n";

	}

	bool check_Triangle_Properties() {
		return
			!triangle::first_side || !triangle::second_side || !triangle::base || !triangle::Angle1 || !triangle::Angle2 || !triangle::Angle3 ||
			((triangle::Angle1 + triangle::Angle2 + triangle::Angle3) != 180) || ((triangle::Angle1 + triangle::Angle2 + triangle::Angle3) <= 0) ||
			((triangle::first_side + triangle::second_side) <= triangle::base) || ((triangle::first_side + triangle::base) <= triangle::second_side) || ((triangle::base + triangle::second_side) <= triangle::first_side);
	}

};
//class scalene -> triangle
class Scalene :  public triangle {
public:
	Scalene
	(float le, float base, float thi, float gr1, float gr2, float gr3, std::string t = " Scalene Triangle ")
		: triangle(le, base, thi, gr1, gr2, gr3, t) {
	}

	float Calculate_area() {
		return triangle::Calculate_area();
	}

	float Calculate_perimeter() {
		return  triangle::first_side + triangle::second_side + triangle::base;
	}

	void display_properties(std::ostream&) 
		{
			if (!isTriangle(this->first_side, this->second_side, this->base, this->Angle1, this->Angle2, this->Angle3))
				return;
			int Angle_sign = 3322;
			int square = 253;
			std::cout << "\n\t***********************************************************************************\n";
			std::cout << "\n\tType Of Figure -------------------------------" << std::setw(10); check_tyoe_of_triangle(); std::cout << this->type_of_figure << std::endl;
			std::cout << "\n\tLength of First Side -------------------------" << std::setw(10) << this->first_side << " cm" << std::endl;
			std::cout << "\n\tLength of Second Side ------------------------" << std::setw(10) << this->second_side << " cm" << std::endl;
			std::cout << "\n\tLength of Third Side -------------------------" << std::setw(10) << this->base << " cm" << std::endl;
			std::cout << "\n\tAngle 1 --------------------------------------" << std::setw(10) << this->Angle1 << (char)Angle_sign << std::endl;
			std::cout << "\n\tAngle 2 --------------------------------------" << std::setw(10) << this->Angle2 << (char)Angle_sign << std::endl;
			std::cout << "\n\tAngle 3 --------------------------------------" << std::setw(10) << this->Angle3 << (char)Angle_sign << std::endl;
			std::cout << "\n\tArea -----------------------------------------" << std::setw(10) << Calculate_area() << " cm" << (char)square << std::endl;
			std::cout << "\n\tPerimeter ------------------------------------" << std::setw(10) << Calculate_perimeter() << " cm" << std::endl;
			std::cout << "\n\tTriangle Rule Necessary Condition-------------" << std::setw(10) << std::boolalpha << !check_Triangle_Properties() << std::endl;
			std::cout << "\n\t***********************************************************************************\n";

		}

	float Calculate_area_of_triangles() {
		return triangle::Calculate_area();
	} // pure virtual because i have three types of a triangles and three different  sometimes the same calculations 

	bool check_Triangle_Properties() {
		return
			!triangle::first_side || !triangle::second_side || !triangle::base || !triangle::Angle1 || !triangle::Angle2 || !triangle::Angle3 ||
			((triangle::Angle1 + triangle::Angle2 + triangle::Angle3) != 180) || ((triangle::Angle1 + triangle::Angle2 + triangle::Angle3) <= 0) ||
			((triangle::first_side + triangle::second_side) <= triangle::base) || ((triangle::first_side + triangle::base) <= triangle::second_side) || ((triangle::base + triangle::second_side) <= triangle::first_side);
	}
};
#endif // !Triangles_h