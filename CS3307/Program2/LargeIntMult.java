/* 
   This is a simple Java program to compute the product of large
   integer values using arrays.
   Name: Nathaniel Clayton
   Date: 11/06/2019 
   FileName : "LargeIntMult.java"
*/
import java.util.Scanner;

class LargeIntMult
{ 
    
   	public static void main(String args[]) 
    	{ 
		// variable declarations
		String uString, vString;
		int [] u;
		int [] v;
		int [] product;
		int leadingZero = 0;
		Scanner scanner = new Scanner(System.in);
		
		// Retrieve u and v from user 
        	System.out.println("Enter a large number: u");
		uString = scanner.nextLine();
		System.out.println("Enter a large number: v");
		vString = scanner.nextLine();
		
		// convert u input to array of ints
		// and display
		u = new int[uString.length()];
		System.out.print("u = ");
		for(int i = 0; i < uString.length(); i++) 
		{
			u[i] = Character.getNumericValue(uString.charAt(i));
			System.out.print(u[i] + " ");
		}		
		
		// convert v input to array of ints
		// and display
		v = new int[vString.length()];
		System.out.print("\nv = ");
		for(int i = 0; i < vString.length(); i++) 
		{
			v[i] = Character.getNumericValue(vString.charAt(i));
			System.out.print(v[i] + " ");
		}
		
		// calculate product of u and v
		// and display product removing any leading zeros
		product = prod(u, v);
		System.out.print("\nProduct u*v = \n");
		if(product.length == 1){
			System.out.print(product[0] + " ");
		} else {
			for(int i = 0; i < product.length; i++) 
		{
				if(product[i] > 0 && leadingZero == 0)
					leadingZero = 1;
				if(leadingZero == 1)				
					System.out.print(product[i] + " ");
		}
		} 
		System.out.println();

    	}
	
	// function to calculate the product of two large 
	// integers using the div mod add and power
	// functions as aides
	public static int []  prod (int [] u, int [] v) 
	{	
		int [] x, y, w, z, array;
		int n, m, sum1, sum2;
		n = u.length;
		
		// calculate n
		if(v.length > n)
			n = v.length;
		
		// check if u == 0
		sum1 = 0;
		for(int i = 0; i < u.length; i++){
			sum1+=u[i];		
		}
		
		// check if v == 0
		sum2 = 0;
		for(int i = 0; i < v.length; i++){
			sum2+=v[i];		
		}
		
		// if u == 0 || v == 0 return 0
		if(sum1 == 0 || sum2 == 0){
			array = new int [1];
			array[0] = 0;
			return array;
		}
		
		// check n against threshold
		if(n <= 1){
			// calculate u * v
			// and store in string
			int prod = u[0] * v[0];
			String product = Integer.toString(prod);
			array = new int [product.length()];
			
			// convert u * v string to array
			for(int i = 0; i < product.length(); i++){
				array[i] = Character.getNumericValue(product.charAt(i));
			}

			return array;

		} else {
			// calculate product
			int [] a,b,c,d,e,f,g,h;
			m = n/2;


			x = div(u, u.length, m);
			y = mod(u, u.length, m);
			w = div(v, v.length, m);
			z = mod(v,v.length,m);
			
			// prod(x,w) * 10**2m
			a = prod(x,w);
			b = power(a, a.length, 2*m);
			
			// (prod(x,z) + prod(w,y)) * 10**m
			c = prod(x,z);
			d = prod(w,y);
			e = add(c,d);
			f = power(e, e.length, m);
			
			// prod(y,z) + f
			g = prod(y,z);			
			h = add(b,f);
			
			// h + g
			array = add(h,g);

			return array; // u*v product			
		}
	
	}
	
	public static int [] add (int [] n, int [] m)
	{
		// variable declaration
		String addition = "";
		int sum = 0, carry = 0;
		int difference;
		int [] array;

		// need cases for different array lengths for n, m
		// case: n.length == m.length
		if(n.length == m.length){
			//cycle through m, adding to n
			for(int i = m.length - 1; i >= 0; i--){
				sum = m[i] + n[i] + carry;
				// checking for carry
				if(sum >= 10){
					carry = 1;				
					sum = sum % 10;
				} else {
					carry = 0;				
				}
				addition = sum + addition;
			}
			// add last carry to front if needed	
			if(carry>0)
				addition = carry + addition;

		// case: n.legnth > m.length
		} else if (n.length > m.length) {
			difference = n.length - m.length;
			// cycle through n adding to m
			for(int i = n.length - 1; i >= difference; i--){
				sum = m[i-difference] + n[i] + carry;
				// check for carry
				if(sum >= 10){
					carry = 1;				
					sum = sum % 10;
				} else {
					carry = 0;				
				}
				addition = sum + addition;
			}
			// add the difference in lengths to front of array	
			for(int i = difference - 1; i >= 0; i--) {
				sum = n[i] + carry;
				// check carry
				if(sum >= 10){
					carry = 1;				
					sum = sum % 10;
				} else {
					carry = 0;				
				}
				addition = sum + addition;
			}
			// add last carry to front if needed
			if(carry>0)
				addition = carry + addition;	

		// case: default		
		} else {
			difference = m.length - n.length;
			// cycle through m, adding to n
			for(int i = m.length - 1; i >= difference; i--){
				sum = m[i] + n[i-difference] + carry;
				// check for carry
				if(sum >= 10){
					carry = 1;				
					sum = sum % 10;
				} else {
					carry = 0;				
				}
				addition = sum + addition;
			}	
			// add the difference in legths to front of array
			for(int i = difference - 1; i >= 0; i--) {
				sum = m[i] + carry;
				// check carry
				if(sum >= 10){
					carry = 1;				
					sum = sum % 10;
				} else {
					carry = 0;				
				}
				addition = sum + addition;
			}
			// add last carry to front if needed
			if(carry>0)
				addition = carry + addition;
		}
		
		// convert string used for addition to new array
		array = new int [addition.length()];
		for(int i = 0; i < addition.length(); i++) 
		{
			array[i] = Character.getNumericValue(addition.charAt(i));
		}
		return array;

	}

	// function to divide array of integers
	// if k>0, it will chop k elements off the end
	// of the array, x
	public static int [] div (int [] x, int n, int k)
	{
		// x / 1 == x
		if(k == 0){
			return x;

		// always returns zero
		} else if((n-k) <= 0) {
			int [] newX = new int[1];
			newX[0] = 0;			
			return newX;		
		}

		// x/10**k, floored
		int [] newX = new int [n - k];
		for(int i = 0; i < newX.length; i ++) 
		{
			newX[i] = x[i];		
		}
		return newX; 
	}
	
	// function to compute modulus of array of integers
	// if k>0, it will copy k elements off the end
	// of the array, x
	public static int [] mod (int [] x, int n, int k)
	{
		// k >= n always returns x
		if(k >= n){
			return x;
		}
		// x % 1 = 0, always
		if(k == 0) {
			int [] newX = new int[1];
			newX[0] = 0;			
			return newX;
		} 
		// x % 10**k
		int [] newX = new int [k];
		for(int i = 0; i < k; i++) 
		{
			newX[i] = x[i+n-k];		
		}
		return newX;
	}

	// function to multiple array of integers by powers of 10
	// if k>0, it will add k zeros to the end
	// of the array, x
	public static int [] power (int[] x, int n, int k)
	{
		// x * 1 = x
		if(k == 0)
			return x;
		
		// multiply by k power of ten
		int [] newX = new int [n + k];
		for(int i = 0; i < newX.length; i ++) 
		{
			if(i < n){
				newX[i] = x[i];		
			} else {
				newX[i] = 0;
			}
		}
		return newX;
	}
     
} 

