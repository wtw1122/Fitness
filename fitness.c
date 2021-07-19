/*
	Date 3. 21
	Author 원태웅
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct											//회원관리 프로그램을 위한 구조체 선언
{
	int num;											//int형 회원 번호를 저장할 변수
	char name[20];										//char형 이름을 저장할 배열
	double weight;										//double형 체중을 저장할 변수
} Fitness;												//휘트니스 구조체

Fitness* ary[100];										//포인터 배열 선언
void total_number(int count);							//전체등록 회원 수 반환
double average_weight(Fitness** pary, int count);		//평균 체중 반환
int max_weight(Fitness** pary, int count);				//평균 체중의 index반환
void print_info(Fitness** pary, int index);				//회원정보 출력
void free_ary(Fitness** pary, int count);				//동적 할당 영역 해제

int main()
{
	int i = 0;
	int index;

	for (i = 0; i < 5; i++)									//5명까지의 회원수를 반복제어
	{
		ary[i] = (Fitness*)malloc(sizeof(Fitness));         //malloc 동적할당후 포인터 연결  = (출력)malloc(입력)
		printf("##휘트니스 회원관리 프로그램입니다.##\n");
		printf("--신규회원 등록--\n");

		printf("---등록할 회원의 번호를 입력해주세요--- \n");	//회원 번호 출력
		scanf("%d", &ary[i]->num);							//회원 번호를 입력 후 num에 저장
		if (ary[i]->num < 0) break;							//음수 입력시 종료

		printf("---등록할 회원의 이름을 입력해주세요--- \n");	//회원 이름 출력
		scanf("%s", ary[i]->name);							//회원 이름을 입력 후 name에 저장

		printf("---등록할 회원의 체중을 입력해주세요--- \n");	//체중 출력
		scanf("%lf", &ary[i]->weight);					    ////회원 체중을 입력 후 weight에 저장, scanf 사용시 . 인식이 안됨
	}
	total_number(i);														//총 등록된 회원수를 불러들이는 변수 
	index = max_weight(ary, i);												//index에 최대체중을 대입
	printf("회원들의 평균체중은 %.lf입니다.\n", average_weight(ary, i));	//총 회원의 평균체중을 출력
	print_info(ary, index);													//최대제중의 회원정보
	free_ary;																//동적 할당 영역 해제

	return 0;
}

void total_number(int count)							//총 회원수를 구하는 함수
{
	printf("총 등록된 회원 수는 %d입니다.\n", count);	//총회원수 출력
}


double average_weight(Fitness** pary, int count)	//평균체중을 구하는 함수	
{
	int i;											//반복제어 변수(인원수 누적변수)
	double sum = 0;
	double avg;

	for (i = 0; i < count; i++)					//count로 비교 반복
	{
		sum += pary[i]->weight;					//인원수 i만큼 체중을 누적
	}
	avg = sum / i;									//총 무게를 i의 총 인원수로 나누어줌

	return avg;
}

int max_weight(Fitness** pary, int count)    //최대 체중 회원의 index 반환
{
	int index = pary[0]->num;				//회원의 번호을 정보를 찾아 0번지에서 부터 비교
	int i;
	double max = pary[0]->weight;			//0번에서부터 무게를 비교

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

void print_info(Fitness** pary, int index)	    //회원정보를 출력하는 함수
{
	int i;
	for (i = 0; i < 5; i++)
	{
		if (index == pary[i]->num)				//index = 최대체중
		{
			printf("최대 체중인 회원은 번호 : %d\t 이름 : %s\t  체중: %.1lf\n", pary[i]->num, pary[i]->name, pary[i]->weight);			//최대제중의 회원정보를 출력
		}
	}
}

void free_ary(Fitness** pary, int count)       //동적 할당 영역을 해제하는 함수
{
	int i;
	for (i = 0; i < count; i++)
	{
		free(ary[i]);
	}
}