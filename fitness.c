/*
	Date 3. 21
	Author ���¿�
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct											//ȸ������ ���α׷��� ���� ����ü ����
{
	int num;											//int�� ȸ�� ��ȣ�� ������ ����
	char name[20];										//char�� �̸��� ������ �迭
	double weight;										//double�� ü���� ������ ����
} Fitness;												//��Ʈ�Ͻ� ����ü

Fitness* ary[100];										//������ �迭 ����
void total_number(int count);							//��ü��� ȸ�� �� ��ȯ
double average_weight(Fitness** pary, int count);		//��� ü�� ��ȯ
int max_weight(Fitness** pary, int count);				//��� ü���� index��ȯ
void print_info(Fitness** pary, int index);				//ȸ������ ���
void free_ary(Fitness** pary, int count);				//���� �Ҵ� ���� ����

int main()
{
	int i = 0;
	int index;

	for (i = 0; i < 5; i++)									//5������� ȸ������ �ݺ�����
	{
		ary[i] = (Fitness*)malloc(sizeof(Fitness));         //malloc �����Ҵ��� ������ ����  = (���)malloc(�Է�)
		printf("##��Ʈ�Ͻ� ȸ������ ���α׷��Դϴ�.##\n");
		printf("--�ű�ȸ�� ���--\n");

		printf("---����� ȸ���� ��ȣ�� �Է����ּ���--- \n");	//ȸ�� ��ȣ ���
		scanf("%d", &ary[i]->num);							//ȸ�� ��ȣ�� �Է� �� num�� ����
		if (ary[i]->num < 0) break;							//���� �Է½� ����

		printf("---����� ȸ���� �̸��� �Է����ּ���--- \n");	//ȸ�� �̸� ���
		scanf("%s", ary[i]->name);							//ȸ�� �̸��� �Է� �� name�� ����

		printf("---����� ȸ���� ü���� �Է����ּ���--- \n");	//ü�� ���
		scanf("%lf", &ary[i]->weight);					    ////ȸ�� ü���� �Է� �� weight�� ����, scanf ���� . �ν��� �ȵ�
	}
	total_number(i);														//�� ��ϵ� ȸ������ �ҷ����̴� ���� 
	index = max_weight(ary, i);												//index�� �ִ�ü���� ����
	printf("ȸ������ ���ü���� %.lf�Դϴ�.\n", average_weight(ary, i));	//�� ȸ���� ���ü���� ���
	print_info(ary, index);													//�ִ������� ȸ������
	free_ary;																//���� �Ҵ� ���� ����

	return 0;
}

void total_number(int count)							//�� ȸ������ ���ϴ� �Լ�
{
	printf("�� ��ϵ� ȸ�� ���� %d�Դϴ�.\n", count);	//��ȸ���� ���
}


double average_weight(Fitness** pary, int count)	//���ü���� ���ϴ� �Լ�	
{
	int i;											//�ݺ����� ����(�ο��� ��������)
	double sum = 0;
	double avg;

	for (i = 0; i < count; i++)					//count�� �� �ݺ�
	{
		sum += pary[i]->weight;					//�ο��� i��ŭ ü���� ����
	}
	avg = sum / i;									//�� ���Ը� i�� �� �ο����� ��������

	return avg;
}

int max_weight(Fitness** pary, int count)    //�ִ� ü�� ȸ���� index ��ȯ
{
	int index = pary[0]->num;				//ȸ���� ��ȣ�� ������ ã�� 0�������� ���� ��
	int i;
	double max = pary[0]->weight;			//0���������� ���Ը� ��

	for (i = 1; i < count; i++)
	{
		if (max < (pary[i]->weight))
		{
			max = pary[i]->weight;
			index = pary[i]->num;
		}
	}
	return index;
}

void print_info(Fitness** pary, int index)	    //ȸ�������� ����ϴ� �Լ�
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (index == pary[i]->num)				//index = �ִ�ü��
		{
			printf("�ִ� ü���� ȸ���� ��ȣ : %d\t �̸� : %s\t  ü��: %.1lf\n", pary[i]->num, pary[i]->name, pary[i]->weight);			//�ִ������� ȸ�������� ���
		}
	}
}

void free_ary(Fitness** pary, int count)       //���� �Ҵ� ������ �����ϴ� �Լ�
{
	int i;
	for (i = 0; i < count; i++)
	{
		free(ary[i]);
	}
}