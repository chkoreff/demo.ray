#include <raylib.h>

#include <memory.h>
#include <text_area.h>

void push_text_area(
	struct list_text_area **list,
	const char *text, int posX, int posY, int fontSize, Color color
	)
	{
	struct list_text_area *top = new_memory(sizeof(struct list_text_area));
	*top = (struct list_text_area)
		{
		*list,
		(struct text_area) { text, posX, posY, fontSize, color }
		};
	*list = top;
	}

void draw_text_area(struct text_area *item)
	{
	DrawText(item->text, item->posX, item->posY, item->fontSize,
		item->color);
	}

void draw_list_text_area(struct list_text_area *list)
	{
	while (list)
		{
		draw_text_area(&list->item);
		list = list->next;
		}
	}

void free_list_text_area(struct list_text_area *list)
	{
	while (list)
		{
		struct list_text_area *next = list->next;
		free_memory(list, sizeof(struct list_text_area));
		list = next;
		}
	}
