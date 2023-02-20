#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>

#include "../layouts/layout.h"
#include "../terminal.h"
#include "element.h"
#include "spacer.h"

using namespace std;

/**
 * Constructor for Group
 * @param layout A pointer to the layout of the Group
 */
class Group : public WindowElement {
   public:
    /**
     * Constructor for Group
     * @param layout A pointer to the layout of the Group
     */
    Group(Layout* layout);
    /**
     * Constructor for Group
     * @param layout A pointer to the layout of the Group
     * @param title The title of the Group
     */
    Group(Layout* layout, string title);
    /**
     * Destructor for Group
     */
    ~Group();
    /**
     * Adds a WindowElement to the Group
     * @param element A pointer to the WindowElement to add
     * @param spacer An integer representing the size of the Spacer to add after the WindowElement
     */
    void addElement(WindowElement* element, int spacer = 0);
    /**
     * Returns the WindowElement at the specified index
     * @param index The index of the WindowElement to return
     * @return The WindowElement at the specified index
     */
    WindowElement* getElement(int index);
    /**
     * Removes the specified WindowElement from the Group
     * @param element A pointer to the WindowElement to remove
     */
    void removeElement(WindowElement* element);
    /**
     * Removes all WindowElements from the Group
     */
    void removeAllElements();
    /**
     * Paints the Group to the screen
     * @param x The x coordinate to paint the Group at
     * @param y The y coordinate to paint the Group at
     * @param width The width of the Group
     * @param height The height of the Group
     */
    void paint(int x, int y, int width, int height) override;

    /**
     * Handles a key press event
     * @param key The key that was pressed
     */
    void arrowKeyEvent(ArrowKey key) override;

    /**
     * Selects the Group
     */
    void select() override;
    /**
     * Sets the title of the Group
     * @param title The title of the Group
     */
    void setTitle(string title);
    /**
     * Sets whether or not the border of the Group should be hidden
     * @param borderHidden A boolean representing whether or not the border should be hidden
     */
    void setBorderHidden(bool borderHidden);
    /**
     * Sets the layout of the Group
     * @param layout A pointer to the layout of the Group
     */
    void setLayout(Layout* layout);
    /**
     * Sets the background color of the Group
     * @param color The color to set the background to
     */
    void setBackgroundColor(Color color);

   private:
    string title;
    bool borderHidden;
    Color backgroundColor;
    vector<WindowElement*> elements;
    Layout* layout;
};

#endif
