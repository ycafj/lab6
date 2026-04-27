Lab Work: RC4 Stream Cipher Implementation
This project is dedicated to text encryption using the RC4 (Rivest Cipher 4) stream cipher algorithm, which involves a Key Scheduling Algorithm (KSA) and a Pseudo-Random Generation Algorithm (PRGA).

Function Descriptions
XOR: A utility function that performs a bitwise exclusive OR operation between two 8-bit sequences. This is the core operation for both encryption and decryption in stream ciphers.
main: Manages the entire cryptographic process, including:
KSA (Key Scheduling Algorithm): Initializes the S-box (permutation vector $S$) using a numeric key (in this case, "347"). It fills the $S$ vector with values from $0$ to $255$ and then scrambles them based on the key.
PRGA (Pseudo-Random Generation Algorithm): Generates a pseudo-random stream of bytes (keystream) that is XORed with the original text for encryption and subsequently with the ciphertext for decryption.
Data Conversion: Converts input text into ASCII values and handles the translation between integers, bitsets, and characters.

Console Output Explanation
Print the text: Prompt for the user to enter the source message.
Decimal sequence: Displays the ASCII codes of the entered characters.
Key expansion: Shows the numeric key digits ("3", "4", "7") and how they are mapped to the K vector.
S-box states: Outputs the state of the $S$ vector before and after the initial scrambling (Permutation).
Binary Debug (n=0): Displays the binary representation of the first keystream byte, the first character, and the resulting XORed bitset for verification.
Final Result: Prints the recovered text after the full decryption process to confirm accuracy.
