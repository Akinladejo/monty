#include "monty.h"

/**
 * main - Monty interpreter
 * @ac: Command line arguments count
 * @av: Command line arguments array of strings
 *
 * Return: 0 if success
 */
int main(int ac, char **av)
{
  char *buff = NULL, *dlim = " \n\t", *optok = NULL;
  size_t buff_size = 0;
  ssize_t line_size;
  FILE *fp;
   
  if (ac != 2)
    {
        dprintf(2, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(av[1], "r");
    if (!fp)
    {
        dprintf(2, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }

    global.fp = fp;
    set_global();

   

    while ((line_size = getline(&buff, &buff_size, global.fp)) >= 0)
    {
        global.line++;
        char *optok = strtok(buff, " \n\t");

        if (optok && optok[0] != '#')
        {
            global.arg = strtok(NULL, " \n\t");
            get_opcode(optok);
        }

        global.arg = NULL;
    }

    free(buff);
    exit_op();
    return 0;
}

/**
 * set_global - Defines global variables
 *
 * Return: No return
 */
void set_global(void)
{
    global.mode = 0;
    global.buffer = NULL;
    global.arg = NULL;
    global.stack = NULL;
    global.line = 0;
}
