//
// Created by paul on 18/02/2021.
//

#ifndef HORLOGE_DIAL_MIXER_INTERFACE_HPP
#define HORLOGE_DIAL_MIXER_INTERFACE_HPP

#include "tools/ledcolor.hpp"
#include "tools/settings.hpp"
#include "tools/safearray.hpp"

class DialMixerInterface {
public:
    virtual void paint() = 0;
};


#endif //HORLOGE_DIAL_MIXER_INTERFACE_HPP
