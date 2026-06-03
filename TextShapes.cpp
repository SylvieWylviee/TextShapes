#include<iostream>
#include<vector>
#include<cmath>

const char asciiPixel=219;

void inline PrintLine(const double length){
	for(double character=length;character>=1;character--)
		std::cout<<asciiPixel<<asciiPixel;
	std::cout<<'\n';
}

void PrintTextTriangle(const double height,const double width){
	const double slope=height/width;
	double lineLength;
	std::vector<double>lineLengths;
	
	for(double line=0;line<=height;line++){
		lineLength=line*slope;
		lineLengths.push_back(lineLength);
		PrintLine(lineLength);
	}
	
	for(int element=lineLengths.size()-2;element>=1;element--)
		PrintLine(lineLengths[element]);
}

void PrintTextHalfEllipse(const double radius,const double semiMajorAxis,const double semiMinorAxis){
	const double lineCount=radius*semiMinorAxis;
	double lineLength;
	std::vector<double>lineLengths;
	
	for(double line=lineCount;line>=1;line--){
		lineLength=(semiMajorAxis*sqrt((radius*semiMinorAxis+line)*(radius*semiMinorAxis-line)))/semiMinorAxis;
		lineLengths.push_back(lineLength);
		PrintLine(lineLength);
	}
	
	for(int element=lineLengths.size()-1;element>=1;element--)
		PrintLine(lineLengths[element]);
}

int main(){
	PrintTextTriangle(10,10);
	PrintTextHalfEllipse(10,1,1);
	return 0;
}
