// 3. Implementation of write () and read () system calls. 

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd;
    char buff[] = "This is Kln Lokesh.";
    fd = open("File1.txt", O_WRONLY | O_CREAT, 0644);
    if(fd == -1){
        perror("open");
        return 1;
    }
    int bytesWritten = write(fd, buff, sizeof(buff));
    if(bytesWritten == -1){
        perror("write");
        return 1;
    }
    // printf("%s", buff);
    printf("%d bytes written.\n", bytesWritten);
    fd = open("File1.txt", O_RDONLY);
    if(fd == -1){
        perror("open");
        return 1;
    }
    char readBuff[1024];
    int bytesRead = read(fd, readBuff, 1024);
    if(bytesRead == -1){
        perror("read");
        return 1;
    }
    printf("%d bytes read", bytesRead);
    close(fd);
    return 0;
}
