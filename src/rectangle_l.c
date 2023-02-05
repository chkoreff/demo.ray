#include <raylib.h>

#include <rectangle.h>
#include <rectangle_l.h>

#include <memory.h>

void push_rectangle_l(
	struct list_rectangle_l **list,
	int posX, int posY, int width, int height,
	Color color, Color color_lines
	)
	{
	struct list_rectangle_l *top = new_memory(sizeof(struct list_rectangle_l));

	*top = (struct list_rectangle_l)
		{
		*list,
		(struct rectangle_l)
			{
			(struct rectangle) {posX, posY, width, height, color},
			color_lines
			}
		};

	*list = top;
	}

void draw_rectangle_l(struct rectangle_l *item)
	{
	struct rectangle *shape = &item->shape;

	draw_rectangle(shape);

	DrawRectangleLines(
		shape->posX, shape->posY, shape->width, shape->height,
		item->lines
		);
	}

void draw_list_rectangle_l(struct list_rectangle_l *list)
	{
	while (list)
		{
		draw_rectangle_l(&list->item);
		list = list->next;
		}
	}

void free_list_rectangle_l(struct list_rectangle_l *list)
	{
	while (list)
		{
		struct list_rectangle_l *next = list->next;
		free_memory(list, sizeof(struct list_rectangle_l));
		list = next;
		}
	}
