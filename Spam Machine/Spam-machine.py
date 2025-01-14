
import time
import pyautogui

message = "HEYYYYY I'm bored"  # Custom message to be typed depending on the "Target"
time.sleep(5) # Timer before the first message is written (Use this time to click on the text box you want to send messages)

# Loop to type the message and press Enter x times with a delay of x seconds. Change depending on the requirement
for _ in range(200): # The range is the amount of times it repeats
    pyautogui.typewrite(message)
    pyautogui.press("enter")
    time.sleep(.2) # Time in between messages

#Made By Bry on Jul 8,2023. I started at 12:25 am and finished by around 1 am.
#Boredom won thus this was created 
