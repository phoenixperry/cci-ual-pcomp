# Games States:

Note: For just about any value-defined behavior below, please expose it as a variable in a settings file so that we can easily tweak design and recompile without digging in code.  Many of these cases are specifically requested below, but some could be added which are not noted.  Anything with a defined value is fair game and will make game testing and balancing WAAAAAAY easier and less annoying for everyone!

### State one:

Start button is visible on the PC control UI used by the game-runner. (Eventually, there will be a hardware start button at the front of the game but we've not designed this yet.) For now, no goals are selected. The LEDs on the pollen are just slowly pulsing on and off.

#### Possible User Interactions:
Action: User presses start button.

Result: If the user/game-runner presses start, a random pollen goal is selected, and the game begins.

### State two:

The game waggle dance vibrational pattern plays slowly, directing a player to a goal pollen. The hexes trigger shorter pulses on the hexes looping back to the main line. If this was music, it would be a "1/4, 1/4, 1/4, 1/4, whole, whole, whole, 1/4, 1/4, 1/4, 1/4" rhythm.  (in current radial configuration, the center line is always 3 hexes, with two "circling back" hexes, and since the side hex notes are shorter, it should play the 1/4 note twice per hex to give the player more time to sense it.) (please make these vibe lengths and repetitions-per-hex into variables.)

#### Possible User Interactions:

Action: User selects the correct pollen

Result: A success vibration plays in the center (plexi) hex ("DA-DA-DAAAAAAAA!"). Note: For all of the following states: if this level of vibe control is not feasible for Wednesday, play a placeholder sound file of some kind.
One of the 6 sides of the LED strip comes on in the center hex.  There is a delay of N seconds (start with a delay setting of 10s, and make this value easily designer-editable with a change to a variable.) After the pause, new pattern begins and the game loop chooses a new random goal. (this will have a total of 6 possible rounds)

Action: User selects the wrong pollen.

Result: A failure vibration plays in the center hex: it ramps up about half way, but decreases speed gradually then halts, like a failure-to-launch, or a motor dying. All the lights dim to black, all the motors go off and after a delay of 20 (editable) seconds, the game goes back to the start state.
It's like the whole hive died from not finding enough nectar/pollen. The game restarts.

Data wise, I'd like to collect win and failed attempts in a file for later.

### State three:

#### End game on win:

Win possiblity
The LED strip is fully lit. And the game is complete.

Play the win vibration 3 times, then turn off all the motors, delay 20 (editable) seconds, and then take the game back to the start state.

Note: We will have to think about a reward here - it could just be vibrational and the motors could make a pleased sound then go all off and the game could begin again and go back to the start state.
