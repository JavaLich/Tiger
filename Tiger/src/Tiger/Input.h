#pragma once

namespace Tiger {

	class Input {
	public:
		using KeyCode = uint16_t;
		using MouseCode = uint16_t;
		virtual ~Input() = default;
		virtual bool isKeyPressed(KeyCode keyCode) = 0;
		virtual bool isMouseButtonPressed(MouseCode mouseCode) = 0;
		virtual std::pair<double, double> getMousePos() = 0;

		static void initializeInput();
		inline static Input& get() { return *instance; };
	private:
		static Scope<Input> instance;
	};

}

#ifdef TG_PLATFORM_WINDOWS
	#define TG_KEY_SPACE              32
	#define TG_KEY_APOSTROPHE         39  /* ' */
	#define TG_KEY_COMMA              44  /* , */
	#define TG_KEY_MINUS              45  /* - */
	#define TG_KEY_PERIOD             46  /* . */
	#define TG_KEY_SLASH              47  /* / */
	#define TG_KEY_0                  48
	#define TG_KEY_1                  49
	#define TG_KEY_2                  50
	#define TG_KEY_3                  51
	#define TG_KEY_4                  52
	#define TG_KEY_5                  53
	#define TG_KEY_6                  54
	#define TG_KEY_7                  55
	#define TG_KEY_8                  56
	#define TG_KEY_9                  57
	#define TG_KEY_SEMICOLON          59  /* ; */
	#define TG_KEY_EQUAL              61  /* = */
	#define TG_KEY_A                  65
	#define TG_KEY_B                  66
	#define TG_KEY_C                  67
	#define TG_KEY_D                  68
	#define TG_KEY_E                  69
	#define TG_KEY_F                  70
	#define TG_KEY_G                  71
	#define TG_KEY_H                  72
	#define TG_KEY_I                  73
	#define TG_KEY_J                  74
	#define TG_KEY_K                  75
	#define TG_KEY_L                  76
	#define TG_KEY_M                  77
	#define TG_KEY_N                  78
	#define TG_KEY_O                  79
	#define TG_KEY_P                  80
	#define TG_KEY_Q                  81
	#define TG_KEY_R                  82
	#define TG_KEY_S                  83
	#define TG_KEY_T                  84
	#define TG_KEY_U                  85
	#define TG_KEY_V                  86
	#define TG_KEY_W                  87
	#define TG_KEY_X                  88
	#define TG_KEY_Y                  89
	#define TG_KEY_Z                  90
	#define TG_KEY_LEFT_BRACKET       91  /* [ */
	#define TG_KEY_BACKSLASH          92  /* \ */
	#define TG_KEY_RIGHT_BRACKET      93  /* ] */
	#define TG_KEY_GRAVE_ACCENT       96  /* ` */
	#define TG_KEY_WORLD_1            161 /* non-US #1 */
	#define TG_KEY_WORLD_2            162 /* non-US #2 */

	/* Function keys */
	#define TG_KEY_ESCAPE             256
	#define TG_KEY_ENTER              257
	#define TG_KEY_TAB                258
	#define TG_KEY_BACKSPACE          259
	#define TG_KEY_INSERT             260
	#define TG_KEY_DELETE             261
	#define TG_KEY_RIGHT              262
	#define TG_KEY_LEFT               263
	#define TG_KEY_DOWN               264
	#define TG_KEY_UP                 265
	#define TG_KEY_PAGE_UP            266
	#define TG_KEY_PAGE_DOWN          267
	#define TG_KEY_HOME               268
	#define TG_KEY_END                269
	#define TG_KEY_CAPS_LOCK          280
	#define TG_KEY_SCROLL_LOCK        281
	#define TG_KEY_NUM_LOCK           282
	#define TG_KEY_PRINT_SCREEN       283
	#define TG_KEY_PAUSE              284
	#define TG_KEY_F1                 290
	#define TG_KEY_F2                 291
	#define TG_KEY_F3                 292
	#define TG_KEY_F4                 293
	#define TG_KEY_F5                 294
	#define TG_KEY_F6                 295
	#define TG_KEY_F7                 296
	#define TG_KEY_F8                 297
	#define TG_KEY_F9                 298
	#define TG_KEY_F10                299
	#define TG_KEY_F11                300
	#define TG_KEY_F12                301
	#define TG_KEY_F13                302
	#define TG_KEY_F14                303
	#define TG_KEY_F15                304
	#define TG_KEY_F16                305
	#define TG_KEY_F17                306
	#define TG_KEY_F18                307
	#define TG_KEY_F19                308
	#define TG_KEY_F20                309
	#define TG_KEY_F21                310
	#define TG_KEY_F22                311
	#define TG_KEY_F23                312
	#define TG_KEY_F24                313
	#define TG_KEY_F25                314
	#define TG_KEY_KP_0               320
	#define TG_KEY_KP_1               321
	#define TG_KEY_KP_2               322
	#define TG_KEY_KP_3               323
	#define TG_KEY_KP_4               324
	#define TG_KEY_KP_5               325
	#define TG_KEY_KP_6               326
	#define TG_KEY_KP_7               327
	#define TG_KEY_KP_8               328
	#define TG_KEY_KP_9               329
	#define TG_KEY_KP_DECIMAL         330
	#define TG_KEY_KP_DIVIDE          331
	#define TG_KEY_KP_MULTIPLY        332
	#define TG_KEY_KP_SUBTRACT        333
	#define TG_KEY_KP_ADD             334
	#define TG_KEY_KP_ENTER           335
	#define TG_KEY_KP_EQUAL           336
	#define TG_KEY_LEFT_SHIFT         340
	#define TG_KEY_LEFT_CONTROL       341
	#define TG_KEY_LEFT_ALT           342
	#define TG_KEY_LEFT_SUPER         343
	#define TG_KEY_RIGHT_SHIFT        344
	#define TG_KEY_RIGHT_CONTROL      345
	#define TG_KEY_RIGHT_ALT          346
	#define TG_KEY_RIGHT_SUPER        347
	#define TG_KEY_MENU               348

	#define TG_KEY_LAST               TG_KEY_MENU

	#define TG_MOUSE_BUTTON_1         0
	#define TG_MOUSE_BUTTON_2         1
	#define TG_MOUSE_BUTTON_3         2
	#define TG_MOUSE_BUTTON_4         3
	#define TG_MOUSE_BUTTON_5         4
	#define TG_MOUSE_BUTTON_6         5
	#define TG_MOUSE_BUTTON_7         6
	#define TG_MOUSE_BUTTON_8         7
	#define TG_MOUSE_BUTTON_LAST      TG_MOUSE_BUTTON_8
	#define TG_MOUSE_BUTTON_LEFT      TG_MOUSE_BUTTON_1
	#define TG_MOUSE_BUTTON_RIGHT     TG_MOUSE_BUTTON_2
	#define TG_MOUSE_BUTTON_MIDDLE    TG_MOUSE_BUTTON_3
#else
	#error Tiger only supports Windows
#endif