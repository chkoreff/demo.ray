#include <raylib.h>

#include <rectangle.h>

#include <memory.h>

void push_rectangle(
	struct list_rectangle **list,
	int posX, int posY, int width, int height,
	Color color
	)
	{
	struct list_rectangle *top = new_memory(sizeof(struct list_rectangle));

	*top = (struct list_rectangle)
		{
		*list,
		(struct rectangle) {posX, posY, width, height, color}
		};

	*list = top;
	}

void draw_rectangle(struct rectangle *item)
	{
	DrawRectangle(item->posX, item->posY, item->width, item->height,
		item->color);
	}

void draw_list_rectangle(struct list_rectangle *list)
	{
	while (list)
		{
		draw_rectangle(&list->item);
		list = list->next;
		}
	}

void free_list_rectangle(struct list_rectangle *list)
	{
	while (list)
		{
		struct list_rectangle *next = list->next;
		free_memory(list, sizeof(struct list_rectangle));
		list = next;
		}
	}
