// Felipe Rueda
// CS50 2019
// pset 3

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // validates number of arguments entered by the user. Should be 1.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // saves argument entered by the user
    char *infile = argv[1];

    // open input file and validates if it isn't NULL
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    int blocksize = 512;
    unsigned char buffer[blocksize];
    FILE *outptr = NULL;

    char filename[8];
    int count = 0;

    // loop that searches for a jpg.
    while(fread(buffer, blocksize, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            if (count > 0)
            {
                fclose(outptr);
            }

            sprintf(filename, "%03d.jpg", count);
            outptr = fopen(filename, "w");

            if (outptr == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
            count++;
        }

        // validates if filename hasn't been created and writes into the file
        if (outptr != NULL)
        {
            fwrite(buffer, blocksize, 1, outptr);
        }
    }

    fclose(outptr);
    fclose(inptr);
    return 0;
}
