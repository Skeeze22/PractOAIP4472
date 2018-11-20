#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fract.h"
#include "fract.c"
//=================================================
int main(void){
    char simv[1];
    struct rational_fraction drob1,drob2,drobotvet,*drobotv;
    input(&drob1);
    input(&drob2);
    printf("Что необходимо сделать?(+-/*)\n");
   scanf("%s",&simv[0]);
//=================================================
if (simv[0] == '+') 
{
    drobotvet=add(drob1,drob2);
}
//=================================================
else if (simv[0] == '-')
{
    sub(drob1,drob2,&drobotvet);
}
//=================================================
else if (simv[0] == '*')
{
   drobotv = mult(drob1,drob2);
}
//=================================================
else if (simv[0] == '/')
{
    drobotvet=divide(&drob1,&drob2);
}
//=================================================
else
{
    printf("Что-то пошло не так =/\n");
}
 out(drobotvet);
//=================================================
}