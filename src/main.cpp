#include <ncurses.h>
using namespace std;

int main(int argc, char ** argv)
{
	// init screen and sets up screen
	initscr();

	WINDOW *win = newwin(15, 17, 2, 10);
	refresh();

	box(win, 0, 0);

	// print to screen
	mvwprintw(win, 0, 1, "Greeter");
	mvwprintw(win, 1, 1, "Hello");

	wrefresh(win);

	// pause the screen output
	getch();

	// deallocates memory and ends ncurses
	endwin();
	return 0;
}
