// cube with lines

struct cube_l
	{
	struct cube shape;
	Color lines;
	};

struct list_cube_l
	{
	struct list_cube_l *next;
	struct cube_l item;
	};

extern void push_cube_l(
	struct list_cube_l **list,
	Vector3 position, float width, float height, float length,
	Color color, Color lines
	);

extern void draw_list_cube_l(struct list_cube_l *list);
extern void free_list_cube_l(struct list_cube_l *list);
