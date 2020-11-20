// Boris Au - 100660279
// INFR4320 Fall 2020
// Door Reader Class for reading and processing door conditions
#include "DoorReader.h"

// read the probabilities file
void DoorReader::readDoor(char* path)
{
	std::string file = std::string(path);
	// read probabilities file
	std::ifstream saveFile(file);
	std::string line;
	std::string word1, word2, word3, word4;
	// store data into vectors
	while (std::getline(saveFile, line))
	{
		std::stringstream ss(line);
		std::getline(ss, word1, '\t');
		std::getline(ss, word2, '\t');
		std::getline(ss, word3, '\t');
		std::getline(ss, word4, '\t');

		col1.push_back(word1);
		col2.push_back(word2);
		col3.push_back(word3);
		col4.push_back(word4);
	}
	saveFile.close();
}

// RNG roll determined by probabilities 
void DoorReader::rollDoor()
{
	// make sure order is Hot, Noisy, Safe, Probability
	swapOrder();
	// assign the probabilites 
	assignProbabilities();

	// reseed the time
	srand(time(0));

	// YYY = 1
	// YYN = 2
	// YNY = 3
	// YNN = 4
	// NYY = 5
	// NYN = 6
	// NNY = 7
	// NNN = 8
	// seed the 20 doors
	for (int x = 0; x < 20; x++)
	{
		// random number generator (odds based on the probabilities in the txt file)
		int door = rand() % 100;
		if (probability[door] == "YYY")
		{
			doorType.push_back(1);
		}
		else if (probability[door] == "YYN")
		{
			doorType.push_back(2);
		}
		else if (probability[door] == "YNY")
		{
			doorType.push_back(3);
		}
		else if (probability[door] == "YNN")
		{
			doorType.push_back(4);
		}
		else if (probability[door] == "NYY")
		{
			doorType.push_back(5);
		}
		else if (probability[door] == "NYN")
		{
			doorType.push_back(6);
		}
		else if (probability[door] == "NNY")
		{
			doorType.push_back(7);
		}
		else if (probability[door] == "NNN")
		{
			doorType.push_back(8);
		}
	}
}

// send door data to unity
int DoorReader::getDoor(int index)
{
	// return the door type based on index
	return doorType[index];
}

// make sure the order is hot, noisy, safe, and percentage
void DoorReader::swapOrder()
{
	// check if in order of hot, noisy, safe, percentage
	if (col1[0] != "Hot")
	{
		if (col2[0] == "Hot")
			col1.swap(col2);
		else if (col3[0] == "Hot")
			col1.swap(col3);
		else if (col4[0] == "Hot")
			col1.swap(col4);
	}
	if (col2[0] != "Noisy")
	{
		if (col3[0] == "Noisy")
			col2.swap(col3);
		if (col4[0] == "Noisy")
			col2.swap(col4);
	}
	if (col3[0] != "Safe Door")
	{
		if (col4[0] == "Safe Door")
			col3.swap(col4);
	}
}

// assigns probabilities based on text file
void DoorReader::assignProbabilities()
{
	// vector size of 100
	// read probability, multiply by 100 = number of door type to be placed into vector

	for (int i = 1; i <= 8; i++)
	{
		// set YYY numbers
		if (col1[i] == "Y" && col2[i] == "Y" && col3[i] == "Y")
		{
			int temp = 100 * std::stof(col4[i]);
			for (int x = 0; x < temp; x++)
			{
				probability.push_back("YYY");
			}
		}

		// set YYN numbers
		else if (col1[i] == "Y" && col2[i] == "Y" && col3[i] == "N")
		{
			int temp = 100 * std::stof(col4[i]);
			for (int x = 0; x < temp; x++)
			{
				probability.push_back("YYN");
			}
		}

		// set YNY numbers
		else if (col1[i] == "Y" && col2[i] == "N" && col3[i] == "Y")
		{
			int temp = 100 * std::stof(col4[i]);
			for (int x = 0; x < temp; x++)
			{
				probability.push_back("YNY");
			}
		}

		// set YNN numbers
		else if (col1[i] == "Y" && col2[i] == "N" && col3[i] == "N")
		{
			int temp = 100 * std::stof(col4[i]);
			for (int x = 0; x < temp; x++)
			{
				probability.push_back("YNN");
			}
		}

		// set NYY numbers
		else if (col1[i] == "N" && col2[i] == "Y" && col3[i] == "Y")
		{
			int temp = 100 * std::stof(col4[i]);
			for (int x = 0; x < temp; x++)
			{
				probability.push_back("NYY");
			}
		}

		// set NYN numbers
		else if (col1[i] == "N" && col2[i] == "Y" && col3[i] == "N")
		{
			int temp = 100 * std::stof(col4[i]);
			for (int x = 0; x < temp; x++)
			{
				probability.push_back("NYN");
			}
		}

		// set NNY numbers
		else if (col1[i] == "N" && col2[i] == "N" && col3[i] == "Y")
		{
			int temp = 100 * std::stof(col4[i]);
			for (int x = 0; x < temp; x++)
			{
				probability.push_back("NNY");
			}
		}

		// set NNN numbers
		else if (col1[i] == "N" && col2[i] == "N" && col3[i] == "N")
		{
			int temp = 100 * std::stof(col4[i]);
			for (int x = 0; x < temp; x++)
			{
				probability.push_back("NNN");
			}
		}
	}
}