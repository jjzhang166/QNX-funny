#include <header.h>

int is_number (char number[])
{
    int i = 0;

    for (; number[i] != 0; i++)
    {
		//if (number[i] > '9' || number[i] < '0')
		if (!isdigit(number[i]))
			return 0;
    }
    return 1;
}
