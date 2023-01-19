#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main( int argc, char *argv[]) {

    char buf[2048];

    char *filename = argv[1];

    int file = open(filename, O_RDONLY);

    int count = read(file, buf, sizeof buf);

    write(1, buf, count);

    close(file);
}