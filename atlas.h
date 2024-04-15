//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
// rTexpacker v3.0 Atlas Descriptor Code exporter v2.0                          //
//                                                                              //
// more info and bugs-report:  github.com/raylibtech/rtools                     //
// feedback and support:       ray[at]raylibtech.com                            //
//                                                                              //
// Copyright (c) 2020-2023 raylib technologies (@raylibtech)                    //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////

//#define ATLAS_ATLAS_IMAGE_PATH      "atlas.png"
#define ATLAS_ATLAS_SPRITE_COUNT    106
#define ATLAS_ATLAS_FONT_SIZE       55

// Atlas sprite properties
typedef struct rtpAtlasSprite {
    const char *nameId;
    int originX, originY;
    int positionX, positionY;
    int sourceWidth, sourceHeight;
    int padding;
    bool trimmed;
    int trimRecX, trimRecY, trimRecWidth, trimRecHeight;

    // Atlas contains font data
    int charValue;
    int charOffsetX, charOffsetY;
    int charAdvanceX;
} rtpAtlasSprite;

// Atlas sprites array
static rtpAtlasSprite rtpDescAtlas[106] = {
        { "NotoSans-VariableFont_wdth,wght-U0020", 0, 0, 0, 0, 10, 55, 0, false, 0, 0, 0, 0, 0x0020, 0, 0, 10 },
        { "NotoSans-VariableFont_wdth,wght-U0021", 0, 0, 160, 103, 6, 30, 0, false, 0, 0, 6, 30, 0x0021, 2, 14, 10 },
        { "NotoSans-VariableFont_wdth,wght-U0022", 0, 0, 74, 214, 12, 11, 0, false, 0, 0, 12, 11, 0x0022, 2, 14, 16 },
        { "NotoSans-VariableFont_wdth,wght-U0023", 0, 0, 72, 132, 25, 29, 0, false, 0, 0, 25, 29, 0x0023, 1, 14, 26 },
        { "NotoSans-VariableFont_wdth,wght-U0024", 0, 0, 183, 36, 19, 34, 0, false, 0, 0, 19, 34, 0x0024, 2, 12, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0025", 0, 0, 202, 69, 31, 31, 0, false, 0, 0, 31, 31, 0x0025, 1, 13, 33 },
        { "NotoSans-VariableFont_wdth,wght-U0026", 0, 0, 104, 70, 28, 31, 0, false, 0, 0, 28, 31, 0x0026, 2, 13, 29 },
        { "NotoSans-VariableFont_wdth,wght-U0027", 0, 0, 250, 213, 5, 11, 0, false, 0, 0, 5, 11, 0x0027, 2, 14, 9 },
        { "NotoSans-VariableFont_wdth,wght-U0028", 0, 0, 225, 0, 10, 36, 0, false, 0, 0, 10, 36, 0x0028, 1, 14, 12 },
        { "NotoSans-VariableFont_wdth,wght-U0029", 0, 0, 215, 0, 10, 36, 0, false, 0, 0, 10, 36, 0x0029, 1, 14, 12 },
        { "NotoSans-VariableFont_wdth,wght-U002A", 0, 0, 203, 218, 20, 19, 0, false, 0, 0, 20, 19, 0x002A, 1, 12, 22 },
        { "NotoSans-VariableFont_wdth,wght-U002B", 0, 0, 163, 218, 19, 21, 0, false, 0, 0, 19, 21, 0x002B, 2, 18, 23 },
        { "NotoSans-VariableFont_wdth,wght-U002C", 0, 0, 242, 217, 7, 11, 0, false, 0, 0, 7, 11, 0x002C, 1, 38, 10 },
        { "NotoSans-VariableFont_wdth,wght-U002D", 0, 0, 243, 228, 11, 4, 0, false, 0, 0, 11, 4, 0x002D, 1, 30, 13 },
        { "NotoSans-VariableFont_wdth,wght-U002E", 0, 0, 86, 214, 6, 6, 0, false, 0, 0, 6, 6, 0x002E, 2, 38, 10 },
        { "NotoSans-VariableFont_wdth,wght-U002F", 0, 0, 239, 160, 15, 29, 0, false, 0, 0, 15, 29, 0x002F, 0, 14, 15 },
        { "NotoSans-VariableFont_wdth,wght-U0030", 0, 0, 233, 69, 21, 31, 0, false, 0, 0, 21, 31, 0x0030, 1, 13, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0031", 0, 0, 217, 189, 12, 29, 0, false, 0, 0, 12, 29, 0x0031, 3, 14, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0032", 0, 0, 44, 102, 20, 30, 0, false, 0, 0, 20, 30, 0x0032, 1, 13, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0033", 0, 0, 180, 72, 20, 31, 0, false, 0, 0, 20, 31, 0x0033, 1, 13, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0034", 0, 0, 170, 160, 23, 29, 0, false, 0, 0, 23, 29, 0x0034, 0, 14, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0035", 0, 0, 64, 102, 19, 30, 0, false, 0, 0, 19, 30, 0x0035, 2, 14, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0036", 0, 0, 160, 72, 20, 31, 0, false, 0, 0, 20, 31, 0x0036, 2, 13, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0037", 0, 0, 110, 161, 21, 29, 0, false, 0, 0, 21, 29, 0x0037, 1, 14, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0038", 0, 0, 67, 71, 21, 31, 0, false, 1, 0, 20, 31, 0x0038, 1, 13, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0039", 0, 0, 107, 101, 19, 31, 0, false, 0, 0, 19, 31, 0x0039, 2, 13, 23 },
        { "NotoSans-VariableFont_wdth,wght-U003A", 0, 0, 250, 189, 6, 24, 0, false, 0, 0, 6, 24, 0x003A, 2, 20, 10 },
        { "NotoSans-VariableFont_wdth,wght-U003B", 0, 0, 229, 189, 7, 29, 0, false, 0, 0, 7, 29, 0x003B, 1, 20, 10 },
        { "NotoSans-VariableFont_wdth,wght-U003C", 0, 0, 143, 214, 20, 21, 0, false, 0, 0, 20, 21, 0x003C, 2, 18, 23 },
        { "NotoSans-VariableFont_wdth,wght-U003D", 0, 0, 223, 218, 19, 12, 0, false, 0, 0, 19, 12, 0x003D, 2, 23, 23 },
        { "NotoSans-VariableFont_wdth,wght-U003E", 0, 0, 123, 214, 20, 21, 0, false, 0, 0, 20, 21, 0x003E, 2, 18, 23 },
        { "NotoSans-VariableFont_wdth,wght-U003F", 0, 0, 0, 87, 17, 31, 0, false, 0, 0, 17, 31, 0x003F, 0, 13, 17 },
        { "NotoSans-VariableFont_wdth,wght-U0040", 0, 0, 202, 36, 32, 33, 0, false, 0, 0, 32, 33, 0x0040, 2, 14, 36 },
        { "NotoSans-VariableFont_wdth,wght-U0041", 0, 0, 21, 132, 26, 29, 0, false, 0, 0, 26, 29, 0x0041, 0, 14, 25 },
        { "NotoSans-VariableFont_wdth,wght-U0042", 0, 0, 23, 161, 22, 29, 0, false, 0, 0, 22, 29, 0x0042, 3, 14, 26 },
        { "NotoSans-VariableFont_wdth,wght-U0043", 0, 0, 44, 71, 23, 31, 0, false, 0, 0, 23, 31, 0x0043, 2, 13, 25 },
        { "NotoSans-VariableFont_wdth,wght-U0044", 0, 0, 47, 132, 25, 29, 0, false, 0, 0, 25, 29, 0x0044, 3, 14, 29 },
        { "NotoSans-VariableFont_wdth,wght-U0045", 0, 0, 169, 189, 18, 29, 0, false, 0, 0, 18, 29, 0x0045, 3, 14, 22 },
        { "NotoSans-VariableFont_wdth,wght-U0046", 0, 0, 187, 189, 18, 29, 0, false, 0, 0, 18, 29, 0x0046, 3, 14, 20 },
        { "NotoSans-VariableFont_wdth,wght-U0047", 0, 0, 19, 71, 25, 31, 0, false, 0, 0, 25, 31, 0x0047, 2, 13, 29 },
        { "NotoSans-VariableFont_wdth,wght-U0048", 0, 0, 193, 160, 23, 29, 0, false, 0, 0, 23, 29, 0x0048, 3, 14, 29 },
        { "NotoSans-VariableFont_wdth,wght-U0049", 0, 0, 205, 189, 12, 29, 0, false, 0, 0, 12, 29, 0x0049, 1, 14, 13 },
        { "NotoSans-VariableFont_wdth,wght-U004A", 0, 0, 161, 0, 12, 37, 0, false, 0, 0, 12, 37, 0x004A, -4, 14, 11 },
        { "NotoSans-VariableFont_wdth,wght-U004B", 0, 0, 67, 161, 22, 29, 0, false, 0, 0, 22, 29, 0x004B, 3, 14, 24 },
        { "NotoSans-VariableFont_wdth,wght-U004C", 0, 0, 151, 162, 18, 29, 0, false, 0, 0, 18, 29, 0x004C, 3, 14, 21 },
        { "NotoSans-VariableFont_wdth,wght-U004D", 0, 0, 209, 131, 30, 29, 0, false, 0, 0, 30, 29, 0x004D, 3, 14, 36 },
        { "NotoSans-VariableFont_wdth,wght-U004E", 0, 0, 146, 133, 24, 29, 0, false, 0, 0, 24, 29, 0x004E, 3, 14, 30 },
        { "NotoSans-VariableFont_wdth,wght-U004F", 0, 0, 132, 70, 28, 31, 0, false, 0, 0, 28, 31, 0x004F, 2, 13, 31 },
        { "NotoSans-VariableFont_wdth,wght-U0050", 0, 0, 131, 162, 20, 29, 0, false, 0, 0, 20, 29, 0x0050, 3, 14, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0051", 0, 0, 133, 0, 28, 37, 0, false, 0, 0, 28, 37, 0x0051, 2, 13, 31 },
        { "NotoSans-VariableFont_wdth,wght-U0052", 0, 0, 45, 161, 22, 29, 0, false, 0, 0, 22, 29, 0x0052, 3, 14, 25 },
        { "NotoSans-VariableFont_wdth,wght-U0053", 0, 0, 88, 101, 19, 31, 0, false, 0, 0, 19, 31, 0x0053, 2, 13, 22 },
        { "NotoSans-VariableFont_wdth,wght-U0054", 0, 0, 216, 160, 23, 29, 0, false, 0, 0, 23, 29, 0x0054, 0, 14, 22 },
        { "NotoSans-VariableFont_wdth,wght-U0055", 0, 0, 21, 102, 23, 30, 0, false, 0, 0, 23, 30, 0x0055, 3, 14, 29 },
        { "NotoSans-VariableFont_wdth,wght-U0056", 0, 0, 97, 132, 25, 29, 0, false, 0, 0, 25, 29, 0x0056, 0, 14, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0057", 0, 0, 171, 131, 38, 29, 0, false, 0, 0, 37, 29, 0x0057, 0, 14, 37 },
        { "NotoSans-VariableFont_wdth,wght-U0058", 0, 0, 122, 132, 24, 29, 0, false, 0, 0, 24, 29, 0x0058, 0, 14, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0059", 0, 0, 0, 161, 23, 29, 0, false, 0, 0, 23, 29, 0x0059, 0, 14, 22 },
        { "NotoSans-VariableFont_wdth,wght-U005A", 0, 0, 89, 161, 21, 29, 0, false, 0, 0, 21, 29, 0x005A, 1, 14, 23 },
        { "NotoSans-VariableFont_wdth,wght-U005B", 0, 0, 173, 36, 10, 36, 0, false, 0, 0, 10, 36, 0x005B, 3, 14, 13 },
        { "NotoSans-VariableFont_wdth,wght-U005C", 0, 0, 239, 131, 15, 29, 0, false, 0, 0, 15, 29, 0x005C, 0, 14, 15 },
        { "NotoSans-VariableFont_wdth,wght-U005D", 0, 0, 235, 0, 10, 36, 0, false, 0, 0, 10, 36, 0x005D, 1, 14, 13 },
        { "NotoSans-VariableFont_wdth,wght-U005E", 0, 0, 182, 218, 21, 20, 0, false, 0, 0, 21, 20, 0x005E, 1, 13, 23 },
        { "NotoSans-VariableFont_wdth,wght-U005F", 0, 0, 106, 235, 20, 4, 0, false, 0, 0, 20, 4, 0x005F, -1, 46, 17 },
        { "NotoSans-VariableFont_wdth,wght-U0060", 0, 0, 74, 225, 9, 7, 0, false, 0, 0, 9, 7, 0x0060, 1, 12, 11 },
        { "NotoSans-VariableFont_wdth,wght-U0061", 0, 0, 21, 190, 19, 24, 0, false, 0, 1, 19, 23, 0x0061, 1, 20, 22 },
        { "NotoSans-VariableFont_wdth,wght-U0062", 0, 0, 45, 39, 20, 32, 0, false, 0, 0, 20, 32, 0x0062, 3, 12, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0063", 0, 0, 59, 190, 17, 24, 0, false, 0, 0, 17, 24, 0x0063, 2, 20, 19 },
        { "NotoSans-VariableFont_wdth,wght-U0064", 0, 0, 25, 39, 20, 32, 0, false, 0, 0, 20, 32, 0x0064, 2, 12, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0065", 0, 0, 40, 190, 19, 24, 0, false, 0, 0, 19, 24, 0x0065, 2, 20, 22 },
        { "NotoSans-VariableFont_wdth,wght-U0066", 0, 0, 238, 100, 16, 31, 0, false, 0, 0, 16, 31, 0x0066, 0, 12, 13 },
        { "NotoSans-VariableFont_wdth,wght-U0067", 0, 0, 234, 36, 20, 33, 0, false, 0, 0, 20, 33, 0x0067, 2, 20, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0068", 0, 0, 219, 100, 19, 31, 0, false, 0, 0, 19, 31, 0x0068, 3, 12, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0069", 0, 0, 166, 103, 5, 30, 0, false, 0, 0, 5, 30, 0x0069, 3, 13, 10 },
        { "NotoSans-VariableFont_wdth,wght-U006A", 0, 0, 14, 0, 11, 40, 0, false, 0, 0, 11, 40, 0x006A, -3, 13, 10 },
        { "NotoSans-VariableFont_wdth,wght-U006B", 0, 0, 126, 101, 19, 31, 0, false, 0, 0, 19, 31, 0x006B, 3, 12, 21 },
        { "NotoSans-VariableFont_wdth,wght-U006C", 0, 0, 17, 102, 4, 31, 0, false, 0, 0, 4, 31, 0x006C, 3, 12, 10 },
        { "NotoSans-VariableFont_wdth,wght-U006D", 0, 0, 92, 190, 32, 23, 0, false, 0, 0, 32, 23, 0x006D, 3, 20, 37 },
        { "NotoSans-VariableFont_wdth,wght-U006E", 0, 0, 124, 191, 19, 23, 0, false, 0, 0, 19, 23, 0x006E, 3, 20, 24 },
        { "NotoSans-VariableFont_wdth,wght-U006F", 0, 0, 0, 190, 21, 24, 0, false, 0, 0, 21, 24, 0x006F, 2, 20, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0070", 0, 0, 84, 38, 20, 33, 0, false, 0, 0, 20, 33, 0x0070, 3, 20, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0071", 0, 0, 133, 37, 20, 33, 0, false, 0, 0, 20, 33, 0x0071, 2, 20, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0072", 0, 0, 92, 213, 14, 23, 0, false, 0, 0, 14, 23, 0x0072, 3, 20, 16 },
        { "NotoSans-VariableFont_wdth,wght-U0073", 0, 0, 76, 190, 16, 24, 0, false, 0, 0, 16, 24, 0x0073, 2, 20, 19 },
        { "NotoSans-VariableFont_wdth,wght-U0074", 0, 0, 236, 189, 14, 28, 0, false, 0, 0, 14, 28, 0x0074, 0, 16, 14 },
        { "NotoSans-VariableFont_wdth,wght-U0075", 0, 0, 143, 191, 19, 23, 0, false, 0, 0, 19, 23, 0x0075, 3, 21, 24 },
        { "NotoSans-VariableFont_wdth,wght-U0076", 0, 0, 32, 214, 21, 22, 0, false, 0, 0, 21, 22, 0x0076, 0, 21, 20 },
        { "NotoSans-VariableFont_wdth,wght-U0077", 0, 0, 0, 214, 32, 22, 0, false, 0, 0, 32, 22, 0x0077, 0, 21, 31 },
        { "NotoSans-VariableFont_wdth,wght-U0078", 0, 0, 53, 214, 21, 22, 0, false, 0, 0, 21, 22, 0x0078, 0, 21, 21 },
        { "NotoSans-VariableFont_wdth,wght-U0079", 0, 0, 104, 38, 21, 32, 0, false, 0, 0, 21, 32, 0x0079, 0, 21, 20 },
        { "NotoSans-VariableFont_wdth,wght-U007A", 0, 0, 106, 213, 17, 22, 0, false, 0, 0, 17, 22, 0x007A, 1, 21, 18 },
        { "NotoSans-VariableFont_wdth,wght-U007B", 0, 0, 187, 0, 14, 36, 0, false, 0, 0, 14, 36, 0x007B, 1, 14, 15 },
        { "NotoSans-VariableFont_wdth,wght-U007C", 0, 0, 10, 0, 4, 41, 0, false, 0, 0, 4, 41, 0x007C, 9, 12, 22 },
        { "NotoSans-VariableFont_wdth,wght-U007D", 0, 0, 173, 0, 14, 36, 0, false, 0, 0, 14, 36, 0x007D, 1, 14, 15 },
        { "NotoSans-VariableFont_wdth,wght-U007E", 0, 0, 223, 230, 20, 6, 0, false, 0, 0, 20, 6, 0x007E, 2, 26, 23 },
        { "NotoSans-VariableFont_wdth,wght-U0219", 0, 0, 153, 37, 16, 32, 0, false, 0, 0, 16, 32, 0x0219, 2, 20, 19 },
        { "NotoSans-VariableFont_wdth,wght-U021B", 0, 0, 201, 0, 14, 36, 0, false, 0, 0, 14, 36, 0x021B, 0, 16, 14 },
        { "NotoSans-VariableFont_wdth,wght-U0103", 0, 0, 200, 100, 19, 31, 0, false, 0, 0, 19, 31, 0x0103, 1, 13, 22 },
        { "NotoSans-VariableFont_wdth,wght-U00EE", 0, 0, 145, 101, 15, 31, 0, false, 0, 0, 15, 31, 0x00EE, -2, 12, 10 },
        { "NotoSans-VariableFont_wdth,wght-U00E2", 0, 0, 0, 55, 19, 32, 0, false, 0, 0, 19, 32, 0x00E2, 1, 12, 22 },
        { "NotoSans-VariableFont_wdth,wght-U0218", 0, 0, 51, 0, 19, 39, 0, false, 0, 0, 19, 39, 0x0218, 2, 13, 22 },
        { "NotoSans-VariableFont_wdth,wght-U021A", 0, 0, 110, 0, 23, 38, 0, false, 0, 0, 23, 38, 0x021A, 0, 14, 22 },
        { "NotoSans-VariableFont_wdth,wght-U0102", 0, 0, 84, 0, 26, 38, 0, false, 0, 0, 26, 38, 0x0102, 0, 5, 25 },
        { "NotoSans-VariableFont_wdth,wght-U00CE", 0, 0, 70, 0, 14, 39, 0, false, 0, 0, 14, 39, 0x00CE, 0, 4, 13 },
        { "NotoSans-VariableFont_wdth,wght-U00C2", 0, 0, 25, 0, 26, 39, 0, false, 0, 0, 26, 39, 0x00C2, 0, 4, 25 },
        { "NotoSans-VariableFont_wdth,wght-U000A", 0, 0, 0, 0, 0, 0, 0, false, 0, 0, 0, 0, 0x000A, 0, 0, 0 },
};