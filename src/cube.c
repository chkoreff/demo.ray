#include <raylib.h>

#include <cube.h>
#include <memory.h>

void push_cube(
	struct list_cube **list,
	Vector3 position, float width, float height, float length,
	Color color
	)
	{
	struct list_cube *top = new_memory(sizeof(struct list_cube));
	*top = (struct list_cube)
		{
		*list,
		(struct cube) { position, width, height, length, color }
		};
	*list = top;
	}

void draw_cube(struct cube *item)
	{
	DrawCube(item->position, item->width, item->height, item->length,
		item->color);
	}

void draw_list_cube(struct list_cube *list)
	{
	while (list)
		{
		draw_cube(&list->item);
		list = list->next;
		}
	}

void free_list_cube(struct list_cube *list)
	{
	while (list)
		{
		struct list_cube *next = list->next;
		free_memory(list, sizeof(struct list_cube));
		list = next;
		}
	}
