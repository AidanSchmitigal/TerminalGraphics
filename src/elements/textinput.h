#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include <string>

#include "element.h"

using namespace std;

/**
 * Constructor for TextInput object
 * @param title the title of the text input
 * @param templateText the template text to be shown if input is empty
 * @param widthPercent the percentage of the screen's width the text input should take up, defaults to 0.6
 */
class TextInput : public WindowElement {
   public:
    /**
     * Constructor for TextInput object
     * @param title the title of the text input
     * @param templateText the template text to be shown if input is empty
     * @param widthPercent the percentage of the screen's width the text input should take up, defaults to 0.6
     */
    TextInput(string title, string templateText, float widthPercent = 0.6);

    /**
     * Sets the title of the text input
     * @param title the new title to be set
     */
    void setTitle(string title);

    /**
     * Sets the text input's current text
     * @param text the new text to be set
     */
    void setText(string text);

    /**
     * Paints the text input on the screen
     * @param x the x position of the text input on the screen
     * @param y the y position of the text input on the screen
     * @param width the width of the text input on the screen
     * @param height the height of the text input on the screen
     */
    void paint(int x, int y, int width, int height) override;

    /**
     * Gets the input that the user has entered into the text input
     * @return the user's input
     */
    string getInput();

   private:
    string title;
    string text = "";
    string templateText;
};

#endif
