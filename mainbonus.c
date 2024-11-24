#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void read_from_fd(int fd)
{
    char *line;

    // Dosyayı satır satır okuma
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
}

int main(void)
{
    int fd1, fd2, fd3;

    // Dosyaları açma
    fd1 = open("text.txt", O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error opening text.txt");
        return (1);
    }

    fd2 = open("text2.txt", O_RDONLY);
    if (fd2 == -1)
    {
        perror("Error opening text2.txt");
        close(fd1);
        return (1);
    }

    fd3 = open("text3.txt", O_RDONLY);
    if (fd3 == -1)
    {
        perror("Error opening text3.txt");
        close(fd1);
        close(fd2);
        return (1);
    }

    // Dosya 1'i okuma
    printf("\nReading from text.txt:\n");
    read_from_fd(fd1);
    close(fd1);

    // Dosya 2'yi okuma
    printf("\nReading from text2.txt:\n");
    read_from_fd(fd2);
    close(fd2);

    // Dosya 3'ü okuma
    printf("\nReading from text3.txt:\n");
    read_from_fd(fd3);
    close(fd3);

    return (0);
}
