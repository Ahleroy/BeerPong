from time import sleep
import Shifter

def main():
	pause=0.5
	gpio.setmode(gpio.BOARD)
	shifter=Shifter()
	running=True
	while running==True:
        	try:
			#shifter.clear()
			#shifter.setValue(1)
			#sleep(1)
			shifter.clear()
			shifter.setValue(0x0AAAAAA)
			sleep(pause)
			shifter.clear()
			shifter.setValue(0x0555555)
			sleep(pause)
	        


if __name__=="__main__":
    main()
