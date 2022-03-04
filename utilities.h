typedef struct player player;
typedef struct stacknode *stackptr;

char isNumber(char* n);
char enough_arguments(char* argument);
player *check_color(char* p, player* black, player* white);
char colorValue(char* p);
char check_orientation(char* orientation);
int path_steps(char** wall_matrix, int boardsize, player* pl, char color);
char is_vertex_valid(char hor, int boardsize);
char isValidWall(int vertex_x, int vertex_y, int boardsize, char** wall_matrix, char orientation);
char thereIsAWall(char or, char** wall_matrix, int boardsize, int vertex_x, int vertex_y);
char there_is_a_path(char** wall_matrix, int boardsize, player* white, player* black);
char wallBelow(int i, int j, char** wall_matrix, int boardsize);
char wallAbove(int i, int j, char** wall_matrix, int boardsize);
char wallOnTheRight(int i, int j, char** wall_matrix, int boardsize);
char wallOnTheLeft(int i, int j, char** wall_matrix, int boardsize);
char addMove(stackptr* last, int i, int j, char* type);
unsigned char depth(int boardsize);
char positionEvaluation(player black, player white, int boardsize, char** wall_matrix, int* evaluation);
unsigned char findDepth(int boardsize, char* pseudo);