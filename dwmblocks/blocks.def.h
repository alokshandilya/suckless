//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
  //Icon               Command                                  Update Interval         Update Signal  
  // AWESOME FONTS :
  // {"^C5^ ﮮ ^d^",      "$HOME/.local/bin/dwmblocks/upt",         60,                     2},
  // {"^C3^  ^d^",      "$HOME/.local/bin/dwmblocks/pacupdate",   360,                    5},
  // {"^C4^  ^d^",      "$HOME/.local/bin/dwmblocks/weather",     60,                     1},
  // // {"^C1^  ^d^",      "$HOME/.local/bin/dwmblocks/kernel",      360,                    2},
  // {"^C6^  ^d^",      "$HOME/.local/bin/dwmblocks/cpu",         2,                      1},
  // {"^C5^ 瑱 ^d^",     "$HOME/.local/bin/dwmblocks/memory",      6,                      1},
  // {"^C3^   ^d^",     "$HOME/.local/bin/dwmblocks/battery",     150,                    1},
  // {"^C4^  ^d^",      "$HOME/.local/bin/dwmblocks/volume",      2,                      5},
  // {"^C1^  ^d^",      "$HOME/.local/bin/dwmblocks/clock",       5,                      0},

  // ICONS [requires libxft-bgra]
  {" 🏏 ",            "$HOME/.local/bin/dwmblocks/upt",         60,                     2},
  {" 📬 ",            "$HOME/.local/bin/dwmblocks/pacupdate",   300,                    9},
  {" 🏝️ ",             "$HOME/.local/bin/dwmblocks/weather",     60,                     1},
  // {" 🐧 ",            "$HOME/.local/bin/dwmblocks/kernel",      360,                    2},
  {" 🪁 ",            "$HOME/.local/bin/dwmblocks/cpu",         2,                      1},
  {" 🦾 ",            "$HOME/.local/bin/dwmblocks/memory",      6,                      1},
  {" 🔋",             "$HOME/.local/bin/dwmblocks/battery",     150,                    1},
  {" 🔔",             "$HOME/.local/bin/dwmblocks/volume",      2,                      5},
  {" ⏰ ",            "$HOME/.local/bin/dwmblocks/clock",       5,                      0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "\0";
static unsigned int delimLen = 5;
