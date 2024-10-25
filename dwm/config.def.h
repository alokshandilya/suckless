#include <X11/XF86keysym.h>

// Constants
#define TERMINAL "st"
#define TERMCLASS "St"
// #define BROWSER "thorium-browser"
// #define BROWSERCLASS "Thorium-browser"
// #define BROWSER "microsoft-edge-stable"
// #define BROWSERCLASS "microsoft-edge-stable"
#define BROWSER "firefox"
#define BROWSERCLASS "Firefox"
#define FILEMANAGER "thunar"
#define SESSION_FILE "/tmp/dwm-session"

// Appearance settings
static const unsigned int borderpx  = 2;        // border pixel of windows
static const unsigned int snap      = 32;       // snap pixel
static const unsigned int gappih    = 7;       // horiz inner gap between windows
static const unsigned int gappiv    = 7;       // vert inner gap between windows
static const unsigned int gappoh    = 7;       // horiz outer gap between windows and screen edge
static const unsigned int gappov    = 10;       // vert outer gap between windows and screen edge
static       int smartgaps          = 0;        // 1 means no outer gap when there is only one window
static const unsigned int systraypinning = 0;   // 0: sloppy systray follows selected monitor, >0: pin systray to monitor X
static const unsigned int systrayonleft = 0;    // 0: systray in the right corner, >0: systray on left of status text
static const unsigned int systrayspacing = 2;   // systray spacing
static const int systraypinningfailfirst = 1;   // 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor
static const int showsystray        = 1;        // 0 means no systray
static const int showbar            = 1;        // 0 means no bar
static const int topbar             = 1;        // 0 means bottom bar
static const int horizpadbar        = 0;        // horizontal padding for statusbar
static const int vertpadbar         = 7;        // vertical padding for statusbar

#define ICONSIZE 21     // icon size
#define ICONSPACING 6   // space between icon and title

static const char *fonts[] = { "Fira Code:sytle:extrabold:size=10", "FiraCode Nerd Font:sytle:extrabold:size=14",
                               "Twemoji:size=10:antialias=true:autohint=true" };
static const char dmenufont[] = "FiraCode Nerd Font:style:extrabold:size=10";

// ##############################
// ######## GRUVBOX DARK ########
// ##############################
static char normbgcolor[]           = "#1d2021";
static char normbordercolor[]       = "#504945";
static char normfgcolor[]           = "#D3BD97";
static char selfgcolor[]            = "#89B482";
static char selbordercolor[]        = "#89B482";
static char selbgcolor[]            = "#1d2021";

// ######################
// ######## NORD ########
// ######################
// static char normbgcolor[]           = "#2e3440";
// static char normbordercolor[]       = "#4c566a";
// static char normfgcolor[]           = "#d8dee9";
// static char selfgcolor[]            = "#88c0d0";
// static char selbordercolor[]        = "#81a1c1";
// static char selbgcolor[]            = "#2e3440";

// ##############################
// ######## TOKYO NIGHT #########
// ##############################
// static char normbgcolor[]           = "#1a1b26";
// static char normbordercolor[]       = "#414868";
// static char normfgcolor[]           = "#c0caf5";
// static char selfgcolor[]            = "#7aa2f7";
// static char selbordercolor[]        = "#7aa2f7";
// static char selbgcolor[]            = "#1a1b26";

// ##########################
// ######## ONE DARK ########
// ##########################
// static char normbgcolor[]           = "#1E2127";
// static char normbordercolor[]       = "#3A3F4B";
// static char normfgcolor[]           = "#ABB2BF";
// static char selfgcolor[]            = "#56b6c2";
// static char selbordercolor[]        = "#56b6c2";
// static char selbgcolor[]            = "#1E2127";

static char termcol0[] = "#000000";  // black
static char termcol1[] = "#ff0000";  // red
static char termcol2[] = "#33ff00";  // green
static char termcol3[] = "#ff0099";  // yellow
static char termcol4[] = "#0066ff";  // blue
static char termcol5[] = "#cc00ff";  // magenta
static char termcol6[] = "#00ffff";  // cyan
static char termcol7[] = "#d0d0d0";  // white
static char termcol8[]  = "#808080"; // black
static char termcol9[]  = "#ff0000"; // red
static char termcol10[] = "#33ff00"; // green
static char termcol11[] = "#ff0099"; // yellow
static char termcol12[] = "#0066ff"; // blue
static char termcol13[] = "#cc00ff"; // magenta
static char termcol14[] = "#00ffff"; // cyan
static char termcol15[] = "#ffffff"; // white
static char *termcolor[] = {
  termcol0,
  termcol1,
  termcol2,
  termcol3,
  termcol4,
  termcol5,
  termcol6,
  termcol7,
  termcol8,
  termcol9,
  termcol10,
  termcol11,
  termcol12,
  termcol13,
  termcol14,
  termcol15,
};
static char *colors[][3] = {
  //               fg            bg           border
  [SchemeNorm] = { normfgcolor,  normbgcolor, normbordercolor },
  [SchemeSel]  = { selfgcolor,   selbgcolor,  selbordercolor },
};

static const char *const autostart[] = {
  "dunst", NULL,
  "xbanish", NULL,
  "sh", "-c", "~/Documents/suckless/dwmblocks/dwmblocks", NULL,
  // "picom --config ~/.config/picom/picom-blur.conf --experimental-backends", NULL,
  "picom", NULL,
  // "st", NULL,
  NULL // terminate
};

// tagging

    
// static const char *tags[] = { "󰎦", "󰎩", "󰎬", "󰎮", "󰎰", "󰎵", "󰎸" , "󰎻", "󰎾" };
// static const char *alttags[] = { "󰎤", "󰎧", "󰎪", "󰎭", "󰎱", "󰎳", "󰎶", "󰎹", "󰎼" };
static const char *tags[] = { "", " ", "", "", "", "󰎵", "" , "󰎻", "󰎾" };
static const char *alttags[] = { "", " ", "", "", "", "󰎳", "", "󰎹", "󰎼" };

static const Rule rules[] = {
// xprop(1):
// WM_CLASS(STRING) = instance, class
// WM_NAME(STRING)  = title

  // class                 instance    title       tags mask     switchtotag      isfloating   monitor
  { BROWSERCLASS,          NULL,       NULL,       1 << 0,       1,               0,           0 },
  // { "Microsoft-edge",      NULL,       NULL,       1 << 0,       1,               0,           1 },
  { "firefox",             NULL,       NULL,       1 << 0,       1,               0,           1 },
  // { TERMCLASS,             NULL,       NULL,       1 << 1,       1,               0,           0 },
  { "Code",                NULL,       NULL,       1 << 1,       1,               0,           1 },
  { "kitty",               NULL,       NULL,       1 << 1,       1,               0,           0 },
  { "jetbrains-idea-ce",   NULL,       NULL,       1 << 1,       1,               0,           0 },
  { "Emacs",               NULL,       NULL,       1 << 1,       1,               0,           0 },
  { "GitHub Desktop",      NULL,       NULL,       1 << 3,       1,               0,           0 },
  { "Spotify",             NULL,       NULL,       1 << 4,       1,               0,           0 },
  { "Rhythmbox",           NULL,       NULL,       1 << 4,       1,               0,           0 },
  { "Soffice",             NULL,       NULL,       1 << 4,       1,               0,           0 },
  { "okular",              NULL,       NULL,       1 << 4,       1,               0,           0 },
  { "Gimp",                NULL,       NULL,       1 << 5,       1,               0,           0 },
  // { "vlc",                 NULL,       NULL,       1 << 5,       1,               0,           0 },
  // { "mpv",                 NULL,       NULL,       1 << 5,       1,               0,           0 },
  { "Mailspring",          NULL,       NULL,       1 << 6,       1,               0,           0 },
  { "TelegramDesktop",     NULL,       NULL,       1 << 6,       1,               0,           1 },
};

// layout(s)
static const float mfact     = 0.55; // factor of master area size [0.05..0.95]
static const int nmaster     = 1;    // number of clients in master area
static const int resizehints = 1;    // 1 means respect size hints in tiled resizals
static const int lockfullscreen = 1; // 1 will force focus on the fullscreen window

#define FORCE_VSPLIT 1  // nrowgrid layout: force two clients to always split vertically
#include "vanitygaps.c"

static const Layout layouts[] = {
  // symbol     arrange function
  { "[]=",      tile },    // first entry is default
  { "[M]",      monocle },
  { "[@]",      spiral },
  { "[\\]",     dwindle },
  { "H[]",      deck },
  { "TTT",      bstack },
  { "===",      bstackhoriz },
  { "HHH",      grid },
  { "###",      nrowgrid },
  { "---",      horizgrid },
  { ":::",      gaplessgrid },
  { "|M|",      centeredmaster },
  { ">M>",      centeredfloatingmaster },
  { "><>",      NULL },    // no layout function means floating behavior
  { NULL,       NULL },
};

// key definitions
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  {1, {{MODKEY, KEY}},                                view,           {.ui = 1 << TAG} }, \
  {1, {{MODKEY|ControlMask, KEY}},                    toggleview,     {.ui = 1 << TAG} }, \
  {1, {{MODKEY|ShiftMask, KEY}},                      tag,            {.ui = 1 << TAG} }, \
  {1, {{MODKEY|ControlMask|ShiftMask, KEY}},          toggletag,      {.ui = 1 << TAG} },

// helper for spawning shell commands in the pre dwm-5.0 fashion
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/dash", "-c", cmd, NULL } }

// commands
static char dmenumon[2] = "0"; // component of dmenucmd, manipulated in spawn()
// static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", normbgcolor, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };
static const char scratchpadname[] = "Alok's Playing Area-51 🏏";
static const char *scratchpadcmd[] = { TERMINAL, "-t", scratchpadname, "-g", "120x32", NULL };
static const char *roficmd[] = { "rofi", "-show", "drun", NULL };

static const char *mutecmd[] = { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *volupcmd[] = { "amixer", "-q", "set", "Master", "2%+", "unmute", NULL };
static const char *voldowncmd[] = { "amixer", "-q", "set", "Master", "2%-", "unmute", NULL };

static const char *nightLight[] = { "redshift", "-l", "22:77", NULL };
static const char *nightLightOff[] = { "killall", "redshift", NULL };

static const char *brupcmd[] = { "brightnessctl", "s", "1%+", NULL };
static const char *brdowncmd[] = { "brightnessctl", "s", "1%-", NULL };

static const char *browsercmd[] = { BROWSER, NULL };
static const char *filemanagercmd[] = { FILEMANAGER, NULL };
static const char *volume_control[] = { "/usr/bin/pavucontrol", NULL };
static const char *ranger[] = { TERMINAL, "-e", "ranger", NULL };
static const char *nvimcmd[] = { TERMINAL, "-e", "lvim", NULL };

static const char *bpytop[] = { TERMINAL, "-e", "bpytop", NULL };

static const char *printscr_full[] = { "flameshot", "full", "-p", "/home/aloks/Pictures/new/", NULL };
// static const char *printscr_full[] = { "flameshot", "gui", NULL };
static const char *lockscreen[] = { "betterlockscreen", "-l", "blur", NULL };

#include "movestack.c"
static Keychord keychords[] = {
  // modifier, key                                    function        argument
  { 1, {{ MODKEY, XK_Return }},                       spawn,          {.v = termcmd } },
  { 2, {{ MODKEY, XK_w }, { 0, XK_b }},               spawn,          {.v = browsercmd } },
  // { 1, {{ MODKEY, XK_w }},                            spawn,          SHCMD("brave --ignore-gpu-blocklist --enable-features=TouchpadOverscrollHistoryNavigation,VaapiVideoDecoder,VaapiVideoEncoder,VaapiVideoDecodeLinuxGL,VaapiIgnoreDriverChecks --disable-features=UseChromeOSDirectVideoDecoder,UseSkiaRenderer --password-store=gnome-libsecret --enable-zero-copy") },
  // { 1, {{ MODKEY, XK_w }},                            spawn,          SHCMD("brave-launcher") },
  // { 1, {{ MODKEY, XK_w }},                            spawn,          SHCMD("microsoft-edge-stable --password-store=libsecret --ignore-gpu-blocklist --enable-features=VaapiVideoDecoder,VaapiVideoEncoder,VaapiVideoDecodeLinuxGL,VaapiIgnoreDriverChecks --disable-features=UseChromeOSDirectVideoDecoder,UseSkiaRenderer") },
  { 1, {{ MODKEY, XK_grave }},                        togglescratch,  {.v = scratchpadcmd } },
  { 2, {{ MODKEY, XK_d }, { 0, XK_m }},               spawn,          {.v = dmenucmd } },
  { 1, {{ MODKEY, XK_c }},                            spawn,          SHCMD("rofi -modi \"clipboard:greenclip print\" -show clipboard -run-command '{cmd}'") },
  { 2, {{ MODKEY, XK_d }, { 0, XK_d }},               spawn,          SHCMD("mimeopen -n \"$(~/Documents/suckless/dmenu/scripts/dbrowse)\"") },
  { 2, {{ MODKEY, XK_y }, { 0, XK_v }},               spawn,          SHCMD("~/.local/bin/scripts/youtube-download-video.sh") },
  { 2, {{ MODKEY, XK_y }, { 0, XK_p }},               spawn,          SHCMD("~/.local/bin/scripts/youtube-download-playlist.sh") },
  { 1, {{ MODKEY, XK_a }},                            spawn,          SHCMD("~/.local/bin/scripts/app-launcher.sh") },
  { 1, {{ MODKEY|ShiftMask, XK_d }},                  spawn,          {.v = roficmd } },
  { 2, {{ MODKEY, XK_y }, { 0, XK_t }},               spawn,          SHCMD("$BROWSER --new-window https://youtube.com/feed/subscriptions") },
  { 2, {{ MODKEY, XK_g }, { 0, XK_h }},               spawn,          SHCMD("$BROWSER --new-window https://github.com/alokshandilya") },
  { 2, {{ MODKEY, XK_w }, { 0, XK_p }},               spawn,          SHCMD("$BROWSER --new-window https://web.whatsapp.com/") },
  { 2, {{ MODKEY, XK_e }, { 0, XK_f }},               spawn,          {.v = filemanagercmd } },
  // { 2, {{ MODKEY, XK_e }, { 0, XK_e }},               spawn,          {.v = nvimcmd } },
  { 2, {{ MODKEY, XK_n }, { 0, XK_p }},               spawn,          SHCMD("ls -r ~/Dropbox/notes/pdf/*.pdf | head -n1 | xargs zathura") },
  { 2, {{ MODKEY, XK_n }, { 0, XK_j }},               spawn,          SHCMD("zathura ~/Dropbox/notes/pdf/note-2-dsa.pdf") },
  { 2, {{ MODKEY, XK_n }, { 0, XK_h }},               spawn,          SHCMD("zathura ~/Documents/Programming/web-development/html/htmlcheatsheet.pdf") },
  { 2, {{ MODKEY, XK_s }, { 0, XK_p }},               spawn,          SHCMD("spotify") },
  { 2, {{ MODKEY, XK_b }, { 0, XK_m}},                spawn,          SHCMD("blueman-manager") },
  { 2, {{ MODKEY, XK_r }, { 0, XK_s }},               spawn,          {.v = nightLight } },
  { 2, {{ MODKEY, XK_r }, { 0, XK_e }},               spawn,          {.v = nightLightOff } },
  { 2, {{ MODKEY, XK_v }, { 0, XK_c }},               spawn,          SHCMD("code") },
  { 2, {{ MODKEY, XK_v }, { 0, XK_v }},               spawn,          {.v = volume_control } },
  { 2, {{ MODKEY, XK_e }, { 0, XK_r }},               spawn,          {.v = ranger } },
  { 1, {{ MODKEY|ShiftMask, XK_t }},                  spawn,          {.v = bpytop } },
  { 1, {{ 0, XK_Print }},                             spawn,          {.v = printscr_full } },
  { 1, {{ MODKEY|ControlMask, XK_x }},                spawn,          {.v = lockscreen } },
  /* { 2, {{ MODKEY, XK_e }, { 0, XK_e }},               spawn,          SHCMD("emacsclient -c -a 'emacs' --eval '(dashboard-refresh-buffer)'") }, */
  { 2, {{ MODKEY, XK_e }, { 0, XK_e }},               spawn,          SHCMD("emacsclient -c -a 'emacs'") },
  { 2, {{ MODKEY, XK_b }, { 0, XK_b}},                togglebar,      {0} },
  { 1, {{ MODKEY, XK_j }},                            focusstack,     {.i = +1 } },
  { 1, {{ MODKEY, XK_k }},                            focusstack,     {.i = -1 } },
  { 1, {{ MODKEY, XK_i }},                            incnmaster,     {.i = +1 } },
  { 1, {{ MODKEY, XK_p }},                            incnmaster,     {.i = -1 } },
  { 1, {{ MODKEY, XK_h }},                            setmfact,       {.f = -0.05} },
  { 1, {{ MODKEY, XK_l }},                            setmfact,       {.f = +0.05} },
  { 1, {{ MODKEY|ShiftMask, XK_h }},                  setcfact,       {.f = +0.25} },
  { 1, {{ MODKEY|ShiftMask, XK_l }},                  setcfact,       {.f = -0.25} },
  { 1, {{ MODKEY|ShiftMask, XK_o }},                  setcfact,       {.f =  0.00} },
  { 1, {{ MODKEY|ShiftMask, XK_j }},                  movestack,      {.i = +1 } },
  { 1, {{ MODKEY|ShiftMask, XK_k }},                  movestack,      {.i = -1 } },
  { 1, {{ MODKEY|ShiftMask, XK_Return }},             zoom,           {0} },
  { 1, {{ MODKEY, XK_u }},                            incrgaps,       {.i = +1 } },
  { 1, {{ MODKEY|ShiftMask, XK_u }},                  incrgaps,       {.i = -1 } },
  { 1, {{ MODKEY|ControlMask, XK_i }},                incrigaps,      {.i = +1 } },
  { 1, {{ MODKEY|ControlMask|ShiftMask, XK_i }},      incrigaps,      {.i = -1 } },
  { 1, {{ MODKEY|ControlMask, XK_o }},                incrogaps,      {.i = +1 } },
  { 1, {{ MODKEY|ControlMask|ShiftMask, XK_o }},      incrogaps,      {.i = -1 } },
  { 1, {{ MODKEY|ControlMask, XK_6 }},                incrihgaps,     {.i = +1 } },
  { 1, {{ MODKEY|ControlMask|ShiftMask, XK_6 }},      incrihgaps,     {.i = -1 } },
  { 1, {{ MODKEY|ControlMask, XK_7 }},                incrivgaps,     {.i = +1 } },
  { 1, {{ MODKEY|ControlMask|ShiftMask, XK_7 }},      incrivgaps,     {.i = -1 } },
  { 1, {{ MODKEY|ControlMask, XK_8 }},                incrohgaps,     {.i = +1 } },
  { 1, {{ MODKEY|ControlMask|ShiftMask, XK_8 }},      incrohgaps,     {.i = -1 } },
  { 1, {{ MODKEY|ControlMask, XK_9 }},                incrovgaps,     {.i = +1 } },
  { 1, {{ MODKEY|ControlMask|ShiftMask, XK_9 }},      incrovgaps,     {.i = -1 } },
  { 1, {{ MODKEY|ControlMask, XK_0 }},                togglegaps,     {0} },
  { 1, {{ MODKEY|ControlMask|ShiftMask, XK_0 }},      defaultgaps,    {0} },
  { 1, {{ MODKEY, XK_Tab }},                          view,           {0} },
  { 1, {{ MODKEY|ShiftMask, XK_q }},                  killclient,     {0} },
  { 1, {{ MODKEY, XK_t }},                            setlayout,      {.v = &layouts[0]} },
  { 1, {{ MODKEY, XK_f }},                            setlayout,      {.v = &layouts[1]} },
  { 1, {{ MODKEY, XK_m }},                            setlayout,      {.v = &layouts[2]} },
  { 1, {{ MODKEY|ControlMask, XK_comma }},            cyclelayout,    {.i = -1 } },
  { 1, {{ MODKEY|ControlMask, XK_period }},           cyclelayout,    {.i = +1 } },
  { 1, {{ MODKEY, XK_space }},                        setlayout,      {0} },
  { 1, {{ MODKEY|ShiftMask, XK_space }},              togglefloating, {0} },
  { 1, {{ MODKEY|ShiftMask, XK_f }},                  togglefullscr,  {0} },
  { 1, {{ MODKEY, XK_0 }},                            view,           {.ui = ~0 } },
  { 1, {{ MODKEY|ShiftMask, XK_0 }},                  tag,            {.ui = ~0 } },
  { 1, {{ MODKEY, XK_comma }},                        focusmon,       {.i = -1 } },
  { 1, {{ MODKEY, XK_period }},                       focusmon,       {.i = +1 } },
  { 1, {{ MODKEY|ShiftMask, XK_comma }},              tagmon,         {.i = -1 } },
  { 1, {{ MODKEY|ShiftMask, XK_period }},             tagmon,         {.i = +1 } },
  { 1, {{ MODKEY, XK_Right }},                        viewnext,       {0} },
  { 1, {{ MODKEY, XK_Left }},                         viewprev,       {0} },
  { 1, {{ MODKEY|ShiftMask, XK_Right }},              tagtonext,      {0} },
  { 1, {{ MODKEY|ShiftMask, XK_Left }},               tagtoprev,      {0} },
  { 1, {{ MODKEY, XK_F5 }},                           xrdb,           {.v = NULL } },
 
  TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_2,                      1)
  TAGKEYS(                        XK_3,                      2)
  TAGKEYS(                        XK_4,                      3)
  TAGKEYS(                        XK_5,                      4)
  TAGKEYS(                        XK_6,                      5)
  TAGKEYS(                        XK_7,                      6)
  TAGKEYS(                        XK_8,                      7)
  TAGKEYS(                        XK_9,                      8)
 
  // for keyboard with no media keys (some doen't even have function key...)
  { 2, {{ MODKEY, XK_x }, { 0, XK_x }},               quit,           {0} },
  { 2, {{ MODKEY, XK_x }, { 0, XK_p }},               spawn,          SHCMD("poweroff") },
  { 2, {{ MODKEY, XK_x }, { 0, XK_r }},               quit,           {1} },
  { 1, {{ MODKEY|ControlMask, XK_l }},                spawn,          {.v = brupcmd } },
  { 1, {{ MODKEY|ControlMask, XK_h }},                spawn,          {.v = brdowncmd } },
  { 1, {{ MODKEY|ControlMask, XK_k }},                spawn,          {.v = volupcmd } },
  { 1, {{ MODKEY|ControlMask, XK_j }},                spawn,          {.v = voldowncmd } },
  { 1, {{ 0, XF86XK_AudioMute }},                     spawn,          {.v = mutecmd } },
  { 1, {{ 0, XF86XK_AudioLowerVolume }},              spawn,          {.v = voldowncmd } },
  { 1, {{ 0, XF86XK_AudioRaiseVolume }},              spawn,          {.v = volupcmd } },
  { 1, {{ 0, XF86XK_MonBrightnessUp }},               spawn,          {.v = brupcmd } },
  { 1, {{ 0, XF86XK_MonBrightnessDown }},             spawn,          {.v = brdowncmd } },
};

// button definitions
// click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin
static Button buttons[] = {
  // click                event mask      button          function        argument
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
