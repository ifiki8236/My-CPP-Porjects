import java.util.Scanner;

public class Roman_Numerals {
	public static void main(String[] args) {
		//creating scanner object for user input
		Scanner sc = new Scanner(System.in);
		String romanNum = "";
		
		System.out.print("Enter a number in the range of 1 - 10: ");
		int input = sc.nextInt();

		//catch input outside set range 
        while (input < 1 || input > 10) {
            System.out.println("Only numbers 1 - 10 are allowed");
            System.out.print("Enter a number in the range of 1 - 10: ");
            input = sc.nextInt();
		}
		//checks user input and converts from standard numbers to Roman Numerals
		switch (input) {
			case 1:
			romanNum = "I";
			break;
			case 2:
            romanNum = "II";
			break;
			case 3:
            romanNum = "III";
			break;
			case 4:
            romanNum = "IV";
			break;
			case 5:
            romanNum = "V";
			break;
			case 6:
            romanNum = "VI";
			break;
			case 7:
            romanNum = "VII";
			break;
			case 8:
            romanNum = "VIII";
			break;
			case 9:
            romanNum = "IX";
			break;
			case 10:
            romanNum = "X";
			break;
		}
		//prints the roman numeral and closes the scanner object
		System.out.printf(romanNum);
        sc.close();
    }
}