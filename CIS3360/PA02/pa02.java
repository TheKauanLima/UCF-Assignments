/*============================================================================
| Assignment: pa02 - Calculate the checksum of an input file given:
| -> the name of the input file,
| -> the checksum size of either 8, 16, or 32 bits
| Author: Kauan Lima
| Language: Java
| To Compile: javac pa02.java
| To Execute: java -> java pa02 inputFilename.txt checksumSize
| where inputFilename.txt is the input file
| and checksumSize is either 8, 16, or 32
| Note:
| All input files are simple 8 bit ASCII input
| All execute commands above have been tested on Eustis
| Class: CIS3360 - Security in Computing - Spring 2025
| Instructor: McAlpin
| Due Date: 3/23/2025
+===========================================================================*/

// import necessary utilities
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class pa02
{
    // global variables
    private static int numBlocks;
    private static int blockLength;
    private static final char PAD = 'X';

    // main
    public static void main(String[] args) {
        // take in two command line arguments
        String filename = args[0];
        String checksumSizeString = args[1];

        // parse checksumSize to use as an int
        int checksumSize = Integer.parseInt(checksumSizeString);
        numBlocks = checksumSize / 8;

        // check if checksum size is a valid integer
        if (checksumSize == 8 || checksumSize == 16 || checksumSize == 32 ) {
            echoText(filename);
            long fileLength = fileLength(filename);
            long sum = checkSum(filename, checksumSize, fileLength);

            // correct fileLength to take into account padding
            while (fileLength % blockLength != 0)
                fileLength++;

            printChecksum(checksumSize, sum, fileLength);
        }
        // report error if checksum size is not valid
        else
            System.err.println("Valid checksum sizes are 8, 16, or 32");
    }

    // print the checksum
    public static void printChecksum(int checksumSize, long sum, long fileLength) {
        // compute the mask needed
        long mask = (1L << checksumSize) - 1;
        long maskedSum = sum & mask;

        // print formatted output
        System.out.printf("%2d bit checksum is %8x for all %4d chars\n",
            checksumSize, maskedSum, fileLength);
    }

    public static void echoText(String fn) {
        System.out.println();

        // open and close filereader if program works with no errors
        try (FileReader fr = new FileReader(fn))
        {
            // ch stores the current char and ctr stores the current position
            int ch;
            int ctr = 0;

            // StringBuilder to build pt char by char
            StringBuilder pt = new StringBuilder();

            // check if the file has ended, if not, keep streaming
            while ((ch = fr.read()) != -1)
                // if the current char is in standard ascii
                if (ch < 128) {
                    // append to pt, print, and increment ctr
                    pt.append((char)ch);
                    System.out.print((char) ch);
                    ctr++;

                    // print new line every 80 chars
                    if (ctr % 80 == 0)
                        System.out.println();
                }
        }
        // catch i/o exception while reading file
        catch (IOException e) {
            System.err.println("Error reading plaintext file: " + e.getMessage());
        }
        // report any other exception
        catch (Exception e) {
            System.err.println("Error has occurred: " + e.getMessage());
        }
    }

    // compute length of file and reassign blocklength
    public static long fileLength(String fn)
    {
        File file = new File(fn);
        long fileLength = file.length();
        blockLength = (int)Math.ceil(fileLength / (double)numBlocks);

        return fileLength;
    }

    // compute the checksum
    public static long checkSum(String fn, int bitSize, long fS) {
        long sum = 0;
    
        // open and close filereader if program works with no errors
        try (FileReader fr = new FileReader(fn)) {
            // ch stores the current char and ctr stores the current position
            int ch;
            int ctr = 0;

            // find current block and value to shift
            int assignedBlock;
            int shift;
            int shifted;

            // shift each value the necessary block amount
            while ((ch = fr.read()) != -1) {
                assignedBlock = ctr % numBlocks;
                shift = (bitSize - 8) - (assignedBlock * 8);
                shifted = ch << shift;
                sum += shifted;
                ctr++;
            }

            // print and compute padding
            while (ctr < blockLength * numBlocks) {
                assignedBlock = ctr % numBlocks;
                shift = (bitSize - 8) - (assignedBlock * 8);
                shifted = PAD << shift;
                sum += shifted;
                ctr++;
                System.out.print(PAD);
            }
        }
        // catch i/o exception while reading file
        catch (IOException e) {
            System.err.println("Error reading plaintext file: " + e.getMessage());
        }
        // report any other exception
        catch (Exception e) {
            System.err.println("Error has occurred: " + e.getMessage());
        }
    
        // print new line and return sum
        System.out.println();
        return sum;
    }
}
/*
 * =============================================================================
 * | I, Kauan Lima, ka994482 affirm that this program is
 * | entirely my own work and that I have neither developed my code together
 * with
 * | any another person, nor copied any code from any other person, nor
 * permitted
 * | my code to be copied or otherwise used by any other person, nor have I
 * | copied, modified, or otherwise used programs created by others. I
 * acknowledge
 * | that any violation of the above terms will be treated as academic
 * dishonesty.
 * +============================================================================
 * =
 */