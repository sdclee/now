/**
 * now.c
 * Lee Crampton
 * sdclee@gmail.com
 * Original date : May 8th 2012
 * Last change   : May 8th 2012
 *
 * A simple implementation of the "now" program for the windows command line.
 * There program takes a single argument (enclosed by quotes) and prefaces it with a timestamp
 * typically for use in logging from batch/cmd scripts.
 *
 * The source code can be freely distributed and modified but as a courtesy, please leave the
 * original author details in tact.
 * License GPLv3+: GNU GPL version 3 or later
 *
 * usage: now "my message" >> my.log
 */
#include <stdio.h>
#include <time.h>

int main (int argc, char **argv)
{
	if (argc > 2)
	{
		printf ("usage: now 'message string to be timestamped'\n");
		exit (0);
	}
	
	if (argc == 2)
	{
		if (0 == strcmp (argv [1], "--help"))
		{
			printf ("now 'message'\n");
			printf ("License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n");
			printf ("This is free software: you are free to change and redistribute it.\n");
			printf ("There is NO WARRANTY, to the extent permitted by law.\n");
			printf ("SoftDev version written by Lee Crampton sdclee@gmail.com\n");
			printf ("0.1a\n");
			exit (0);
		}

		time_t rawtime; 
		struct tm *timeinfo; 
		char buffer [80]; 

		time (&rawtime); 
		timeinfo = localtime (&rawtime); 

		strftime (buffer, sizeof (buffer), "%Y-%m-%d %H:%M:%S", timeinfo); 

		printf ("%s : %s\n", buffer, argv [1]);	
	}
	
	exit (0);
}