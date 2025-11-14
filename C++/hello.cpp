extern "C" void* __stdcall GetStdHandle(unsigned int);
extern "C" int __stdcall WriteConsoleA(void*, const void*, unsigned long, unsigned long*, void*);
extern "C" void __stdcall ExitProcess(unsigned int);

void mainCRTStartup() {
    const char msg[] = "Hello, World!\n";
    unsigned long written;
    void* hConsole = GetStdHandle((unsigned int)-11); // STD_OUTPUT_HANDLE
    WriteConsoleA(hConsole, msg, sizeof(msg) - 1, &written, nullptr);
    ExitProcess(0);
}
