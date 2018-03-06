import RPi.GPIO as GPIO

class LedRGB:
    def __init__(self, r, g, b):
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(r, GPIO.OUT)
        GPIO.setup(g, GPIO.OUT)
        GPIO.setup(b, GPIO.OUT)
        GPIO.setup(r, GPIO.OUT)
        self.red = GPIO.PWM(r, 100)
        self.green = GPIO.PWM(g, 100)
        self.blue = GPIO.PWM(b, 100)
        self.red.start(0)
        self.green.start(0)
        self.blue.start(0)

    def color(self, r, g, b):
        self.red.ChangeDutyCycle(int(r / 255 * 100))
        self.green.ChangeDutyCycle(int(g / 255 * 100))
        self.blue.ChangeDutyCycle(int(b / 255 * 100))
    def dark(self):
        self.red.stop()              # stop the red PWM output
        self.green.stop()
        self.blue.stop()

    def light(self):
        self.red.start(1)
        self.green.start(1)
        self.blue.start(1)

    def destroy(self):
        self.red.stop()              # stop the red PWM output
        self.green.stop()
        self.blue.stop()
        GPIO.cleanup()
