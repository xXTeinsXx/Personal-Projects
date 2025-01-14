
import time
import pyautogui

def display_progress_bar(current, total):
    bar_length = 20
    filled_length = int(bar_length * current / total)
    bar = "#" * filled_length + "-" * (bar_length - filled_length)
    percent = int(current / total * 100)
    print(f"\r[{bar}] {percent}% Complete", end="")

message = 'Quotation: "She lived alone in that big house, keeping her curtains drawn, and the townspeople said that the smell of dead flowers came from there."'  # Custom message to be typed depending on the "Target"
time.sleep(5) # Timer before the first message is written (Use this time to click on the text box you want to send messages)

total_iterations = 1  # The number of times the message will be sent

for i in range(total_iterations):
    pyautogui.typewrite(message)
    pyautogui.press("enter")
    time.sleep(.5) # Time in between messages

    display_progress_bar(i + 1, total_iterations)

print("\nAll messages sent!")

# Made By Bry on Jul 8,2023. I started at 12:25 am and finished by around 1 am.
# Boredom won thus this was created