#include <iostream>
#include <windows.h> //ConsoleHandler()
#include <conio.h> //_getch()

uint8_t ascii_number = 0;

BOOL WINAPI ConsoleHandler(DWORD dwType)
{
    if (dwType == CTRL_C_EVENT)
    {
        ascii_number = _getch();
        printf("Interrupted Ctrl+C\n");
    }
    
    return TRUE;
}

int main()
{
    while (true && ascii_number != 3)
    {
        if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE))
        {
            return EXIT_FAILURE;
        }
        
        std::cout << "Hello World!\n";
    }
}
