#include <value.h>

#include <basic.h>

value QI;

/* (I x) = x */
value type_I(value f)
	{
	if (!f->L) return 0;
	return hold(f->R);
	}
