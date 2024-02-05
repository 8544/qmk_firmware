#include "jp_bt.h"

// 80 is used to disable key (it is enough high so that the speaker won't make sound)
const uint8_t music_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_jp(
    80, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48,
    80, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
    80, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 80,
    80,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 80, 80,
    80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80
);
