#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum Color {
    RESET = 0,
    BOLD = 1,
    DIM = 2,
    UNDERLINED = 4,
    BLINK = 5,
    REVERSE = 7,
    HIDDEN = 8,
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37,
    GRAY = 90,
    LIGHT_RED = 91,
    LIGHT_GREEN = 92,
    LIGHT_YELLOW = 93,
    LIGHT_BLUE = 94,
    LIGHT_MAGENTA = 95,
    LIGHT_CYAN = 96,
    LIGHT_WHITE = 97,
};

enum State {
    DEFAULT = LIGHT_WHITE,
    DISABLED = DIM,
    SUCCESS = GREEN,
    ERROR = RED,
};

enum Key {
    ENTER = 13,
    ESCAPE = 27,
    TAB = 9,
    SPACE = 32,
    BACKSPACE = 127,
};

enum ArrowKey {
    UP = 65,
    DOWN = 66,
    RIGHT = 67,
    LEFT = 68,
    NONE = -1
};

/**
 * Returns the arrow key pressed by the user
 * @return The arrow key pressed by the user
 */
ArrowKey getArrowKey(int key);

/**
 * Returns the color code of the given color
 * @param color The color for which to get the color code
 * @return The color code of the given color
 */
std::string getColorCode(int color);

/**
 * Draws text on the console at the given position with the given color
 * @param text The text to be drawn on the console
 * @param x The X coordinate of the position at which to draw the text
 * @param y The Y coordinate of the position at which to draw the text
 * @param color The color of the text to be drawn on the console
 */
void drawText(std::string text, int x, int y, int color = LIGHT_WHITE);

/**
 * Draws text on the console at the given position with the given color
 * @param text The text to be drawn on the console
 * @param x The X coordinate of the position at which to draw the text
 * @param y The Y coordinate of the position at which to draw the text
 */
void drawRawText(std::string text, int x, int y);

/**
 * Clears the area of the console at the given position
 * @param x The X coordinate of the position to be cleared
 * @param y The Y coordinate of the position to be cleared
 * @param width The width of the area to be cleared
 * @param height The height of the area to be cleared
 */
void clearArea(int x, int y, int width, int height);

/**
 * Fills the area of the console at the given position with the given color
 * @param x The X coordinate of the position to be filled
 * @param y The Y coordinate of the position to be filled
 * @param width The width of the area to be filled
 * @param height The height of the area to be filled
 * @param color The color of the area to be filled
 */
void fillArea(int x, int y, int width, int height, int color = LIGHT_WHITE);

/**
 * Converts the given string to capital case
 * @param text The string to be converted to capital case
 * @return The given string converted to capital case
 */
std::string toCapitalCase(std::string text);

/**
 * Sets the console cursor position to the given position
 * @param x The X coordinate of the console cursor position to be set
 * @param y The Y coordinate of the console cursor position to be set
 */
void setCursorPosition(int x, int y);

/**
 * Shows the console cursor
 */
void showCursor();

/**
 * Hides the console cursor
 */
void hideCursor();

/**
 * Draws a box on the console at the given position with the given width and height
 * @param x The X coordinate of the position at which to draw the box
 * @param y The Y coordinate of the position at which to draw the box
 * @param width The width of the box to be drawn on the console
 * @param height The height of the box to be drawn on the console
 * @param color The color of the box to be drawn on the console
 */
void drawBox(int x, int y, int width, int height, int color = LIGHT_WHITE);

/**
 * Draws a box with a title on the console at the given position with the given width, height and title
 * @param x The X coordinate of the position at which to draw the box
 * @param y The Y coordinate of the position at which to draw the box
 * @param width The width of the box to be drawn on the console
 * @param height The height of the box to be drawn on the console
 * @param title The title of the box to be drawn on the console
 * @param color The color of the box to be drawn on the console
 */
void drawBox(int x, int y, int width, int height, std::string title, int color = LIGHT_WHITE);

/**
 * Draws an image on the console at the given position with the given width and height
 * @param path The path of the image to be drawn on the console
 * @param x The X coordinate of the position at which to draw the image
 * @param y The Y coordinate of the position at which to draw the image
 * @param width The width of the image to be drawn on the console
 * @param height The height of the image to be drawn on the console
 */
void drawImage(std::string path, int x, int y, int width, int height);

/**
 * Reads an image from the given file path
 * @param path The path of the image file to be read
 * @return A 2D vector representing the image read from the file
 */
std::vector<std::vector<int>> readImage(std::string path);

/**
 * Scales the given image to the given width and height
 * @param image The image to be scaled as a 2D vector
 * @param width The width to which to scale the image
 * @param height The height to which to scale the image
 * @return The given image scaled to the given width and height as a 2D vector
 */
std::vector<std::vector<int>> scaleImage(std::vector<std::vector<int>> image, int width, int height);

//;;split

ArrowKey getArrowKey(int key) {
    switch (key) {
        case UP:
            return UP;
        case DOWN:
            return DOWN;
        case RIGHT:
            return RIGHT;
        case LEFT:
            return LEFT;
        default:
            return NONE;
    }
}

std::string getColorCode(int color) {
    return "\033[" + std::to_string(color) + "m";
}

void drawText(std::string text, int x, int y, int color) {
    if (x < 0 || y < 0) {
        return;
    }
    setCursorPosition(x, y);
    std::cout << getColorCode(color) << text << "\033[0m";
}

void drawRawText(std::string text, int x, int y) {
    if (x < 0 || y < 0) {
        return;
    }
    setCursorPosition(x, y);
    std::cout << text;
}

void clearArea(int x, int y, int width, int height) {
    if (x < 0 || y < 0) {
        return;
    }
    for (int i = 0; i < height; i++) {
        setCursorPosition(x, y + i);
        for (int j = 0; j < width; j++) {
            std::cout << " ";
        }
    }
}

void fillArea(int x, int y, int width, int height, int color) {
    if (x < 0 || y < 0) {
        return;
    }
    for (int i = 0; i < height; i++) {
        setCursorPosition(x, y + i);
        for (int j = 0; j < width; j++) {
            std::cout << getColorCode(color) << "█";
        }
    }
}

std::string toCapitalCase(std::string text) {
    std::string result = "";
    bool isSpace = true;
    for (int i = 0; i < text.length(); i++) {
        if (isSpace) {
            result += toupper(text[i]);
            isSpace = false;
        } else {
            if (text[i] == ' ' || text[i] == '_') {
                isSpace = true;
                result += ' ';
            } else {
                result += tolower(text[i]);
            }
        }
    }
    return result;
}

void setCursorPosition(int x, int y) {
    std::cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
}

void showCursor() {
    std::cout << "\033[?25h";
}

void hideCursor() {
    std::cout << "\033[?25l";
}

void drawBox(int x, int y, int width, int height, int color) {
    if (x < 0 || y < 0) {
        return;
    }
    // Draw corners
    drawText("╭", x, y, color);
    drawText("╰", x, y + height - 1, color);
    drawText("╮", x + width - 1, y, color);
    drawText("╯", x + width - 1, y + height - 1, color);

    // Draw side borders
    for (int i = 1; i < height - 1; i++) {
        drawText("│", x, y + i, color);
        drawText("│", x + width - 1, y + i, color);
    }

    // Draw top & bottom border
    std::string border = "";
    for (int i = 1; i < width - 1; i++) {
        border += "─";
    }
    drawText(border, x + 1, y, color);
    drawText(border, x + 1, y + height - 1, color);
}

void drawBox(int x, int y, int width, int height, std::string title, int color) {
    if (x < 0 || y < 0) {
        return;
    }
    drawBox(x, y, width, height, color);
    drawText("┤" + title + "├", x + 1, y, color);
}

void drawImage(std::string path, int x, int y, int width, int height) {
    if (x < 0 || y < 0) {
        return;
    }
    std::vector<std::vector<int>> image = readImage(path);
    std::vector<std::vector<int>> scaledImage = scaleImage(image, width, height);
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            int colorCode = scaledImage[j][i];
            // Check if outside color range
            if (colorCode < 0 || colorCode > 7) {
                std::string colorToText = std::to_string(colorCode);
                drawText(colorToText, x + i, y + j, 0);
            } else {
                drawText("█", x + i, y + j, colorCode + 30);
            }
        }
    }
}

std::vector<std::vector<int>> readImage(std::string path) {
    std::vector<std::vector<int>> image;
    std::ifstream file(path);
    std::string line;
    while (getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            row.push_back(c - '0');
        }
        image.push_back(row);
    }
    return image;
}

std::vector<std::vector<int>> scaleImage(std::vector<std::vector<int>> image, int width, int height) {
    int imageWidth = image[0].size();
    int imageHeight = image.size();
    std::vector<std::vector<int>> scaledImage(height, std::vector<int>(width));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int imageX = (x * imageWidth) / width;
            int imageY = (y * imageHeight) / height;
            scaledImage[y][x] = image[imageY][imageX];
        }
    }
    return scaledImage;
}
