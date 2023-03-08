
#ifndef UTIL_H
#define UTIL_H

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

#endif

#ifndef TERMINAL_H
#define TERMINAL_H

#include <math.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

/**
 * Constructor method for Terminal class.
 * Initializes the Terminal.
 * @param layout: A pointer to a layout object.
 */
class Terminal {
   public:
    /**
     * Constructor method for Terminal class.
     * Initializes the Terminal.
     * @param layout: A pointer to a layout object.
     */
    Terminal(Layout* layout);

    /**
     * Destructor method for Terminal class.
     * Exits the terminal.
     */
    ~Terminal();

    /**
     * Checks if the user has pressed any keys.
     * If the user has pressed a key, it is handled.
     */
    static void checkInputs();

    /**
     * Initializes the Terminal window.
     */
    static void initTerminal();

    /**
     * Checks if the size of the Terminal window is big enough to display all content.
     * If the window is too small, prints an error message and exits the program.
     */
    static void checkScreenSize();

    /**
     * Exits the Terminal window with a fancy animation.
     */
    static void exit();

    static void addElement(WindowElement* element);

    static void removeElement(WindowElement* element);

    static void removeAllElements();

    static void select();

    static Group* rootWindow;
    static termios oldTerminalSettings;
    static struct winsize size;
    static struct pollfd fds[1];
    static bool exitFlag;
    const static int minWidth = 100;
    const static int minHeight = 30;
};

termios Terminal::oldTerminalSettings;
struct winsize Terminal::size;
Group* Terminal::rootWindow;
struct pollfd Terminal::fds[1];
bool Terminal::exitFlag = false;

Terminal::Terminal(Layout* layout) {
    initTerminal();
    rootWindow = new Group(layout);
    // rootWindow->paint(0, 0, size.ws_col, size.ws_row);
}

Terminal::~Terminal() {
    // printf("033[?1049l");  // Disable alternate screen buffer
    // printf("033[?25h");    // Show cursor
    // printf("033[?1000l");  // Disable mouse input
    // tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminalSettings);
    delete rootWindow;
}

void Terminal::initTerminal() {
    // printf("033[?1049h");  // Enable alternate screen buffer

    struct termios raw_attr;

    tcgetattr(STDIN_FILENO, &oldTerminalSettings);
    raw_attr = oldTerminalSettings;
    cfmakeraw(&raw_attr);
    raw_attr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw_attr);

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);

    // printf("033[?1000h");  // Enable mouse input
    hideCursor();

    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;
}

// Checking the size of the terminal window and if it is too small, it will print an error message and exit the program.
void Terminal::checkScreenSize() {
    if (size.ws_col < minWidth || size.ws_row < minHeight) {
        std::cout << getColorCode(LIGHT_CYAN) << "🚨 Screen size is too small." << std::endl;
        std::cout << "Please resize your Window to at least" << minWidth << "x" << minHeight << " characters." << std::endl;
        std::cout << "Your terminal is currently " << size.ws_col << "x" << size.ws_row << " characters." << std::endl;
        std::cout << getColorCode(RESET);
        std::exit(1);
    }
}

void Terminal::checkInputs() {
    rootWindow->select();
    rootWindow->paint(0, 0, size.ws_col, size.ws_row);
    std::cout.flush();

    std::string input;
    while (!exitFlag) {
        int c = getchar();

        if (c == 3) {  // Check for Control+C
            exitFlag = true;
        } else if (c == 27) {        // Check for escape sequence
            if (getchar() == '[') {  // Check for arrow keys
                ArrowKey arrow = getArrowKey(getchar());
                if (arrow != ArrowKey::NONE) {
                    WindowElement::focusedElement->arrowKeyEvent(arrow, WindowElement::focusedElement);
                }
            }
        } else {
            WindowElement::focusedElement->keyEvent(c);
        }

        rootWindow->paint(0, 0, size.ws_col, size.ws_row);
        std::cout.flush();
    }
    exit();
}

void Terminal::exit() {
    showCursor();
    setCursorPosition(0, 0);

    // printf("033[?1000l");  // Disable mouse input
    oldTerminalSettings.c_lflag |= (ICANON | ECHO);
    cfsetspeed(&oldTerminalSettings, B38400);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTerminalSettings);
    tcflush(STDIN_FILENO, TCIFLUSH);

    // for (int t = 5; t > 0; t--) {
    //     int time = t * t;
    //     for (int i = 0; i < size.ws_col; i++) {
    //         float x = (float)i / (float)size.ws_col * 2 - 1;
    //         float eqTop = -pow(abs(x), time) + 1;
    //         float eqBottom = pow(abs(x), time) - 1;
    //
    //         for (int i = 0; i < size.ws_row; i++) {
    //             float y = (float)i / (float)size.ws_row * 2 - 1;
    //             if (y < eqTop && y > eqBottom) {
    //                 cout << "▓";
    //             }
    //         }
    //     }
    //
    //     sleep(1);
    // }
    std::cout << "033[2J033[1;1H"
              //  << "033[1J"
              << "Goodbye. 👋" << std::endl;
}

void Terminal::addElement(WindowElement* element) {
    rootWindow->addElement(element);
}

void Terminal::removeElement(WindowElement* element) {
    if (element == rootWindow) {
        return;
    }
    if (element == WindowElement::focusedElement) {
        WindowElement::focusedElement = rootWindow;
    }
    rootWindow->removeElement(element);
}

void Terminal::removeAllElements() {
    rootWindow->removeAllElements();
    WindowElement::focusedElement = rootWindow;
}

void Terminal::select() {
    rootWindow->select();
}
#endif

#ifndef GROUP_H
#define GROUP_H

#include <sstream>
#include <string>
#include <vector>

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
    Group(Layout* layout, std::string title);
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
    void removeElement(WindowElement* element, bool remove = true);
    /**
     * Removes all WindowElements from the Group
     */
    void removeAllElements();
    /**
     * Hides all WindowElements in the Group
     */
    void hideAllElements();
    /**
     * Shows all WindowElements in the Group
     */
    void showAllElements();
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
    void arrowKeyEvent(ArrowKey key, WindowElement* element) override;

    /**
     * Selects the Group
     */
    bool select() override;
    /**
     * Sets the title of the Group
     * @param title The title of the Group
     */
    void setTitle(std::string title);
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
    std::string title;
    bool borderHidden;
    Color backgroundColor;
    std::vector<WindowElement*> elements;
    Layout* layout;
};
#endif
