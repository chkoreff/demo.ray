#include <raylib.h>

#include <cube.h>
#include <cube_l.h>
#include <memory.h>

void push_cube_l(
	struct list_cube_l **list,
	Vector3 position, float width, float height, float length,
	Color color, Color lines
	)
	{
	struct list_cube_l *top = new_memory(sizeof(struct list_cube_l));
	*top = (struct list_cube_l)
		{
		*list,
		(struct cube_l)
			{
			(struct cube) { position, width, height, length, color },
			lines
			}
		};
	*list = top;
	}

void draw_cube_l(struct cube_l *item)
	{
	struct cube *shape = &item->shape;

	draw_cube(shape);
	DrawCubeWires(shape->position, shape->width, shape->height,
		shape->length, item->lines);
	}

void draw_list_cube_l(struct list_cube_l *list)
	{
	while (list)
		{
		draw_cube_l(&list->item);
		list = list->next;
		}
	}

void free_list_cube_l(struct list_cube_l *list)
	{
	while (list)
		{
		struct list_cube_l *next = list->next;
		free_memory(list, sizeof(struct list_cube_l));
		list = next;
		}
	}
