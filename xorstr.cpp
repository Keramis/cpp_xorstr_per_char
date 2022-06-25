#include <string>
#include <iostream>
#include <bitset>
#include <vector>

/*
Mission: To XOR each character of a string.
How-to:
-Get 8-bit representation of a char
-XOR the representation
-Get INT back from representation
-Get char from it
--DONE ^^ww^^

-Now, we:
-Do it for every character
-Make the return string have said characters
*/

std::string binaryXor(std::string binaryInput, std::string eightBitKey)
{
	std::string binaryReturn{"aaaaaaaa"}; //initialize
	for (int i = 0; i < 8; i++)
	{
		if (binaryInput[i] == eightBitKey[i])
		{
			binaryReturn[i] = '0';
		}
		else
		{
			binaryReturn[i] = '1';
		}
	}
	return binaryReturn;
}

char xorCharUsingBits(char input, std::string eightBitKey)
{
	int ichar = static_cast<int>(input); //convert char to int (for binary)
	std::string binary = std::bitset<8>(ichar).to_string(); //binary string

	std::string xor_binary = binaryXor(binary, eightBitKey); //xor'd binary
	int xor_int = std::stoi(xor_binary, nullptr, 2); //int from binary
	char xor_char = static_cast<char>(xor_int); //new char
	return xor_char;
}

std::string xorStringPerChar(std::string input, std::string eightBitKey)
{
	auto length = input.length();
	std::string retString = std::string(length, 'a'); //make the string have dummy chars (needed)
	for (int i = 0; i < length; i++)
	{
		retString[i] = xorCharUsingBits(input[i], eightBitKey);
	}
	return retString;
}
//xor's both ways!

/*
New mission:
-XOR using multiple keys.
How-to:
-Vector with said keys (user inputs)
-Get size of vector
-Loop through the string through the keys of the vector
-Save said strings, we're gonna need them to decrypt.
--
Make functions to:
-Encrypt
-Decrypt
...using a vector length and for loops.
*/

std::vector<std::string> userKeys{"10110010", "11001010", "00110101"}; //these will be custom-set.

std::string encrypted_string_iteration(std::string mainString, std::vector<std::string> inputKeys)
{
	std::string last_back = mainString;
	for (int i = 0; i < inputKeys.size(); i++)
	{
		last_back = (xorStringPerChar(last_back, inputKeys[i])); //element at end of vector
		//std::cout << last_back << '\n';
	}
	//std::cout << "Returning " << last_back << '\n';
	return last_back;
}
std::string decrypted_string_iteration(std::string encrypted_string, std::vector<std::string> inputKeys)
{
	std::string last_back = encrypted_string;
	for (size_t i = inputKeys.size(); i > 0; i--)
	{
		last_back = xorStringPerChar(last_back, inputKeys[i]);
		//std::cout << last_back << '\n';
	}
	//std::cout << "Returning " << last_back << '\n';
	return last_back;
}


int main()
{
	auto a = encrypted_string_iteration("This is an encryped string!", userKeys);
	std::cout << '\n\n';
	auto b = encrypted_string_iteration(a, userKeys);
}
