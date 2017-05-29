#include<stdio.h>
#include<math.h>
#include"EasyBMP.h"
#include<string>

int main(void){
	printf("%d", (unsigned char)'ｱ'); return 0;
	BMP input;
	std::string name = "heart2.bmp";
	input.ReadFromFile(name.c_str());// 40x40 pix

	BMP output;
	output.SetSize(90, 20);
	output.SetBitDepth(24);

	for (int x = 0; x < output.TellWidth(); x++){
		for (int y = 0; y < output.TellHeight(); y++){
			//(x,y)を極座標に変換
			double r = (double)y;
			double theta = 360.0 * x / output.TellWidth();
			//inputから極座標で色をフェッチ
			int u = input.TellWidth() / 2 - (double)r * sin(theta / 180.0f * 3.14159265);
			int v = input.TellHeight() / 2 + (double)r * cos(theta / 180.0f * 3.14159265);
			ebmpBYTE color = ((int)input(u, v)->Red + (int)input(u, v)->Green + (int)input(u, v)->Blue)/3;
			output(x, y)->Red =
			output(x, y)->Green =
			output(x, y)->Blue = color;

		}
	}

	output.WriteToFile((std::string("out_")+name).c_str());

	//bitmapをデータ列に変換
	printf("txt");
	FILE* out;
	fopen_s(&out, (std::string("data_")+name+std::string(".txt")).c_str(),"w");
	fprintf(out,"{\n");
	for (int i = 0; i < output.TellWidth(); i++){
		fprintf(out,"	{0b0000%d%d%d%d,0b%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d},\n",
			output(i, 19)->Red != 0,
			output(i, 18)->Red != 0,
			output(i, 17)->Red != 0,
			output(i, 16)->Red != 0,
			output(i, 15)->Red != 0,
			output(i, 14)->Red != 0,
			output(i, 13)->Red != 0,
			output(i, 12)->Red != 0,
			output(i, 11)->Red != 0,
			output(i, 10)->Red != 0,
			output(i, 9)->Red != 0,
			output(i, 8)->Red != 0,
			output(i, 7)->Red != 0,
			output(i, 6)->Red != 0,
			output(i, 5)->Red != 0,
			output(i, 4)->Red != 0,
			output(i, 3)->Red != 0,
			output(i, 2)->Red != 0,
			output(i, 1)->Red != 0,
			output(i, 0)->Red != 0
			);
	}
	fprintf(out, "}\n");
	fclose(out);
	return 0;
}

