# Script for the matrix scroll
# You only need to use the function scrollMatrix(input_str) within your text as parameter
#
# Author : Alix LEROY
# Prom : ESTIA 2017
# Email 1 : alix.leroy@net.estia.fr
# Email 2 : alixleroy49@gmail.com
# Date : Janvier 2017

# coding: utf-8

import sys
reload(sys)
sys.setdefaultencoding("utf-8")
import unicodedata
import re
import listCharacters as lc
import numpy as np
import afficheur

#Function to remove accents
def remove_accents(input_str):
    nkfd_form = unicodedata.normalize('NFKD', unicode(input_str))
    return u"".join([c for c in nkfd_form if not unicodedata.combining(c)])


#Function to remove special characters
def remove_nonletters(input_str):
	regex = re.compile('[^a-zA-Z]')
	#First parameter is the replacement, second parameter is your input string
	regex.sub('', input_str)



#Formalize the text in order to display it on the led screen
def FormalizeText(input_str):
	textClean = remove_accents(input_str)
	textUpper = textClean.upper()
	return textUpper


def getCharMatrix(input_char): #return the corresponding matrix
	return {
		'A': lc.A,
		'B': lc.B,
		'C': lc.C,
        'D': lc.D,
        'E': lc.E,
        'F': lc.F,
        'G': lc.G,
        'H': lc.H,
        'I': lc.I,
        'J': lc.J,
        'K': lc.K,
        'L': lc.L,
        'M': lc.M,
        'N': lc.N,
        'O': lc.O,
        'P': lc.P,
        'Q': lc.Q,
        'R': lc.R,
        'S': lc.S,
        'T': lc.T,
        'U': lc.U,
        'V': lc.V,
        'W': lc.W,
        'X': lc.X,
        'Y': lc.Y,
        'Z': lc.Z,
        }.get(input_char, lc.A)



def getScrolledMatrix(input_str):
	numberOfChars = len(input_str) # Get the number of chars in the input string
	charsOfInput = list(input_str) # Convert input string to an array of chars

	ScrolledMatrix = lc.initializedScrolledMatrix

	for n in range(numberOfChars): #For each char

		#Select the n'th char in the list
		char = charsOfInput[n]

		#get its corresponding matrix
		charMatrix = getCharMatrix(char)

		#concatenate the ScrolledMatrix with the new character
		ScrolledMatrix = np.concatenate((ScrolledMatrix, charMatrix), axis=1)


	return ScrolledMatrix




def scrollMatrix(input_str):

	#formalize the input text in order to avoid unwanted chars
	FormalizedText = FormalizeText(input_str)

	#Get the Matrix corresponding to the formalized text
	ScrolledMatrix = getScrolledMatrix (FormalizedText)


	#Create a matrix full of zeros
	currentMatrix = np.zeros((12,32), dtype=np.int)

	#Get the dimension of the ScrolledMatrix
	shape = ScrolledMatrix.shape

	#shape[1] is the number of columns

	for n in range(shape[1]):

		#Shift the current Matrix columns
		for i in range (12): #for each row of the current Matrix
			for j in range (31): #For each column of the current Matrix exepct the last one
				currentMatrix[i][j] = currentMatrix[i][j+1]

		for i in range (12):
			currentMatrix[i][31] = ScrolledMatrix[i][n]

		afficheur.affiche(50, currentMatrix)

	#Shit until the text disappear
	for n in range(31):

		#Shift the current Matrix columns
		for i in range (12): #for each row of the current Matrix
			for j in range (31): #For each column of the current Matrix exepct the last one
				currentMatrix[i][j] = currentMatrix[i][j+1]

		for i in range (12):
			currentMatrix[i][31] = 0

		afficheur.affiche(50, currentMatrix)


#scrollMatrix("ababABCCCccBABA")
