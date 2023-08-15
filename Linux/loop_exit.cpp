#include <cstdio>
#include <signal.h> //signal header

bool signal_handle = false;

void interruptSignal(int signal)
{
    (void)signal;
    signal_handle = true;
}

int main()
{
    signal(SIGINT, interruptSignal);
    while (true && !signal_handle)
    {
        printf("Hello World!\n");
    }
}
