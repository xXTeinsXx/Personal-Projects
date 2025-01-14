# Spam Machine V4
# This program will send messages to a whatever app you want to send them to

# Imports needed for the program
import time
import pyautogui

# Def that asks if the user wants to run the code
def runcode():
    runcode = str(input('\nDo you want to run this code?(Yes/No): '))
    return runcode

# Def that gets the inputs from the user
def get_inputs():
    global message, total_messages
    # Error catch for the message
    while True:
            message = input("Enter the message you want to send: ")
            if message.isnumeric():
                    print('You entered a number. Please try again and enter a message.')
            else:
                break
    
    # Error catch for the total_messages
    while True:
        try:
            total_messages = int(input("Enter the number of times you want to send the message: "))
            if total_messages < 0:
                    print("Please try and enter a possitive value.")
            else:
                break
        except ValueError:
                print("Please try and enter a valid number.")
    return message, total_messages

# Def that tells the user 5 seconds to send the message
def fivesectimer():
    # Tells the user 5 seconds to send the message
    print('5 seconds till the first message...(Use this time to click on the text box you want to send messages)')

    # Timer before the first message
    time.sleep(5)

# Progress bar code to show the progress of completion
def display_progress_bar(current, total):
    bar_length = 20
    filled_length = int(bar_length * current / total)
    bar = "#" * filled_length + "-" * (bar_length - filled_length)
    percent = int(current / total * 100)
    print(f"\r[{bar}] {percent}% Complete", end="")

# Def that sends the messages
def send_messages(message, total_messages):
    for i in range(total_messages):
        pyautogui.typewrite(message)
        pyautogui.press("enter")
        time.sleep(.5) # Time in between messages
        display_progress_bar(i + 1, total_messages)
    print(f"\nAll messages sent! Total messages sent: {total_messages}")

# Code that Runs when the user wants to run the code
while runcode().casefold() == 'yes':
    get_inputs()
    fivesectimer()
    send_messages(message, total_messages)

# If the user does not want to run the code this will happen.
else:
     print('Code did not run. Thank You.')


# Made By Bry on Oct 15,2024. I started at 11:50 pm and finished by around Oct 16, 2024; 12:30:25 am.
# Praise the Sun, and may the Old Blood guide you!
# Boredom won thus this was created v3.0