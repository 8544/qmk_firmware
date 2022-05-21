#pragma once

#include "quantum.h"

#define LAYOUT_JP(                                                                              \
    K14, K16, K17, K15, K13, K10, K11, K12, K1E, K1C, K1A, K19, K18, K1D, K3D,                  \
    K24, K26, K27, K25, K23, K20, K21, K22, K2E, K2C, K2A, K29, K28,                            \
    K04, K06, K07, K05, K03, K00, K01, K02, K0E, K0C, K0A, K09, K08, K3F,                       \
    K34, K36, K37, K35, K33, K30, K31, K32, K3E, K3C, K3A, K39, K38, K3B,                       \
    K44, K46, K47, K45, K43,   K40,    K42, K4E, K4C, K4A, K49, K48, K4B)                       \
{ \
    { K00,   K10,   K20,  K30, K40   },                    \
    { K01,   K11,   K21,  K31, KC_NO },                    \
    { K02,   K12,   K22,  K32, K42   },                    \
    { K03,   K13,   K23,  K33, K43   },                    \
    { K04,   K14,   K24,  K34, K44   },                    \
    { K05,   K15,   K25,  K35, K45   },                    \
    { K06,   K16,   K26,  K36, K46   },                    \
    { K07,   K17,   K27,  K37, K47   },                    \
    { K08,   K18,   K28,  K38, K48   },                    \
    { K09,   K19,   K29,  K39, K49   },                    \
    { K0A,   K1A,   K2A,  K3A, K4A   },                    \
    { KC_NO, KC_NO, KC_NO,K3B, K4B   },                    \
    { K0C,   K1C,   K2C,  K3C, K4C   },                    \
    { KC_NO, K1D,   KC_NO,K3D, KC_NO },                    \
    { K0E,   K1E,   K2E,  K3E, K4E   },                    \
    { KC_NO, KC_NO, KC_NO,K3F, KC_NO }                     \
}
