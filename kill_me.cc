#include <cstdio>
#include <iostream>
#include <cstdlib>

class foo
{
public:
    foo()
    {
        ++*this;
    }

    void operator ++()
    {
        std::cerr << "incremented self\n";
        return;
    }
};


int 
main()
{
    foo f;
    return( EXIT_SUCCESS );
}
