//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_COLORATION_SERVICE_HPP
#define HORLOGE_COLORATION_SERVICE_HPP

#include <tools/selector.hpp>
#include "tools/safearray.hpp"
#include "tools/settings.hpp"
#include <service/service.hpp>
#include <dial_mixer.hpp>

class ColorationService : public Service, public Selector {
private:

    void beforeChanging() override;

protected:
    SafeArray<color_t, DIAL_COUNT> pattern;
    DialMixer& mixer;

public:
    ColorationService(DialMixer& mixer, size_t nb_modes, size_t default_mode);
};


#endif //HORLOGE_COLORATION_SERVICE_HPP
