#include<limits.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
    FILE *fptr;
    char filename[PATH_MAX];

    if (argc != 3){
        printf("Requires two arguments. <newfile contents> <newfile>");
    }
    printf("Writing %s writing to file %s\n", argv[1], argv[2]);
    strcat(filename, "./");
    strcat(filename, argv[2]);
    fptr = fopen(filename, "w+");
    for (int i = 0; i < strlen(argv[1]); ++i){
        fputc(argv[1][i], fptr);
    }
    fclose(fptr);

    return 0;
}
