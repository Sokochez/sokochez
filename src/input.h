/**
 * \file input.h
 * \authors The GNU project
 * \brief Functions related to terminal mode management taken from
 *        https://www.gnu.org/software/libc/manual/html_node/Noncanon-Example.html
 */

#ifndef INPUT_H
#define INPUT_H
#include <termios.h>
#include <unistd.h>

/**
 * @brief Sets NonCanonical mode
 */

void set_input_mode (void);

/**
 * @brief Resets the input mode
 */

void reset_input_mode (void);

#endif // INPUT_H


