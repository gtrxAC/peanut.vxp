extern "C" void _exit(int a);

namespace __gnu_cxx
{
    void __verbose_terminate_handler()
    {
        _exit(0);
    }
}