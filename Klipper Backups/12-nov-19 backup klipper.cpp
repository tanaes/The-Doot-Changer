# This file serves as documentation for config parameters. One may
# copy and edit this file to configure a new cartesian style
# printer. For delta style printers, see the "example-delta.cfg"
# file. For corexy/h-bot style printers, see the "example-corexy.cfg"
# file. Only common config sections are described here - see the
# "example-extras.cfg" file for configuring less common devices.

# DO NOT COPY THIS FILE WITHOUT CAREFULLY READING AND UPDATING IT
# FIRST. Incorrectly configured parameters may cause damage.

# A note on pin names: pins may be configured with a hardware name
# (such as "PA4") or with an Arduino alias name (such as "ar29" or
# "analog3"). In order to use Arduino names, the pin_map variable in
# the mcu section must be present and have a value of "arduino". Pin
# names may be preceded by an '!' to indicate that a reverse polarity
# should be used (eg, trigger on low instead of high). Input pins may
# be preceded by a '^' to indicate that a hardware pull-up resistor
# should be enabled for the pin. If the micro-controller supports
# pull-down resistors then an input pin may alternatively be preceded
# by a '~'.


# The stepper_x section is used to describe the stepper controlling
# the X axis in a cartesian robot.
[stepper_x]
step_pin: ar54
#   Step GPIO pin (triggered high). This parameter must be provided.
dir_pin: !ar55
#   Direction GPIO pin (high indicates positive direction). This
#   parameter must be provided.
enable_pin: !ar38
#   Enable pin (default is enable high; use ! to indicate enable
#   low). Alternatively, this may be a comma separated list of pins to
#   enable. If this parameter is not provided then the stepper motor
#   driver must always be enabled.
step_distance: .0125
#   Distance in mm that each step causes the axis to travel. This
#   parameter must be provided.
endstop_pin: ^ar3
#   Endstop switch detection pin. This parameter must be provided for
#   the X, Y, and Z steppers on cartesian style printers.
#position_min: 0
#   Minimum valid distance (in mm) the user may command the stepper to
#   move to.  The default is 0mm.
position_endstop: 0
#   Location of the endstop (in mm). This parameter must be provided
#   for the X, Y, and Z steppers on cartesian style printers.
position_max: 300
homing_speed: 40.0
#homing_retract_dist: 5.0
#second_homing_speed:
#homing_positive_dir:

[stepper_y]
step_pin: ar60
dir_pin: !ar61
enable_pin: !ar56
step_distance: .0125
endstop_pin: ^ar14
homing_speed: 40.0
position_endstop: 0
position_max: 300

[stepper_z]
step_pin: ar46
dir_pin: !ar48
enable_pin: !ar62
step_distance: .0025
endstop_pin: ^ar18
position_endstop: 0
#endstop_pin: probe:z_virtual_endstop
position_max: 285
position_min: -2
homing_speed: 10

[extruder]
step_pin: ar26
dir_pin: ar28
enable_pin: !ar24
step_distance: 0.0024045
nozzle_diameter: 0.4
filament_diameter: 1.7500
#max_extrude_cross_section:
max_extrude_only_distance: 700
#max_extrude_only_velocity:
#max_extrude_only_accel:
pressure_advance: 0.04
#pressure_advance_lookahead_time: 0.010
heater_pin: ar10
#max_power: 1.0
sensor_type: ATC Semitec 104GT-2
#   Type of sensor - this may be "EPCOS 100K B57560G104F", "ATC
#   Semitec 104GT-2", "NTC 100K beta 3950", "Honeywell 100K
#   135-104LAG-J01", "NTC 100K MGB18-104F39050L32", "AD595", "PT100
#   INA826", "MAX6675", "MAX31855", "MAX31856", or "MAX31865".
#   Additional sensor types may be available - see the
#   example-extras.cfg file for details. This parameter must be
#   provided.
sensor_pin: analog13
#pullup_resistor: 4700
#inline_resistor: 0
#adc_voltage: 5.0
#smooth_time: 2.0
#control: pid
#pid_Kp: 16.34
#pid_Ki: 1.16
#pid_Kd: 57.57
#pid_integral_max:
#pwm_cycle_time: 0.100
#   Time in seconds for each software PWM cycle of the heater. It is
#   not recommended to set this unless there is an electrical
#   requirement to switch the heater faster than 10 times a second.
#   The default is 0.100 seconds.
#min_extrude_temp: 170
#   The minimum temperature (in Celsius) at which extruder move
#   commands may be issued. The default is 170 Celsius.
min_temp: 0
max_temp: 260
#   The maximum range of valid temperatures (in Celsius) that the
#   heater must remain within. This controls a safety feature
#   implemented in the micro-controller code - should the measured
#   temperature ever fall outside this range then the micro-controller
#   will go into a shutdown state. This check can help detect some
#   heater and sensor hardware failures. Set this range just wide
#   enough so that reasonable temperatures do not result in an
#   error. These parameters must be provided.

#[extruder1]
#step_pin: ar36
#dir_pin: !ar34
#enable_pin: !ar30
#step_distance: 0.0025364567057292
#nozzle_diameter: 0.4
#filament_diameter: 1.7500
#max_extrude_only_distance: 650
#pressure_advance: 0.31
#shared_heater: extruder

# The heater_bed section describes a heated bed (if present - omit
# section if not present).
[heater_bed]
heater_pin: ar8
sensor_type: NTC 100K beta 3950
sensor_pin: analog14
control: pid
pid_Kp: 54.73
pid_Ki: 1.69
pid_Kd: 1180.74
#max_delta: 2.0
#   On 'watermark' controlled heaters this is the number of degrees in
#   Celsius above the target temperature before disabling the heater
#   as well as the number of degrees below the target before
#   re-enabling the heater. The default is 2 degrees Celsius.
min_temp: 0
max_temp: 110
max_power: 1.0

# Print cooling fan 
[fan]
pin: ar9
#max_power: 1.0
#shutdown_speed: 0
#   The desired fan speed (expressed as a value from 0.0 to 1.0) if
#   the micro-controller software enters an error state. The default
#   is 0.
#cycle_time: 0.010
#   The amount of time (in seconds) for each PWM power cycle to the
#   fan. It is recommended this be 10 milliseconds or greater when
#   using software based PWM. The default is 0.010 seconds.
#hardware_pwm: False
#   Enable this to use hardware PWM instead of software PWM. Most fans
#   do not work well with hardware PWM, so it is not recommended to
#   enable this unless there is an electrical requirement to switch at
#   very high speeds. When using hardware PWM the actual cycle time is
#   constrained by the implementation and may be significantly
#   different than the requested cycle_time. The default is False.
#kick_start_time: 0.100
#   Time (in seconds) to run the fan at full speed when first enabling
#   it (helps get the fan spinning). The default is 0.100 seconds.

# Micro-controller information.
[mcu]
serial: /dev/ttyUSB0
#   The serial port to connect to the MCU. If unsure (or if it
#   changes) see the "Where's my serial port?" section of the FAQ. The
#   default is /dev/ttyS0
#baud: 250000
#   The baud rate to use. The default is 250000.
pin_map: arduino
#   This option may be used to enable Arduino pin name aliases. The
#   default is to not enable the aliases.
#restart_method:
#   This controls the mechanism the host will use to reset the
#   micro-controller. The choices are 'arduino', 'rpi_usb', and
#   'command'. The 'arduino' method (toggle DTR) is common on Arduino
#   boards and clones. The 'rpi_usb' method is useful on Raspberry Pi
#   boards with micro-controllers powered over USB - it briefly
#   disables power to all USB ports to accomplish a micro-controller
#   reset. The 'command' method involves sending a Klipper command to
#   the micro-controller so that it can reset itself. The default is
#   'arduino' if the micro-controller communicates over a serial port,
#   'command' otherwise.

# The printer section controls high level printer settings.
[printer]
kinematics: corexy
#   This option must be "cartesian" for cartesian printers.
max_velocity: 400
#   Maximum velocity (in mm/s) of the toolhead (relative to the
#   print). This parameter must be specified.
max_accel: 1250
#   Maximum acceleration (in mm/s^2) of the toolhead (relative to the
#   print). This parameter must be specified.
#max_accel_to_decel:
#   A pseudo acceleration (in mm/s^2) controlling how fast the
#   toolhead may go from acceleration to deceleration. It is used to
#   reduce the top speed of short zig-zag moves (and thus reduce
#   printer vibration from these moves). The default is half of
#   max_accel.
max_z_velocity: 15
#   For cartesian printers this sets the maximum velocity (in mm/s) of
#   movement along the z axis. This setting can be used to restrict
#   the maximum speed of the z stepper motor on cartesian
#   printers. The default is to use max_velocity for max_z_velocity.
max_z_accel: 80
#   For cartesian printers this sets the maximum acceleration (in
#   mm/s^2) of movement along the z axis. It limits the acceleration
#   of the z stepper motor on cartesian printers. The default is to
#   use max_accel for max_z_accel.
square_corner_velocity: 8.0
#   The maximum velocity (in mm/s) that the toolhead may travel a 90
#   degree corner at. A non-zero value can reduce changes in extruder
#   flow rates by enabling instantaneous velocity changes of the
#   toolhead during cornering. This value configures the internal
#   centripetal velocity cornering algorithm; corners with angles
#   larger than 90 degrees will have a higher cornering velocity while
#   corners with angles less than 90 degrees will have a lower
#   cornering velocity. If this is set to zero then the toolhead will
#   decelerate to zero at each corner. The default is 5mm/s.


# Looking for more options? Check the example-extras.cfg file.

#Controller cooling fan (one may define any number of sections with a
# "controller_fan" prefix). A "controller fan" is a fan that will be
# enabled whenever its associated heater or any configured stepper
# driver is active. The fan will stop, whenever an idle_timeout is
# reached to ensure no overheating will occur after deactivating a
# watched component.
#[controller_fan my_controller_fan]
#pin: ar44
#max_power: 0.8
#shutdown_speed:
#cycle_time:
#hardware_pwm:
#kick_start_time:
#   See the "fan" section in example.cfg for a description of the
#   above parameters.
#idle_timeout:
#   The ammount of time (in seconds) after a stepper driver or heater
#   was active and the fan should be kept running. The default
#   is 30 seconds.
#idle_speed:
#   The fan speed (expressed as a value from 0.0 to 1.0) that the fan
#   will be set to when a heater or stepper driver was active and before
#   the idle_timeout is reached. This must be greater or equal
#   max_power. The default is max_power
#heater:
#   Name of the config section defining the heater that this fan is
#   associated with. If a comma separated list of heater names is
#   provided here, then the fan will be enabled when any of the given
#   heaters are enabled. The default is "extruder".


# Heater cooling fans (one may define any number of sections with a
# "heater_fan" prefix). A "heater fan" is a fan that will be enabled
# whenever its associated heater is active. By default, a heater_fan
# has a shutdown_speed equal to max_power.
[heater_fan my_nozzle_fan]
pin: ar7
#max_power: 1.0
#shutdown_speed:
#cycle_time:
#hardware_pwm:
#kick_start_time:
#   See the "fan" section in example.cfg for a description of the
#   above parameters.
#heater: extruder
#   Name of the config section defining the heater that this fan is
#   associated with. If a comma separated list of heater names is
#   provided here, then the fan will be enabled when any of the given
#   heaters are enabled. The default is "extruder".
#heater_temp: 50.0
#   A temperature (in Celsius) that the heater must drop below before
#   the fan is disabled. The default is 50 Celsius.
#fan_speed: 1.0
#   The fan speed (expressed as a value from 0.0 to 1.0) that the fan
#   will be set to when its associated heater is enabled. The default
#   is 1.0




# Common EXP1 / EXP2 (display) pins
[board_pins]
aliases:
    # Common EXP1 header found on many "all-in-one" ramps clones
    EXP1_1=ar37, EXP1_3=ar17, EXP1_5=ar23, EXP1_7=ar27, EXP1_9=<GND>,
    EXP1_2=ar35, EXP1_4=ar16, EXP1_6=ar25, EXP1_8=ar29, EXP1_10=<5V>,
    # EXP2 header
    EXP2_1=ar50, EXP2_3=ar31, EXP2_5=ar33, EXP2_7=ar49, EXP2_9=<GND>,
    EXP2_2=ar52, EXP2_4=ar53, EXP2_6=ar51, EXP2_8=ar41, EXP2_10=<RST>
    # Pins EXP2_1, EXP2_6, EXP2_2 are also MISO, MOSI, SCK of bus "spi"
    # Note, some boards wire: EXP2_8=<RST>, EXP2_10=ar41

# Support for a display attached to the micro-controller.
[display]
lcd_type: hd44780
rs_pin: EXP1_4
e_pin: EXP1_3
d4_pin: EXP1_5
d5_pin: EXP1_6
d6_pin: EXP1_7
d7_pin: EXP1_8
encoder_pins: ^EXP2_3, ^EXP2_5
click_pin: ^!EXP1_2
kill_pin: ^!EXP2_8

[output_pin beeper]
pin: EXP1_1

[tmc2208 extruder]
#interpolate: false
uart_pin: ar66
microsteps: 16
run_current: 0.55

[tmc2208 stepper_x]
#interpolate: false
uart_pin: ar59
microsteps: 16
run_current: 0.85
#stealthchop_threshold: 150

[tmc2208 stepper_y]
#interpolate: false
uart_pin: ar64
microsteps: 16
run_current: 0.85
#stealthchop_threshold: 150

[tmc2208 stepper_z]
#interpolate: false
uart_pin: ar44
microsteps: 16
run_current: 0.86

[gcode_macro G29]
gcode:
       G28
       G1 Z10 F600
       BED_MESH_CALIBRATE

[gcode_macro M600]
default_parameter_X: 10
default_parameter_Y: 280
default_parameter_Z: 10
gcode:
    SAVE_GCODE_STATE NAME=M600_state
    PAUSE
    G91
    G1 E-.8 F2700
    G1 Z{Z}
    G90
    G1 X{X} Y{Y} F3000
    G91
    G1 E-450 F1000
    G90

#*# <---------------------- SAVE_CONFIG ---------------------->
#*# DO NOT EDIT THIS BLOCK OR BELOW. The contents are auto-generated.
#*#
#*# [extruder]
#*# control = pid
#*# pid_kp = 23.347
#*# pid_ki = 1.402
#*# pid_kd = 97.180
