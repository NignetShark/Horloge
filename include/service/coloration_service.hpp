//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_COLORATION_SERVICE_HPP
#define HORLOGE_COLORATION_SERVICE_HPP

#include <tools/selector.hpp>
#include "tools/pingpongarray.hpp"
#include "tools/settings.hpp"
#include <service/async_service.hpp>
#include <service/dial_mixer_interface.hpp>

class ColorationService : public AsyncService, public Selector {
private:

    void beforeChanging() override;

protected:


public:
    ColorationService(size_t nb_modes, size_t default_mode);
};


#endif //HORLOGE_COLORATION_SERVICE_HPP
