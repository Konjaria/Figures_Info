#include "Figures.h"
#ifndef Assign4_Figures_Circle_h
#define Assign4_Figures_Circle_h
//preprocessor directives 
// 
// all of the Circles are the figures themselves so Clsss Circle is derived from the Base Figures class


template<typename T> class Circle : public figures {
// private access specifiyer
private:
// generic specification for  class  Circle gives me the possibility to use generic data type here as well
	T radius; std::string type_of_figure;
//public access specifyer	
public: 
//circle explicit value constructor
		Circle(T r = 0, std::string ka = "Circle") {
//validating the parameters
		if (!r || r<=0 ) {
			std::cout << "\n\tError Reason : Invalid Parameter for The Circle  \n\t" << std::endl;
			return;}
// if provided radius is less than zero or not a floating number at all   it's an error
		else {
			this->radius = r;
			this->type_of_figure = ka;
			}
		}
//method to calculate Area
			float Calculate_area() {
		return PI * radius * radius;
	}
//method to calculate Perimeter
					float Calculate_perimeter() {
		return 2 * PI * radius;
	}
//function to traverse all the elements of the Figure
						void display_properties(std::ostream&) {
// with helping of ASCII table I  declared  an integer number and fincally use them as a characters 
							
							int Angle_sign = 3322;
							int square = 253;
							std::cout << "\n\t***********************************************************************************\n";
							std::cout << "\n\tType Of Figure -------------------------------" << std::setw(4) << this->type_of_figure << std::endl;
							std::cout << "\n\tRadius ---------------------------------------" << std::setw(4) << this->radius << " cm" << std::endl;
							std::cout << "\n\tArea -----------------------------------------" << std::setw(4) << Calculate_area() << " cm" << (char)square << std::endl;
							std::cout << "\n\tCircumference --------------------------------" << std::setw(4) << Calculate_perimeter() << " cm" << std::endl;
							std::cout << "\n\t***********************************************************************************\n";

						}
};
#endif
