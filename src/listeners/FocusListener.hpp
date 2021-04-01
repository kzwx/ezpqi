/*
 * my_hunter
 */

#ifndef FOCUS_LISTENER_HPP
#define FOCUS_LISTENER_HPP

class FocusListener {
    public:
        virtual ~FocusListener() = default;

        virtual void onFocusIn() = 0;
        virtual void onFocusOut() = 0;
};

#endif
