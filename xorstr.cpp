#include <string>
#include <iostream>
#include <bitset>

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
