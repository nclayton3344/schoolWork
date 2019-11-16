import java.util.Scanner;
import java.io.File;
import java.io.IOException;

class Scheduling {

	  // Class created to represent the jobs
		// contains all information needed about the jobs
		// that are read from the file
		private static class Job
		{
				public double ratio;
		    public int weight;
		    public int length;
				public int difference;

				// default constructor
				Job() {
					weight = 0;
					length = 0;
					difference = 0;
					ratio = 0;
				}

				// constructor to intialize with data
				Job(int w, int l, int d, double r) {
					weight = w;
					length = l;
					difference = d;
					ratio = r;
				}

				// function to set data for the object
				public void setData(int w, int l, int d, double r) {
					weight = w;
					length = l;
					difference = d;
					ratio = r;
				}
		 };


		public static void main(String args[]) throws IOException {

			// variable declarations
			File file = new File("jobs.txt");
			Scanner sc = new Scanner(file);
			int fileSize, weight, length;
			Job[] jobArray;

			// get length from file and dynamically create array to
			// hold the given number of jobs
			fileSize = Integer.parseInt(sc.nextLine());
			jobArray = new Job[fileSize];

			// retrieve all job data from the file
			for(int i = 0; sc.hasNextLine() && i < jobArray.length; i++) {

				// read data from line
				String data = sc.nextLine();
				String[] jobData = data.split(" ");

				// parse data as integer
				weight = Integer.parseInt(jobData[0]);
				length = Integer.parseInt(jobData[1]);

				// create Job object with data to jobArray[i]
				jobArray[i] = new Job(weight, length, weight - length, 1.0 * weight / length);

			}

			// sort array by difference and output sum
			sort(jobArray, 0, fileSize-1, 0);
			System.out.println("Part a = " + calculateSum(jobArray));

			// sort array by ration and output sum
			sort(jobArray, 0, fileSize-1, 1);
			System.out.println("Part b = " + calculateSum(jobArray));

		}

		// calculates the sum for a list (array) of Job objects
		public static long calculateSum(Job[] arr) {

			// variable declarations
			long sum;
			int lengthSum;
			sum = lengthSum = 0;

			// loop through array and calculate sum
			// based on Job object weight and length
			for(int i = 0; i < arr.length; i++){
				lengthSum += arr[i].length;
				sum += (arr[i].weight * lengthSum);
			}

			return sum;

		}

		/* Quicksort algorithm to sort a Job object using either the difference
		   	or the ratio as the pivot item
			*NOTE: version ===> 0 to sort by difference, any other integer will sort by ratio*/
    public static void sort(Job arr[], int low, int high, int version) {
        if (low < high) {
						int pi;
            /* pi is partitioning index, arr[pi] is
              now at right place */
						if(version == 0){
							pi = partitionDiff(arr, low, high);
						} else {
							pi = partitionRatio(arr, low, high);
						}

            // Recursively sort elements before
            // partition and after partition
            sort(arr, low, pi-1, version);
            sort(arr, pi+1, high, version);
        }
    }

		// return a pivot point based on the ratio attribute
		// of a Job object
    public static int partitionRatio(Job arr[], int low, int high) {

				// variable declarations
        double pivot = arr[high].ratio;
        int i = (low-1); // index of larger element

				// loop from low to high looking for objects to be swapped
        for (int j=low; j<high; j++) {
					
            // If current element is larger than the pivot
            if (arr[j].ratio > pivot) {
                i++;

                // swap arr[i] and arr[j]
                Job temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // swap arr[i+1] and arr[high] (or pivot)
        Job temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }

		// returns a pivot point based on the difference attribute
		// and the weight attribute of a Job object
		// essentially it is sorted on the difference and then the weight
    public static int partitionDiff(Job arr[], int low, int high) {

				// variable declaration
        int pivot = arr[high].difference;
				int pivotWeight = arr[high].weight;
        int i = (low-1); // index of larger element

				// loop from low to high looking for objects to be swapped
        for (int j=low; j<high; j++) {

            // If current element is larger than the pivot or equal to the pivot with a larger weight
            if (arr[j].difference > pivot || (arr[j].difference == pivot && arr[j].weight > pivotWeight)) {
                i++;
                // swap arr[i] and arr[j]
                Job temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // swap arr[i+1] and arr[high] (or pivot)
        Job temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        return i+1;
    }

}
