/*
 * my_hunter
 */

#ifndef MOUSE_LISTENER_HPP
#define MOUSE_LISTENER_HPP

class MouseListener {
    public:
        virtual ~MouseListener() = default;

        virtual void onMousePressed(int x, int y) = 0;
        virtual void onMouseReleased(int x, int y) = 0;

        virtual void onMouseMoved(int x, int y) = 0;

        virtual void onMouseEntered(int x, int y) = 0;
        virtual void onMouseExited(int x, int y) = 0;
};

#endif
