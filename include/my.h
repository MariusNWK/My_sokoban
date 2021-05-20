/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my_sokoban
*/

#include <stdio.h>
#include <ncurses.h>

typedef struct Coords
{
    int x;
    int y;
} coords_t;

typedef struct Limits
{
    int x_left;
    int x_right;
} limits_t;

typedef struct Lines
{
    int lines_nbr;
    int *lines_len;
    char **lines;
} lines_t;

typedef struct Cell
{
    coords_t data;
    struct Cell *next;
} list_t, cell_t;

int is_empty_list(list_t *);
long length_list(list_t *);
list_t *add_at(list_t *, coords_t, int);
coords_t get_at(list_t *, int);
void set_at(list_t *, coords_t, int);
list_t *free_at(list_t *, int);
list_t *free_list(list_t *);
void print_list(list_t *);

char *file_reader(char const *);
void my_puterr(char *);
int my_strlen(char *);
void my_putchar(char);
void my_putstr(char *);
void my_putnbr(int);

////////////////////////////////////////////////////

int error_handling(int, char **, char **, lines_t *);
int is_map_valid(char *, lines_t *, int);
int check_border(char *, lines_t *);
int is_one_sharp_a_line(int, int *, char **);
int is_map_delimited(int, int *, char **);
int check_columns(list_t **, char **);
int is_full_of_sharps(int, int, int, char **);
int check_sharps_if_x_different(coords_t, coords_t, limits_t *, char **);
int free_pos_and_reduce_len(list_t **, int, int);
int check_entities(char *);
void free_lines_memory(int, int *, char **);
int are_same_coords(int, int, list_t *, list_t *);

////////////////////////////////////////////////////

typedef struct Entities
{
    coords_t player;
    coords_t prec_player;
    list_t *walls;
    list_t *boxes;
    list_t *cp;
} entities_t;

typedef struct Direction
{
    int left;
    int up;
    int right;
    int down;
} direction_t;

typedef struct Leni
{
    int len;
    int i;
} leni_t;

char *keep_borders_only(char *);
entities_t define_entities(lines_t);
int my_sokoban(char *, entities_t *, lines_t);
coords_t define_window_min_size(char *);
int game(char *, entities_t *, int);
void manage_player(entities_t *, int);
void manage_boxes(entities_t *, int);
void manage_cp(entities_t *);
coords_t define_coords(int, int);
int are_coords_equal(coords_t, coords_t);
coords_t define_coords(int, int);
int animate_screen(WINDOW *, char *, entities_t *, lines_t);
int can_a_box_move(entities_t *);
int are_all_boxes_stored(entities_t *);
list_t *search_same_coords(list_t *, int, list_t *);
int get_limits_and_check_inside(list_t **, leni_t, limits_t *, char **);

typedef struct VerticHoriz
{
    int horiz_1;
    int horiz_2;
    int vertic_1;
    int vertic_2;
} vehor_t;

typedef struct Loop
{
    int key;
    int i;
    int j;
    int k;
} lp_t;

char **copy_map(char **, int *, char *, lp_t);

typedef struct light
{
    coords_t left;
    coords_t right;
    coords_t prec_left;
} light_t;

////////////////////////////////////////////////////