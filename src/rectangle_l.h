// rectangle with lines

struct rectangle_l
	{
	struct rectangle shape;
	Color lines;
	};

struct list_rectangle_l
	{
	struct list_rectangle_l *next;
	struct rectangle_l item;
	};

extern void push_rectangle_l(
	struct list_rectangle_l **list,
	int posX, int posY, int width, int height,
	Color color, Color color_lines
	);

extern void draw_rectangle_l(struct rectangle_l *item);
extern void draw_list_rectangle_l(struct list_rectangle_l *list);
extern void free_list_rectangle_l(struct list_rectangle_l *list);
