/*
  distancethreshold: Minimum cutoff for a gestures to take effect
  degreesleniency: Offset degrees within which gesture is recognized (max=45)
  timeoutms: Maximum duration for a gesture to take place in miliseconds
  orientation: Number of 90 degree turns to shift gestures by
  verbose: 1=enabled, 0=disabled; helpful for debugging
  device: Path to the /dev/ filesystem device events should be read from
  gestures: Array of gestures; binds num of fingers / gesturetypes to commands
            Supported gestures: SwipeLR, SwipeRL, SwipeDU, SwipeUD,
                                SwipeDLUR, SwipeURDL, SwipeDRUL, SwipeULDR
*/

unsigned int distancethreshold = 20;
unsigned int distancethreshold_pressed = 60;
unsigned int degreesleniency = 15;
unsigned int timeoutms = 800;
unsigned int orientation = 0;
unsigned int verbose = 0;
double edgesizeleft = 50.0;
double edgesizetop = 200.0;
double edgesizeright = 50.0;
double edgesizebottom = 200.0;
double edgessizecaling = 1.0;
/*
 * Run the `sudo libinput list-devices`, and find the line
 * `Capabilities: touch`.
 * Check the `/dev/input/eventN`, and find the static name by running
 * the `ls -l /dev/input/by-path`.
 */
char *device = "/dev/input/by-path/pci-0000:00:15.0-platform-i2c_designware.0-event";

//Gestures can also be specified interactively from the command line using -g
Gesture gestures[] = {
	/* nfingers  gesturetype  command */
	/* Volume up */
	{ 1,         SwipeDU,     EdgeTop, DistanceAny, ActModeReleased, "pactl set-sink-volume @DEFAULT_SINK@ +5%" },
	/* Volume down */
	{ 1,         SwipeUD,     EdgeTop, DistanceAny, ActModeReleased, "pactl set-sink-volume @DEFAULT_SINK@ -5%" },
	/* Brightness up */
	{ 1,         SwipeLR,     EdgeTop, DistanceAny, ActModeReleased, "brightnessctl --device intel_backlight --min-value=1 set 2%+" },
	/* Brightness down */
	{ 1,         SwipeRL,     EdgeTop, DistanceAny, ActModeReleased, "brightnessctl --device intel_backlight set 2%-" },
	/* Show a virtual keyboard */
	{ 1,         SwipeDU,     EdgeBottom, DistanceAny, ActModeReleased, "~/script/control_wvkbd.sh SIGUSR2" },
	/* Hide a virtual keyboard */
	{ 1,         SwipeUD,     EdgeBottom, DistanceAny, ActModeReleased, "~/script/control_wvkbd.sh SIGUSR1" },
};
