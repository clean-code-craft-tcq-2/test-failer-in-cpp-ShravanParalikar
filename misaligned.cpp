#include <iostream>
#include <assert.h>
#include <string>
#include <cstring>
#include <stdio.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

const char* getPairNumColorString(int majorColorId , int minorColorId) {

	int pairNum = (majorColorId)* 5 + minorColorId + 1;
	static char pairNumandColorPairStr[80];
	sprintf(pairNumandColorPairStr,"\t%d\t|%s\t|%s", pairNum,majorColor[majorColorId],minorColor[minorColorId]);
	return pairNumandColorPairStr;
}

int printColorMap()
{
    int majorColorIndex = 0;
	int minorColorIndex = 0;
    const int c_MaxIndex = 5;
	for(majorColorIndex = 0; majorColorIndex < c_MaxIndex; majorColorIndex++) {
		for(minorColorIndex = 0; minorColorIndex < c_MaxIndex; minorColorIndex++) {
			std::cout <<std::endl<<getPairNumColorString(majorColorIndex,minorColorIndex)<< std::endl;

		}
	}
	return majorColorIndex * minorColorIndex;
}

void colour_code_test(int majorColorId, int minorColorId ,std::string expectedPairNumberandColor)
{
	std::string actualPairNumberandColor = getPairNumColorString(majorColorId,minorColorId);
	assert(actualPairNumberandColor.compare(expectedPairNumberandColor) == 0);
}


int main() {
	int result = printColorMap();
	assert(result == 25);
    colour_code_test(0 , 0, "	1	|White	|Blue");
	colour_code_test(1 , 0, "	6	|Red	|Blue");
	colour_code_test(2 , 0, "	11	|Black	|Blue");
	colour_code_test(3 , 0, "	16	|Yellow	|Blue");
    colour_code_test(4 , 0, "	21	|Violet	|Blue");
    
	std::cout << "All is well (maybe!)\n";
	return 0;
}