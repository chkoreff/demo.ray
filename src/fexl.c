#include <value.h>

#include <basic.h>

static void beg_const(void)
	{
	/* basic */
	QI = Q(type_I);
	}

static void end_const(void)
	{
	/* basic */
	drop(QI);
	}

void beg_fexl(void)
	{
	beg_const();
	}

void end_fexl(void)
	{
	end_const();
	end_value();
	}
