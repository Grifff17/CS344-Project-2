#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc == 1) {
        int count = 2048;
        char buf[2048];

        while(count > 0) {
            count = read(0, buf, sizeof buf);
            write(1, buf, count);
        }

    } else {
        for(int i=0; i < argc; i++) {

            int count = 2048;
            char buf[2048];
            char *filename = argv[i+1];
            int file = open(filename, O_RDONLY);

            while(count > 0) {
                count = read(file, buf, sizeof buf);
                write(1, buf, count);
            }

            close(file);
        }
    }

}