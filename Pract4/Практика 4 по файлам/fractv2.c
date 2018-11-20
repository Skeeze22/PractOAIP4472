#include <stdio.h>
#include <stdlib.h>
#define ERR -1
#include "fract.h"
struct rational_fraction{ 
    int numinator; 
    int denuminator;
};
//=================================================
void input(struct rational_fraction *pd){ 
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
void out(struct rational_fraction dr){
printf("Ответ:\n");
printf("%d/%d\n",dr.numinator,dr.denuminator);
}
//=================================================
void sub(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction *pdr)
{ 
    int delit1,delit2;
    delit1 = dr1.denuminator;
    delit2 = dr2.denuminator;
    dr1.denuminator *= delit2;
    pdr->denuminator = dr1.denuminator;
    dr2.denuminator *= delit1;
    dr1.numinator *= delit2;
    dr2.numinator *= delit1;
    pdr->numinator = dr1.numinator - dr2.numinator;
}
//=================================================
struct rational_fraction add(struct rational_fraction dr1,struct rational_fraction dr2)
{  
    int delit1,delit2;
    delit1 = dr1.denuminator;
    delit2 = dr2.denuminator;
    dr1.denuminator *= delit2;
    dr2.denuminator *= delit1;
    dr1.numinator *= delit2;
    dr2.numinator *= delit1;
    dr1.numinator = dr1.numinator + dr2.numinator;
    return dr1;
}
//=================================================
struct rational_fraction *mult(struct rational_fraction dr1,struct rational_fraction dr2)
{
    int delit1,delit2;
    delit1 = dr1.denuminator;
    delit2 = dr2.denuminator;
    dr1.denuminator *= delit2;
    dr2.denuminator *= delit1;
    dr1.numinator *= delit2;
    dr2.numinator *= delit1;
    dr1.numinator = dr1.numinator * dr2.numinator;
}
//=================================================
struct rational_fraction divide(struct rational_fraction *pd1,struct rational_fraction *pd2)
{
    pd1->numinator = pd1->numinator * pd2->denuminator;
    pd1->denuminator = pd1->denuminator * pd2->numinator;
    return *pd1;
}
//=================================================