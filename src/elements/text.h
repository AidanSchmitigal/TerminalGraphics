#ifndef TEXT_H
#define TEXT_H

#include <string>

#include "element.h"

using namespace std;

/**
 * Creates a new Text object.
 * @param text the string to be displayed
 * @param widthPercent the percentage of the width of the window that the Text should take up.
 */
class Text : public WindowElement {
   public:
    /**
     * Creates a new Text object.
     * @param text the string to be displayed
     */
    Text(string text);

    /**
     * Creates a new Text object.
     * @param text the string to be displayed
     * @param widthPercent the percentage of the width of the window that the Text should take up.
     */
    Text(string text, float widthPercent);

    /**
     * Sets the text of the Text object.
     * @param text the string to be displayed
     */
    void setText(string text);

    /**
     * Displays the text on the window.
     * @param x the x coordinate of the text's position
     * @param y the y coordinate of the text's position
     * @param width the width of the text
     * @param height the height of the text
     */
    void paint(int x, int y, int width, int height);

   private:
    string text = "";
};

#endif
