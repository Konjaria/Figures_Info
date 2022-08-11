#include <list>
#include <fstream>
#include <algorithm>
#include "Circle.h"
#include "Quadriliteral.h"
#include "Triangles.h"
//preprocesors
const int number_of_figures_from_file = 16;
//declaring the global const variable

template<typename T> void Test1();

void Test2();

void Test3();

void Test4();

template<typename T, typename U > T validate_decimals(T& number, U before_input)
{
	std::cout << before_input; std::cin >> number;

	while (std::cin.fail() || number <= 0) {
		std::cout << "\a\t\t\tError  :  -  number , that is more than zero Is not provided - " << std::endl;
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cout << "\t\t\t" << before_input; std::cin >> number;
	}
	return number;

}

float Calculate_Angles(float& a, float&  b, float& c,int which) {
	float result;
	if (which == 1) {
		result = (acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c)) * 180) / PI;
		return result;
	}

	else if (which == 2) // angle of a 
	{
		result = (acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c)) * 180) / PI;
		return result;
	}
	else if (which == 3)//angle of b
	{
		result = (acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)) * 180) / PI;
		return result;
	}//angle of c

		return 0.0;
 }  // cosine theorem

float Angles(float a, float  b, float c,int which) {
	float result;
	if (which == 1) {
		result = (acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c)) * 180) / PI;
		return result;
	}

	else if (which == 2) // angle of a 
	{
		result = (acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c)) * 180) / PI;
		return result;
	}
	else if (which == 3)//angle of b
	{
		result = (acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b)) * 180) / PI;
		return result;
	}//angle of c

		return 0.0;
 }  // cosine theorem

bool Check_if_Triangle_by_sides (float first_side, float second_side, float base) {
	return 
		first_side && second_side && base &&
		((first_side + second_side) > base) 
		&& ((first_side + base) > second_side)
		&& ((base + second_side) > first_side);
}  //checks if the triangle  exists by its sides

bool isEquilateral(float first_side, float second_side, float base) {
	if (Check_if_Triangle_by_sides(first_side, second_side, base))
		if ((first_side == second_side) && (second_side == base) && (first_side == base))
			return true;
	
	return false;
}  // check if the triangle is equilateral

bool isIsosceles(float a, float b, float c) { // by sides 
	if (Check_if_Triangle_by_sides(a, b, c))
	{
		if (a == b && b != c && a != c) // a b 
			return true;
		else if (a == c && c != b && a != b) // a c 
			return true;
		else if (b == c && c != a && b != a)
			return true;
		return false;
	}
	return false;
}  // checks if the triangle is isosceles or not

void User_Defined_For_Triangles(std::list <figures*>& figures_container, int number_of_iteration) {
	//5 rectangle  , 2 circle , 3 triangle 
	float side_a, side_b, side_c;
	float angle_a, angle_b, angle_c;
	int figure_numerator;
	for (int j = 0; j < number_of_iteration; j++) {
		figure_numerator = j + 1;
		std::cout << "\n\t -- > Figure number " << figure_numerator << std::endl;

		std::cout << " Please provide the triangle" << figure_numerator << " Properties " << std::endl;

		// first of all let's validate the angles 

		validate_decimals<float, std::string>(side_a, " Side  A : ");//170
		validate_decimals<float, std::string>(side_b, " Side  B : ");//10
		validate_decimals<float, std::string>(side_c, " Side  C : ");//10
		angle_a = Calculate_Angles(side_a, side_b, side_c, 1);
		angle_b = Calculate_Angles(side_a, side_b, side_c, 2);
		angle_c = Calculate_Angles(side_a, side_b, side_c, 3);

		std::cout << "\t\t\t --->  Triangle Rule : " << std::boolalpha << Check_if_Triangle_by_sides(side_a, side_b, side_c) << std::endl;// we need to be ensure that triangle rule condition mets there
		std::cout << "\t\t\t --->  Sum of The angles Condition : " << std::boolalpha << (angle_a + angle_b + angle_c == 180.0) << std::endl;
		//sum of angles should be equal to 180

		if (angle_a + angle_b + angle_c == 180.0) {



			std::cout << "Angle near A : " << angle_a << std::endl;
			std::cout << "Angle near B : " << angle_b << std::endl;
			std::cout << "Angle near C : " << angle_c << std::endl;

			// case : Equilateral Triangle 

			if (angle_a == 60 && angle_b == 60 && angle_c == 60) {
				std::cout << "\t\t\t --->  Triangle is  an Equilateral " << std::endl;
				figures_container.push_back(new Equilateral_triangle(side_a));
			}

			// case Isosceles Triangle

			else if ((angle_a == angle_b && angle_a != angle_c && angle_b != angle_c) ||
				(angle_a == angle_c && angle_a != angle_b && angle_c != angle_b)
				|| (angle_b == angle_c && angle_b != angle_a && angle_c != angle_a))
			{

				// case a = b 

				std::cout << "\t\t\t --->  Triangle is  an Isosceles " << std::endl;
				if (angle_a == angle_b && angle_a != angle_c && angle_b != angle_c) {
					try {
						//arbitrary 
						if (side_c == side_a || !Check_if_Triangle_by_sides(side_a, side_b, side_c))
							throw std::logic_error(" sides  doesn't match angles "); // if all of the angles is not equal to each other and by  themselves to 60 it is an error for such side length(es)
						else figures_container.push_back(new Isosceles_triangle(side_a, side_c, angle_a));
					}
					catch (...) {
						std::cout << "\t\t\t --->   Due to invalid input Unfortunately we can not construct  the triangle #" << figure_numerator << std::endl;
					}
				}

				// case a = c

				else if (angle_a == angle_c && angle_a != angle_b && angle_c != angle_b) {
					try {
						if (side_b == side_a || !Check_if_Triangle_by_sides(side_a, side_b, side_c))
							throw std::logic_error("Angles doesn't match"); // if all of the angles is not equal to each other and by  themselves to 60 it is an error for such side length(es)
						else figures_container.push_back(new Isosceles_triangle(side_a, side_b, angle_a));
					}
					catch (...) {
						std::cout << "\t\t\t --->   Due to invalid input Unfortunately we can not construct  the triangle #" << figure_numerator << std::endl;
					}
				}

				// case b = c

				else if (angle_b == angle_c && angle_b != angle_a && angle_c != angle_a) {
					try {
						if (side_a == side_b || !Check_if_Triangle_by_sides(side_a, side_b, side_c))
							throw std::logic_error("doesn't match");
						else figures_container.push_back(new Isosceles_triangle(side_b, side_a, angle_b));
					}
					catch (...) {
						std::cout << "\t\t\t --->   Due to invalid input Unfortunately we can not construct  the triangle #" << figure_numerator << std::endl;
					}
				}


			}

			// case arbitrary angles for arbitrary sides Scalene is targetting here

			else if (angle_a != angle_b && angle_b != angle_c && angle_a != angle_c)
			{
				std::cout << "\t\t\t --->  Triangle is  a Scalene " << std::endl;
				try {
					if (!Check_if_Triangle_by_sides(side_a, side_b, side_c) || isEquilateral(side_a, side_b, side_c) || isIsosceles(side_a, side_b, side_c))
						throw std::logic_error("undefined Triangle");
					// if all of the angles is not equal to each other and by  themselves to 60 it is an error for such side length(es)
					else figures_container.push_back(new Scalene(side_a, side_b, side_c, angle_a, angle_b, angle_c));
				}
				catch (...) {
					std::cout << "\a - - - - >  Due to invalid input Unfortunately we can not construct  the triangle #" << figure_numerator << std::endl;
				}
			}
		}
		else {
			std::cout << " \a Error  Possible Reason : Sum of the angles is not 180 - \n"
				<< "    Error  Possible Reason : Sides length(es) isn't compatible for Triangle Rule - \n";
		}


	}

}  // useful in test 1()
//for example where i have to ask the user the properties of the triangle

void User_Defined_Quadriliterals(std::list<figures*>& Figures, int number_of_tries = 1, int type = 0) {
	float side1, side2,anglea,angleb;
	for (int i = 0; i < number_of_tries;i++ ) {
		
		if (type == 1) {
			
				std::cout << "\n\t -- > Let's come with the properties of the Rectangle " << i + 1;
				validate_decimals<float, std::string>(side1, "\n\t -- > Length of the Rectangle  : ");
				validate_decimals<float, std::string>(side2, "\n\t -- > Height of the Rectangle  :");
				if (side1 != side2)
					Figures.push_back(new Rectangle(side1, side2));
				else if (side1 == side2)
					Figures.push_back(new Square(side1));
			
		}
		else  {
			std::cout << "\n\n\t -- > Let's come with the properties of the Parelelogram # " << i + 1;
			validate_decimals<float, std::string>(side1, "\n\t -- > Length of the Quadriliteral: ");
			validate_decimals<float, std::string>(side2, "\n\t -- > Heigh of the Quadriliteral:  ");
			validate_decimals<float, std::string>(anglea, "\n\t -- > Angle A:				       ");
			angleb = 180 - anglea;

			if (anglea == 90 && angleb == 90) {
				if (side1 == side2)
					Figures.push_back(new Square(side1));
				else if (side1 != side2)
					Figures.push_back(new Rectangle(side1, side2));
			}
			else {
				Figures.push_back(new Paralelogram(side1, side2, anglea, angleb));
			}
		}
				
	}
}
//for example where i have to ask the user the properties of the Quadrilateral

template<typename T>
void User_Defined_Circles(std::list<figures*>& Figures, int number_of_tries)
{
	for (int i = 0; i < number_of_tries; i++)
	{
		T radius1{};
		validate_decimals <T, std::string>(radius1, " Radius of the Circle  : ");
		std::cout << " Circle #" << i + 1 << " is created successfully " << std::endl;
		Figures.push_back(new Circle<T>(radius1));
	}
}
//for example where i have to ask the user the properties of the Circle(s)

std::ostream& operator<<(std::ostream& COUT, figures& figobj) {
	figobj.display_properties(COUT);
	return COUT;
}
//overloaded ostream operator

int main() {
	system("color A");
	std::cout << "*********** Test 1 Results ***********" << std::endl;
	Test1<float>();
	//Test1<int>();
	//Test1<char>();
	//Test1<float>();
	std::cout << "*********** Test 2 Results ***********" << std::endl;
	Test2();
	std::cout << "*********** Test 3 Results ***********" << std::endl;
	Test3();
	std::cout << "*********** Test 4 Results ***********" << std::endl;
	Test4();
	return 0;
}

template<typename T>
void Test1() {
	std::list <figures*> figures_container;
	User_Defined_For_Triangles(figures_container, 3);
	User_Defined_Quadriliterals(figures_container, 5, 1); // 1 strictly means that the angles in paralellogram is  90  ( for all 4 angles )
	User_Defined_Circles<T>(figures_container, 2);
	figures* ptr;
	for (std::list<figures*>::iterator it = figures_container.begin(); it != figures_container.end(); ++it) {
		ptr = *it;
		try {
			std::cout << "\n\t\t\t" << *ptr << std::endl;
			std::cout << "\n\n\n\n";
		}
		catch (...) { std::cout << "\n\t -- > Please check the properties is it correctly denoted ? " << std::endl; }
	}
	std::cin.clear(); std::cin.ignore(100000, '\n');

}

void Test2() {
	std::list<figures*> figures_cont;
	figures* ptr;
	// 3 different kinds of a triangles
	Isosceles_triangle tr1(12, 9, 30);  figures_cont.push_front(&tr1);
	Scalene tr2(9, 5, 7, 10, 80, 90); 	figures_cont.push_back(&tr2);
	Equilateral_triangle tr3(9); 		figures_cont.push_front(&tr3);
	// 3 different kinds of a foursides
	User_Defined_Quadriliterals(figures_cont, 3, 1);//1  as a last parameter for this function is set because of structly rectangles user defined approach 
	// for else tfings I am gonnaa invoke this function again with this parameter and the user will be able to provide angles as well
	//1 circle
	Circle<int>   c1(34);         figures_cont.push_front(&c1);
	Circle<float> c2(34);		  figures_cont.push_front(&c2);
	Circle<char>  c3('a');		  figures_cont.push_back(&c3);
	Circle<char>  c4(34);		  figures_cont.push_front(&c4);
	// I pushed with no logic one from the front and  some of them from back in order to use sorting algorithm
	//sort by their perimeters
	std::cout << "\n*************************************************************************\n" << std::endl;
	std::cout << "\n\t\t\t Sorted  " << std::endl;
	std::cout << "\n*************************************************************************\n" << std::endl;
	figures_cont.sort();
	//traverse the list elements
	std::for_each(figures_cont.begin(), figures_cont.end(), [](const auto& e) {
		std::cout << *e << std::endl;
		});
}

void Test3()
{
	
	std::ifstream fin("Figures.txt");
	figures* pointer;
	std::list<figures*>container;
	std::list<figures*>::iterator it;
	std::string figure_type;
 
	float a, b, c ,LA, LB, LC, radius;
	if (fin.is_open()) {
		for (int i = 0; i < number_of_figures_from_file; ++i) {
			fin >> figure_type;
			if      (figure_type == "Rectangle" || figure_type == "rectangle" || figure_type == "RECTANGLE") 
			{
				fin >> a >> b;
				if (a && b && (a>0) && (b> 0)) {
					if (a != b)
						container.push_front(new Rectangle(a, b, 90, figure_type));
					else if (a == b )
						container.push_front(new Square(a));
				}
				else {
					if(a && b)
					std::cerr << " \a\n\tThere was written in to the file:  -- > " << figure_type << " " << a << "  and  " << b << std::endl
							  << " \tError solution :  You have to provide nonnegative numbers for corresponding figure, Please make sure there is a number here " << std::endl;
					else {
						std::cerr << "\a\n\t --> For the figure " << figure_type << " You have to provide nonnegative number  " << std::endl;
						break;
					}
				}
			}
			else if (figure_type == "Square" or figure_type == "square" or figure_type == "SQUARE")
			{
				fin >> a ;
				if ((a > 0) && a)
				{
					container.push_back(new Square(a,90,figure_type));
				}
				else {
					if(a)
					std::cerr << "\a\n\t there was written --> "<<figure_type<<" " <<a<<"\n \tError solution : you have to provide nonnegative number here, Make sure there is a number here as well " << std::endl;
					else {
						std::cerr << "\a\n\t --> For the figure " << figure_type << " You have to provide nonnegative number " << std::endl;
						break;
					}
				}
			}
			else if (figure_type == "Paralelogram" || figure_type == "paralelogram" || figure_type == "PARALELOGRAM") {
				fin >> a >> b >> LA;
				LB = 180 - LA;
				if ((a and b and LA and LB ) && (a and b and LA and LB) >0 ) {
					if (((LA and LB) == 90) && (a != b)) {
						container.push_back(new Rectangle(a, b));
					}
					else if (((LA and LB) == 90) && (a == b)) {
						container.push_back(new Square(a));
					}
					else {
						container.push_back(new Paralelogram(a, b, LA, LB, figure_type));
					}
				}
				else {
					if(a && b && LA)
					std::cerr << "\a\n\t Into the file there was written "<<figure_type<<" Sides : "<<a<<","<<b<<" and Angle : "<< LA << "\n\t - - > \tError solution: there should be nonnegative numbers for length(es) and angles as well\n\tPlease take into account that sum of the angles should be 360 and make sure there is not anything else numbers" << std::endl;
					else {
						std::cerr << "\a\n\t --> For the figure " << figure_type << " You have to provide nonegative number  " << std::endl;
						break;
					}
				}
			}
			else if (figure_type == "Triangle" || figure_type == "triangle" || figure_type == "TRIANGLE") {
				fin >> a >> b >> c;
				LA = Calculate_Angles(a, b, c, 1);
				LB = Calculate_Angles(a, b, c, 2);
				LC = Calculate_Angles(a, b, c, 3);
				float sum = LA + LB + LC;
				if (Check_if_Triangle_by_sides(a, b, c) && (sum == 180))
				{
					
					if (isEquilateral(a, b, c)) {
						container.push_back(new Equilateral_triangle(a));
					}
					else if (isIsosceles(a, b, c)) {
						if (a == b && a != c && b != c)
							container.push_front(new Isosceles_triangle(a, c, LA));
						else if (a == c && a != b && c != b)
							container.push_back(new Isosceles_triangle(a, b, LA));
						else if (b == c and b != a && c != a)
							container.push_front(new Isosceles_triangle(b, a, LB));
					}
					else container.push_back(new Scalene(a, b, c, LA, LB, LC));
				}
				else {
					if(a && b && c)
					std::cerr << "\a\n\t There was written into a file  --> "<<figure_type<<" "<<a<< ","<<b<<","<<c<< "\n\t\tError solution: There should be prompted nonnegative numbers(make sure you have a numbers) \n\t The sides should be met with the Triangle Rule conditions as well " << std::endl;
					else {
						std::cerr << "\a\n\t --> For the figure " << figure_type << " You have to provide nonnegative number " << std::endl;
						break;
					}
				}
			}
			else if (figure_type == "Circle" || figure_type == "circle" || figure_type == "CIRCLE") {
				fin >> radius;
				if (radius and radius > 0)
					container.push_back(new Circle<float>(radius, figure_type));//for all circumstances i set float for thegeneric Circle class
				else {
					if(radius)
					std::cerr << "\a\n There was written:  --> "<<figure_type<<" "<<radius<<"\n\t You have to provide nonegative number for the circle Radius " << std::endl;
					else if (!radius) {
						std::cerr << "\a\n\t --> For the figure " << figure_type << " You have to provide nonegative number for the circle Radius " << std::endl;
						break;
					}
				}
			}
			else {
				std::cout <<"\n\t " << figure_type << " --> Undefined figure " << std::endl;
				break;
			}
		}
		std::cout << "\n\t  Reading from the file Ends up here" << std::endl;
		for (it = container.begin(); it != container.end(); ++it) {
			pointer = *it;
			std::cout << *pointer << std::endl;
		}
	}
	else  std::cerr << "\a\n\t Oops! something went wrong " << std::endl;
	
}

void Test4()
{
	std::list<figures*> figures_content;
	//test isosceles triangle for three times
	Isosceles_triangle is1 (12,23,Angles(12,12,23,1));      figures_content.push_back (&is1);
	Isosceles_triangle is2 (12,23,Angles(12,12,23,2));		figures_content.push_back (&is2);
	Isosceles_triangle is3 (-12,24,Angles(-12,-12,24,1));	figures_content.push_back (&is3);  // is not ok
	// test equilateral triangle for three times
	Equilateral_triangle eq1(-6);       figures_content.push_back (&eq1);// not ok
	Equilateral_triangle eq2(6.e3);		figures_content.push_back (&eq2);// ok
	Equilateral_triangle eq3(64);		figures_content.push_back (&eq3);//ok
	// test Scalene for three times
	Scalene sc1(12,13,15,Angles(12,13,15,1), Angles(12, 13, 15, 2), Angles(12, 13, 15, 3));//ok
	Scalene sc2(1.e3,78,100,Angles(1.e3,78,100,1), Angles(1.e3,78,100, 2), Angles(1.e3,78,100, 3)); //not ok
	Scalene sc3(-12,23,45,Angles(-12,23,45,1), Angles(-12, 23, 45, 2), Angles(-12, 23, 45, 3)); // not ok

	figures_content.push_back(&sc1);
	figures_content.push_back(&sc2);
	figures_content.push_back(&sc3);

	//// test Paralelogram for three times
	Paralelogram pr1(-12,-12,90);    figures_content.push_back (&pr1);// not ok
	Paralelogram pr2(12,0,60);		 figures_content.push_back (&pr2);//not ok
	Paralelogram pr3(12,24,30);		 figures_content.push_back (&pr3);//ok
	//// test Rectangle for three times
	Rectangle rec1(-12,-12);    figures_content.push_back (&rec1);//not ok
	Rectangle rec2(-12,24);		figures_content.push_back (&rec2);//not ok
	Rectangle rec3(12,78);		figures_content.push_back (&rec3);//ok
	//// test Square for three times
	Square sqr1(0);    figures_content.push_back (&sqr1);//not ok
	Square sqr2(-1);   figures_content.push_back (&sqr2);//not ok
	Square sqr3(1);	   figures_content.push_back (&sqr3);//ok
	//traverse the elements
	for (std::list<figures*>::iterator it = figures_content.begin(); it != figures_content.end(); ++it) {
		std::cout << **it << std::endl;
	}
}