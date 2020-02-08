#ifndef SWFG_INPUT_HPP
#define SWFG_INPUT_HPP
#include "Base.hpp"
namespace swfg
{
 namespace Input
 {
  namespace Key
  {
   /*
    * KeyCode列挙体はSDL2.0のSDL_Scancodeと対応している。
    * 不明なキーは以下を参照。
    * http://sdl2referencejp.osdn.jp/SDL_Scancode.html
   */
   typedef enum
   {
    KeyUNKNOWN = 0,

    KeyA = 4,
    KeyB = 5,
    KeyC = 6,
    KeyD = 7,
    KeyE = 8,
    KeyF = 9,
    KeyG = 10,
    KeyH = 11,
    KeyI = 12,
    KeyJ = 13,
    KeyK = 14,
    KeyL = 15,
    KeyM = 16,
    KeyN = 17,
    KeyO = 18,
    KeyP = 19,
    KeyQ = 20,
    KeyR = 21,
    KeyS = 22,
    KeyT = 23,
    KeyU = 24,
    KeyV = 25,
    KeyW = 26,
    KeyX = 27,
    KeyY = 28,
    KeyZ = 29,

    Key1 = 30,
    Key2 = 31,
    Key3 = 32,
    Key4 = 33,
    Key5 = 34,
    Key6 = 35,
    Key7 = 36,
    Key8 = 37,
    Key9 = 38,
    Key0 = 39,

    KeyRETURN = 40,
    KeyESCAPE = 41,
    KeyBACKSPACE = 42,
    KeyTAB = 43,
    KeySPACE = 44,

    KeyMINUS = 45,
    KeyEQUALS = 46,
    KeyLEFTBRACKET = 47,
    KeyRIGHTBRACKET = 48,
    KeyBACKSLASH = 49,
    KeyNONUSHASH = 50,
    KeySEMICOLON = 51,
    KeyAPOSTROPHE = 52,
    KeyGRAVE = 53,
    KeyCOMMA = 54,
    KeyPERIOD = 55,
    KeySLASH = 56,

    KeyCAPSLOCK = 57,

    KeyF1 = 58,
    KeyF2 = 59,
    KeyF3 = 60,
    KeyF4 = 61,
    KeyF5 = 62,
    KeyF6 = 63,
    KeyF7 = 64,
    KeyF8 = 65,
    KeyF9 = 66,
    KeyF10 = 67,
    KeyF11 = 68,
    KeyF12 = 69,

    KeyPRINTSCREEN = 70,
    KeySCROLLLOCK = 71,
    KeyPAUSE = 72,
    KeyINSERT = 73,
    KeyHOME = 74,
    KeyPAGEUP = 75,
    KeyDELETE = 76,
    KeyEND = 77,
    KeyPAGEDOWN = 78,
    KeyRIGHT = 79,
    KeyLEFT = 80,
    KeyDOWN = 81,
    KeyUP = 82,

    KeyNUMLOCKCLEAR = 83,
    KeyKP_DIVIDE = 84,
    KeyKP_MULTIPLY = 85,
    KeyKP_MINUS = 86,
    KeyKP_PLUS = 87,
    KeyKP_ENTER = 88,
    KeyKP_1 = 89,
    KeyKP_2 = 90,
    KeyKP_3 = 91,
    KeyKP_4 = 92,
    KeyKP_5 = 93,
    KeyKP_6 = 94,
    KeyKP_7 = 95,
    KeyKP_8 = 96,
    KeyKP_9 = 97,
    KeyKP_0 = 98,
    KeyKP_PERIOD = 99,

    KeyNONUSBACKSLASH = 100,
    KeyAPPLICATION = 101,
    KeyPOWER = 102,
    KeyKP_EQUALS = 103,
    KeyF13 = 104,
    KeyF14 = 105,
    KeyF15 = 106,
    KeyF16 = 107,
    KeyF17 = 108,
    KeyF18 = 109,
    KeyF19 = 110,
    KeyF20 = 111,
    KeyF21 = 112,
    KeyF22 = 113,
    KeyF23 = 114,
    KeyF24 = 115,
    KeyEXECUTE = 116,
    KeyHELP = 117,
    KeyMENU = 118,
    KeySELECT = 119,
    KeySTOP = 120,
    KeyAGAIN = 121,   /**< redo */
    KeyUNDO = 122,
    KeyCUT = 123,
    KeyCOPY = 124,
    KeyPASTE = 125,
    KeyFIND = 126,
    KeyMUTE = 127,
    KeyVOLUMEUP = 128,
    KeyVOLUMEDOWN = 129,
    /* not sure whether there's a reason to enable these */
    /*     KeyLOCKINGCAPSLOCK = 130,  */
    /*     KeyLOCKINGNUMLOCK = 131, */
    /*     KeyLOCKINGSCROLLLOCK = 132, */
    KeyKP_COMMA = 133,
    KeyKP_EQUALSAS400 = 134,

    KeyINTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    KeyINTERNATIONAL2 = 136,
    KeyINTERNATIONAL3 = 137, /**< Yen */
    KeyINTERNATIONAL4 = 138,
    KeyINTERNATIONAL5 = 139,
    KeyINTERNATIONAL6 = 140,
    KeyINTERNATIONAL7 = 141,
    KeyINTERNATIONAL8 = 142,
    KeyINTERNATIONAL9 = 143,
    KeyLANG1 = 144, /**< Hangul/English toggle */
    KeyLANG2 = 145, /**< Hanja conversion */
    KeyLANG3 = 146, /**< Katakana */
    KeyLANG4 = 147, /**< Hiragana */
    KeyLANG5 = 148, /**< Zenkaku/Hankaku */
    KeyLANG6 = 149, /**< reserved */
    KeyLANG7 = 150, /**< reserved */
    KeyLANG8 = 151, /**< reserved */
    KeyLANG9 = 152, /**< reserved */

    KeyALTERASE = 153, /**< Erase-Eaze */
    KeySYSREQ = 154,
    KeyCANCEL = 155,
    KeyCLEAR = 156,
    KeyPRIOR = 157,
    KeyRETURN2 = 158,
    KeySEPARATOR = 159,
    KeyOUT = 160,
    KeyOPER = 161,
    KeyCLEARAGAIN = 162,
    KeyCRSEL = 163,
    KeyEXSEL = 164,

    KeyKP_00 = 176,
    KeyKP_000 = 177,
    KeyTHOUSANDSSEPARATOR = 178,
    KeyDECIMALSEPARATOR = 179,
    KeyCURRENCYUNIT = 180,
    KeyCURRENCYSUBUNIT = 181,
    KeyKP_LEFTPAREN = 182,
    KeyKP_RIGHTPAREN = 183,
    KeyKP_LEFTBRACE = 184,
    KeyKP_RIGHTBRACE = 185,
    KeyKP_TAB = 186,
    KeyKP_BACKSPACE = 187,
    KeyKP_A = 188,
    KeyKP_B = 189,
    KeyKP_C = 190,
    KeyKP_D = 191,
    KeyKP_E = 192,
    KeyKP_F = 193,
    KeyKP_XOR = 194,
    KeyKP_POWER = 195,
    KeyKP_PERCENT = 196,
    KeyKP_LESS = 197,
    KeyKP_GREATER = 198,
    KeyKP_AMPERSAND = 199,
    KeyKP_DBLAMPERSAND = 200,
    KeyKP_VERTICALBAR = 201,
    KeyKP_DBLVERTICALBAR = 202,
    KeyKP_COLON = 203,
    KeyKP_HASH = 204,
    KeyKP_SPACE = 205,
    KeyKP_AT = 206,
    KeyKP_EXCLAM = 207,
    KeyKP_MEMSTORE = 208,
    KeyKP_MEMRECALL = 209,
    KeyKP_MEMCLEAR = 210,
    KeyKP_MEMADD = 211,
    KeyKP_MEMSUBTRACT = 212,
    KeyKP_MEMMULTIPLY = 213,
    KeyKP_MEMDIVIDE = 214,
    KeyKP_PLUSMINUS = 215,
    KeyKP_CLEAR = 216,
    KeyKP_CLEARENTRY = 217,
    KeyKP_BINARY = 218,
    KeyKP_OCTAL = 219,
    KeyKP_DECIMAL = 220,
    KeyKP_HEXADECIMAL = 221,

    KeyLCTRL = 224,
    KeyLSHIFT = 225,
    KeyLALT = 226, /**< alt, option */
    KeyLGUI = 227, /**< windows, command (apple), meta */
    KeyRCTRL = 228,
    KeyRSHIFT = 229,
    KeyRALT = 230, /**< alt gr, option */
    KeyRGUI = 231, /**< windows, command (apple), meta */

    KeyMODE = 257,    /**< I'm not sure if this is really not covered
                                 *   by any of the above, but since there's a
                                 *   special KMOD_MODE for it I'm adding it here
                                 */

    /* @} *//* Usage page 0x07 */

    /**
     *  \name Usage page 0x0C
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    KeyAUDIONEXT = 258,
    KeyAUDIOPREV = 259,
    KeyAUDIOSTOP = 260,
    KeyAUDIOPLAY = 261,
    KeyAUDIOMUTE = 262,
    KeyMEDIASELECT = 263,
    KeyWWW = 264,
    KeyMAIL = 265,
    KeyCALCULATOR = 266,
    KeyCOMPUTER = 267,
    KeyAC_SEARCH = 268,
    KeyAC_HOME = 269,
    KeyAC_BACK = 270,
    KeyAC_FORWARD = 271,
    KeyAC_STOP = 272,
    KeyAC_REFRESH = 273,
    KeyAC_BOOKMARKS = 274,

    /* @} *//* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    KeyBRIGHTNESSDOWN = 275,
    KeyBRIGHTNESSUP = 276,
    KeyDISPLAYSWITCH = 277, /**< display mirroring/dual display
                                           switch, video mode switch */
    KeyKBDILLUMTOGGLE = 278,
    KeyKBDILLUMDOWN = 279,
    KeyKBDILLUMUP = 280,
    KeyEJECT = 281,
    KeySLEEP = 282,

    KeyAPP1 = 283,
    KeyAPP2 = 284,

    /* @} *//* Walther keys */

    /**
     *  \name Usage page 0x0C (additional media keys)
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    KeyAUDIOREWIND = 285,
    KeyAUDIOFASTFORWARD = 286,

    /* @} *//* Usage page 0x0C (additional media keys) */

    /* Add any other keys here. */

    KeyNUM_SCANCODES = 512 /**< not a key, just marks the number of scancodes
                                 for array bounds */
   } KeyCode;


   inline bool isKeyPressed(int code)
   {
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    if(state[code])return true;
    return false;
   }
   inline bool OnceExeKey(int code)
   {
    const Uint8* state = SDL_GetKeyboardState(nullptr);
    static const Uint8* buf = state;
    return false;
   }
  };
  namespace Mouse
  {
   static bool dMouseData;
  };
 }
}
#endif // SWFG_INPUT_HPP
