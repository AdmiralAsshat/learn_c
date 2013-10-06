#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if ((argv[1] != NULL && memcmp(argv[1], "--checksum", 10) == 0))
    {
        printf("Passed checksum argument\n.");
    }
	else
	{
		printf("Did not pass checksum argument.\n");
	}

return 0;
}
