#ifndef Assign4_Figures_Figures_h
#define Assign4_Figures_Figures_h
#define PI 3.14159265358979323846 // pi number  defined say so 
#include <iostream>
#include<iomanip>
class figures {
public:

	virtual float Calculate_area() = 0;

	virtual float Calculate_perimeter() = 0;

	virtual void display_properties(std::ostream&) = 0;

};
#endif // !Figures_h

