//
// Created by paul on 19/02/2021.
//

#ifndef HORLOGE_COLOR_INPUT_INTERFACE_HPP
#define HORLOGE_COLOR_INPUT_INTERFACE_HPP

#include <vector>
#include <string>

/**
 * Provide an interface to change the color
 */
class ColorInputInterface {
public:

private:

public:
    ColorInputInterface();

    virtual void set_night_mode() = 0;
    virtual void set_day_mode() = 0;

    virtual void next_color_mode() = 0;
    virtual void previous_color_mode() = 0;

    static bool command_call(std::vector<std::string> &args);
};

#endif //HORLOGE_COLOR_INPUT_INTERFACE_HPP
