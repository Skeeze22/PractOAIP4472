struct rational_fraction;//стуктура как переменная
//в этом файле вызываются прототипы
//=================================================
void input (struct rational_fraction *pd);//прототип функции ввода 
void out(struct rational_fraction dr);//прототип функции вывода
struct rational_fraction add(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction dr3);//прототип функции сложения
void sub(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction dr3);//прототип функции вычитания
struct rational_fraction *mult(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction dr3);//прототип функции умножения
struct rational_fraction divide(struct rational_fraction *pd1,struct rational_fraction *pd2,struct rational_fraction *pd3);//прототип функции деления
 
