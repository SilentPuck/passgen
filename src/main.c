#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "passgen.h"
#include <time.h>
#include <sys/stat.h>


bool file_exists(const char *filename)
{
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

void secure_delete(const char *filename)
{
    FILE *f = fopen(filename, "r+");
    if (!f)
    {
        perror("fopen");
        return;
    }
    fseek(f,0,SEEK_END);
    long size = ftell(f);
    rewind(f);

    for (long i = 0; i < size; i++)
    {
        fputc(rand() % 256,f);
    }
    fclose(f);
    remove(filename);
}
void print_help() {
    printf("Password Generator (passgen)\n");
    printf("Usage:\n");
    printf("  passgen -n <length> [options]\n");
    printf("\nOptions:\n");
    printf("  -l                 Use letters (a-z, A-Z)\n");
    printf("  -d                 Use digits (0-9)\n");
    printf("  -s                 Use special characters (!@#$...)\n");
    printf("  -n <number>        Password length (minimum: 8)\n");
    printf("  -c <number>        Number of passwords to generate (default: 1)\n");
    printf("  -o <filename>      Save to specified file\n");
    printf("  --auto-name        Generate unique filename based on time\n");
    printf("  --silent           Do not print to terminal\n");
    printf("  --remove <file>    Delete specified file\n");
    printf("  --secure-delete <file>  Securely overwrite and delete file\n");
    printf("  --help             Show this help message\n");
}
void save_to_file(char *password, char *filename, int index)
{
    FILE *file = fopen(filename, "a");
    if (!file)
    {
        perror("fopen");
        return;
    }
    
    fprintf(file, "[%d] %s\n",index, password);
    
    fclose(file);
}


int main(int argc, char *argv[]) {
    srand(time(NULL));
    bool use_letters = false;
    bool use_digits = false;
    bool use_specials = false;
    bool use_filename = false;
    bool silent_mode = false;
    bool auto_name = false;
    char *remove_filename = NULL;
    char *secure_delete_filename = NULL;
    char output_filename_buffer[64];
    char *output_filename =NULL;

    int length = 0;
    int count = 1;

    if (argc == 1) {
        print_help();
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            use_letters = true;
        } else if (strcmp(argv[i], "-d") == 0) {
            use_digits = true;
        } else if (strcmp(argv[i], "-s") == 0) {
            use_specials = true;
        } else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            length = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            count = atoi(argv[++i]);
        } else if (strcmp(argv[i],"-o") == 0 && i + 1 < argc){
            use_filename = true;
            output_filename = argv[++i];
        } else if (strcmp(argv[i], "--silent") == 0){
            silent_mode =true;
        } else if (strcmp(argv[i], "--auto-name") == 0){
            auto_name = true;
        } else if (strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if(strcmp(argv[i], "--remove") == 0 && i + 1 < argc){
            remove_filename = argv[++i];
        } else if( strcmp(argv[i], "--secure-delete") == 0 && i + 1 < argc){
            secure_delete_filename = argv[++i];
        } else {
            printf("Unknown option: %s\n", argv[i]);
            printf("Use --help to see available options.\n");
            return 1;
        }
    }
    if (remove_filename)
    {
        if(file_exists(remove_filename))
        {
            if (remove(remove_filename) == 0)
            {
                printf("✅ File '%s' removed.\n", remove_filename);
            } else
                perror("remove");
        } else{
            printf("⚠️ File '%s' does not exist.\n", remove_filename);
        }
        return 0;
    }

    if (secure_delete_filename)
    {
        if (file_exists(secure_delete_filename))
        {
            secure_delete(secure_delete_filename);
            printf("✅ File '%s' securely deleted.\n", secure_delete_filename);
        } else {
            printf("⚠️ File '%s' does not exist.\n", secure_delete_filename);
        }
        return 0;
    }
    
    
    if(auto_name)
    {
        time_t now = time(NULL);
        strftime(output_filename_buffer, sizeof(output_filename_buffer),
                    "passgen_%Y%m%d_%H%M%S.txt", localtime(&now));
        output_filename = output_filename_buffer;
        use_filename =true;
    }
    // Validation
    if (use_filename && file_exists(output_filename))
    {
         printf("⚠️  Warning: File '%s' already exists. Appending to it.\n", output_filename);
    }
    if (length < 8) {
        printf("Error: Password length must be at least 8.\n");
        return 1;
    }

    if (count < 1) {
        printf("Error: Number of passwords must be at least 1.\n");
        return 1;
    }

    if (!use_letters && !use_digits && !use_specials) {
        printf("Error: Please select at least one character type (-l, -d, -s).\n");
        return 1;
    }
    
    char *charset = build_charset(use_letters, use_digits, use_specials);
    if (!charset) {
        printf("Error: Failed to build character set.\n");
        return 1;
    }

    for (int i = 0; i < count; i++)
    {        
        char *password = generate_password(charset, length);
        if(use_filename) save_to_file(password, output_filename, i + 1);
        if(!silent_mode)
            printf("Password [%d]: %s\n",i + 1, password);
        free(password);
    }
    
    

    free(charset);
    return 0;
}