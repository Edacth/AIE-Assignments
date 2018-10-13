#include<iostream>
int main()
{
	// Celsius to Fahrenheit)
	/*
	float degCelsius = 0.0f;
	float degFahrenheit = 0.0f; // Hint: Your code should modify this variable.\

	std::cout << "Enter your degrees in Celcius" << std::endl;
	std::cin >> degCelsius;

	degFahrenheit = degCelsius * 9 / 5 + 32;

	std::cout << "Celsius to Fahrenheit)" << std::endl;
	std::cout << "Celsius:    " << degCelsius << std::endl;
	std::cout << "Fahrenheit: " << degFahrenheit << std::endl;
	*/


	/*
	float a, b, c, d, e;    // Modify these variables below.
	float avg;              // Modify this variable below.
	avg = a = b = c = d = e = 0.0f; // Initialize all to zero.

	std::cout << "Please enter your five numbers" << std::endl;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	std::cin >> e;

	avg = (a + b + c + d + e) / 5;

	std::cout << "Average of Five)" << std::endl;
	std::cout << a << "," << b << "," << c << "," << d << "," << e << std::endl;
	std::cout << "avg: " << avg << std::endl;
	*/


	// Conforming to Conventions)
	/*
	int age;
	int bullet_count;
	float dog_years;
	int qty;
	float shield_value;
	float defense_matrix_cooldown;
	int red_armor_value;
	float red_armor_ratio;
	int happiness;
	int gandhi_aggression;
	*/

	/*
	//Number Swap (difficulty up)
	int A = 10;
	int B = 3;

	A += B;
	B = A - B;
	A = A - B;
	std::cout << A << " " << B << std::endl; 
	*/

	
	//Handling errors
	int number = -1;

	std::cout << "Enter a number" << std::endl;
	std::cin >> number;
	while (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "That's not a number, you nice indevidual" << std::endl;

		std::cout << "Enter a number" << std::endl;
		std::cin >> number;
	}
	std::cout << "You entered: " << number << std::endl;
	


	return 0;
}