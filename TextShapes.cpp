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
	int textShape;
	double height,width,
		radius,semiMajorAxis,semiMinorAxis;
	
	std::cout<<"0: Text triangle\n1: Text half-ellipse\n";
	std::cin>>textShape;
	
	switch(textShape){
		case 0:
			default:
				std::cout<<"\nEnter height and width: ";
				std::cin>>height>>width;
				PrintTextTriangle(height,width);
				break;
		case 1:
			std::cout<<"\nEnter radius, semi-major axis, and semi-minor axis: ";
			std::cin>>radius>>semiMajorAxis>>semiMinorAxis;
			PrintTextHalfEllipse(radius,semiMajorAxis,semiMinorAxis);
			break;
	}return 0;
}
