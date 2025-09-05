/*============================================================================
| Assignment: pa01 - Encrypting a plaintext file using the Hill cipher
|
| Author: Kauan Lima
| Language: Java
| To Compile: javac pa01.java
| To Execute: java -> java pa01 kX.txt pX.txt
| where kX.txt is the keytext file
| and pX.txt is plaintext file
| Note:
| All input files are simple 8 bit ASCII input
| All execute commands above have been tested on Eustis
|
| Class: CIS3360 - Security in Computing - Spring 2025
| Instructor: McAlpin
| Due Date: 2/23/2025
+===========================================================================*/

// import necessary utilities
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class pa01
{
    // main
    public static void main(String[] args)
    {
        // take in two command line arguments
        String keyText = args[0];
        String sourceText = args[1];

        // get and print the key matrix
        System.out.println("\nKey matrix: ");
        int[][] matrix = getMatrix(keyText);
        int blockSize = matrix.length;

        // get and print the plaintext
        System.out.println("\nPlaintext: ");
        String formatPlaintext = getPlaintext(sourceText, blockSize);

        // print the cipher
        System.out.println("\nCiphertext: ");
        printCipher(formatPlaintext, matrix);
    }

    // return the matrix from the k.txt file
    // read file int by int and return the matrix
    private static int[][] getMatrix(String kFile)
    {
        // open and close file and scanner if program works with no errors
        try (Scanner fr = new Scanner(new File(kFile)))
        {
            // obtain the matrix size
            int squareLength = fr.nextInt();
            int[][] matrix = new int[squareLength][squareLength];

            // scan each int in the matrix and store in a square matrix
            for (int i = 0; i < squareLength; i++)
                for (int j = 0; j < squareLength; j++)
                    if (fr.hasNextInt())
                        matrix[i][j] = fr.nextInt();

            // print the matrix
            for (int[] row : matrix)
            {
                for (int num : row)
                    System.out.printf("%4d", num);
                System.out.println();
            }

            // return the 2d array
            return matrix;
        }
        // report if file not found
        catch (FileNotFoundException e)
        {
            System.err.println("File not found: " + e.getMessage());
        }
        // report any other errors
        catch (Exception e)
        {
            System.err.println("Error reading matrix file: " + e.getMessage());
        }

        // return null if error occurs
        return null;
    }

    // return the plaintext obtained from the p.txt file
    // streams plaintext and prints char by char until finished, then return
    private static String getPlaintext(String pFile, int blockSize)
    {
        // open and close filereader if program works with no errors
        try (FileReader fr = new FileReader(pFile))
        {
            // ch stores the current char and ctr stores the current number of chars in the plaintext
            int ch;
            int ctr = 0;

            // StringBuilder to build pt char by char
            StringBuilder pt = new StringBuilder();

            // check if the file has ended, if not, keep streaming
            while ((ch = fr.read()) != -1)
                // if the current char is a letter and also is a latin character
                if (Character.isLetter((char)ch) &&
                    Character.UnicodeBlock.of((char)ch) == Character.UnicodeBlock.BASIC_LATIN)
                {
                    // append lowercase to pt, print, and increment ctr
                    pt.append(Character.toLowerCase((char)ch));
                    System.out.print(Character.toLowerCase((char) ch));
                    ctr++;

                    // print new line every 80 chars
                    if (ctr % 80 == 0)
                        System.out.println();
                }

            // set pad variable and calculate the required padding size
            char pad = 'x';
            int padSize = blockSize - (ctr % blockSize);

            // iterate until no more padding required
            for (; padSize != 0; padSize--)
            {
                // append the pad to pt, print, and increment ctr
                pt.append(pad);
                System.out.print(pad);
                ctr++;

                // if padding results in a line longer than 80 chars, print a new line
                if (ctr % 80 == 0)
                    System.out.println();
            }

            // print newline and return the string 
            System.out.println();
            return pt.toString();
        }
        // catch i/o exception while reading file
        catch (IOException e)
        {
            System.err.println("Error reading plaintext file: " + e.getMessage());
        }
        // report any other exception
        catch (Exception e)
        {
            System.err.println("Error has occurred: " + e.getMessage());
        }

        // return null if error occurs
        return null;
    }

    // print the cipher text
    private static void printCipher(String plaintext, int[][] matrix)
    {
        // StringBuilder to append every encrypted char to ciphertext
        StringBuilder ciphertext = new StringBuilder();

        // declare necessary variables
        char cipherChar;
        int blockSize = matrix.length;
        int index = 0;

        // while there exists plaintext to be encrypted
        while (index < plaintext.length())
        {
            // obtain portion of plaintext that is the size of a block
            // and directly after the previous loop iteration
            String ptSubstring = plaintext.substring(index, index + blockSize);

            // hill cipher
            // for each row in the matrix
            for (int i = 0; i < blockSize; i++)
            {
                // initialize int to store char to perform necessary operations
                int asciiChar = 0;

                // for each column in matrix
                // recieve the first char of the substring until the final
                // cast to an int and subtract 97 to obtain the numerical position in the alphabet
                // multiply by each specified element in matrix
                // save ascii char
                for (int j = 0; j < blockSize; j++)
                    asciiChar += ((int)ptSubstring.charAt(j) - 97) * matrix[i][j];

                // asciichar % 26 to get the alphabetical value of the char
                // add 97 to recieve the proper ascii value of that char in lowercase
                // append to cipher text
                cipherChar = (char) ((asciiChar % 26) + 97);
                ciphertext.append(cipherChar);
            }

            // start new index for substring directly after the previous final index for substring
            index += blockSize;
        }

        // print the ciphertext char by char until 80 characters reached, print a new line
        for (int i = 1; i <= ciphertext.length(); i++)
        {
            System.out.print(ciphertext.charAt(i - 1));
            if (i % 80 == 0)
                System.out.println();
        }

        // print final newline char
        System.out.println();
        return;
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