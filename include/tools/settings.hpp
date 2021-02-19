//
// Created by paul on 17/02/2021.
//

#ifndef HORLOGE_SETTINGS_HPP
#define HORLOGE_SETTINGS_HPP

#define DIAL_COUNT              6                          // 6 dials
#define DIGITS_COUNT            10                         // 10 digits (from 0 to 9)
#define LED_COUNT               (DIAL_COUNT * DIGITS_COUNT)

#define TARGET_FREQ             800000                     // Fréquence (800kHz)
#define HORLOGE_GPIO_PIN        12                         // PIN de sortie du signal PWM
#define DMA                     10                         // Sélection du service PWM
#define STRIP_TYPE              WS2811_STRIP_GRB		   // Formatage de la couleur

#endif //HORLOGE_SETTINGS_HPP
