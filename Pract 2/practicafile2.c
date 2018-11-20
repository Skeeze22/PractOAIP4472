#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
//Задать случайно элементы двумерного динамического массива a. Размер массива вводит пользователь.
	int **a, n, m;//указатель на двумерный массив, размерности массива
	int *b, nm;//указатель на одномерный массив, размерность массива
	int schet=0,i, j,colvchet;// индексы элементов матрицы
	FILE *fp = fopen("f1.txt","r");// открытие файла f1.txt на чтение(должен быть создан заранее)
	FILE *fp2 = fopen("f2.txt","w");//открытие файла f2.txt на запись(если его нет,он создается программой)
	if(fp != NULL)//если найден первый файл
		{ 
			fscanf(fp,"%d",&n);//сканирование размерности
			printf("n = %d\n",n);//вывод размерности
		} 
	else 
		{
			printf("Невозможно открыть файл на чтение.\n ");//ошибка если файла нет 
			fclose(fp);//закрытие файла
			return 0; 
		}
	m=n;//для удобства работы с квадратной матрицей 
	nm = m*n;//размер одномерного массива
	a = (int**)malloc(n * sizeof(int*));// выделяем память для столбцов в двумерном массиве
	b = (int*)malloc(nm * sizeof(int));// выделяем память под одномерный массив
	if (!a)// если ошибка и столбцы двумерного массива имеют размеры 0 или меньше, то выходим из программы
		{
			printf("Error: there is no memory.\n");
			return 0;
		}
	for (i = 0; i < n; ++i)// цикл выделения памяти для строк в двумерном массиве
	{
		a[i] = (int*)malloc(m * sizeof(int));//выделяем строкам память
		if (!a[i])// если ошибка и  размеры строк имеют размер 0 или меньше, то освобождаем память и выходим из программы
		{
			for (j = 0; j < i; ++j)//цикл для очистки
				free(a[j]);//освобождаем строки
			free(a);//освобождаем массив столбцов
			printf("Error: there is no memory.\n");
			return 0;
		}
	}
	for (i = 0; i < n; ++i)// вводим элементы массива
		for (j = 0; j < m; ++j)
		{
			fscanf(fp,"%d",&a[i][j]);//сканирование элемента матрицы из файла
		}
//Требуется сформировать одномерный динамический массив с, переписав в него вначале четные строки массива a, затем нечетные.
	printf("Двумерный берется из файла f1.txt:\n");
	for (i = 0; i < n; ++i)//выводим двумерный массив в консоль(для проверки точности сканирования)
	{
		for (j = 0; j < m; ++j)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	for (i = 0; i<n ; ++i)//выполняем поиск четных строк
	{
		if(i%2==0)//если строка четная
		{
			for ( j = 0; j<m; ++j)//цикл по столбцам
			{
				b[schet]=a[i][j];//присваиваем элементу одномерного массива значение элемента четной строки
				schet++;//счетчик для нахождения последнего элемента четных строк
			}
		}
	}
	for (i = 0;i<n;++i)//выполняем поиск нечетных строк
	{
		if(i%2!=0)//если строка нечетная
		{
			for(j=0;j<m;j++)//цыкл по столбцам
			{
				b[schet]=a[i][j];//присваиваем элементу одномерного массива значение элемента нечетной строки
				schet++;//переход к следующей ячейки одномерного массива
			}
		}
	}		
	printf("Одномерный находится в файле f2.txt: ");
	for (i = 0; i < nm; ++i)//записываем новый массив в файл f2.txt
		fprintf(fp2,"%5d",b[i]);//записываем
	printf("\n");
	return 1;
	//освобождаем захваченную память
	for (i = 0; i < n; ++i)//Цикл освобождения памяти строк двумерного массива
		free(a[i]);//освобождаем строки
	free(a);//освобождаем столбцы
	free(b);//освобожаем одномерный массив
	return 1;
}