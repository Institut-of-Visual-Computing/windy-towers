#pragma once

#include "Arduino.h"

class BTS7960
{
    public:
        enum class Direction
        {
            STOPPED = 0,
            LEFT = 1,
            RIGHT = 2,
        };

        BTS7960(uint8_t EN, uint8_t L_PWM, uint8_t R_PWM);
        
        void Enable();
        void Disable();
        void Stop();
        void TurnLeft(uint8_t pwm);
        void TurnRight(uint8_t pwm);
        void Turn(Direction direction, uint8_t pwm);
        const bool isEnabled() const { return enabled_; }
        const Direction getDirection() const { return direction_; }
        const uint8_t getPwmValue() const { return currentPwm_; }

    private:
        uint8_t en_;
        uint8_t l_pwm_;
        uint8_t r_pwm_;
        Direction direction_;
        bool enabled_;
        uint8_t currentPwm_;
};
