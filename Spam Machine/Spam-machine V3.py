# Spam Machine V3
# This program will send messages to a whatever app you want to send them to

# Imports needed for the program
import time
import pyautogui

# Custom message to be typed depending on the "Target"
message = input("Enter the message you want to send: ")

# The number of times the message will be sent
total_messages = int(input("Enter the number of times you want to send the message: "))

# Tells the user 5 seconds to send the message
print('5 seconds till the first message...')

# Timer before the first message is written (Use this time to click on the text box you want to send messages)
time.sleep(5)

# Progress bar code to show the progress of completion
def display_progress_bar(current, total):
    bar_length = 20
    filled_length = int(bar_length * current / total)
    bar = "#" * filled_length + "-" * (bar_length - filled_length)
    percent = int(current / total * 100)
    print(f"\r[{bar}] {percent}% Complete", end="")

# Sending the messages
for i in range(total_messages):
    pyautogui.typewrite(message)
    pyautogui.press("enter")
    time.sleep(.5) # Time in between messages

    display_progress_bar(i + 1, total_messages)

print(f"\nAll messages sent! Total messages sent: {total_messages}")

# Made By Bry on Oct 15,2024. I started at 10:31 pm and finished by around 11:00 pm.
# Time taken to write this program was around 30 minutes.
# Praise the Sun, and may the Old Blood guide you!
# Boredom won thus this was created v2.0