# CD4007UB 2-to-1 Multiplexer Automated Testbench

This repository contains an automated testbench code for a 2-to-1 multiplexer (MUX) using the CD4007UB chip. The code is written for an Arduino, and it applies various test cases to check the functionality of the multiplexer based on different input conditions and control signals. The results are printed to the Serial Monitor for each test case, showing whether the test passed or failed.

## Features

- **Automated Testing**: Runs through a set of predefined test vectors for the 2-to-1 MUX and evaluates the output based on the expected logic.
- **Real-time Feedback**: Displays test results (PASS/FAIL) for each input combination on the Serial Monitor.
- **Detailed Summary**: After running all test cases, the code provides an overall success rate.

## How It Works

The 2-to-1 multiplexer selects between two inputs (`Input A` and `Input B`) based on a control signal (`Control`). The output (`Output Y`) is determined by the value of the control signal:

- When `Control = LOW`, the output is `Input A`.
- When `Control = HIGH`, the output is `Input B`.

This testbench automates the process of applying different combinations of `Input A`, `Input B`, and `Control`, then checks if the output matches the expected behavior.

### Pin Assignments

| Pin         | Arduino Pin | Description               |
|-------------|-------------|---------------------------|
| Input A     | 3           | First input to the multiplexer |
| Input B     | 4           | Second input to the multiplexer |
| Control     | 2           | Control signal for selecting input |
| Output Y    | 5           | Output from the multiplexer  |

### Test Vectors

The testbench runs the following test vectors:

- For `Control = LOW`, the output should match `Input A`.
- For `Control = HIGH`, the output should match `Input B`.

Each test vector has a set of inputs and an expected output, which is compared against the actual output.

## Setup Instructions

1. **Hardware Requirements**:
   - Arduino board
   - CD4007UB 2-to-1 multiplexer
   - Breadboard and connecting wires
   - Logic level signals to apply inputs and read outputs

2. **Software**:
   - Install the Arduino IDE.
   - Upload the provided code to your Arduino.

3. **Connections**:
   - Connect the multiplexer pins to the Arduino according to the pin assignments listed above.
   - Ensure proper power supply and grounding for the CD4007UB chip.

4. **Running the Tests**:
   - Open the Serial Monitor in the Arduino IDE.
   - Set the baud rate to 9600.
   - The testbench will automatically run and display the results in the Serial Monitor.

## Serial Monitor Output

For each test, the following details are printed:

- `Test n`: The test number.
- `INPUT1`, `INPUT2`, and `CONTROL`: The values applied to the multiplexer.
- `Expected OUTPUT`: The expected result based on the control signal.
- `Actual OUTPUT`: The value read from the output pin.
- `Result`: Whether the test passed or failed.

At the end of the test sequence, the number of passed tests and the overall success rate are displayed.

## Example Output

```
Test 1: INPUT1=LOW, INPUT2=LOW, CONTROL=LOW | Expected OUTPUT=LOW | Actual OUTPUT=LOW | Result: PASS
Test 2: INPUT1=LOW, INPUT2=HIGH, CONTROL=LOW | Expected OUTPUT=LOW | Actual OUTPUT=LOW | Result: PASS
...
Test Sequence Completed.
Passed Tests: 8 out of 8 tests.
Overall Success Rate: 100.0%
```
