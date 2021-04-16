/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=13", "font-awesome:10"  };
//static const char *fonts[]          = { "noto-emoji:size=12","monospace:size=10"  };
// static char dmenufont[]             = "monospace:size=10";
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#5972e0";
static char selbgcolor[]            = "#5972e0";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;

const char *spcmd1[] = {"st", "-n", "scratchpad", "-g", "120x30", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"scratchpad",      spcmd1},
};
// static const char scratchpadname[] = "scratchpad";
// static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

/* tagging */
static const char *tags[] = { "1", "2", "3", "4","5", "", "", "" };
//static const char *tags[] = { "1", "2", "3", "4","5", "F", "E", "C" };


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class     instance      	title       	 tags mask    isfloating   isterminal  noswallow  monitor */
//	{ "Gimp",      NULL,       	NULL,       	    1 << 6,       0,           0,         0,        -1 },
    { "Hexchat",   NULL,        NULL,               1 << 7,       0,           0,         0,        -1 }, 
	{ "KeePassXC", NULL,        NULL,       	    1 << 7,       0,           0,         0,        -1 },
	// { "thunderbird",  NULL,       NULL,         1 << 7,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
// #include "vanitygaps.c"
#include "layouts.c"
#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "[@]",	spiral },		/* Fibonacci spiral */
 	{ "[M]",	monocle },		/* All windows on top of eachother */
	{ "|M|",	centeredmaster },		/* Master in middle, slaves on sides */
	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },

	// { "TTT",	bstack },		/* Master on top, slaves on bottom */
	// { "[\\]",	dwindle },		/* Decreasing in size right and leftward */
	// { "H[]",	deck },			/* Master on left, slaves in monocle-like mode on right */
	// { ">M>",	centeredfloatingmaster },	/* Same but master floats */
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
/* #define STACKKEYS(MOD,ACTION) \
	{ MOD|ShiftMask,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD|ShiftMask,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \ */
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
// static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *tmuxcmd[]  = { "alacritty","-e","tmux", NULL };

#include <X11/XF86keysym.h>
#include "shiftview.c"
#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	// STACKKEYS(MODKEY,                          focus)
	// STACKKEYS(MODKEY|ShiftMask,                push)
	TAGKEYS(			XK_1,		0)
	TAGKEYS(			XK_2,		1)
	TAGKEYS(			XK_3,		2)
	TAGKEYS(			XK_4,		3)
	TAGKEYS(			XK_5,		4)
	TAGKEYS(			XK_6,		5)
	TAGKEYS(			XK_7,		6)
	TAGKEYS(			XK_8,		7)
	// TAGKEYS(			XK_9,		8)
	TAGKEYS(			XK_w,			5)
	TAGKEYS(			XK_e,			4)
	TAGKEYS(			XK_c,			7)
	{ MODKEY,			XK_0,		view,		{.ui = ~0 } },
	{ MODKEY,			XK_Tab,		view,		{0} },
	{ MODKEY|ShiftMask,		XK_0,		tag,		{.ui = ~0 } },


	{ MODKEY,				XK_t,		setlayout,	{.v = &layouts[0]} }, /* tile */
	{ MODKEY,				XK_y,		setlayout,	{.v = &layouts[1]} }, /* spiral */
	{ MODKEY,		    	XK_f,		setlayout,	{.v = &layouts[2]} }, /* monocle */
	{ MODKEY,				XK_u,		setlayout,	{.v = &layouts[3]} }, /* centeredmaster */
	{ MODKEY|ShiftMask,		XK_i,		setlayout,	{.v = &layouts[4]} }, /* floating */

	{ MODKEY,                       XK_j,		focusstack,	{.i = +1 } },
	{ MODKEY,                       XK_k,		focusstack,	{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,		movestack,	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,		movestack,	{.i = -1 } },
	{ MODKEY,						XK_space,	zoom,		{0} },
	{ MODKEY,                       XK_h,		setmfact,	{.f = -0.05} },
	{ MODKEY,                       XK_l,		setmfact,	{.f = +0.05} },
	{ MODKEY|ShiftMask,		XK_i,		incnmaster,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_o,		incnmaster,	{.i = -1 } },
	{ MODKEY,			XK_b,		togglebar,	{0} },

	{ MODKEY,           XK_0,		    view,		{.ui = ~0 } },
	{ MODKEY|ShiftMask,	    XK_0,		tag,		{.ui = ~0 } },
	{ MODKEY,			XK_q,		killclient,	{0} },
	{ MODKEY|ShiftMask,	    XK_q,		quit,		{0} },
	{ MODKEY,			XK_g,		    shiftview,	{ .i = -1 } },
	{ MODKEY,			XK_semicolon,	shiftview,	{ .i = 1 } },
	{ MODKEY,			XK_Page_Up,	    shiftview,	{ .i = -1 } },
	{ MODKEY,			XK_Page_Down,	shiftview,	{ .i = 1 } },
	{ MODKEY,           XK_z,      incrogaps,      {.i = +3 } },
	{ MODKEY,           XK_s,      incrigaps,      {.i = +3 } },
	{ MODKEY|ShiftMask,     XK_z,      incrogaps,      {.i = -3 } },
	{ MODKEY|ShiftMask,     XK_s,      incrigaps,      {.i = -3 } },
	{ MODKEY|ShiftMask,     XK_t,      defaultgaps,     {0} },
	{ MODKEY|ShiftMask,     XK_d,      togglegaps,    {0} },
	{ MODKEY|ControlMask,	XK_g,		togglesticky,	{0} },
	
	{ MODKEY,			XK_grave,	togglescratch,	{.ui = 0} },

	{ MODKEY,				XK_Left,	focusmon,	{.i = -1 } },
	{ MODKEY|ShiftMask,		XK_Left,	tagmon,		{.i = -1 } },
	{ MODKEY,				XK_Right,	focusmon,	{.i = +1 } },
	{ MODKEY|ShiftMask,		XK_Right,	tagmon,		{.i = +1 } },
	{ MODKEY,				XK_space,	zoom,		{0} },
	{ MODKEY|ShiftMask,		XK_space,	togglefloating,	{0} },


	// Launch ST:
	{ MODKEY,			XK_Return,	spawn,		{.v = termcmd } },
	{ MODKEY|ShiftMask,		XK_Return,	spawn,		{.v = tmuxcmd } },


	// { MODKEY,				XK_PageUp,	shiftview,	{ .i = -1 } },
	// { MODKEY|ShiftMask,		XK_Page_Up,	shifttag,	{ .i = -1 } },
	// { MODKEY,				XK_Page_Down,	shiftview,	{ .i = +1 } },
	// { MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	{ .i = +1 } },

	/* { MODKEY|ShiftMask,		XK_Escape,	spawn,	SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_grave,	togglescratch,	SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_Tab,		spawn,		SHCMD("") }, */
	// { MODKEY|ShiftMask,		XK_y,		setlayout,	{.v = &layouts[3]} }, /* dwindle */
	// { MODKEY|ShiftMask,		XK_t,		setlayout,	{.v = &layouts[1]} }, /* bstack */
	/* { MODKEY|ShiftMask,		XK_backslash,		spawn,		SHCMD("") }, */
	// { MODKEY|ShiftMask,             XK_j,		movestack,	{.i = +1 } },
	// { MODKEY|ShiftMask,             XK_k,		movestack,	{.i = -1 } },
	/* { MODKEY|ShiftMask,		XK_apostrophe,	spawn,		SHCMD("") }, */
	// { MODKEY|ShiftMask,		XK_Return,	togglescratch,	{.ui = 0} },
	/* { MODKEY|ShiftMask,		XK_z,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_x,		spawn,		SHCMD("") }, */
	/* { MODKEY,			XK_c,		spawn,		SHCMD("") }, */
	/* { MODKEY|ShiftMask,		XK_c,		spawn,		SHCMD("") }, */
	/* V is automatically bound above in STACKKEYS */
	/* { MODKEY|ShiftMask,		XK_b,		spawn,		SHCMD("") }, */

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};
