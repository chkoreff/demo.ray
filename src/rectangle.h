struct rectangle
	{
	int posX;
	int posY;
	int width;
	int height;
	Color color;
	};

struct list_rectangle
	{
	struct list_rectangle *next;
	struct rectangle item;
	};

extern void push_rectangle(
	struct list_rectangle **list,
	int posX, int posY, int width, int height,
	Color color
	);

extern void draw_rectangle(struct rectangle *item);
extern void draw_list_rectangle(struct list_rectangle *list);
extern void free_list_rectangle(struct list_rectangle *list);
