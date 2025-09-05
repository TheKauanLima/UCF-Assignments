/**
 * Purpose: Create various methods for use in Picturetester.java
 * 
 * @author Kauan Lima
 * @version 3/21/2024
*/


import java.awt.*;
import java.awt.font.*;
import java.awt.geom.*;
import java.awt.image.BufferedImage;
import java.lang.ProcessBuilder.Redirect;
import java.text.*;
import java.util.*;
import java.util.List; // resolves problem with java.awt.List and java.util.List

/**
 * A class that represents a picture.  This class inherits from 
 * SimplePicture and allows the student to add functionality to
 * the Picture class.  
 * 
 * @author Barbara Ericson ericson@cc.gatech.edu
 */
public class Picture extends SimplePicture 
{
  ///////////////////// constructors //////////////////////////////////
  
  /**
   * Constructor that takes no arguments 
   */
  public Picture ()
  {
    /* not needed but use it to show students the implicit call to super()
     * child constructors always call a parent constructor 
     */
    super();  
  }
  
  /**
   * Constructor that takes a file name and creates the picture 
   * @param fileName the name of the file to create the picture from
   */
  public Picture(String fileName)
  {
    // let the parent class handle this fileName
    super(fileName);
  }
  
  /**
   * Constructor that takes the width and height
   * @param height the height of the desired picture
   * @param width the width of the desired picture
   */
  public Picture(int height, int width)
  {
    // let the parent class handle this width and height
    super(width, height);
  }
  
  /**
   * Constructor that takes a picture and creates a 
   * copy of that picture
   * @param copyPicture the picture to copy
   */
  public Picture(Picture copyPicture)
  {
    // let the parent class do the copy
    super(copyPicture);
  }
  
  /**
   * Constructor that takes a buffered image
   * @param image the buffered image to use
   */
  public Picture(BufferedImage image)
  {
    super(image);
  }
  
  ////////////////////// methods ///////////////////////////////////////
  
  /**
   * Method to return a string with information about this picture.
   * @return a string with information about the picture such as fileName,
   * height and width.
   */
  public String toString()
  {
    String output = "Picture, filename " + getFileName() 
                       + " height " + getHeight() 
                       + " width " + getWidth();
    return output;
    
  }
  
  /////////////////////////// Activity 5 ////////////////////////////
  /** Method to set the blue to 0 */
  public void zeroBlue()
  {
    Pixel[][] pixels = this.getPixels2D();
    for (Pixel[] rowArray : pixels)
    {
      for (Pixel pixelObj : rowArray)
      {
        pixelObj.setBlue(0);
      }
    }
  }
  
  // keepOnlyBlue
  public void keepOnlyBlue()
  {
    Pixel[][] pixels = this.getPixels2D();
    for (Pixel[] rowArray : pixels)
      for (Pixel pixelObj : rowArray)
      {
    	  pixelObj.setRed(0);
    	  pixelObj.setGreen(0);
      }
  }
  
  // keepOnlyRed
  // keepOnlyGreen
  // negate
  public void negate()
  {
    Pixel[][] pixels = this.getPixels2D();
    for (Pixel[] rowArray : pixels)
      for (Pixel pixelObj : rowArray)
      {
    	  pixelObj.setRed(255 - pixelObj.getRed());
    	  pixelObj.setGreen(255 - pixelObj.getGreen());
    	  pixelObj.setBlue(255 - pixelObj.getBlue());
      }
  }
  // grayscale
  public void grayscale()
  {
    Pixel[][] pixels = this.getPixels2D();
    int grayColor;
    for (Pixel[] rowArray : pixels)
      for (Pixel pixelObj : rowArray)
      {
    	  grayColor = (pixelObj.getRed() + pixelObj.getGreen() + pixelObj.getBlue()) / 3;;
    	  pixelObj.setRed(grayColor);
    	  pixelObj.setGreen(grayColor);
    	  pixelObj.setBlue(grayColor);
      }
  }
  // fixUnderWater - optional
  public void fixUnderWater()
  {
    Pixel[][] pixels = this.getPixels2D();
    int grayColor;
    for (Pixel[] rowArray : pixels)
      for (Pixel pixelObj : rowArray)
      {
    	  if(pixelObj.getBlue() > pixelObj.getRed() && pixelObj.getBlue() > pixelObj.getGreen())
    	  {
    		  pixelObj.setBlue(pixelObj.getBlue() + 40);
    		  
    		  if(pixelObj.getBlue() > 255)
        		  pixelObj.setBlue(255);
    	  }
    	  else
    	  {
    		  pixelObj.setRed(pixelObj.getRed() - 40);
    		  pixelObj.setGreen(pixelObj.getGreen() - 40);
    		  
    		  if(pixelObj.getRed() < 0)
        		  pixelObj.setRed(0);
    		  
    		  if(pixelObj.getGreen() < 0)
        		  pixelObj.setGreen(0);
    	  }
      }
  }
  /////////////////////////// Activity 6 ////////////////////////////
  /** Method that mirrors the picture around a 
    * vertical mirror in the center of the picture
    * from left to right */
  public void mirrorVertical()
  {
    Pixel[][] pixels = this.getPixels2D();
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    int width = pixels[0].length;
    for (int row = 0; row < pixels.length; row++)
    {
      for (int col = 0; col < width / 2; col++)
      {
        leftPixel = pixels[row][col];
        rightPixel = pixels[row][width - 1 - col];
        rightPixel.setColor(leftPixel.getColor());
      }
    } 
  }
  
  // mirrorVerticalRightToLeft 
  public void mirrorVerticalRightToLeft()
  {
    Pixel[][] pixels = this.getPixels2D();
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    int width = pixels[0].length;
    for (int row = 0; row < pixels.length; row++)
    {
      for (int col = 0; col < width / 2; col++)
      {
        leftPixel = pixels[row][col];
        rightPixel = pixels[row][width - 1 - col];
        leftPixel.setColor(rightPixel.getColor());
      }
    } 
  }
  
  // mirrorHorizontal
  public void mirrorHorizontal()
  {
    Pixel[][] pixels = this.getPixels2D();
    Pixel topPixel = null;
    Pixel botPixel = null;
    int length = pixels.length;
    for (int row = 0; row < length; row++)
    {
      for (int col = 0; col < pixels[0].length; col++)
      {
        topPixel = pixels[row][col];
        botPixel = pixels[length - 1 - row][col];
        botPixel.setColor(topPixel.getColor());
      }
    } 
  }
  
  // mirrorHorizontalBotToTop 
  public void mirrorHorizontalBotToTop()
  {
    Pixel[][] pixels = this.getPixels2D();
    Pixel topPixel = null;
    Pixel botPixel = null;
    int length = pixels.length;
    for (int row = 0; row < length; row++)
    {
      for (int col = 0; col < pixels[0].length; col++)
      {
        topPixel = pixels[row][col];
        botPixel = pixels[length - 1 - row][col];
        topPixel.setColor(botPixel.getColor());
      }
    } 
  }
  
  /////////////////////////// Activity 7 ////////////////////////////
  /** Mirror just part of a picture of a temple */
  public void mirrorTemple()
  {
    int mirrorPoint = 276;
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    int count = 0;
    Pixel[][] pixels = this.getPixels2D();
    
    // loop through the rows
    for (int row = 27; row < 97; row++)
    {
      // loop from 13 to just before the mirror point
      for (int col = 13; col < mirrorPoint; col++)
      {
        
        leftPixel = pixels[row][col];      
        rightPixel = pixels[row][mirrorPoint - col + mirrorPoint];
        rightPixel.setColor(leftPixel.getColor());
        count++;
      }
    }
    System.out.println(count);
  }
  
  // mirrorArms 
  public void mirrorArms()
  {
    int mirrorPoint = 193;
    Pixel topPixel = null;
    Pixel botPixel = null;
    int count = 0;
    Pixel[][] pixels = this.getPixels2D();
    
    //right arm loops
    // loop through the rows
    for (int row = 158; row < mirrorPoint; row++)
    {
      // loop from 103 to just before the mirror point
      for (int col = 103; col < 170; col++)
      {
        
        topPixel = pixels[row][col];      
        botPixel = pixels[mirrorPoint - row + mirrorPoint][col];
        botPixel.setColor(topPixel.getColor());
        count++;
      }
    }
    
    mirrorPoint = 198;
    
    //left arm loops
    // loop through the rows
    for (int row = 171; row < mirrorPoint; row++)
    {
      // loop from 239 to just before the mirror point
      for (int col = 239; col < 294; col++)
      {
        
        topPixel = pixels[row][col];      
        botPixel = pixels[mirrorPoint - row + mirrorPoint][col];
        botPixel.setColor(topPixel.getColor());
        count++;
      }
    }
    System.out.println(count);
  }
  
  // mirrorGull 
  public void mirrorGull()
  {
    int mirrorPoint = 345;
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    int count = 0;
    Pixel[][] pixels = this.getPixels2D();
    
    //gull
    // loop through the rows
    for (int row = 235; row < 323; row++)
    {
      // loop from 238 to just before the mirror point
      for (int col = 238; col < mirrorPoint; col++)
      {
        
        rightPixel = pixels[row][col];      
        leftPixel = pixels[row][mirrorPoint - col + mirrorPoint / 3];
        leftPixel.setColor(rightPixel.getColor());
        count++;
      }
    }
    System.out.println(count);
  }
  
  /////////////////////////// Activity 8 ////////////////////////////
  /** copy from the passed fromPic to the
    * specified startRow and startCol in the
    * current picture
    * @param fromPic the picture to copy from
    * @param startRow the start row to copy to
    * @param startCol the start col to copy to
    */
  public void copy(Picture fromPic, int startRow, int startCol)
  {
    Pixel fromPixel = null;
    Pixel toPixel = null;
    Pixel[][] toPixels = this.getPixels2D();
    Pixel[][] fromPixels = fromPic.getPixels2D();
    for (int fromRow = 0, toRow = startRow; 
         fromRow < fromPixels.length &&
         toRow < toPixels.length; 
         fromRow++, toRow++)
    {
      for (int fromCol = 0, toCol = startCol; 
           fromCol < fromPixels[0].length &&
           toCol < toPixels[0].length;  
           fromCol++, toCol++)
      {
        fromPixel = fromPixels[fromRow][fromCol];
        toPixel = toPixels[toRow][toCol];
        toPixel.setColor(fromPixel.getColor());
      }
    }   
  }

  /** copy from the passed fromPic to the
    * specified startRow and startCol in the
    * current picture
    * @param fromPic the picture to copy from
    * @param fromStartRow the row to start coping
    * from in the from picture
    * @param fromStartCol the column to start
    * copying from in the from picture
    * @param fromEndRow the row to stop before in the from picture 
    * @param fromEndCol the column to stop before in the from picture
    * @param toStartRow the row to start copying to
    * @param toStartCol the column to start copying to
    */
  public void copy(Picture fromPic, 
                   int fromStartRow,
                   int fromStartCol,
                   int fromEndRow,
                   int fromEndCol,
                   int toStartRow, 
                   int toStartCol)
  {
    // to be completed for Activity 8
  }
  
  
  /** Method to create a collage of several pictures */
  public void createCollage()
  {
    Picture flower1 = new Picture("flower1.jpg");
    Picture flower2 = new Picture("flower2.jpg");
    this.copy(flower1,0,0);
    this.copy(flower2,100,0);
    this.copy(flower1,200,0);
    Picture flowerNoBlue = new Picture(flower2);
    flowerNoBlue.zeroBlue();
    this.copy(flowerNoBlue,300,0);
    this.copy(flower1,400,0);
    this.copy(flower2,500,0);
    this.mirrorVertical();
    this.write("collage.jpg");
  }
  
  // myCollage
  
  
  /////////////////////////// Activity 9 ////////////////////////////
  /** Method to show large changes in color 
    * @param edgeDist the distance for finding edges
    */
  public void edgeDetection(int edgeDist)
  {
    Pixel leftPixel = null;
    Pixel rightPixel = null;
    Pixel[][] pixels = this.getPixels2D();
    Color rightColor = null;
    for (int row = 0; row < pixels.length; row++)
    {
      for (int col = 0; col < pixels[0].length-1; col++)
      {
        leftPixel = pixels[row][col];
        rightPixel = pixels[row][col+1];
        rightColor = rightPixel.getColor();
        if (leftPixel.colorDistance(rightColor) > edgeDist)
          leftPixel.setColor(Color.BLACK);
        else
          leftPixel.setColor(Color.WHITE);
      }
    }
  }  
  
  // edgeDetection2
  
} // this } is the end of class Picture, put all new methods before this
