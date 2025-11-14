// Compile with: gcc -o hello.exe hello.c 

void* GetStdHandle(unsigned int nStdHandle);
int WriteConsoleA(void* hConsoleOutput, const void* lpBuffer, unsigned long nNumberOfCharsToWrite,
                  unsigned long* lpNumberOfCharsWritten, void* lpReserved);
void ExitProcess(unsigned int uExitCode);

void main() {
    const char msg[] = "Hello, World!\n";
    unsigned long written;
    void* hConsole = GetStdHandle((unsigned int)-11); // STD_OUTPUT_HANDLE = -11
    WriteConsoleA(hConsole, msg, sizeof(msg) - 1, &written, 0);
    ExitProcess(0);
}