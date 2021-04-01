/*
 * my_hunter
 */

#ifndef KEYBOARD_LISTENER_HPP
#define KEYBOARD_LISTENER_HPP

class KeyboardListener {
    public:
        virtual ~KeyboardListener() = default;

        virtual void onKeyPressed(char character) = 0;
};

#endif
