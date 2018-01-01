#include <stdio.h>
#include <stdlib.h>
#define MAXChar 100 //﹃程す砛

int char_to_num(char ch); //锣传
char num_to_char(int num);//锣传
long source_to_decimal(char temp[], int source);//セ计锣10秈
int decimal_to_object(char temp[], long decimal_num, int object);
void output(char temp[], int length);

int main()
{
	char temp[MAXChar];
	int source;//セ秈
	int object;//ㄓ秈
	int length;//纗锣传秈
	long decimal_num;//纗锣传Θ秈计
	int flag = 1;
	while (flag)
	{
		printf("锣传玡计琌:");
		scanf("%s", temp);
		printf("锣传玡秈琌:");
		scanf("%d", &source);
		printf("锣传秈琌:");
		scanf("%d", &object);
		printf("锣传计琌:");
		decimal_num = source_to_decimal(temp,source);
		length = decimal_to_object(temp,decimal_num,object);
		output(temp,length);
		printf("膥尿叫块1挡叫块0: \n");
		scanf("%d", &flag);
	}
	system("pause");
	return 0;
}
//盢﹃锣传Θ计
int char_to_num(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';//计﹃锣计
	else
		return ch - 'A' + 10;//ダ才腹锣计
}
char num_to_char(int num)
{
	if (num >= 0 && num <= 9)
		return (char)('0' + num - 0);//盢0~9ぇ丁计锣Θ﹃
	else
		return(char)('A' + num - 10);//盢10计锣Θ﹃
}
long source_to_decimal(char temp[], int source)
{
	long decimal_num = 0;//セ计甶秨㎝
	int length;
	int i;
	for (i = 0; temp[i] != '\0'; i++)
		length = i;
	for (i = 0; i <= length; i++)
		decimal_num = (decimal_num*source) + char_to_num(temp[i]);
	return decimal_num;
}
int decimal_to_object(char temp[], long decimal_num, int object)
{
	int i = 0;
	while (decimal_num)
	{
		temp[i] = num_to_char(decimal_num %object);
		decimal_num = decimal_num / object;
		i++;
	}
	temp[i] = '\0';
	return i;
}
void output(char temp[], int length)
{
	int i;
	for (i = length - 1; i >= 0; i--)
	{
		printf("%c", temp[i]);
	}
	printf("\n");
}