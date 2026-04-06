#include "Base.hpp"
#include "identify.hpp"
int main()
{
    Base *lilly = generate();
    Base *snape = generate();

    identify(*lilly);
    identify(*snape);
}
