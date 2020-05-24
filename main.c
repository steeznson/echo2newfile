#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_help(int argc){
    printf("Received %d arguments.\n", argc);
    puts("Requires at least two arguments. <newfile contents> <newfile>");
    puts("Optionally add an input file with '-p' flag. -p <infile> <newfile>");
    exit(1);
}

int main(int argc, char *argv[]){
    FILE *outfile_ptr;
    char filename[PATH_MAX];
    char parse_char;
    int has_infile = 0;

    if (argc < 3){
        print_help(argc);
    } else if (argc == 4){
        if (strcmp("-p", argv[1]) == 0){
            has_infile = 1;
        } else {
            print_help(argc);
        }
     }

    if (has_infile){
        printf("Writing contents of %s to %s\n", argv[2], argv[3]);
        strcat(filename, argv[3]);
    } else {
        printf("Writing '%s' to file %s\n", argv[1], argv[2]);
        strcat(filename, argv[2]);
    }

    outfile_ptr = fopen(filename, "w");

    if (has_infile){
        FILE *infile_ptr = fopen(argv[2], "r");
        if (infile_ptr){
           parse_char = fgetc(infile_ptr);
           while (parse_char != EOF){
               fputc(parse_char, outfile_ptr);
               parse_char = fgetc(infile_ptr);
           }
        } else {
            puts("Infile not found");
            exit(1);
        }
        fclose(infile_ptr);
    } else {
        for (int i = 0; i < strlen(argv[1]); ++i){
            fputc(argv[1][i], outfile_ptr);
        }
     }

    fclose(outfile_ptr);
    return 0;
 }
