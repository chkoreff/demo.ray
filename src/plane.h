struct plane
	{
	Vector3 centerPos;
	Vector2 size;
	Color color;
	};

struct list_plane
	{
	struct list_plane *next;
	struct plane item;
	};

extern void push_plane(
	struct list_plane **list,
	Vector3 centerPos, Vector2 size, Color color
	);

extern void draw_list_plane(struct list_plane *list);
extern void free_list_plane(struct list_plane *list);
