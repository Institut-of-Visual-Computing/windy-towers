#include "BTS7960.h"


BTS7960::BTS7960(uint8_t EN, uint8_t L_PWM, uint8_t R_PWM) : en_{EN}, l_pwm_{L_PWM}, r_pwm_{R_PWM}, direction_{Direction::STOPPED}, enabled_{false}, currentPwm_{0}
{
    pinMode(l_pwm_, OUTPUT);
    pinMode(r_pwm_, OUTPUT);

    Stop();
    pinMode(en_, OUTPUT);
    Enable();
}

void BTS7960::Stop()
{
    analogWrite(l_pwm_, LOW);
    analogWrite(r_pwm_, LOW);
    currentPwm_ = 0;
    direction_ = Direction::STOPPED;
}

void BTS7960::Disable()
{
    digitalWrite(en_, LOW);
    enabled_ = false;
}

void BTS7960::Enable()
{
    digitalWrite(en_, HIGH);
    enabled_ = true;
}

void BTS7960::TurnLeft(uint8_t pwm)
{
    if(direction_ != Direction::LEFT)
    {
        analogWrite(r_pwm_, 0);
	    delayMicroseconds(100);
    }
    currentPwm_ = pwm;
    analogWrite(l_pwm_, currentPwm_);
    direction_ = Direction::LEFT;
}

void BTS7960::TurnRight(uint8_t pwm)
{
    if(direction_ != Direction::RIGHT)
    {
        analogWrite(l_pwm_, 0);
	    delayMicroseconds(100);
    }
    currentPwm_ = pwm;
    analogWrite(r_pwm_, currentPwm_);
    direction_ = Direction::RIGHT;
}

void BTS7960::Turn(Direction direction, uint8_t pwm)
{

    if(direction == Direction::STOPPED)
    {
        Stop();
    } 
    else if(direction == Direction::LEFT)
    {
        TurnLeft(pwm);
    } 
    else 
    {
        TurnRight(pwm);
    }
}