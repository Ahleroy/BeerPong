import RPi.GPIO as gpio


class carteColonne():

	clock=15
	

	def __init__(self):
		self.setupBoard()
		self.pause=0
	def colonneSuivante(self):
		gpio.output(Shifter.clock,gpio.HIGH)
		sleep(self.pause)
		gpio.output(Shifter.clock,gpio.LOW)
		sleep(self.pause)
		
	def clear(self):
		gpio.output(Shifter.clearPin,gpio.LOW)
		Shifter.tick(self)
		gpio.output(Shifter.clearPin,gpio.HIGH)

	def setupBoard(self):

		#gpio.setup(Shifter.inputA,gpio.OUT)
		#gpio.output(Shifter.inputA,gpio.HIGH)

		gpio.setup(Shifter.inputB,gpio.OUT)
		gpio.output(Shifter.inputB,gpio.LOW)

		gpio.setup(Shifter.clock,gpio.OUT)
		gpio.output(Shifter.clock,gpio.LOW)

		gpio.setup(Shifter.clearPin,gpio.OUT)
		gpio.output(Shifter.clearPin,gpio.HIGH)