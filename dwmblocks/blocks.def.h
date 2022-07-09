//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
    /*Icon*/       /*Command*/                         /*Update Interval*/     /*Update Signal*/

    // AWESOME FONTS :
    {"^C5^ ﮮ  ^d^", "$HOME/.config/scripts/upt",         60,                     2},
    {"^C3^   ^d^", "$HOME/.config/scripts/pacupdate",   360,                    5},
    {"^C4^   ^d^", "$HOME/.config/scripts/weather",     60,                     1},
    // {"^C1^   ^d^", "$HOME/.config/scripts/kernel",      360,                    2},
    {"^C6^   ^d^", "$HOME/.config/scripts/cpu",         2,                      1},
    {"^C5^   ^d^", "$HOME/.config/scripts/memory",      6,                      1},
    {"^C3^   ^d^", "$HOME/.config/scripts/battery",     150,                    1},
    {"^C4^   ^d^", "$HOME/.config/scripts/volume",      2,                      5},
    {"^C1^   ^d^", "$HOME/.config/scripts/clock",       5,                      0},

    // ICONS [requires libxft-bgra]
    // {" 🔺 ",        "$HOME/.config/scripts/upt",         60,                     2},
    // {" 📦 ",        "$HOME/.config/scripts/pacupdate",   300,                    9},
    // {" ⛅ ",        "$HOME/.config/scripts/weather",     60,                     1},
    // {" 🐧 ",        "$HOME/.config/scripts/kernel",      360,                    2},
    // {" 💻 ",        "$HOME/.config/scripts/cpu",         2,                      1},
    // {" 💾 ",        "$HOME/.config/scripts/memory",      6,                      1},
    // {" 🔋 ",        "$HOME/.config/scripts/battery",     150,                    1},
    // {" 🔊 ",        "$HOME/.config/scripts/volume",      2,                      5},
    // {" 🕑 ",        "$HOME/.config/scripts/clock",       5,                      0},

    // NERD FONTS :
    // {"^C5^ 卑 ^d^", "$HOME/.config/scripts/upt",         60,                     2},
    // {"^C3^   ^d^", "$HOME/.config/scripts/pacupdate",   360,                    9},
    // {"^C4^   ^d^", "$HOME/.config/scripts/weather",     60,                     1},
    // {"^C1^   ^d^", "$HOME/.config/scripts/kernel",      360,                    2},
    // {"^C6^   ^d^", "$HOME/.config/scripts/cpu",         2,                      1},
    // {"^C5^   ^d^", "$HOME/.config/scripts/memory",      6,                      1},
    // {"^C3^   ^d^", "$HOME/.config/scripts/battery",     150,                    1},
    // {"^C4^   ^d^", "$HOME/.config/scripts/volume",      2,                      5},
    // {"^C1^   ^d^", "$HOME/.config/scripts/clock",       5,                      0},

};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "\0";
static unsigned int delimLen = 5;
