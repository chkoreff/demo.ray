struct cube
	{
	Vector3 position;
	float width;
	float height;
	float length;
	Color color;
	};

struct list_cube
	{
	struct list_cube *next;
	struct cube item;
	};

extern void push_cube(
	struct list_cube **list,
	Vector3 position, float width, float height, float length,
	Color color
	);

extern void draw_cube(struct cube *item);
extern void draw_list_cube(struct list_cube *list);
extern void free_list_cube(struct list_cube *list);
