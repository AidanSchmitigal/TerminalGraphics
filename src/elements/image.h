#ifndef IMAGE_H
#define IMAGE_H

#include "element.h"

using namespace std;

/**
 * Constructs an Image object with a given path and size.
 *
 * @param path The path of the image to be constructed.
 * @param size The size of the image to be constructed.
 */
class Image : public WindowElement {
   public:
    /**
     * Constructs an Image object with a given path and size.
     *
     * @param path The path of the image to be constructed.
     * @param size The size of the image to be constructed.
     */
    Image(string path, int size);

    /**
     * Sets the image of the Image object.
     *
     * @param path The path of the image to be set.
     */
    void setImage(string path);

    /**
     * Paints the image object at the given coordinates.
     *
     * @param x The x coordinate at which the image should be painted.
     * @param y The y coordinate at which the image should be painted.
     * @param width The width at which the image should be painted.
     * @param height The height at which the image should be painted.
     */
    void paint(int x, int y, int width, int height) override;

   private:
    string path = "";
};

#endif
