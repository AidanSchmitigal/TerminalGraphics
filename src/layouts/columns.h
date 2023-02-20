#ifndef COLUMNS_H
#define COLUMNS_H

#include <vector>

#include "layout.h"

using namespace std;

/**
 * Constructor for ColumnLayout object
 * @param widths an array of integers representing the width of each element in the layout
 */
class ColumnLayout : public Layout {
   public:
    /**
     * Constructor for ColumnLayout object
     * @param widths an array of integers representing the width of each element in the layout
     */
    ColumnLayout(int widths[]);

    /**
     * Paints the layout on the screen
     * @param x the x position of the layout on the screen
     * @param y the y position of the layout on the screen
     * @param width the width of the layout on the screen
     * @param height the height of the layout on the screen
     * @param elements a vector of WindowElement objects to be included in the layout
     */
    void paint(int x, int y, int width, int height, vector<WindowElement*> elements) override;

    /**
     * Selects the next WindowElement in the layout
     * @param selectedElement the currently selected WindowElement
     * @param elements a vector of WindowElement objects to be included in the layout
     * @param direction the direction to select the next WindowElement in
     */
    bool selectNext(WindowElement* selectedElement, vector<WindowElement*> elements, ArrowKey direction) override;

   private:
    int* widths;
};

#endif
