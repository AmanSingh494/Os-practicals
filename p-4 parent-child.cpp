#include <iostream>
#include <unistd.h>

using namespace std;
int main() {
    pid_t pid = fork();
    if(pid < 0){
        cerr << "Fork failed" << endl;
        return -1;
    }
    if(pid == 0) cout << "Child process executing" <<endl;
    else cout << "Parent process executing" << endl;
    
return 0;
}