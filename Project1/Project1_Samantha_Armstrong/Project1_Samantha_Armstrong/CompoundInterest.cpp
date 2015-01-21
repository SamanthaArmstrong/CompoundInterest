 /**************************************************************************************
 Title:      Compound Interest      
 Programmer: Samantha Armstrong     
 Course:     CSCI 240     
 Instructor: Prof. Ringenberg     
 Due Date:   September 16, 2014     

 Description: This Program will read the data from a file called stock_data.txt then, 
	calculate compound interest given a company name, a quantity of stock purchased, 
	an original purchase price, a year 1 growth percentage, and a year 2 growth percentage;
	and derive a year 2 ending value for that stock and output the data to a file 
	called stock_statement.txt.
 **************************************************************************************/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

int main() {
	ifstream inData;
	ofstream outData;
	string	companyName;
	double	stockVal;
	int		stockQuantity;
	double	year1GrowthPct;
	double	year2GrowthPct;
	double	totalPurchaseVal;
	double	year1EndVal;
	double	year2EndVal;
	double	changeInVal;
	double	pctChangeInVal;
	
	//input read from a file called stock_data.txt
	inData.open("stock_data.txt");

	if (!inData){
		cout << "Error reading in file." << endl;
    }

	//output read into a file called stock_statement.txt
	outData.open("stock_statement.txt");

	if (!outData){
		cout << "Error reading in file." << endl;
    }

	//Read in the stock company name
	getline(inData, companyName);

	//Read in the purchase price (individual stock)
	inData >> stockVal;

	//Read in how many stocks purchased
	inData >> stockQuantity;

	//Read in the first year percent growth
	inData >> year1GrowthPct;

	//Read in the second year percent growth
	inData >> year2GrowthPct;

	//Close the input file
	inData.close();
	

	outData << "-----------------------------------------------" << endl;
	outData << "|" << "Stock name:" << setfill('.') 
		    << setw(34) << companyName << "|" << endl;

	outData << setprecision(2) << fixed;
	outData << "|" << "Purchase Price ($):" << setfill('.') 
		    << setw(26) << stockVal << "|" <<endl;

	outData << "|" << "Quantity Purchased:" << setfill('.') 
		    << setw(26) << stockQuantity << "|" <<endl;

	outData << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;

	outData << "" << endl;

	totalPurchaseVal = stockVal * stockQuantity;

	outData << setprecision(2) << fixed;
	outData << "|" << "Total Purchase Value ($):" << setfill('.') 
		    << setw(20) << totalPurchaseVal << "|" << endl;

	outData << "|" << "Year 1 Percent Growth:" << setfill('.') 
		    << setw(22) << setprecision(1) << year1GrowthPct << "%" << "|" << endl;

	year1EndVal = totalPurchaseVal + (totalPurchaseVal * (year1GrowthPct / 100));

	outData << setprecision(2) << fixed;
	outData << "|" << "Year 1 Ending Value ($):" << setfill('.') 
		    << setw(21) << year1EndVal << "|" << endl;

	outData << "|" << "Year 2 Percent Growth:" << setfill('.') 
		    << setw(22) << setprecision(1) << year2GrowthPct << "%" << "|" << endl;

	year2EndVal = year1EndVal + (year1EndVal * (year2GrowthPct / 100));

	outData << setprecision(2) << fixed;
	outData << "|" << "Year 2 Ending Value ($):" << setfill('.') 
		    << setw(21) << year2EndVal << "|" << endl;

	outData << "-----------------------------------------------" << endl;
	
	outData << "" << endl;

	changeInVal = year2EndVal - totalPurchaseVal;

	pctChangeInVal = ((changeInVal / totalPurchaseVal) * 100);

	outData << setfill(' ') << "                You gained $" 
		    << setprecision(2) << fixed << changeInVal << " (" 
		    << setprecision(0) << fixed << pctChangeInVal << "%)" << endl;

	outData << "-----------------------------------------------" << endl;
	
	//Close the output file
	outData.close();

	return 0;
}