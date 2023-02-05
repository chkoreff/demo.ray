#include <output.h>
#include <fexl.h>
#include <stdio.h>
#include <scene.h>

int main(void)
	{
	beg_fexl();
	if (1)
		run_scene();
	else
		{
		if (0) printf("Hello world\n");
		put("Hello world.");nl();
		}
	end_fexl();
	return 0;
	}
