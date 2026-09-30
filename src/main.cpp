// You will write all your code for this tutorial here!
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>

int main()
{
    // initialisation
    bn::core::init();
    int counter = 0;
    // setting bg color
    bn::backdrop::set_color(bn::color(20, 20, 31));

    // while game runs,
    while (true)
    {
        // since it is 60 fps, every 60 frames, switch colour between rgb.
        if (counter == 60)
        {
            bn::backdrop::set_color(bn::color(0, 20, 0));
        }
        else if (counter == 120)
        {
            bn::backdrop::set_color(bn::color(20, 0, 0));
        }
        else if (counter == 180)
        {
            bn::backdrop::set_color(bn::color(0, 0, 20));
            counter = 0;
        }
        counter++;
        // update frame
        bn::core::update();
    }
}