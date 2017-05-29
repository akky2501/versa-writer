#include<iostream>
#include<algorithm>
#include<string>


int main(void){
	std::string str = "MzkuM3g1p2IzqJksMJ5wo2Eypa0=";
	std::string out = str;
	for (int i = -30; i < 30;i++){
		std::transform(str.begin(), str.end(), out.begin(), [&](char x){return x + i; });
		std::cout << out << std::endl;
	}
	return 0;
}