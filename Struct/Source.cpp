#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "Header.h"
#include <Windows.h>
#define MAX50 50
#define MAX12 12
enum city
{
	Almaty, Astana
};

struct address
{	
	city city;
	char RegionName[MAX50];
	char streetName[MAX50];
	int house;
	int apartment;
	int zip; 
};

struct student 
{
	char Fname[MAX50];
	char Lname[MAX50];
	char DateOfBirth[MAX12];

	int Age;
	//char * adress;
	struct address adress;
};

void sl(int age)
{
	if (age < 18)
		printf("(Призывник)");
}

void PrintStudentInfo(struct student * NAME) // придет указатель на структуру
{
	printf("Информация о студенте:");
	sl(NAME->Age);
	printf("\n");
	printf(" === %s %s Возраст %d\n",NAME->Lname, NAME->Fname, NAME->Age); // если обычная структура то ставим . если указатель, то ставим ->
	printf("\n\n-------------------------------------\n\n");
}



void PrintStudentInfo(struct student * NAME, int count)// придет указатель на структуру
{
	printf("Список поступающих: \n");
	for (int i = 0; i < 2; i++)
	{
		/*printf("==>%d === %s %s, возраст - %d\n", i + 1, students[i].Lname, students[i].Fname, students[i].Age);*/
		PrintStudentInfo(&NAME[i]); // передаем указатель
	}

	printf("\n\n-------------------------------------\n\n");
	printf("\n\nИТОГО %d поступающих\n\n", count);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("\nSTRUCTS\n");

	struct student Dmitriy// создал структуру студента с именем Дмитрий
	{	
		//int a;
		//student = int, Dmitriy = a; student - мой тип
		"Dmitiy",
		"Glavatskikh",
		"09.02.1993",
		25
			//можно не заполнять все
		/*NULL,
		Almaty*/
	};
	

	struct student Ivan;
	Ivan.Age = 15;
	//Ivan.Fname = "Help";
//	Ivan.DateOfBirth = "08/15/1996";
	//Ivan.
	printf("Student #1 %s %s - %d \n", Dmitriy.Fname, Dmitriy.Lname, Dmitriy.Age);
	printf("Student #1 %c %s - %d \n", Dmitriy.Fname[0], Dmitriy.Lname, Dmitriy.Age);


	struct student students[10]; // можем делать динамическим
	int count = 0;
	int index;

	printf("Введите имя студента \n");
	while (count < 2 && gets_s(students[count].Fname) != NULL && students[0].Fname[0] != '\0') // Вводим имя Fname 
	{
		printf("Введите фамилию студента - "); // вводим фамилию Lname
		gets_s(students[count].Lname);
		printf("Введите возраст - ");
		scanf("%d", &students[count].Age); // вводим возраст Age
		while (getchar() != '\n') // вводим до тех пор, пока не нажмем Enter
		{
			continue;
		}
		if (count < 2)
			printf("Введите имя студента\n");
		count++;
	}

	printf("\n\n-------------------------------------\n\n");
	if (count > 0)
	{

		PrintStudentInfo(students, count);



		//printf("Список поступающих: \n");
		//for (int i = 0; i < 2; i++)
		//{
		//	printf("==>%d === %s %s, возраст - %d\n", i + 1, students[i].Lname, students[i].Fname, students[i].Age);
		//	PrintStudentInfo(&students[i]); // передаем указатель
		//}
		//
		//printf("\n\n-------------------------------------\n\n");
		//printf("\n\nИТОГО %d поступающих\n\n", count);
	}

	students[3].adress.city = Almaty;
	strcpy(students[3].adress.RegionName, "Алматы обл");
	strcpy(students[3].adress.streetName, "Пушкина");
}