#include<stdio.h>
int main(void)
{
	int a=17;
	int b = 1;
	for (int i = 2; i < a; i++)
	{
		if (a % i == 0) { b += 1; }
		else { b = b; }
	}   
	    if (a == 1) { printf("not prime\n"); }
		else if (a==2 || b==1) {printf("prime\n");}
		else { printf("not prime\n"); }
	
	
	 
	//for (�ϐ��̒�`;������;��){ ���s�����R�[�h }

	return 0;
}
