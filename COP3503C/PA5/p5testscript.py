#Dr. Andrew Steinberg
#COP3503 Student Python Script v1.0
#This script will automatically compile, run, and compare your results to a provided txt file that contains sample output.
#DO NOT MODIFY THE CONTENTS OF THIS FILE!
#You do not need understand this code as this is out of the scope of this course. However, if you are interested you can discuss with Dr. Steinberg

import os
import sys
import subprocess
import functools
import re

#this is where we will put the input... yes they are global variables but this is ok to do for this scenario since this is a script
#it is list and each item will be string representing input for each question
#example  ['1 2 3', '2' , '4.2 41.4']
qinputs = [] 

def result():
    cwd = os.getcwd()
    
    f1 = open(cwd + '/samplesolutionp5.txt', "r")
    f2 = open(cwd + '/program5solution_student_output.txt', "r")
    
    #read output from each text file
    l1 = f1.readlines()
    l2 = f2.readlines()
    
    
    #compare the content read
    if len(l1) == len(l2) and functools.reduce(lambda x, y : x and y, map(lambda p, q: p == q, l1, l2), True): 
        print(r"  __")
        print(r"<(o )___")
        print(r" (  ._>  All tests passed!")
        print(r"  `---'")
        print("Quack-tastic! All tests passed! The Debugging Duck approves your code, but make sure you followed Dr. Steinberg's code style guidelines and requirements for the assignment!")
        subprocess.run(["rm program5solution_student_output.txt"], capture_output=True, text = True, shell = True)
    else: 
        print(r"""
                  __
                <(o )___
                 (  ._>  Oops! Some tests failed... Check out your output file to see what didn't pass.
                  `---'

                Don't worry. Even ducks take a wrong turn sometimes!
                Keep quacking at it, you'll get all tests next time.
                """)
    

def compilerunfile():
    cwd = os.getcwd()
    
    #javac compile command the executable will be KnightNetDriver.class
    
    javac = "javac " + cwd + "/KnightNetDriver.java" #compile solution file command and generate class file

    proc = subprocess.run([javac], capture_output=True, text = True, shell = True)
    

    
    java = "java KnightNetDriver"
    
    f = open('program5solution_student_output.txt', "w")
    
    #list comprehension
    inputs = ' '.join([str(item) for item in qinputs])
    
    
    #catch infinite loops and time constraints
    try:
        proc2 = subprocess.run([java], capture_output=True, input = inputs, text = True, shell = True, timeout = 3) 
        f.write(str(proc2.stdout))    
    except subprocess.TimeoutExpired as e:
        print("Your program is NOT within the time constraint! Please fix or else points will be deducted.")
    


    print("Done running the student's solution.")
    f.close()


def setupchecker():
    print("We are now checking to make sure you have all necessary files in the same directory.")
    cwd = os.getcwd() #this grabs the current directory as it varies for each student based on NID
    
    
    #check to see if java file is placed properly. Only checks parts of it. Student is responsible for naming it properly with respective name as stated in the directions.
    if not os.path.exists(cwd + "/KnightNet.java"):
        raise FileNotFoundError("You are missing your Java source!! Please put in your Java file. Script Exiting!")
        
    
    #check to see if java file is placed properly. Only checks parts of it. Student is responsible for naming it properly with respective name as stated in the directions.
    if not os.path.exists(cwd + "/KnightNetDriver.java"):
        raise FileNotFoundError("You are missing your Java source!! Please put in your Java Runner file. Script Exiting!")
    
    f = open("KnightNet.java", 'r')
    name = f.readline().strip()
    name = re.findall(r"\s(.*)", name)
    name = ''.join([str(item) for item in name])
    print("The name that will appear in the grader script is " + name + '.')
    print("If this is not right then you need to fix your comment header as Dr. Steinberg has mentioned.")
    
    #first check to see if solution txt file exists in the same directory as this script
    
    if not os.path.exists(cwd + "/samplesolutionp5.txt"):
        raise FileNotFoundError("The provided sample solution text file is not in the currect directory as this script." + 
        " Please place the text file in this directory and try again. Script Exiting!")
        
    
    print("We are done with checking to make sure necessary files were provided.")
    

def main():
    print("Beginning the test of my program compared with a provided txt file from Dr. Steinberg.")
    print("Before this script tests the program, we need to make sure you have everything in order.")
    setupchecker()
    print("Setup is now complete. Begin testing.")
    print("Now it is time to compile and run the file.")
    compilerunfile()
    print("Now it is time for the moment of truth. Comparing my file output with Dr. Steinberg's sample solution file.")
    result()
    
    #remove class files to prevent confusion
    subprocess.run(["rm *.class"], capture_output=True, text = True, shell = True)

                
    
    
    

if __name__ == "__main__":
    main()