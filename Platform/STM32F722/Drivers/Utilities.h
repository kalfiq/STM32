#ifndef UTILITIES_H
#define UTILITIES_H

#define REG_WRITE(reg, value)       (*reg = value)
#define SET_BIT(reg, bitPos)        (*reg |= (1U << bitPos))
#define CLEAR_BIT(reg, bitPos)      (*reg &= ~(1U << bitPos))
#define CHECK_BIT(reg, bitPos)      (*reg & (1U << bitPos))

#define WRITE_VALUE(reg, bitPos, value) (*reg |= (value << bitPos))
#define CLEAR_VALUE(reg, bitPos, value) (*reg &= ~(value << bitPos))

#endif

