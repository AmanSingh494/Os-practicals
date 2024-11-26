#include <iostream>
using namespace std;
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
void filecopy(int f1, int f2);
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "File not found" << endl;
        exit(1);
    }

    int fd1 = open(argv[1], 0);
    if (fd1 == -1)
    {
        cout << "\nError in file opening.";
        exit(1);
    }
    int fd2 = creat(argv[2], 0666);
    if (fd2 == -1)
    {
        cout << "\nError while creating file ";
        exit(1);
    }
    filecopy(fd1, fd2);
    close(fd1);
    close(fd2);
    return 0;
}
void filecopy(int f1, int f2)
{
    char buf[512];
    int cnt;
    while (cnt = read(f1, buf, sizeof(buf)))
    {
        write(f2, buf, cnt);
    }
}