/* Copyright 2020 joshajohnson
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#define ___ KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

// 2U keys on numpad, plus 1.5U on RHS of split space bar
#define LAYOUT_2U_SS( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, K0f, K010, K011, K012, K013,  \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, K1f, K110,    K112,    K113,  \
         K21, K22, K23, K24,   K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, K2f, K210, K211,   K212,  K213,  \
    K30, K31, K32, K33, K34,    K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e, K3f, K310,      K311,    K313,  \
         K41, K42, K43, K45,     K46, K47, K48, K49, K4a, K4b, K4c, K4d, K4e, K4f,       K411,  K412, K413,  \
    K50, K51,      K53, K54,   K55,  K57,      K59,   K5a,    K5c,        K5e, K510,       K511, K512, K513   \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, K0f, K010, K011, K012, K013 },  \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, K1f, K110, ___,  K112, K113 },  \
    { ___, K21, K22, K23, K24, ___, K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, K2f, K210, K211, K212, K213 },  \
    { K30, K31, K32, K33, K34, ___, K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e, K3f, K310, K311, ___,  K313 },  \
    { ___, K41, K42, K43, ___, K45, K46, K47, K48, K49, K4a, K4b, K4c, K4d, K4e, K4f,  ___, K411, K412, K413 },  \
    { K50, K51, ___, K53, K54, K55, ___, K57, ___, K59, K5a, ___, K5c, ___, K5e, ___, K510, K511, K512, K513 }   \
}

// 2U keys on numpad, plus 1.5U on RHS of single space bar
#define LAYOUT_2U( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, K0f, K010, K011, K012, K013,  \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, K1f, K110,    K112,    K113,  \
         K21, K22, K23, K24,   K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, K2f, K210, K211,   K212,  K213,  \
    K30, K31, K32, K33, K34,    K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e, K3f, K310,      K311,    K313,  \
         K41, K42, K43, K45,     K46, K47, K48, K49, K4a, K4b, K4c, K4d, K4e, K4f,       K411,  K412, K413,  \
    K50, K51,      K53, K54,   K55,  K57,             K5a,                K5e, K510,       K511, K512, K513   \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, K0f, K010, K011, K012, K013 },  \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, K1f, K110, ___,  K112, K113 },  \
    { ___, K21, K22, K23, K24, ___, K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, K2f, K210, K211, K212, K213 },  \
    { K30, K31, K32, K33, K34, ___, K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e, K3f, K310, K311, ___,  K313 },  \
    { ___, K41, K42, K43, ___, K45, K46, K47, K48, K49, K4a, K4b, K4c, K4d, K4e, K4f,  ___, K411, K412, K413 },  \
    { K50, K51, ___, K53, K54, K55, ___, K57, ___, ___, K5a, ___, ___, ___, K5e, ___, K510, K511, K512, K513 }   \
}

// 1U keys wherever possible, single space bar
#define LAYOUT_ALL( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, K0f, K010, K011, K012, K013,  \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, K1f, K110,    K112,    K113,  \
    K20, K21, K22, K23, K24,   K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, K2f, K210, K211,   K212,  K213,  \
    K30, K31, K32, K33, K34,    K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e, K3f, K310,      K311,    K313,  \
    K40, K41, K42, K43, K45,     K46, K47, K48, K49, K4a, K4b, K4c, K4d, K4e, K4f,       K411,  K412, K413,  \
    K50, K51, K52, K53, K54,   K55,  K57,             K5a,                K5e, K5f, K510, K511, K512, K513   \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, K0f, K010, K011, K012, K013 },  \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, K1f, K110, ___,  K112, K113 },  \
    { K20, K21, K22, K23, K24, ___, K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, K2f, K210, K211, K212, K213 },  \
    { K30, K31, K32, K33, K34, ___, K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e, K3f, K310, K311, ___,  K313 },  \
    { K40, K41, K42, K43, ___, K45, K46, K47, K48, K49, K4a, K4b, K4c, K4d, K4e, K4f, ___,  K411, K412, K413 },  \
    { K50, K51, K52, K53, K54, K55, ___, K57, ___, ___, K5a, ___, ___, ___, K5e, K5f, K510, K511, K512, K513 }   \
}

// 1U keys wherever possible, split space
#define LAYOUT_ALL_SS( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, K0f, K010, K011, K012, K013,  \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, K1f, K110,    K112,    K113,  \
    K20, K21, K22, K23, K24,   K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, K2f, K210, K211,   K212,  K213,  \
    K30, K31, K32, K33, K34,    K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e, K3f, K310,      K311,    K313,  \
    K40, K41, K42, K43, K45,     K46, K47, K48, K49, K4a, K4b, K4c, K4d, K4e, K4f,       K411,  K412, K413,  \
    K50, K51, K52, K53, K54,   K55,  K57,      K59,   K5a,    K5c,        K5e, K5f, K510, K511, K512, K513   \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0a, K0b, K0c, K0d, K0e, K0f, K010, K011, K012, K013 },  \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1a, K1b, K1c, K1d, K1e, K1f, K110, ___,  K112, K113 },  \
    { K20, K21, K22, K23, K24, ___, K26, K27, K28, K29, K2a, K2b, K2c, K2d, K2e, K2f, K210, K211, K212, K213 },  \
    { K30, K31, K32, K33, K34, ___, K36, K37, K38, K39, K3a, K3b, K3c, K3d, K3e, K3f, K310, K311, ___,  K313 },  \
    { K40, K41, K42, K43, ___, K45, K46, K47, K48, K49, K4a, K4b, K4c, K4d, K4e, K4f, ___,  K411, K412, K413 },  \
    { K50, K51, K52, K53, K54, K55, ___, K57, ___, K59, K5a, ___, K5c, ___, K5e, K5f, K510, K511, K512, K513 }   \
}
