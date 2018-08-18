/*
* This fucking header file defines how the kb_code fucks with keyboard.
* example: #define KB_LEFT = 75 (kb_code)
* See also: https://stackoverflow.com/questions/13996455/what-are-the-other-defines-relating-to-define-kb-up-72-for-c-what-are-all-of
*/

#pragma once

//arrow keys
#define KB_LEFT VK_LEFT
#define KB_RIGHT VK_RIGHT
#define KB_UP VK_UP
#define KB_DOWN VK_DOWN
#define KB_SPACE 32

//non-cap letters
#define KB_q 113
#define KB_w 119
#define KB_e 101
#define KB_a 97
#define KB_s 115
#define KB_d 100

//capital letters
#define KB_Q 81
#define KB_W 87
#define KB_E 69
#define KB_A 65
#define KB_S 83
#define KB_D 68

//esc
#define KB_ESC 27
