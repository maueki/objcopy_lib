
#include <cstdio>

extern size_t get_size1();
extern size_t get_size2();

int main(int argc, char *argv[])
{
    printf("get_size1() == %d\n", get_size1());
    printf("get_size2() == %d\n", get_size2());
    return 0;
}
