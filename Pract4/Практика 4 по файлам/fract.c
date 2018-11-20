#include <stdio.h>
#include <stdlib.h>
#define ERR -1
#include "fract.h"
//в этом файле вызываются функции
//в этом же файле вызвается структура
struct rational_fraction{ //объявление структуры
    int numinator; //числитель
    int denuminator; //знаменатель
};
//=================================================
void input(struct rational_fraction *pd){ //функция ввода с указателем
    printf("введите значение числителя\n");
    scanf("%d", &pd->numinator);
    printf("Введите значение знаменателя\n");  
    scanf("%d", &pd->denuminator);
    if(pd->denuminator == 0){
    printf("Ошибка, делитель не может быть равным '0'\n");
    exit(ERR);
    }
}
//=================================================
void out(struct rational_fraction dr){ //функция вывода
printf("Ответ:\n");
printf("%d/%d\n",dr.numinator,dr.denuminator);
}
//=================================================
void sub(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction dr3)//функция вычитания
{ 
    int delit1,delit2;//переменные для сохранения значений
    delit1 = dr1.denuminator;//соответственно храним значения
    delit2 = dr2.denuminator;//соответственно храним значения
    dr1.denuminator *= delit2;//умножения первого делителя на второй
    dr2.denuminator *= delit1;//умножение второго делителя на первый
    dr1.numinator *= delit2;//умножения первого делимого на второй делитель
    dr2.numinator *= delit1;//умножение второго делимого на первый делитель
    dr3.denuminator = dr1.denuminator;//сохранения делителя в ответ
    dr3.numinator = dr1.numinator - dr2.numinator;//отнимаем и сохраняем делимое
    out(dr3);//вызываем вывод
}
//=================================================
struct rational_fraction add(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction dr3) //функция сложения
{  
    int delit1,delit2;//переменные для сохранения значений
    delit1 = dr1.denuminator;//соответственно храним значения
    delit2 = dr2.denuminator;//соответственно храним значения
    dr1.denuminator *= delit2;//умножения первого делителя на второй
    dr2.denuminator *= delit1;//умножение второго делителя на первый
    dr1.numinator *= delit2;//умножения первого делимого на второй делитель
    dr2.numinator *= delit1;//умножение второго делимого на первый делитель
    dr3.denuminator = dr1.denuminator;//сохранения делителя в ответ
    dr3.numinator = dr1.numinator + dr2.numinator;//складываем и сохраняем делимое
    out(dr3);//вызываем вывод
    return dr3;
}
//=================================================
struct rational_fraction *mult(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction dr3) //функции умнажения
{
    int delit1,delit2;//переменные для сохранения значений
    delit1 = dr1.denuminator;//соответственно храним значения
    delit2 = dr2.denuminator;//соответственно храним значения
    dr1.denuminator *= delit2;//умножения первого делителя на второй
    dr2.denuminator *= delit1;//умножение второго делителя на первый
    dr1.numinator *= delit2;//умножения первого делимого на второй делитель
    dr2.numinator *= delit1;//умножение второго делимого на первый делитель
    dr3.denuminator = dr1.denuminator;//сохранения делителя в ответ
    dr3.numinator = dr1.numinator * dr2.numinator;//умножаем и сохраняем делимое
    out(dr3);//вызываем вывод
}
//=================================================
struct rational_fraction divide(struct rational_fraction *pd1,struct rational_fraction *pd2,struct rational_fraction *pd3) // /
{
    pd3->numinator = pd1->numinator * pd2->denuminator;//умножаем первое делимое на второй делитеть
    pd3->denuminator = pd1->denuminator * pd2->numinator;//умножаем первый делитель на второе делимое 
    out(*pd3);//вызываем вывод
    return *pd3;
}
//=================================================