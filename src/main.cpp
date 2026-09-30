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
    bool apress = false;
    int currentCounter = 0;

    // setting bg color
    bn::backdrop::set_color(bn::color(20, 20, 31));

    // while game runs,
    while (true)
    {
        // a pressed, turn screen black for 2 seconds
        if (bn::keypad::a_pressed())
        {
            counter = 0;
            apress = true;
            bn::backdrop::set_color(bn::color(0, 0, 0));
        }

        // logic to turn screen to normal after pressing a
        if (apress == true && counter == 120)
        {
            apress = false;
            counter = 0;
            bn::backdrop::set_color(bn::color(20, 20, 31));
        }

        // b button will pause frame switching.
        if (bn::keypad::b_pressed())
        {
            currentCounter = counter;
        }
        if (bn::keypad::b_held())
        {
            if (counter != currentCounter)
            {
                counter = currentCounter;
            }
        }
        if (bn::keypad::b_released())
        {
            counter = 0;
            currentCounter = 0;
        }
        // since it is 60 fps, every 60 frames, switch colour between rgb.
        if (counter == 60 && !apress)
        {
            bn::backdrop::set_color(bn::color(0, 20, 0));
        }
        else if (counter == 120 && !apress)
        {
            bn::backdrop::set_color(bn::color(20, 0, 0));
        }
        else if (counter == 180 && !apress)
        {
            bn::backdrop::set_color(bn::color(0, 0, 20));
            counter = 0;
        }
        counter++;
        // update frame
        bn::core::update();
    }
}