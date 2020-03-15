#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n

// vector for stored numebrs
typedef std::vector<char> char_array;

// stored numbers as char
char_array charset()
{
	//Change this to suit
	return char_array(
		{ '1','2','3','4',
		'5','6','7','8','9',
		'1','2','3','4',
		'5','6','7','8','9',
		'1','2','3','4',
		'5','6','7','8','9',
		});
};

// given a function that generates a random character,
// return a string of the requested length
std::string random_string(size_t length, std::function<char(void)> rand_char)
{
	std::string str(length, 0);
	std::generate_n(str.begin(), length, rand_char);
	return str;
}

// generate our random number, then convert it to int
void generateRandom() {

		//   0) create the character set.
		//   yes, you can use an array here, 
		//   but a function is cleaner and more flexible
		const auto ch_set = charset();

		//1) create a non-deterministic random number generator      
		std::default_random_engine rng(std::random_device{}());

		//2) create a random number "shaper" that will give
		//   us uniformly distributed indices into the character set
		std::uniform_int_distribution<> dist(0, ch_set.size() - 1);

		//3) create a function that ties them together, to get:
		//   a non-deterministic uniform distribution from the 
		//   character set of your choice.
		auto randchar = [ch_set, &dist, &rng]() {return ch_set[dist(rng)]; };

		//4) set the length of the string you want and profit!        
		auto length = 9;

		//std::cout << random_string(length, randchar);

		std::string s = random_string(length, randchar);

		try
		{
			// change int i" to finalRandomNumber
			// change << i << to finalRandomNumber
			int i = std::stoi(s);
			std::cout << "Rand: " << i << '\n';

		}

		// any bad input being converted
		catch (std::invalid_argument const& e)
		{
			system("cls");
			std::cout << "Bad input: std::invalid_argument thrown" << '\n';
			std::cout << "Invalids: " << &e << std::endl;
		}

		catch (std::out_of_range const& e)
		{
			system("cls");
			std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
			std::cout << "Invalids: " << &e << std::endl;
		}

		system("pause");
	
}

int main()
{


	generateRandom();

	system("pause");
	return 0;
}