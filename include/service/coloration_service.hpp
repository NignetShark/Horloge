//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_COLORATION_SERVICE_HPP
#define HORLOGE_COLORATION_SERVICE_HPP

#include <tools/selector.hpp>
#include "tools/ping_pong_array.hpp"
#include "tools/settings.hpp"
#include <service/async_service.hpp>
#include <service/dial_mixer_interface.hpp>
#include <input/color_input_interface.hpp>

/**
 * Abstract class of any coloration service
 */
class ColorationService : public AsyncService, protected Selector, public ColorInputInterface {
private:

    /**
     * Called when change is requested
     */
    void mode_changed() override;

    virtual unsigned int get_night_mode() = 0;

public:
    void next_color_mode() override;

    void previous_color_mode() override;

    void set_day_mode() override;

    void set_night_mode() override;

protected:


public:
    ColorationService(size_t nb_modes, size_t default_mode);
};


#endif //HORLOGE_COLORATION_SERVICE_HPP
