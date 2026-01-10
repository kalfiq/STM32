#ifndef UTILITIES_H
#define UTILITIES_H

#define REG_WRITE(reg, value)            (*reg = value)
#define SET_BIT(reg, bit_pos)            (*reg |= (1U << bit_pos))
#define CLEAR_BIT(reg, bit_pos)          (*reg &= ~(1U << bit_pos))
#define CHECK_BIT(reg, bit_pos)          (*reg & (1U << bit_pos))

#define WRITE_VALUE(reg, bit_pos, value) (*reg |= (value << bit_pos))
#define CLEAR_VALUE(reg, bit_pos, value) (*reg &= ~(value << bit_pos))

#endif

