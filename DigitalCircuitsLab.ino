// Define pin assignments
const int input1Pin = 3;           // Connected to Input A
const int input2Pin = 4;           // Connected to Input B
const int controlPin = 2;          // Control Signal (S)
const int outputPin = 5;           // Connected to Output Y

// Define test vectors for 2-to-1 MUX
struct TestVector {
  bool INPUT1;
  bool INPUT2;
  bool CONTROL;
  bool EXPECTED_OUTPUT;
};

// Define all possible test cases
const TestVector testVectors[] = {
  // CONTROL = 0, EXPECTED_OUTPUT = INPUT1
  {LOW, LOW, LOW, LOW},
  {LOW, HIGH, LOW, LOW},
  {HIGH, LOW, LOW, HIGH},
  {HIGH, HIGH, LOW, HIGH},
  
  // CONTROL = 1, EXPECTED_OUTPUT = INPUT2
  {LOW, LOW, HIGH, LOW},
  {LOW, HIGH, HIGH, HIGH},
  {HIGH, LOW, HIGH, LOW},
  {HIGH, HIGH, HIGH, HIGH}
};

const int numTests = sizeof(testVectors) / sizeof(testVectors[0]);

// Variables to keep track of test results
int passedTests = 0;

void setup() {
  // Initialize serial communication at 9600 bps
  Serial.begin(9600);
  
  // Configure pin modes
  pinMode(input1Pin, OUTPUT);        // Input 1
  pinMode(input2Pin, OUTPUT);        // Input 2
  pinMode(controlPin, OUTPUT);       // Control Signal
  pinMode(outputPin, INPUT);         // Output
  
  // Initialize inputs to LOW
  digitalWrite(input1Pin, LOW);
  digitalWrite(input2Pin, LOW);
  digitalWrite(controlPin, LOW);
  
  Serial.println("CD4007UB 2-to-1 Multiplexer Automated Testbench");
  Serial.println("--------------------------------------------------");
}

void loop() {
  passedTests = 0; // Reset passed tests count
  
  Serial.println("\nStarting Test Sequence...\n");
  
  for (int i = 0; i < numTests; i++) {
    // Apply Control Signal
    digitalWrite(controlPin, testVectors[i].CONTROL);
    
    // Apply Inputs 1 and 2
    digitalWrite(input1Pin, testVectors[i].INPUT1);
    digitalWrite(input2Pin, testVectors[i].INPUT2);
    delay(100); // Short delay to stabilize
    
    // Read Output
    bool actualOutput = digitalRead(outputPin);
    
    // Validate Output
    bool testPassed = (actualOutput == testVectors[i].EXPECTED_OUTPUT);
    if (testPassed) {
      passedTests++;
    }
    
    // Log Result
    Serial.print("Test ");
    Serial.print(i + 1);
    Serial.print(": INPUT1=");
    Serial.print(testVectors[i].INPUT1 ? "HIGH" : "LOW");
    Serial.print(", INPUT2=");
    Serial.print(testVectors[i].INPUT2 ? "HIGH" : "LOW");
    Serial.print(", CONTROL=");
    Serial.print(testVectors[i].CONTROL ? "HIGH" : "LOW");
    Serial.print(" | Expected OUTPUT=");
    Serial.print(testVectors[i].EXPECTED_OUTPUT ? "HIGH" : "LOW");
    Serial.print(" | Actual OUTPUT=");
    Serial.print(actualOutput ? "HIGH" : "LOW");
    Serial.print(" | Result: ");
    Serial.println(testPassed ? "PASS" : "FAIL");
    
    delay(500); // Wait before next test vector
  }
  
  // Calculate and log overall success rate
  Serial.println("\nTest Sequence Completed.");
  Serial.print("Passed Tests: ");
  Serial.print(passedTests);
  Serial.print(" out of ");
  Serial.print(numTests);
  Serial.println(" tests.");
  
  float successRate = ((float)passedTests / numTests) * 100;
  Serial.print("Overall Success Rate: ");
  Serial.print(successRate);
  Serial.println("%");
  
  // Wait before repeating the test sequence
  delay(5000); // Wait for 5 seconds before next iteration
}