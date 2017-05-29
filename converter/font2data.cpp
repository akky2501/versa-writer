#include<stdio.h>

struct Data{
	unsigned char high;
	unsigned short low;
};

int main(void){
	FILE *in, *out;
	fopen_s(&in, "ichigojam-font.bin", "rb");
	if (!in) return 0;
	fopen_s(&out,"font.txt","w");
	if (!out) return 0;
	
	unsigned char dat[8] = {};
	fread(&dat[0], 1, 1, in);//1byte‚¸‚ê‚Ä‚½
	int x = 0;
	while(! feof(in)){
		for (int i = 0; i < 8;i++) fread(&dat[i], 1,1, in);
//		if (/*x == 0 || */(48 <= x&&x <= 58)/* || (63 <= x&&x <= 90) || (97 <= x&&x <= 122)*/){
			fprintf(out, "//%d\n{{\n", x);
			for (int i = 7; i >= 0; i--){
				fprintf(out, "	{0b0000%d%d%d%d,0b%d%d%d%d000000000000}",
					(dat[0] >> i) & 1,
					(dat[1] >> i) & 1,
					(dat[2] >> i) & 1,
					(dat[3] >> i) & 1,

					(dat[4] >> i) & 1,
					(dat[5] >> i) & 1,
					(dat[6] >> i) & 1,
					(dat[7] >> i) & 1);
				if (i == 0) fprintf(out, "\n");
				else fprintf(out, ",\n");
			}
			fprintf(out, "}},\n\n");
//		}
		x++;
	}

	fclose(in);
	fclose(out);
	return 0;
}