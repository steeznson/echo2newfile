#include<limits.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
    FILE *fptr;
    char filename[PATH_MAX];
    int i;
    if (argc != 3){
        printf("Requires two arguments. <newfile> <newfile contents>");
    }
    printf("Writing %s writing to file %s\n", argv[2], argv[1]);
    strcat(filename, "./");
    strcat(filename, argv[1]);
    fptr = fopen(filename, "w+");
    for (i = 0; i < strlen(argv[2]); ++i){
        fputc(argv[2][i], fptr);
    }
    fclose(fptr);
    return 0;
}
