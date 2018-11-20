//ЗАДАНИЕ: ВВЕСТИ ДВЕ ДРОБИ(использовать как структуры) И ВЫПОЛНИТЬ С НИМИ ОПЕРАЦИИ +-*/ С ПОМОЩЬЮ ФУНКЦИЙ
//здесь программа все в одном(в кажой функции есть лишняя перемена для ответа, можно и двумя обойтись, но мне было удобнее так)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERR -1
struct rational_fraction{ //объявление структуры
    int numinator; //числитель
    int denuminator; //знаменатель
};
//=================================================
void input (struct rational_fraction *pd);//прототип функции ввода 
void out(struct rational_fraction dr);//прототип функции вывода
struct rational_fraction add(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction dr3);//прототип функции сложения
void sub(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction dr3);//прототип функции вычитания
struct rational_fraction *mult(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction dr3);//прототип функции умножения
struct rational_fraction divide(struct rational_fraction *pd1,struct rational_fraction *pd2,struct rational_fraction *pd3);//прототип функции деления
//=================================================
int main(void){
    //значения для ввода в калькулятор
    char simv[1];//введенное с клавиатуры значение для выполнения действия
    struct rational_fraction drob1,drob2,drobotvet;//первая и вторая дробь
    input(&drob1);//вызов функции для записи первой дроби 
    input(&drob2);//вызов функции для записи второй дроби 
    printf("Что необходимо сделать?(+-/*)\n");//ввод символа для выполнения действия
    scanf("%s",&simv[0]);
//=================================================
if (simv[0] == '+') 
{
    add(drob1,drob2,drobotvet); //вызов плюса
}
//=================================================
else if (simv[0] == '-')
{
    sub(drob1,drob2,drobotvet); //вызов минуса
}
//=================================================
else if (simv[0] == '*')
{
    mult(drob1,drob2,drobotvet); //вызов умножения
}
//=================================================
else if (simv[0] == '/')
{
    divide(&drob1,&drob2,&drobotvet); //вызов деления
}
//=================================================
else
{
    printf("Что-то пошло не так =/\n"); //если пользователь ввел что-то страшное
}
//=================================================
}

//ниже представленны все функции

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
//YES!!! УДАЛЯЙТЕ КОММЕНТАРИИ, ВЫ ВСЕ ТАКИ ТОЖЕ ДОЛЖНЫ СТРАДАТЬ!!!!