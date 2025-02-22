#include <iostream>
#include <vector>
#include <random>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n

typedef std::vector<char> char_array;

int loopValue = 70;

char_array charset()
{
	//Change this to suit
	return char_array(
		{ '0','1','2','3','4',
		'5','6','7','8','9',
		'A','B','C','D','E','F',
		'G','H','I','J','K',
		'L','M','N','O','P',
		'Q','R','S','T','U',
		'V','W','X','Y','Z',
		'0','1','2','3','4',
		'5','6','7','8','9',
		'A','B','C','D','E','F',
		'G','H','I','J','K',
		'L','M','N','O','P',
		'Q','R','S','T','U',
		'V','W','X','Y','Z'
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

void giveRandom() {
	
	for (int i = 0; i < loopValue; i++) {
		//0) create the character set.
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
		auto length = 7;
		std::cout << "-";
		std::cout << random_string(length, randchar);


	}
	//system("cls");
}

int main()
{

	//system("mode 2000, 30");
	
	for (int i = 0; i < 10; i++) {

		giveRandom();
		std::cout << "\n";
	
	}

	system("pause");
	return 0;
}