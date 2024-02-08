#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point current, char to_fill)
{
	if (current.y < 0 || current.y >= size.y || current.x < 0 || current.x >= size.x
		|| tab[current.y][current.x] != to_fill)
		return;

	tab[current.y][current.x] = 'F';
	fill(tab, size, (t_point){current.x - 1, current.y}, to_fill);
	fill(tab, size, (t_point){current.x + 1, current.y}, to_fill);
	fill(tab, size, (t_point){current.x, current.y - 1}, to_fill);
	fill(tab, size, (t_point){current.x, current.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}


/*
if (current.y < 0 || current.y >= size.y || current.x < 0 || current.x >= size.x
		|| tab[current.y][current.x] != to_fill)
current.y < 0: This checks if the currentrent point is above the top edge of the array. 
	If current.y is less than 0, it means we’ve gone above the top edge.
current.y >= size.y: This checks if the currentrent point is below the bottom edge of the array. 
	If current.y is greater than or equal to size.y (the height of the array), it means we’ve gone below the bottom edge.
current.x < 0: This checks if the currentrent point is to the left of the left edge of the array. 
	If current.x is less than 0, it means we’ve gone to the left of the left edge.
current.x >= size.x: This checks if the currentrent point is to the right of the right edge of the array. 
	If current.x is greater than or equal to size.x (the width of the array), it means we’ve gone to the right of the right edge.
tab[current.y][current.x] != to_fill check if the character matches the starting character. If it isnt, dont fill it.

We only change a character to ‘F’ if it matches the character at the starting point of the flood fill. 
	tab[begin.y][begin.x]: gets the character at the starting point and passes it to the fill function (to_fill).
The function fill() only replaces a character if it matches to_fill.


If you increase y, you’re moving down vertically in the array.
If you decrease y, you’re moving up. 
If you increase x, you’re moving to the right horizontally.
If you decrease x, you’re moving to the left.

*/