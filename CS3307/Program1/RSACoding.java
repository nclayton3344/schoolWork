/* This is a simple Java program to encrypt and decrypt
   messages using the RSA Algorithm.
   Author: Nathaniel Clayton
   FileName : "RSACoding.java".
   Date: 10/10/2019 

   Interesting Note: 
	I originally tried using 9967 and 9973 as my p and q but I 
	quickly realized that large prime numbers would cause
	overflow during encryption/decryption even with the long data 
	type. I picked the lowest 4 digits primes for this reason. 

*/
class RSACoding 
{ 
    public static void main(String args[]) 
    { 
        int p = 1009;
	int q = 1013;
	int n = p * q;	
	int privateKey = 404189;
	int publicKey = 53;
	String message = "HI! HOW ARE YOU? LEND ME YOUR EARS.";

	// Get Message and print the message
	System.out.println("Given Text: ");
	System.out.println(message);
	
	// convert message to numeric representation and display
	message = textToNum(message);
	System.out.println("\nDigital message grouped two together: ");
	System.out.println(message);
	
	
	// Display encrypted message
	message = cryptography(message, publicKey, n);
	System.out.println("\nEncryption for the grouped digits");
	System.out.println(message);

	// Decrypting the encryption and display
	message = cryptography(message, privateKey, n);
	System.out.println("\nDecryption for the number groups:");
	System.out.println(message);

	// Display decrypted message
	message = numToText(message);
	System.out.println("\nDecrypted Message:");
	System.out.println(message);
 
    }

    public static String cryptography(String message, int key, int n) {
	String encrypted = "";
	String[] digits = message.split(" ");

	// send the digitized message through encryption
	for(int i = 0; i < digits.length; i++) {
		long value = Long.parseLong(digits[i]);		
		encrypted += crypto(value, key, n) + " ";
	}
	return encrypted;
    }

    public static String numToText(String digits) {
	
	String convertedMessage = "";
	digits = digits.replaceAll("\\s+","");
	
	// loop through the message and convert
	// message to digits grouped by two
	for(int i = 0; i < digits.length(); i+=2) {
		
		// grab two digits from the digit string
		int value = Integer.parseInt(digits.substring(i,i+2));
		
		// check for special character case
		if(value < 36) {
			convertedMessage += Character.toUpperCase(Character.forDigit(value, 36));	
		} else {
			switch(value) {
				case 40:
					convertedMessage += "!";
					break;
				case 36:
					convertedMessage += " ";
					break;
				case 37:
					convertedMessage += ",";
					break;
				case 38:
					convertedMessage += ".";
					break;
				case 39:
					convertedMessage += "?";
					break;
				default:
					break;
			}		
		}
			
	}
	return convertedMessage;
    }

    public static String textToNum(String message) {

	String convertedMessage = "";
	
	// loop through the message and convert
	// message to digits grouped by two
	for(int i = 0; i < message.length(); i++) {

		char c = message.charAt(i);
		int value;
		
		// check for special character case
		if(Character.isLetter(c)) {
			value = Character.getNumericValue(c);	
		} else {
			switch(c) {
				case '!':
					value = 40;
					break;
				case ' ':
					value = 36;
					break;
				case ',':
					value = 37;
					break;
				case '.':
					value = 38;
					break;
				case '?':
					value = 39;
					break;
				default:
					value = 0;
					break;
			}		
		}

		convertedMessage += value;
		if(i % 2 == 1) {
			convertedMessage += ' ';
		}			
	}
	return convertedMessage;	
    }

    public static long crypto(long message, int key, int n) {
	
	// convert key to binary string
	String binaryString = Integer.toBinaryString(key);
	long a = 1;
	
	// encryption/decryption algorithm
	for(int i = 0; i < binaryString.length(); i++) {
		if(binaryString.charAt(i) == '1'){
			a = ((a * a) * message) % n;		
		} else {
			a = (a * a) % n;		
		}
	}
	return a;   	
    } 
}

