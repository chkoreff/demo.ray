struct text_area
	{
	const char *text;
	int posX;
	int posY;
	int fontSize;
	Color color;
	};

struct list_text_area
	{
	struct list_text_area *next;
	struct text_area item;
	};

extern void push_text_area(
	struct list_text_area **list,
	const char *text, int posX, int posY, int fontSize, Color color
	);

extern void draw_text_area(struct text_area *item);
extern void draw_list_text_area(struct list_text_area *list);
extern void free_list_text_area(struct list_text_area *list);
