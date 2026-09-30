// You will write all your code for this tutorial here!
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>

int main()
{
    // initialisation
    bn::core::init();

    // setting bg color
    bn::backdrop::set_color(bn::color(20, 20, 31));

    // while game runs,
    while (true)
    {
        // update frame
        bn::core::update();
    }
}