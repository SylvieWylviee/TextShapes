#include<iostream>

void inline PrintLineElements(double lineLength){
	for(double lineElement=lineLength;lineElement>=1;lineElement--)
		std::cout<<'0';
	std::cout<<'\n';
}

void PrintTextTriangle(double triangleHeight,double triangleWidth){
	double triangleSlope=triangleHeight/triangleWidth;
	
	for(double lineLength=triangleSlope;lineLength<=triangleHeight;lineLength+=triangleSlope)
		PrintLineElements(lineLength);
	
	for(double lineLength=triangleHeight-triangleSlope;lineLength>=1;lineLength-=triangleSlope)
		PrintLineElements(lineLength);
}

int main(){
	double triangleHeight=1,triangleWidth=1;
	
	std::cout<<"Triangle Height: ";
	std::cin>>triangleHeight;
	
	std::cout<<"Triangle Width: ";
	std::cin>>triangleWidth;
	std::cout<<'\n';
	
	PrintTextTriangle(triangleHeight,triangleWidth);
	return 0;
}

