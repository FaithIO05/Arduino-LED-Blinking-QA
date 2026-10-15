# AI Prompt Log

## 1. Project Information
- **Project Title:** AI-Assisted GitHub-Based QA Documentation and Problem Solving for Electronics Projects
- **Example Project:** Arduino LED Blinking
- **AI Tool Used:** ChatGPT
- **Purpose:** To review the Arduino code, identify potential QA issues, and suggest improvements.

## 2. Prompt Used

I am completing a Project Management assignment titled "AI-Assisted GitHub-Based QA Documentation and Problem Solving for Electronics Projects."

Please review the following Arduino LED-blinking code as a QA engineer.

```cpp
const int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);

  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
```

Please:
1. Explain what the code does.
2. Identify at least four potential QA issues, edge cases, or improvement opportunities.
3. For each finding, provide its severity, root cause, expected behavior, proposed fix, and a verification method.
4. Distinguish confirmed defects from possible hardware compatibility concerns and code-quality improvements.
5. Suggest a refactored version using non-blocking timing with `millis()`, if appropriate.
6. Do not invent test results. Clearly state which findings require hardware testing.
7. Explain how to document each verified finding in GitHub Issues.

Return the findings in a structured table suitable for my assignment report.

## 3. Summary of AI Output

The AI review identified the following potential issues and improvement opportunities:

- **Blocking delays:** The `delay()` function prevents other tasks from running during the waiting period.
- **LED pin compatibility:** Pin 13 must be checked against the selected board and LED connection.
- **Timing verification:** Actual LED ON/OFF durations have not yet been measured.
- **Repeated timing values:** Named constants could improve maintainability.
- **Startup state:** The initial LED state could be explicitly configured.

The review also suggested a non-blocking implementation using `millis()` and proposed test cases for compilation, timing, startup behavior, and hardware compatibility.

## 4. Verification Status

The AI findings are preliminary review results, not proof of confirmed defects. Hardware compatibility and actual timing behavior still require verification.

- **Hardware testing:** Pending
- **Compilation testing:** Pending
- **Timing measurements:** Pending
- **Refactored code testing:** Pending

No test results are claimed until the corresponding tests have actually been performed.

## 5. Learning Outcome

This activity demonstrated how AI can assist with code review, identify potential quality risks, suggest refactoring, and support test planning. It also highlighted the importance of independently verifying AI-generated suggestions before accepting them as correct.
