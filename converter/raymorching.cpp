#include<iostream>
#include"EasyBMP.h"

int pal[6] = { 0, 50, 100, 150, 200, 255 };

int get(double a, double b){
	double x = 0, y = 0;
	for (int i = 1; i <= 1000; i++){
		double x_ = x*x - y*y + a;
		double y_ = 2 * x*y + b;

		if (x_*x_ + y_*y_ >= 10.0f){
			return pal[i % 5 + 1];
		}
		x = x_;
		y = y_;
	}
	return pal[0];
}

int main(void){
	const int W = 10000, H = 10000;
	double rw = 3.6, rh = rw * H / W;
	double offsetx = -rw / 1.6, offsety = -rh / 2.0;//原点をコンソールのどこにするか
	double dx = rw / (double)W, dy = rh / (double)H;

	BMP output;
	output.SetSize(W, H);
	output.SetBitDepth(24);

	for (int i = H - 1; i >= 0; i--){
		for (int j = 0; j < W; j++){
			double a = offsetx + dx*j, b = offsety + dy*i;
			output(j, H - i - 1)->Red =
				output(j, H - i - 1)->Green =
				output(j, H - i - 1)->Blue = get(a, b);
			//std::cout << get(a, b);
		}
		//std::cout << std::endl;
	}
	std::cout << std::endl;
	output.WriteToFile("plot.bmp");


	return 0;
}