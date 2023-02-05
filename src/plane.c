#include <raylib.h>

#include <memory.h>
#include <plane.h>

void push_plane(
	struct list_plane **list,
	Vector3 centerPos, Vector2 size, Color color
	)
	{
	struct list_plane *top = new_memory(sizeof(struct list_plane));
	*top = (struct list_plane)
		{
		*list,
		(struct plane) { centerPos, size, color }
		};
	*list = top;
	}

void draw_list_plane(struct list_plane *list)
	{
	while (list)
		{
		struct plane *item = &list->item;
		DrawPlane(item->centerPos, item->size, item->color);
		list = list->next;
		}
	}

void free_list_plane(struct list_plane *list)
	{
	while (list)
		{
		struct list_plane *next = list->next;
		free_memory(list, sizeof(struct list_plane));
		list = next;
		}
	}
