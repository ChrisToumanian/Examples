#include <string.h>
#include <stdio.h>
#include "cfitsio/fitsio.h"
#include <stdbool.h>

fitsfile *fptr;
char card[FLEN_CARD];
int status = 0, nkeys;

// forward declarations
void trimLeadingSpaces(char* str);
void printKey(char* key);
void printAllKeys();
void writeToFile(char* output, char* filename);

int main(int argc, char *argv[])
{
    // Open FITS file
    printf("Opening FITS file....\n");
    fits_open_file(&fptr, argv[1], READONLY, &status);
    fits_get_hdrspace(fptr, &nkeys, NULL, &status);
 
    // Print header status
    printf("%s%i\n", "Status: ", status);
    printf("%s%i\n\n", "Keys: ", nkeys);

    // Print Key
    if (argv[2] != NULL)
    {
        printKey(argv[2]);
    }

    printAllKeys();

    writeToFile("TEST TEST TEST", "testoutput");

    // Run Commands
    /*for (int i = 0; i < sizeof(argv); i++)
    {
        if (argv[i] == "-r")
        {
            printAllKeys();
        }
    }*/

    // Close FITS file
    printf("\nClosing FITS file...\n");
    printf("END\n\n"); // terminate listing with END
    fits_close_file(fptr, &status);

    if (status) // print any error messages
        fits_report_error(stderr, status);

    return(status);
}

void printKey(char* key)
{
    fits_read_card(fptr, key, card, &status);
    char *trim = strtok(card, "/");
    strtok_r(trim, "=", &trim);
    trimLeadingSpaces(trim);
    printf("%s%s%s%s\n\n", "Requested Key: ", key, "\n", trim);
}

void printAllKeys()
{
    char *trim;

    for (int i = 1; i <= nkeys; i++)
    {
        fits_read_record(fptr, i, card, &status);
        trim = strtok(card, "/");
        printf("%s\n", trim);
    }

    int hdutype;
    if (ffmrhd(fptr, 1, &hdutype, &status) > 0)
    {
	printf("Error");
    }
    else
    {
	fits_get_hdrspace(fptr, &nkeys, NULL, &status);
	printf("%s%i\n", "Keys: ", nkeys);

	for (int i = 1; i <= nkeys; i++)
	{
	    fits_read_record(fptr, i, card, &status);
	    trim = strtok(card, "/");
	    printf("%s\n", trim);
	}
    }
}

void trimLeadingSpaces(char* str)
{
    int index, i, j;
    index = 0;

    // Find last index of whitespace character
    while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
    {
        index++;
    }

    if (index != 0)
    {
        // Shift all trailing characters to its left
        i = 0;
        while(str[i + index] != '\0')
        {
            str[i] = str[i + index];
            i++;
        }
        str[i] = '\0'; // Make sure that string is NULL terminated
    }
}

void writeToFile(char* output, char* filename)
{
    FILE *fp;
    fp = fopen(filename,"w+");

    if ( fp )
    {
	    fputs(output, fp);
    }
    else
    {
        printf("Failed to open the file\n");
    }

   fclose(fp);
}
