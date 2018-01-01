#include <stdio.h>
#include <stdlib.h>
#define MAXChar 100 //�r��̤j���\����

int char_to_num(char ch); //�ഫ
char num_to_char(int num);//�ഫ
long source_to_decimal(char temp[], int source);//�쥻������10�i��
int decimal_to_object(char temp[], long decimal_num, int object);
void output(char temp[], int length);

int main()
{
	char temp[MAXChar];
	int source;//�쥻���i��
	int object;//��Ӫ��i��
	int length;//�x�s�ഫ�i��᪺����
	long decimal_num;//�s�x�ഫ���Q�i���
	int flag = 1;
	while (flag)
	{
		printf("�ഫ�e���Ʀr�O:");
		scanf("%s", temp);
		printf("�ഫ�e���i��O:");
		scanf("%d", &source);
		printf("�ഫ�᪺�i��O:");
		scanf("%d", &object);
		printf("�ഫ�᪺�Ʀr�O:");
		decimal_num = source_to_decimal(temp,source);
		length = decimal_to_object(temp,decimal_num,object);
		output(temp,length);
		printf("�~��п�J1�A�����п�J0: \n");
		scanf("%d", &flag);
	}
	system("pause");
	return 0;
}
//�N�r���ഫ���Ʀr
int char_to_num(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';//�Ʀr�r����Ʀr
	else
		return ch - 'A' + 10;//�r���Ÿ���Ʀr
}
char num_to_char(int num)
{
	if (num >= 0 && num <= 9)
		return (char)('0' + num - 0);//�N0~9���������ন�r��
	else
		return(char)('A' + num - 10);//�N�j��10�����ন�r��
}
long source_to_decimal(char temp[], int source)
{
	long decimal_num = 0;//�쥻�Ʀr�i�}���M
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