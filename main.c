#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>  // open fonksiyonu için
#include <unistd.h> // read, close fonksiyonları için

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc == 2)  // Eğer bir dosya adı verilmişse
    {
        // Dosyayı aç
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            perror("Error opening file");
            return 1;
        }

        // Dosyadan satır satır oku
        while ((line = get_next_line(fd)) != NULL)
        {
            printf("File line: %s", line);
            free(line); // Okunan satırın hafızasını serbest bırak
        }

        close(fd);  // Dosyayı kapat
    }
    else if (argc == 1)  // Eğer bir dosya adı verilmemişse, stdin'den oku
    {
        // Standart girişten satır satır oku
        while ((line = get_next_line(0)) != NULL)  // 0, stdin dosya tanımlayıcısıdır
        {
            printf("Stdin line: %s", line);
            free(line); // Okunan satırın hafızasını serbest bırak
        }
    }
    else
    {
        printf("Usage: %s [file_name]\n", argv[0]);
    }

    return 0;
}
