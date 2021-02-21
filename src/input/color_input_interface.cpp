//
// Created by paul on 19/02/2021.
//

#include <input/color_input_interface.hpp>
#include <manager.hpp>

ColorInputInterface::ColorInputInterface() {

}

bool ColorInputInterface::command_call(std::vector<std::string> &args) {
    if(args.size() != 2) return false;
    std::string param = args[1];

    ColorInputInterface* interface = Manager::get().get_color_input();
    if(interface == nullptr) return false;

    if (param == "n" || param == "night") {
        interface->set_night_mode();
    } else if (param == "d" || param == "day") {
        interface->set_day_mode();
    } else {
        return false;
    }

    return true;
}

