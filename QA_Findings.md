# QA Findings: Arduino LED Blinking

## Project Overview
The project uses an Arduino-compatible board to blink an LED connected to digital pin 13. The LED is turned ON and OFF using `digitalWrite()` and `delay()`.

## QA-01: LED Pin Configuration Requires Verification
- **Category:** Hardware compatibility
- **Severity:** Low
- **Description:** The code uses digital pin 13. The intended LED may use a different pin depending on the board and wiring.
- **Root Cause:** The target board and LED connection have not been confirmed.
- **Expected Behavior:** The intended LED should blink at one-second ON and OFF intervals.
- **Proposed Fix:** Verify the board pinout and wiring, then update `LED_PIN` if necessary.
- **Verification:** Check the pinout, compile the code, and test the LED on the intended hardware.
- **Status:** Open; verification pending.

## QA-02: Blocking Delays Limit Other Tasks
- **Category:** Design limitation
- **Severity:** Medium if other periodic tasks are required
- **Description:** The `delay(1000)` calls block the main loop for one second at a time.
- **Root Cause:** The program uses blocking delays to control LED timing.
- **Expected Behavior:** The LED should blink while allowing other tasks to execute when required.
- **Proposed Fix:** Consider using `millis()` for non-blocking timing.
- **Verification:** Run the refactored code and check whether another periodic task can execute during blinking.
- **Status:** Improvement identified; testing pending.

## QA-03: Actual Timing Has Not Been Measured
- **Category:** Verification gap
- **Severity:** Low
- **Description:** The code requests one-second ON and OFF intervals, but the actual timing has not been measured.
- **Root Cause:** No timing measurements or hardware test results are currently available.
- **Expected Behavior:** The LED should remain ON and OFF for approximately one second per phase.
- **Proposed Fix:** Measure the LED timing using suitable test equipment or a reliable observation method.
- **Verification:** Record measured ON and OFF durations and compare them with the expected values.
- **Status:** Testing pending.

## QA-04: Timing Values Are Repeated as Literals
- **Category:** Maintainability
- **Severity:** Low
- **Description:** The value `1000` appears in both delay calls.
- **Root Cause:** Timing values are written directly into the program instead of being defined as named constants.
- **Expected Behavior:** Timing settings should be easy to understand and modify.
- **Proposed Fix:** Define a named constant such as `BLINK_INTERVAL_MS = 1000`.
- **Verification:** Change the constant and confirm that the intended timing changes after compilation and testing.
- **Status:** Improvement identified; testing pending.

## QA-05: Initial LED State Is Not Explicitly Set
- **Category:** Startup behavior
- **Severity:** Low
- **Description:** The program configures the pin as an output but does not explicitly write the initial LOW state in `setup()`.
- **Root Cause:** Initial output state configuration is omitted.
- **Expected Behavior:** The program should establish a defined initial LED state before starting the blink cycle.
- **Proposed Fix:** Add `digitalWrite(LED_PIN, LOW);` in `setup()` after configuring the pin as an output.
- **Verification:** Reset or power-cycle the board and observe the startup behavior.
- **Status:** Improvement identified; testing pending.

## Verification Note
These findings are based on code review. They are not all confirmed defects. Hardware compatibility, timing accuracy, and startup behavior require testing on the intended board. No tests are marked as passed until they have actually been performed.
## Compilation Verification

- **Test ID:** TC-01
- **Test Description:** Compile the refactored Arduino LED-blinking program.
- **Expected Result:** The code compiles without errors.
- **Actual Result:** Compilation completed successfully in Arduino IDE.
- **Status:** PASS
- **Note:** This confirms successful compilation only. Physical LED behavior and timing have not yet been tested.
