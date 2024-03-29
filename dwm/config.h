/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 4; /* border pixel of windows */
static const unsigned int gappx = 4;    /* gaps between windows */
static const unsigned int snap = 10;    /* snap pixel */
static const int rmaster = 0; /* 1 means master-area is initially on the right */
static const unsigned int systraypinning =0; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor
          X */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int systraypinningfailfirst = 1; /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray = 0; /* 0 means no systray */
static const int showbar = 1;     /* 0 means no bar */
static const int topbar = 1;      /* 0 means bottom bar */
static const char *fonts[] = {"JetBrainsMono Nerd Font:size=16"};
static const char dmenufont[] = "FiraCode Nerd Font Mono:size=16";
//static const char col_gray1[] = "#333333";
//static const char col_gray2[] = "#444444";
//static const char col_gray3[] = "#ffffff";
//static const char col_gray4[] = "#bbbbbb";
//static const char col_cyan[] = "#7799AA"; 

static const unsigned int baralpha = OPAQUE; // 0xd0
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {"#e2d3ba", "#282828", "#a9b665"},
    [SchemeSel] = {"#d8a657", "#282828", "#ea6962"},
};
static const unsigned int alphas[][3] = {
    /*               fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
};

/* tagging */

/* static const char *tags[] = {"", "", "", "", "", "ﳜ"}; */
static const char *tags[] = {"", "", "", "", "", "﮸"};

static const unsigned int ulinepad =
    5; /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke =
    2; /* thickness / height of the underline */
static const unsigned int ulinevoffset =
    0; /* how far above the bottom of the bar the line should appear */
static const int ulineall =
    0; /* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {NULL, NULL, "Media viewer", 0, 1, -1},
    {"wemeetapp", NULL, NULL, TAGMASK, 1, -1},
    {"Telegram", NULL, NULL, 0, 1, -1},
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Flameshot", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;   /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[T]", tile}, /* first entry is default */
    {"[F]", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-i",      "-m",  dmenumon,
                                 "-fn",       dmenufont, "-nb", "#282828",
                                 "-nf",       "#e2d3ba", "-sb", "#282828",
                                 "-sf",       "#d8a657", NULL};
static const char *termcmd[] = {"st", NULL};
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = {"st", "-t", scratchpadname, "-g", "120x34", NULL};
/* Add slock and flameshot */
static const char *slock[] = {"slock", NULL};
static const char *flameshot[] = {"flameshot", "gui", NULL};

/* Add Volume set key binding */
#include <X11/XF86keysym.h>
static const char *raisevol[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@",
                                 "+5%", NULL};
static const char *lowervol[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@",
                                 "-5%", NULL};
static const char *mute[] = {"pactl", "set-sink-mute", "@DEFAULT_SINK@",
                             "toggle", NULL};
static const char *brightup[] = {"light", "-A", "10", NULL};
static const char *brightdown[] = {"light", "-U", "10", NULL};

static Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_d, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_c, spawn, {.v = slock}},
    {0, XK_Print, spawn, {.v = flameshot}},
    {MODKEY, XK_grave, togglescratch, {.v = scratchpadcmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_a, incnmaster, {.i = +1}},
    {MODKEY, XK_s, incnmaster, {.i = -1}},
    {MODKEY | ShiftMask, XK_j, pushdown, {0}},
    {MODKEY | ShiftMask, XK_k, pushup, {0}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY, XK_q, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_f, togglefloating, {0}},
    {MODKEY, XK_r, togglermaster, {0}},
    {MODKEY, XK_Down, moveresize, {.v = "0x 25y 0w 0h"}},
    {MODKEY, XK_Up, moveresize, {.v = "0x -25y 0w 0h"}},
    {MODKEY, XK_Right, moveresize, {.v = "25x 0y 0w 0h"}},
    {MODKEY, XK_Left, moveresize, {.v = "-25x 0y 0w 0h"}},
    {MODKEY | ShiftMask, XK_Down, moveresize, {.v = "0x 0y 0w 25h"}},
    {MODKEY | ShiftMask, XK_Up, moveresize, {.v = "0x 0y 0w -25h"}},
    {MODKEY | ShiftMask, XK_Right, moveresize, {.v = "0x 0y 25w 0h"}},
    {MODKEY | ShiftMask, XK_Left, moveresize, {.v = "0x 0y -25w 0h"}},
    {MODKEY | ControlMask, XK_Up, moveresizeedge, {.v = "t"}},
    {MODKEY | ControlMask, XK_Down, moveresizeedge, {.v = "b"}},
    {MODKEY | ControlMask, XK_Left, moveresizeedge, {.v = "l"}},
    {MODKEY | ControlMask, XK_Right, moveresizeedge, {.v = "r"}},
    {MODKEY | ControlMask | ShiftMask, XK_Up, moveresizeedge, {.v = "T"}},
    {MODKEY | ControlMask | ShiftMask, XK_Down, moveresizeedge, {.v = "B"}},
    {MODKEY | ControlMask | ShiftMask, XK_Left, moveresizeedge, {.v = "L"}},
    {MODKEY | ControlMask | ShiftMask, XK_Right, moveresizeedge, {.v = "R"}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
    {0, XF86XK_AudioRaiseVolume, spawn, {.v = raisevol}},
    {0, XF86XK_AudioLowerVolume, spawn, {.v = lowervol}},
    {0, XF86XK_AudioMute, spawn, {.v = mute}},
    {0, XF86XK_MonBrightnessUp, spawn, {.v = brightup}},
    {0, XF86XK_MonBrightnessDown, spawn, {.v = brightdown}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument
     */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
