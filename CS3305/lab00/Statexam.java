// FILE:  Statexam.java
// This program calls five test function to test the Statistician class.
// Maximum number of points from this program is 100.
//
public class Statexam {

    public static void main( String [] args ) {
        int value = 0;
        int result= 0;

        System.out.printf("Running Statistician tests:\n");

        System.out.printf("TEST 1:\n");
        System.out.printf("Testing nextNumber, reset, length, sum, and mean (51 points).\n");
        result = test1( );
        value += result;
        if ( result > 0 ) System.out.printf("Test 1 passed.\n\n");
        else System.out.printf("Test 1 failed.\n\n");

        System.out.printf("TEST 2:\n");
        System.out.printf("Testing minimum and maximum methods (10 points).\n");
        result = test2( );
        value += result;
        if ( result > 0 ) System.out.printf("Test 2 passed.\n\n");
        else System.out.printf("Test 2 failed.\n\n");

        System.out.printf("Test 5:\n");
        System.out.printf("Testing equals method (12 points).\n");
        result = test5( );
        value += result;
        if ( result > 0 ) System.out.printf("Test 5 passed.\n\n");
        else System.out.printf("Test 5 failed.\n\n");

        System.out.printf("Test 3:\n");
        System.out.printf("Testing union method (10 points).\n");
        result = test3( );
        value += result;
        if ( result > 0 ) System.out.printf("Test 3 passed.\n\n");
        else System.out.printf("Test 3 failed.\n\n");

        System.out.printf("Test 4:\n");
        System.out.printf("Testing scale method (17 points).\n");
        result = test4( );
        value += result;
        if ( result > 0 ) System.out.printf("Test 4 passed.\n\n");
        else System.out.printf("Test 4 failed.\n\n");

        System.out.printf("If you submit the Statistician to Prof. Haiduk now\n" +
                          "this part of the grade will be %d points out of 100\n", value);
        System.exit(0);

    }

    public static boolean close( double a, double b ) {
        double EPSILON = 1e-5;
        return ( Math.abs(a-b) < EPSILON );
    }

    public static int test1( ) {
        // Test function for basic Statistician functions.
        // Returns 51 if everything goes okay; otherwise, return 0.
        
        Statistician s = new Statistician(); Statistician t = new Statistician( );
        int points = 0;

        int i;
        double r = 0;
        if ( s.length( ) != 0 || t.length( ) != 0 ) return 0;
        points += 3;

        if ( s.sum( ) != 0 || t.sum( ) != 0 ) return 0;
        points += 3;

        if ( !Double.isNaN( s.mean( ) ) ) return 0;
        points += 4;

        for (i = 1; i <= 10000; i++) {
            s.nextNumber(i);
            r += i;
        }

        if ( t.length( ) != 0 || t.sum ( ) != 0 ) return 0;
        points += 3;

        if ( s.length( ) != 10000 ) return 0;
        points += 5;

        if ( !close(s.sum( ), r ) ) return 0;
        points += 5;

        if ( !close(s.mean( ), r/10000) ) return 0;
        points += 5;

        // Reset and then retest everything
        s.reset( ); t.reset( ); r = 0;

        if ( s.length( ) != 0 || t.length( ) != 0 ) return 0;
        points += 3;

        if ( s.sum( ) != 0 || t.sum( ) != 0 ) return 0;
        points += 3;

        if ( !Double.isNaN( s.mean( ) ) ) return 0;
        points += 5;

        for (i = 1; i <= 10000; i++) {
            s.nextNumber(i);
            r += i;
        }

        if ( t.length( ) != 0 || t.sum ( ) != 0 ) return 0;
        points += 3;

        if ( s.length( ) != 10000 ) return 0;
        points += 3;

        if ( !close(s.sum( ), r) ) return 0;
        points += 3;

        if ( !close(s.mean( ), r/10000) ) return 0;
        points += 3;

        System.out.printf("points from this test %d\n", points);
        return points;
    }

    public static int test2( ) {
        // Test function for minimum/maximum Statistician functions.
        // Returns 10 if everything goes okay; otherwise returns 0;

        Statistician s = new Statistician(); Statistician t = new Statistician();
        Statistician u = new Statistician();

        int points = 0;

        if ( s.length( ) != 0 || t.length( ) != 0 ) return 0;
        points += 1;
        if ( s.sum( ) != 0 || t.sum( ) != 0 ) return 0;
        points += 1;

        if ( !Double.isNaN( s.minimum( ) ) ) return 0;
        points += 1;

        if ( !Double.isNaN( s.maximum( ) ) ) return 0;
        points += 1;

        double r = 1.39804e-76;
        r = 1/r;
        s.nextNumber( r );
        if ( (s.minimum( ) != r ) || (s.maximum( ) != r) ) return 0;
        points += 2;

        r *= -1;
        t.nextNumber(r);
        if ( (t.minimum( ) != r) || (t.maximum( ) != r) ) return 0;
        points += 2;

        u.nextNumber( 100 ); u.nextNumber( -1 ); u.nextNumber( 101 ); u.nextNumber( 3 );
        if ( (u.minimum( ) != -1) || (u.maximum( ) != 101) ) return 0;
        points += 2;

        System.out.printf("points from this test %d\n", points);
        return points;
    }

    public static int test3( ) {
        // Test function for the union and equals method of the Statistician
        // Return 10 if everything is okay; otherwise, returns 0.

        Statistician s, t, u, v;
        s = new Statistician(); t = new Statistician();
        u = new Statistician(); v = new Statistician();

        int points = 0;

        if ( s.length( ) != 0 || 
             t.length( ) != 0 || 
             u.length( ) != 0 || 
             v.length( ) != 0 ) return 0;
        if ( s.sum( ) != 0 ||
             t.sum( ) != 0 ||
             u.sum( ) != 0 ||
             v.sum( ) != 0 ) return 0;

        t.nextNumber( 5 );
        u.nextNumber( 0 ); u.nextNumber( 10 ); u.nextNumber( 10 ); u.nextNumber( 20 );

        v = Statistician.union( s, s );
        if ( v.length( ) != 0 || v.sum( ) != 0 ) return 0;
        points += 2;
        //System.out.printf("Success with t = union( s, s)\n");

        v = Statistician.union( s, u );
        if ( !u.equals( v ) ) return 0;
        points += 2;
        //System.out.printf("Success with v = union( s, u)\n");

        v = Statistician.union( t, s );
        if ( !t.equals( v ) ) return 0;
        points += 2;
        //System.out.printf("Success with v = union( t, s)\n");

        v = Statistician.union( t, u );
        if ( v.length( ) != 5 ) return 0;
        if ( !close( v.sum( ), 45 ) ) return 0;
        if ( v.minimum( ) != 0 ) return 0;
        if ( v.maximum( ) != 20 ) return 0;
        if ( !close( v.mean( ), 45.0/5 ) ) return 0;
        points += 2;
        //System.out.printf("Success with v = union( t, u)\n");

        v = Statistician.union( v, t );
        if ( v.length() != 6 ) return 0;
        if ( !close( v.sum( ), 50 ) ) return 0;
        if ( v.minimum( ) != 0 ) return 0;
        if ( v.maximum( ) != 20 ) return 0;
        if ( !close( v.mean( ), 50.0/6 ) ) return 0;
        points += 2;
        //System.out.printf("Success with v = union( v, t)\n");

        System.out.printf("points from this test %d\n", points);
        return points;
    }

    public static int test4( ) {
        // Test function for the Statistician scale method
        // Returns 17 if everything goes okay; otherwise, returns 0.

        Statistician s, t, u;
        s = new Statistician(); t = new Statistician(); u = new Statistician();
        int points = 0;

        if ( s.length( ) != 0 || 
             t.length( ) != 0 || 
             u.length( ) != 0 ) return 0;
        if ( s.sum( ) != 0 ||
             t.sum( ) != 0 ||
             u.sum( ) != 0  ) return 0;

        u.nextNumber( 0 ); u.nextNumber( 10 ); u.nextNumber( 10 ); u.nextNumber( 20 );

        s = Statistician.scale( 2, u );
        if ( s.length( ) != 4 ) return 0;
        if ( !close( s.sum( ), 80 ) ) return 0;
        if ( s.minimum( ) != 0 ) return 0;
        if ( s.maximum( ) != 40 ) return 0;
        if ( !close( s.mean( ), 80.0/4 ) )return 0;
        points += 2;

        s = Statistician.scale( -2, u );
        if ( s.length( ) != 4 ) return 0;
        if ( !close( s.sum( ), -80 ) ) return 0;
        if ( s.minimum( ) != -40) return 0;
        if ( s.maximum( ) != 0 ) return 0;
        if ( !close( s.mean( ), -80.0/4 ) )return 0;
        points += 11;

        s = Statistician.scale( 0, u );
        if ( s.length( ) != 4 ) return 0;
        if ( !close( s.sum( ), 0 ) ) return 0;
        if ( s.minimum( ) != 0) return 0;
        if ( s.maximum( ) != 0 ) return 0;
        if ( !close( s.mean( ), 0 ) )return 0;
        points += 2;

        s = Statistician.scale( 10, t );
        if ( s.length( ) != 0 ) return 0;
        if ( !close( s.sum( ), 0 ) ) return 0;
        points += 2;

        System.out.printf("points from this test %d\n", points);
        return points;
    }

    public static int test5( ) {
        // Test function for the equals method of the Statistician
        // Returns 12 if everything is okay; otherwise, returns 0.
        Statistician s, t, u, v, w, x;
        int points = 0;

        s = new Statistician(); t = new Statistician(); u = new Statistician();
        v = new Statistician(); w = new Statistician(); x = new Statistician();

        t.nextNumber( 10 );
        u.nextNumber( 0 ); u.nextNumber( 10 ); u.nextNumber( 10 ); u.nextNumber( 20 );
        v.nextNumber( 5 ); v.nextNumber( 0 ); v.nextNumber( 20 ); v.nextNumber( 15 );
        w.nextNumber( 0 );
        x.nextNumber( 0 ); x.nextNumber( 0 );

        if ( !s.equals(s) ) return 0;
        points += 2;

        if ( s.equals(t) ) return 0;
        points += 2;

        if ( t.equals(s) ) return 0;
        points += 2;

        if ( u.equals(t) ) return 0;
        points += 2;

        if ( !u.equals(v) ) return 0;
        points += 2;

        if ( w.equals(x) ) return 0;
        points += 2;

        System.out.printf("points from this test %d\n", points);
        return points;
    }

}
