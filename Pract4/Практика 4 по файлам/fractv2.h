struct rational_fraction;
//=================================================
void input (struct rational_fraction *pd);
void out(struct rational_fraction dr);
struct rational_fraction add(struct rational_fraction dr1,struct rational_fraction dr2);
void sub(struct rational_fraction dr1,struct rational_fraction dr2,struct rational_fraction *pdr);
struct rational_fraction *mult(struct rational_fraction dr1,struct rational_fraction dr2);
struct rational_fraction divide(struct rational_fraction *pd1,struct rational_fraction *pd2);
